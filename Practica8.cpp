#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//Ejercicio 1
/*int main() {
	Mat img, img_er, img_dil, img_open, img_close;
	img = imread("Imagenes/open_close.png");

	if (!img.data) {
		cout << "Error loading the image" << endl;
		return 1;
	}

	morphologyEx(img, img_er, MORPH_ERODE, Mat());
	morphologyEx(img, img_dil, MORPH_DILATE, Mat());
	morphologyEx(img, img_open, MORPH_OPEN, Mat());
	morphologyEx(img, img_close, MORPH_CLOSE, Mat());

	namedWindow("original", CV_WINDOW_AUTOSIZE);
	namedWindow("erode", CV_WINDOW_AUTOSIZE);
	namedWindow("dilate", CV_WINDOW_AUTOSIZE);
	namedWindow("open", CV_WINDOW_AUTOSIZE);
	namedWindow("close", CV_WINDOW_AUTOSIZE);

	imshow("original", img);
	imshow("erode", img_er);
	imshow("dilate", img_dil);
	imshow("open", img_open);
	imshow("close", img_close);


	waitKey(0);
	destroyAllWindows();

	return 0;
}*/

//Ejercicio 2
/*int main() {
	Mat binary, binary_lab, stats, centroids;
	binary = imread("Imagenes/binary_image.png", IMREAD_GRAYSCALE);

	if (!binary.data) {
		cout << "Error loading the image" << endl;
		return 1;
	}

	connectedComponentsWithStats(binary, binary_lab, stats, centroids);

	cvtColor(binary,binary,CV_GRAY2BGR);

	RNG color;
	for (int i = 0; i < stats.rows; i++) {
		int x = stats.at<int>(Point(0, i));
		int y = stats.at<int>(Point(1, i));
		int w = stats.at<int>(Point(2, i));
		int h = stats.at<int>(Point(3, i));

		Rect rect(x, y, w, h);
		rectangle(binary, rect, Scalar(color.uniform(0,255), color.uniform(0, 255), color.uniform(0, 255)));

		double x_c = centroids.at<double>(i, 0);
		double y_c = centroids.at<double>(i, 1);

		circle(binary, Point(x_c, y_c), 2, Scalar(color.uniform(0, 255), color.uniform(0, 255), color.uniform(0, 255)));

	}

	namedWindow("original", CV_WINDOW_AUTOSIZE);
	imshow("original", binary);

	waitKey(0);
	destroyAllWindows();

	return 0;

}*/

//Ejercicio 3
/*int MinMax(Mat&);

int main() {
	Mat img;
	img = imread("Imagenes/binary_image.png", IMREAD_GRAYSCALE);

	if (!img.data) {
		cout << "Error loading the image" << endl;

		return 1;
	}

	float range[] = { 0 , 256 };
	const float* ranges[] = { range };
	int hist_size = 256;
	Mat hist;

	calcHist(&img, 1, 0, Mat(), hist, 1, &hist_size, ranges);

	int histogram_width = 512;
	int histogram_height = 400;
	int bin_w = cvRound((double)histogram_width / hist_size);
	Mat aux_hist;
	Mat norm_hist(histogram_height, histogram_width, CV_8UC3, Scalar(0, 0, 0));

	normalize(hist, aux_hist, 0, histogram_height, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < 256; i++) {

		Point p1(bin_w * (i - 1), histogram_height - cvRound(aux_hist.at<float>(i - 1)));
		Point p2(bin_w * (i), histogram_height - cvRound(aux_hist.at<float>(i)));
		line(norm_hist, p1, p2, Scalar(255, 0, 0), 2);

	}

	Mat img_th;
	int min1 = MinMax(hist);
	threshold(img, img_th, min1, 255, THRESH_BINARY);

	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(img_th, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	RNG color;
	Mat img_dib(img.rows,img.cols,CV_8UC3);
	for (int i = 0; i < contours.size(); i++) {
		drawContours(img_dib, contours, i, Scalar(color.uniform(0, 255), color.uniform(0, 255), color.uniform(0, 255)), 1, 8, hierarchy);
	}

	namedWindow("original", CV_WINDOW_AUTOSIZE);
	namedWindow("threshold", CV_WINDOW_AUTOSIZE);
	namedWindow("dibujo", CV_WINDOW_AUTOSIZE);

	imshow("original", img);
	imshow("threshold", img_th);
	imshow("dibujo", img_dib);


	waitKey(0);
	destroyAllWindows();
}

//Threshold values
int MinMax(Mat& hist) {
	Mat hist_aux(256, 1, CV_32FC1);
	int i, max1, max2, min;

	max1 = 0;
	for (i = 1; i < 256; ++i) {
		if (hist.at<float>(max1) < hist.at<float>(i)) {
			max1 = i;
		}
	}
	for (i = 0; i < 256; ++i) {
		hist_aux.at<float>(i) = hist.at<float>(i) * abs(i - max1);
	}

	max2 = 0;
	for (i = 1; i < 256; ++i) {
		if (hist_aux.at<float>(max2) < hist_aux.at<float>(i)) {
			max2 = i;
		}
	}
	cout << "Maximo 1 " << max1 << " Maximo 2 " << max2 << endl;

	if (max1 < max2) {
		min = max1;
		for (i = min + 1; i < max2; ++i) {
			if (hist.at<float>(i) < hist.at<float>(min)) {
				min = i;
			}
		}
	}
	else {
		min = max2;
		for (i = min + 1; i < max1; ++i) {
			if (hist.at<float>(i) < hist.at<float>(min)) {
				min = i;
			}
		}
	}
	cout << "Minimo " << min << endl;
	return(min);
}*/

//Ejercicio 4
int MinMax(Mat&);

int main() {
	Mat img;
	img = imread("Imagenes/cafe.tif", IMREAD_GRAYSCALE);

	if (!img.data) {
		cout << "Error loading the image" << endl;

		return 1;
	}

	float range[] = { 0 , 256 };
	const float* ranges[] = { range };
	int hist_size = 256;
	Mat hist;

	calcHist(&img, 1, 0, Mat(), hist, 1, &hist_size, ranges);

	int histogram_width = 512;
	int histogram_height = 400;
	int bin_w = cvRound((double)histogram_width / hist_size);
	Mat aux_hist;
	Mat norm_hist(histogram_height, histogram_width, CV_8UC3, Scalar(0, 0, 0));

	normalize(hist, aux_hist, 0, histogram_height, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < 256; i++) {

		Point p1(bin_w * (i - 1), histogram_height - cvRound(aux_hist.at<float>(i - 1)));
		Point p2(bin_w * (i), histogram_height - cvRound(aux_hist.at<float>(i)));
		line(norm_hist, p1, p2, Scalar(255, 0, 0), 2);

	}

	Mat img_th;
	int min1 = MinMax(hist);
	threshold(img, img_th, min1, 255, THRESH_BINARY_INV);

	morphologyEx(img_th, img_th, MORPH_ERODE, Mat(), Point(-1,-1), 5);

	Mat img_c, img_lab, stats, centroids;
	connectedComponentsWithStats(img_th, img_lab, stats, centroids);

	RNG color;
	cvtColor(img, img, CV_GRAY2BGR);
	for (int i = 0; i < stats.rows; i++) {

		double x_c = centroids.at<double>(i, 0);
		double y_c = centroids.at<double>(i, 1);

		circle(img, Point(x_c, y_c), 2, Scalar(color.uniform(0, 255), color.uniform(0, 255), color.uniform(0, 255)));
	}


	namedWindow("original", CV_WINDOW_AUTOSIZE);
	namedWindow("threshold", CV_WINDOW_AUTOSIZE);

	imshow("original", img);
	imshow("threshold", img_th);


	waitKey(0);
	destroyAllWindows();
}

//Threshold values
int MinMax(Mat& hist) {
	Mat hist_aux(256, 1, CV_32FC1);
	int i, max1, max2, min;

	max1 = 0;
	for (i = 1; i < 256; ++i) {
		if (hist.at<float>(max1) < hist.at<float>(i)) {
			max1 = i;
		}
	}
	for (i = 0; i < 256; ++i) {
		hist_aux.at<float>(i) = hist.at<float>(i) * abs(i - max1);
	}

	max2 = 0;
	for (i = 1; i < 256; ++i) {
		if (hist_aux.at<float>(max2) < hist_aux.at<float>(i)) {
			max2 = i;
		}
	}
	cout << "Maximo 1 " << max1 << " Maximo 2 " << max2 << endl;

	if (max1 < max2) {
		min = max1;
		for (i = min + 1; i < max2; ++i) {
			if (hist.at<float>(i) < hist.at<float>(min)) {
				min = i;
			}
		}
	}
	else {
		min = max2;
		for (i = min + 1; i < max1; ++i) {
			if (hist.at<float>(i) < hist.at<float>(min)) {
				min = i;
			}
		}
	}
	cout << "Minimo " << min << endl;
	return(min);
}