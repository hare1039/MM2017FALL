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

	/*
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
	*/

	//version 2 end


	Mat test = imread("test.png");


	//print color image
	imshow("color", test);

	Mat gray = test;

	//opencv use bgr order

	int i, j;

	for (i = 0; i<test.rows; i++)
	{
		for (j = 0; j<test.cols; j++)
		{
			Vec3b pix = gray.at<Vec3b>(Point(j, i));

			uchar blu = pix[0];
			uchar gre = pix[1];
			uchar red = pix[2];
			//gray = (blue + green + red)/3
			uchar gra = ((blu + gre + red) / 3);

			pix[0] = gra;
			pix[1] = gra;
			pix[2] = gra;

			gray.at<Vec3b>(Point(j, i)) = pix;
		}
	}

	imshow("gray", gray);

	//use mat to create image
	//r,c,img

	Mat imgbw;
	imgbw.create((i * 4), (j * 4), CV_8UC3);

	imshow("bw", imgbw);

	cvWaitKey();

	return 0;
}

