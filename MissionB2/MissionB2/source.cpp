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
	string path = "../../Data/GD61.pbm";
	cv::Mat1b src, dest;
	src = cv::imread(path, cv::IMREAD_GRAYSCALE);

	//image processing
	cv::normalize(src, dest, 255, 255, cv::NormTypes::NORM_INF);

	//displaying images
	cv::imshow("MissionB1 : GD61", src);
	cv::imshow("MissionB1 : Result", dest);
	cv::waitKey();

	return 0;
}