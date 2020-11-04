#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//Ejercicio 1
//Funciones
int MinMax(Mat&);

//Ejercicio 1
int main() {
	Mat umbra1;
	Mat umbra3;

	umbra1 = imread("Imagenes/umbra1.tif", IMREAD_GRAYSCALE);
	umbra3 = imread("Imagenes/umbra3.tif", IMREAD_GRAYSCALE);

	if (!umbra1.data || !umbra3.data) {
		cout << "Error loading the images" << endl;
		return 1;
	}

	//Umbra 1
	float range[] = { 0 , 256 };
	const float* ranges[] = { range };
	int hist_size = 256;
	Mat hist;

	calcHist(&umbra1, 1, 0, Mat(), hist, 1, &hist_size, ranges);

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

	Mat umbra1_th;
	int min1 = MinMax(hist);
	line(norm_hist, Point(bin_w * min1, 0), Point(bin_w * min1,histogram_height), Scalar(0, 255, 0), 2);
	threshold(umbra1, umbra1_th, min1, 255, THRESH_BINARY);

	namedWindow("original", CV_WINDOW_AUTOSIZE);
	namedWindow("threshold", CV_WINDOW_AUTOSIZE);
	namedWindow("histograma", CV_WINDOW_AUTOSIZE);
	imshow("original", umbra1);
	imshow("threshold", umbra1_th);
	imshow("histograma", norm_hist);

	//Umbra 3
	Mat hist3;

	calcHist(&umbra3, 1, 0, Mat(), hist3, 1, &hist_size, ranges);

	Mat aux_hist3;
	Mat norm_hist3(histogram_height, histogram_width, CV_8UC3, Scalar(0, 0, 0));

	normalize(hist3, aux_hist3, 0, histogram_height, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < 256; i++) {

		Point p1_3(bin_w * (i - 1), histogram_height - cvRound(aux_hist3.at<float>(i - 1)));
		Point p2_3(bin_w * (i), histogram_height - cvRound(aux_hist3.at<float>(i)));
		line(norm_hist3, p1_3, p2_3, Scalar(255, 0, 0), 2);

	}

	Mat umbra3_th;
	int min3 = MinMax(hist3);
	line(norm_hist3, Point(bin_w * min3, 0), Point(bin_w * min3, histogram_height), Scalar(0, 255, 0), 2);
	threshold(umbra3, umbra3_th, min3, 255, THRESH_BINARY);

	namedWindow("original 3", CV_WINDOW_AUTOSIZE);
	namedWindow("threshold 3", CV_WINDOW_AUTOSIZE);
	namedWindow("histograma 3", CV_WINDOW_AUTOSIZE);
	imshow("original 3", umbra3);
	imshow("threshold 3", umbra3_th);
	imshow("histograma 3", norm_hist3);

	waitKey(0);
	destroyAllWindows();

	return 0;

}

//Threshold values
int MinMax(Mat & hist) {
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
	} else {
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

//Ejercicio 2
/*int main() {
	Mat building;
	building = imread("Imagenes/building.jpg", IMREAD_GRAYSCALE);

	if (!building.data) {
		cout << "Error loading the image" << endl;
	}

	Mat edges;
	Mat edges_c;
	Mat edges_c_p;

	Canny(building, edges, 100, 200);
	cvtColor(edges, edges_c, COLOR_GRAY2BGR);
	edges_c_p = edges_c.clone();

	//Standard Hough
	vector<Vec2f> lines;
	HoughLines(edges, lines, 1, CV_PI / 180, 150, 0, 0);

	//Draw lines
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));
		line(edges_c, pt1, pt2, Scalar(0, 0, 255), 3, CV_AA);
	}

	//Probabilistic Hough
	vector<Vec4i> linesP;
	HoughLinesP(edges, linesP, 1, CV_PI / 180, 50, 50, 10);

	//Draw the lines
	for (size_t i = 0; i < linesP.size(); i++)
	{
		Vec4i l = linesP[i];
		line(edges_c_p, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, CV_AA);
	}

	namedWindow("original", CV_WINDOW_AUTOSIZE);
	namedWindow("edges", CV_WINDOW_AUTOSIZE);
	namedWindow("lines hough", CV_WINDOW_AUTOSIZE);
	namedWindow("lines hough p", CV_WINDOW_AUTOSIZE);
	imshow("original", building);
	imshow("edges", edges);
	imshow("lines hough", edges_c);
	imshow("lines hough p", edges_c_p);

	waitKey(0);
	destroyAllWindows();

	return 0;
}*/
