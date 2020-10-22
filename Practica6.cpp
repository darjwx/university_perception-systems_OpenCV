#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//Ejercicio 1
/*int main() {
	Mat square1;
	Mat square2;
	Mat square3;
	Mat square4;
	Mat square5;

	square1 = imread("Imagenes/Square01.png", IMREAD_GRAYSCALE);
	square2 = imread("Imagenes/Square02.png", CV_8UC1);
	square3 = imread("Imagenes/Square03.png", CV_8UC1);
	square4 = imread("Imagenes/Square04.png", CV_8UC1);
	square5 = imread("Imagenes/Square05.png", CV_8UC1);

	if (!square1.data || !square2.data || !square3.data || !square4.data || !square5.data) {
		cout << "Error loading the images" << endl;

		return 1;
	}

	vector<Point2f> corners1;
	vector<Point2f> corners2;
	vector<Point2f> corners3;
	vector<Point2f> corners4;
	vector<Point2f> corners5;

	goodFeaturesToTrack(square1, corners1, 4, 0.01, 10);
	goodFeaturesToTrack(square2, corners2, 4, 0.01, 10);
	goodFeaturesToTrack(square3, corners3, 4, 0.01, 10);
	goodFeaturesToTrack(square4, corners4, 4, 0.01, 10);
	goodFeaturesToTrack(square5, corners5, 4, 0.01, 10);

	cvtColor(square1, square1, CV_GRAY2BGR);
	cvtColor(square2, square2, CV_GRAY2BGR);
	cvtColor(square3, square3, CV_GRAY2BGR);
	cvtColor(square4, square4, CV_GRAY2BGR);
	cvtColor(square5, square5, CV_GRAY2BGR);

	for (int i = 0; i < corners1.size(); i++) {

		circle(square1, corners1[i], 3, Scalar(255,0,0), -1);

	}
	for (int i = 0; i < corners2.size(); i++) {

		circle(square1, corners2[i], 3, Scalar(255, 0, 0), -1);

	}
	for (int i = 0; i < corners3.size(); i++) {

		circle(square1, corners3[i], 3, Scalar(255, 0, 0), -1);

	}
	for (int i = 0; i < corners4.size(); i++) {

		circle(square1, corners4[i], 3, Scalar(255, 0, 0), -1);

	}
	for (int i = 0; i < corners5.size(); i++) {

		circle(square1, corners5[i], 3, Scalar(255, 0, 0), -1);

	}

	vector<uchar> status;
	vector<float> err;
	calcOpticalFlowPyrLK(square1, square2, corners1, corners2, status, err);

	for (int i = 0; i < status.size(); i++) {
		if (status[i] == 1) {
			line(square1, corners1[i], corners2[i], Scalar(0, 255, 0));
		}
	}

	calcOpticalFlowPyrLK(square2, square3, corners2, corners3, status, err);

	for (int i = 0; i < status.size(); i++) {
		if (status[i] == 1) {
			line(square1, corners2[i], corners3[i], Scalar(0, 255, 0));
		}
	}

	calcOpticalFlowPyrLK(square3, square4, corners3, corners4, status, err);

	for (int i = 0; i < status.size(); i++) {
		if (status[i] == 1) {
			line(square1, corners3[i], corners4[i], Scalar(0, 255, 0));
		}
	}

	calcOpticalFlowPyrLK(square4, square5, corners4, corners5, status, err);

	for (int i = 0; i < status.size(); i++) {
		if (status[i] == 1) {
			line(square1, corners4[i], corners5[i], Scalar(0, 255, 0));
		}
	}




	namedWindow("square 1", CV_WINDOW_AUTOSIZE);
	namedWindow("square 2", CV_WINDOW_AUTOSIZE);
	namedWindow("square 3", CV_WINDOW_AUTOSIZE);
	namedWindow("square 4", CV_WINDOW_AUTOSIZE);
	namedWindow("square 5", CV_WINDOW_AUTOSIZE);
	imshow("square 1", square1);
	imshow("square 2", square2);
	imshow("square 3", square3);
	imshow("square 4", square4);
	imshow("square 5", square5);


	waitKey(0);
	destroyAllWindows();

	return 0;

}*/

//Ejercicio 2
/*int main() {
	Mat hand;

	hand = imread("Imagenes/hand.jpg");

	if (!hand.data) {
		cout << "Error loading the images" << endl;

		return 1;
	}

	Mat hsv;
	cvtColor(hand, hsv, CV_BGR2HSV);

	Mat hsv_splitted[3];

	split(hsv, hsv_splitted);

	float range[] = { 0 , 180 };
	const float* ranges[] = { range };
	int hist_size = 180;
	Mat hist;

	calcHist(&hsv_splitted[0], 1, 0, Mat(), hist, 1, &hist_size, ranges);

	int histogram_width = 512;
	int histogram_height = 400;
	int bin_w = cvRound((double)histogram_width / hist_size);
	Mat aux_hist;
	Mat norm_hist(histogram_height, histogram_width, CV_8UC1, Scalar(255, 0, 0));

	normalize(hist, aux_hist, 0, histogram_height, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < 180; i++) {

		Point p1(bin_w * (i - 1), histogram_height - cvRound(aux_hist.at<float>(i - 1)));
		Point p2(bin_w * (i), histogram_height - cvRound(aux_hist.at<float>(i)));
		line(norm_hist, p1, p2, Scalar(0, 0, 0), 2);

	}

	Mat img1;
	img1 = imread("Imagenes/image0.jpg");

	if (!img1.data) {
		cout << "Error loading the images" << endl;

		return 1;
	}

	cvtColor(img1, img1, CV_BGR2HSV);

	Mat img1_splitted[3];
	split(img1, img1_splitted);

	Mat back_image;

	calcBackProject(&img1_splitted[0], 1, 0, aux_hist, back_image, ranges);

	namedWindow("original h", CV_WINDOW_AUTOSIZE);
	namedWindow("histogram h", CV_WINDOW_AUTOSIZE);
	namedWindow("back image", CV_WINDOW_AUTOSIZE);
	imshow("original h", hsv_splitted[0]);
	imshow("histogram h", norm_hist);
	imshow("back image", back_image);

	waitKey(0);
	destroyAllWindows();

	return 0;
}*/

#define ESCAPE 27

void onMouse(int event, int x, int y, int, void*);

bool drawing = false;

Point origin;
Point final;

Mat frame;

//Ejercicio 3
int main() {
	char pressedKey = 0;

	VideoCapture camera(0);
	if (!camera.isOpened()) {
		cout << "Error opening the camera" << endl;
		return 1;
	}

	while (1) {
		camera >> frame;
		if (frame.empty()) break;

		namedWindow("Webcam", CV_WINDOW_AUTOSIZE);
		imshow("Webcam", frame);

		pressedKey = waitKey(0);

		//Any other key shows next frame
		if (pressedKey == ESCAPE) {
			break;
		}

	}

	namedWindow("Selected frame", CV_WINDOW_AUTOSIZE);

	setMouseCallback("Selected frame", onMouse);

	while (1) {
		imshow("Selected frame", frame);
		pressedKey = waitKey(10);

		if (pressedKey == ESCAPE) {
			break;
		}
	}

	Mat frame_roi = frame(Rect(origin, final));

	namedWindow("Region of interest", CV_WINDOW_AUTOSIZE);
	imshow("Region of interest", frame_roi);

	cvtColor(frame_roi, frame_roi, CV_BGR2HSV);

	Mat frame_roi_splitted[3];
	split(frame_roi, frame_roi_splitted);

	namedWindow("H", CV_WINDOW_AUTOSIZE);
	imshow("H", frame_roi_splitted[0]);

	float range[] = { 0 , 180 };
	const float* ranges[] = { range };
	int hist_size = 180;
	Mat hist;

	calcHist(&frame_roi_splitted[0], 1, 0, Mat(), hist, 1, &hist_size, ranges);

	int histogram_width = 512;
	int histogram_height = 400;
	int bin_w = cvRound((double)histogram_width / hist_size);
	Mat aux_hist;
	Mat norm_hist(histogram_height, histogram_width, CV_8UC1, Scalar(255, 0, 0));

	normalize(hist, aux_hist, 0, histogram_height, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < 180; i++) {

		Point p1(bin_w * (i - 1), histogram_height - cvRound(aux_hist.at<float>(i - 1)));
		Point p2(bin_w * (i), histogram_height - cvRound(aux_hist.at<float>(i)));
		line(norm_hist, p1, p2, Scalar(0, 0, 0), 2);

	}

	namedWindow("Histogram H", CV_WINDOW_AUTOSIZE);
	imshow("Histogram H", norm_hist);

	Mat back_image;
	Mat frame_splitted[3];

	//TODO: camara en tiempo real
	while (1) {
		camera >> frame;
		if (frame.empty()) break;

		cvtColor(frame, frame, CV_BGR2HSV);
		split(frame, frame_splitted);

		calcBackProject(&frame_splitted[0], 1, 0, aux_hist, back_image, ranges);

		//namedWindow("Back image", CV_WINDOW_AUTOSIZE);
		//imshow("Back image", back_image);

		TermCriteria term_crit(TermCriteria::EPS | TermCriteria::COUNT, 10, 1);
		Rect roi(origin, final);
		RotatedRect rot_rect = CamShift(back_image, roi, term_crit);

		Point2f vertices[4];
		rot_rect.points(vertices);
		for (int i = 0; i < 4; i++) {
			line(frame, vertices[i], vertices[(i + 1) % 4], Scalar(0, 0, 255));
		}

		cvtColor(frame, frame, CV_HSV2BGR);

		namedWindow("Webcam", CV_WINDOW_AUTOSIZE);
		imshow("Webcam", frame);

		pressedKey = waitKey(5);

		//Any other key shows next frame
		if (pressedKey == ESCAPE) {
			break;
		}

	}



	waitKey(0);
	camera.release();
	destroyAllWindows();

	return 0;

}

void onMouse(int event, int x, int y, int, void*) {

	switch (event) {
	case CV_EVENT_LBUTTONDOWN:
		origin = Point(x, y);
		drawing = true;

		break;
	case CV_EVENT_MOUSEMOVE:
		if (drawing == true) {
			//rectangle(frame, origin, Point(x, y), Scalar(0,0,255), -1);
		}
		break;
	case CV_EVENT_LBUTTONUP:
		drawing = false;
		final = Point(x, y);
		//rectangle(frame, origin, final, Scalar(0, 0, 255), -1);

		break;
		}
}