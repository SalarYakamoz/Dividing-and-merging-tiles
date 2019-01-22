// First consider that we want to divide our images to 4 parts and accumalate the images to input to our DL model
int divideParameter = 2;
static std::vector<dlib::matrix<dlib::rgb_pixel>> imagesTotal
std::vector<cv::Mat>& src;
// Dividing part
for (int k = 0; k < divideParameter * divideParameter; k++){
			int j = k / divideParameter;
			int m = k % divideParameter;
			// Heare src is our source image 
			srcDivided = src(Rect((col / divideParameter) * m, (row / divideParameter) * j, (col / divideParameter), (row / divideParameter))).clone();	
			imagesTotal.push_back(srcDivided);
			}
			
// After running the main part of the application, we want to merge each divided tile to a results tile with the same size of input tile.
// The main adavantage of this dividing and merging is that we don't resize our input images or we dont need to crop our input tiles

 // Merging part
 // Here the main idea is that we copy small tiles to a bigger one for each consecutive 4 tiles. This whole process is inside a for loop for all tiles in a whole slide image
images[imagesIndex] = dst;
imagesIndex = imagesIndex + 1;
atd::vector<cv::Mat> results;
// Last subtile of a tile (This means that we wait for the fourth divided tile to make the bigger tile)
if (k % (divideParameter * divideParameter) == (divideParameter * divideParameter) - 1){
	originalIndex = originalIndex + 1;
	Mat resutImage = Mat::zeros(row , col , CV_8UC4);
	for (int i = 0; i < divideParameter; i++){
		for (int j = 0; j < divideParameter; j++){
			images[j + i * divideParameter].copyTo(resutImage(Rect((col / divideParameter) * j, (row / divideParameter) * i, col / divideParameter, row / divideParameter)));
			}
	    }
	cv::Mat resutImageMasked = cv::Mat(row, col, CV_8UC1, cv::Scalar(255, 255, 255));
	resutImage.copyTo(resutImageMasked, edgeMask); // we could use an edgeMask to discard regions outside the selected area
	results.push_back(resutImageMasked);
	delete[] images;
	images = nullptr;
	imagesIndex = 0;
}