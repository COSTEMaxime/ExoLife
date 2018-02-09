#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include "opencv2\objdetect\objdetect.hpp"
#include "opencv2\videoio\videoio.hpp"
#include "opencv2\imgcodecs\imgcodecs.hpp"

#include <vector>
#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, const char** argv)
{
	//Loading images
	string path1 = "../../Data/Jupiter1.pbm";
	string path2 = "../../Data/Jupiter2.pbm";
	cv::Mat1b src1, src2, dest;

	src1 = cv::imread(path1, cv::IMREAD_GRAYSCALE);
	src2 = cv::imread(path2, cv::IMREAD_GRAYSCALE);
	dest = src1.clone();

	//image processing
	cv::Mat kernel;
	cv::Point anchor;
	int kernelSize, iterations;
	
	kernelSize = 2;
	kernel = cv::Mat::ones(kernelSize, kernelSize, CV_8U);
	
	//opening = erosion followed by dilatation
	//cv::morphologyEx(dest, dest, cv::MORPH_OPEN, kernel, anchor, iterations, cv::BORDER_CONSTANT, cv::MORPH_RECT);

	//closing = dilation followed by erosion
	//cv::morphologyEx(dest, dest, cv::MORPH_CLOSE, kernel, anchor, iterations, cv::BORDER_CONSTANT, cv::MORPH_RECT);

	cv::erode(dest, dest, kernel, anchor, iterations = 1, cv::BORDER_CONSTANT, cv::MORPH_RECT);
	cv::dilate(dest, dest, kernel, anchor, iterations = 2, cv::BORDER_CONSTANT, cv::MORPH_RECT);
	cv::erode(dest, dest, kernel, anchor, iterations = 1, cv::BORDER_CONSTANT, cv::MORPH_RECT);
	
	//displaying images
	cv::imshow("MissionA4 : Jupiter1", src1);
	cv::imshow("MissionA4 : Jupiter2", src2);
	cv::imshow("MissionA4 : Result", dest);
	cv::waitKey();

	return 0;
}