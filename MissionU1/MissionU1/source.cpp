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

const int KERNEL_SIZE = 3;

int main(int argc, const char** argv)
{
	//Loading images
	string path = "../../Data/U1_surface.pbm";
	cv::Mat1b src, dest;
	src = cv::imread(path, cv::IMREAD_GRAYSCALE);
	cv::imshow("MissionU1 : U1", src);

	int ddepth = CV_8U;
	cv::Mat grad_x, grad_y;
	cv::Mat abs_grad_x, abs_grad_y;
	cv::Mat grad;

	//calc sobel for x and y axis
	cv::Sobel(src, grad_x, ddepth, 1, 0, KERNEL_SIZE);
	cv::convertScaleAbs(grad_x, abs_grad_x);
	cv::Sobel(src, grad_y, ddepth, 0, 1, KERNEL_SIZE);
	cv::convertScaleAbs(grad_y, abs_grad_y);
	//merge result
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
	cv::imshow("Sobel", grad);

	//calc scharr on the x and y axis
	cv::Mat scharr, scharrX, scharrY;
	cv::Scharr(src, scharrY, ddepth, 0, 1);
	cv::Scharr(src, scharrX, ddepth, 1, 0);

	cv::addWeighted(scharrX, 0.5, scharrY, 0.5, 0, scharr);
	cv::imshow("Scharr", scharr);

	cv::waitKey();

	return 0;
}