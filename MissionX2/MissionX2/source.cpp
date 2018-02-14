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

const int BLUR_SIZE = 3;

int main(int argc, const char** argv)
{
	string path = "../../Data/Gliese 581d V2.pbm";
	cv::Mat1b src, dest1, dest2, dest3, dest4, dest5;
	src = cv::imread(path, cv::IMREAD_GRAYSCALE);

	/*
	GaussianBlur(src, dest1, cv::Size(BLUR_SIZE, BLUR_SIZE), 0, 0);
	blur(src, dest2, cv::Size(BLUR_SIZE, BLUR_SIZE), cv::Point(-1, -1));
	medianBlur(src, dest3, BLUR_SIZE);
	*/

	bilateralFilter(src, dest4, BLUR_SIZE, BLUR_SIZE * 2, BLUR_SIZE / 2);

	cv::Mat kernel = cv::Mat::ones(2, 2, CV_8U);
	cv::morphologyEx(dest3, dest5, cv::MorphTypes::MORPH_OPEN, kernel);
	cv::morphologyEx(dest5, dest5, cv::MorphTypes::MORPH_CLOSE, kernel);

	imshow("Original", src);
	imshow("Opening", dest5);

	/*
	imshow("Homogeneous", dest1);
	imshow("Gaussian", dest2);
	imshow("Median", dest3);
	imshow("Bilateral", dest4);
	*/

	cv::waitKey(0);
	return 0;
}