#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include "opencv2\objdetect\objdetect.hpp"
#include "opencv2\videoio\videoio.hpp"
#include "opencv2\imgcodecs\imgcodecs.hpp"

#include <vector>
#include <stdio.h>
#include <Windows.h>
#include <iostream>

using namespace std;

int main(int argc, const char** argv)
{
	//Loading images
	string path = "../../Data/Encelade_surface.pbm";
	cv::Mat1b src;
	src = cv::imread(path, cv::IMREAD_GRAYSCALE);

	//Finding maximum value coordinates in the image
	double max;
	cv::Point locMax;
	cv::minMaxLoc(src, nullptr, &max, nullptr, &locMax);

	//Printing location
	cout << "Max : " << max << endl;
	cout << "At index :" << locMax << endl;

	//Displaying images
	cv::imshow("MissionA1 : Encelade", src);
	cv::waitKey();

	return 0;
}