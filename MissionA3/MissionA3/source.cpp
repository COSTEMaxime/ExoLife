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
	//loading image
	string path = "../../Data/Europa_surface.pbm";
	cv::Mat1b src, dest;
	src = cv::imread(path, cv::IMREAD_GRAYSCALE);

	//Applying gaussian filter on the image
	cv::adaptiveThreshold(src, dest, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 10001, 30);

	//Displaying images
	cv::imshow("MissionA3 : Europa", src);
	cv::imshow("MissionA3 : Result", dest);
	cv::waitKey();

	return 0;
}