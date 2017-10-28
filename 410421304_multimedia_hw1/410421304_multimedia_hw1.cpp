// 410421304_multimedia_hw1.cpp: 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <opencv\cxcore.h>
#include <opencv\highgui.h>
#include "math.h"


using namespace cv;


int main(int argc, char argv[])
{
	//printf("test111");

	IplImage *test;
	test = cvLoadImage("test.png");
	cvNamedWindow("test");
	cvShowImage("test", test);

	IplImage *gray;
	//8 bit depth gray
	gray = cvCreateImage(cvGetSize(test), 8, 1);

	//use BGR2GRAY to perform change
	cvCvtColor(test, gray, CV_BGR2GRAY);
	cvNamedWindow("gray");
	cvShowImage("gray", gray);

	cvWaitKey();

	return 0;
}

