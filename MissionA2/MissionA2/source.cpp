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
	string path = "../../Data/Mars_surface.pbm";
	cv::Mat1b src;
	src = cv::imread(path, cv::IMREAD_GRAYSCALE);

	//Findind average value of the image
	double sum = cv::sum(src)[0];
	cv::Size size = src.size();
	double avg =  sum / (255 * size.height * size.width);

	//Printing gaz concentration
	cout << "Taux de gaz dans l'image : " << setprecision(3) << avg * 100 << "%" << endl;

	//Displaying image
	imshow("MissionA2 : Mars", src);
	cv::waitKey();

	return 0;
}