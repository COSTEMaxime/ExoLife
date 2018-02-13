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
	string path = "../../Data/HD215497.pbm";
	cv::Mat1b src;
	src = cv::imread(path, cv::IMREAD_GRAYSCALE);
	cv::Mat dest = cv::Mat::zeros(src.rows, src.cols, CV_8UC3);

	//image processing
	int histSize[] = { 256 };

	float range[] = { 0, 256 };
	const float* histRange[] = { range };

	cv::Mat hist;
	int channels[] = { 0 };
	int histHeight = 256;

	//calcul de l'histogramme
	cv::calcHist(&src, 1, channels, cv::Mat(), hist, 1, histSize, histRange);
	
	vector<int> seuils;
	float sum = 0;
	int nbPixels = src.cols * src.rows;

	//calcul des seuils
	for (int i = 0; i < 256; i++) {

		sum += hist.at<float>(i);
		if (sum > nbPixels / 4) { seuils.push_back(i); sum = 0; }
	}

	//Construction de la nouvelle image à l'aide des seuils
	for (int i = 0; i < nbPixels; i++) {

		if (src.at<byte>(i) < seuils[0]) {
			dest.at<cv::Vec3b>(i) = cv::Vec3b( 0, 0, 255 );
		}
		else if (src.at<byte>(i) < seuils[1]) {
			dest.at<cv::Vec3b>(i) = cv::Vec3b(0, 255, 0);
		}
		else if (src.at<byte>(i) < seuils[2]) {
			dest.at<cv::Vec3b>(i) = cv::Vec3b(255, 0, 0);
		}
		else {
			dest.at<cv::Vec3b>(i) = cv::Vec3b(255, 255, 255);
		}
	}

	//displaying images
	cv::imshow("Mission B3 : HD215497", src);
	cv::imshow("Mission B3 : Result", dest);
	cv::waitKey();

	return 0;
}