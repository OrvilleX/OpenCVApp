// OpenCVApp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include "EDLib.h"
#include "LSWMS.h"

using namespace cv;

/**
 * @brief 
*/
void EDLinesTest() {
	Mat testImg = imread("F://lane2.png", 0);
	ED testED = ED(testImg, SOBEL_OPERATOR, 36, 8, 1, 10, 1.0, true); // apply ED algorithm

	//Show resulting edge image
	Mat edgeImg = testED.getEdgeImage();
	//imshow("Edge Image - PRESS ANY KEY TO CONTINUE", edgeImg);
	//waitKey();

	//Output number of segments
	int noSegments = testED.getSegmentNo();
	std::cout << "Number of edge segments: " << noSegments << std::endl;

	//Get edges in segment form (getSortedSegments() gives segments sorted w.r.t. legnths) 
	std::vector< std::vector<Point> > segments = testED.getSegments();


	//***************************** EDLINES Line Segment Detection *****************************
	//Detection of line segments from the same image
	EDLines testEDLines = EDLines(testImg);
	Mat lineImg = testEDLines.getLineImage();	//draws on an empty image
	imwrite("test3_r.jpg", lineImg);
	// imshow("Line Image 1 - PRESS ANY KEY TO CONTINUE", lineImg);

	//Detection of lines segments from edge segments instead of input image
	//Therefore, redundant detection of edge segmens can be avoided
	testEDLines = EDLines(testED);
	lineImg = testEDLines.drawOnImage();	//draws on the input image
	imwrite("test3_a.jpg", lineImg);
	imshow("Line Image 2  - PRESS ANY KEY TO CONTINUE", lineImg);

	//Acquiring line information, i.e. start & end points
	std::vector<LS> lines = testEDLines.getLines();
	int noLines = testEDLines.getLinesNo();
	std::cout << "Number of line segments: " << noLines << std::endl;
}

void LSWMSTest() {
	Mat inputImg = imread("F://lane2.png", 0);
	std::vector<LSWMS::LSEG> lSegs;
	std::vector<double> errors;
	LSWMS lswms(cv::Size(inputImg.cols, inputImg.rows), 3, 0, false, false);
	lswms.run(inputImg, lSegs, errors);
	lswms.drawLSegs(inputImg, lSegs, errors);
	imshow("LSWMS", inputImg);
}

int main()
{
	// EDLinesTest();
	LSWMSTest();
	waitKey();
    return 0;
}
