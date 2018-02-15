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
#include <algorithm>

using namespace std;

int main(int argc, const char** argv)
{
	string path = "../../Data/U2_surface.pbm";
	cv::Mat1b src;
	src = cv::imread(path, cv::IMREAD_GRAYSCALE);

	cv::imshow("MissionU2 : Source", src);

	cv::Mat1b cannyDest;
	//detection des arrêtes dans l'imahge
	cv::Canny(src, cannyDest, 100, 200, 3);

	vector<vector<cv::Point> > contours;
	vector<cv::Vec4i> hierarchy;
	//recherche des contours de l'image
	cv::findContours(cannyDest, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

	cv::Mat1b contour = cv::Mat::zeros(cannyDest.size(), CV_8U);
	//sort en fonction de la longueur des contours
	sort(contours.begin(), contours.end(), [](const vector<cv::Point>& c1, const vector<cv::Point>& c2) {
		return cv::contourArea(c1, false) > cv::contourArea(c2, false);
	});

	//remplissage du contour avec le plus grand périmètre
	cv::Scalar color = cv::Scalar(255, 255, 255);
	cv::drawContours(contour, contours, 0, color, CV_FILLED, 8, hierarchy, 0, cv::Point());

	cv::imshow("MissionU2 : Contour", contour);

	cv::Mat1b object;
	//permet d'utiliser l'image créer précédement comme un filtre et ainsi de ne faire apparaître que l'objet
	cv::bitwise_and(src, contour, object);

	cv::imshow("MissionU2 : Objet", object);
	cv::waitKey();

	return 0;
}