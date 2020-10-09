#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//Ejercicio 1
int main() {
	Mat backl;

	backl = imread("Imagenes/rayosx.tif", IMREAD_GRAYSCALE);

	if (!backl.data) {
		cout << "Error loading image" << endl;
		return 1;
	}

	float range[] = { 0 , 256 };
	const float* ranges[] = { range };
	int hist_size = 256;
	Mat hist;

	calcHist(&backl, 1, 0, Mat(), hist, 1, &hist_size , ranges);

	int histogram_width = 512;
	int histogram_height = 400;
	int bin_w = cvRound((double)histogram_width / hist_size);
	Mat aux_hist;
	Mat norm_hist(histogram_height, histogram_width, CV_8UC1, Scalar(255, 0, 0));

	normalize(hist, aux_hist, 0, histogram_height, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < 256; i++) {

		Point p1(bin_w * (i - 1), histogram_height - cvRound(aux_hist.at<float>(i - 1)));
		Point p2(bin_w * (i), histogram_height - cvRound(aux_hist.at<float>(i)));
		line(norm_hist, p1, p2, Scalar(0, 0, 0), 2);

	}

	double minVal, minValNorm, maxVal, maxValNorm;
	Point minLoc, minLocNorm, maxLoc, maxLocNorm;

	minMaxLoc(hist, &minVal, &maxVal, &minLoc, &maxLoc);
	minMaxLoc(aux_hist, &minValNorm, &maxValNorm, &minLocNorm, &maxLocNorm);

	cout << "Original" << endl;
	cout << hist << endl;
	cout << "Valor minimo " << minVal << " en " << minLoc << endl;
	cout << "Valor maximo " << maxVal << " en " << maxLoc << endl;

	cout << "Normalizado" << endl;
	cout << aux_hist << endl;
	cout << "Valor minimo " << minValNorm << " en " << minLocNorm << endl;
	cout << "Valor maximo " << maxValNorm << " en " << maxLocNorm << endl;

	namedWindow("original", CV_WINDOW_AUTOSIZE);
	namedWindow("histograma", CV_WINDOW_AUTOSIZE);
	imshow("original", backl);
	imshow("histograma", norm_hist);

	waitKey(0);
	destroyAllWindows();

	return 0;
}

//Ejercicio 2
/*int main() {
	Mat backl;

	backl = imread("Imagenes/rayosx.tif", IMREAD_GRAYSCALE);

	if (!backl.data) {
		cout << "Error loading image" << endl;
		return 1;
	}

	float range[] = { 0 , 256 };
	const float* ranges[] = { range };
	int hist_size = 256;
	Mat hist;

	calcHist(&backl, 1, 0, Mat(), hist, 1, &hist_size, ranges);

	int histogram_width = 512;
	int histogram_height = 400;
	int bin_w = cvRound((double)histogram_width / hist_size);
	Mat aux_hist;
	Mat norm_hist(histogram_height, histogram_width, CV_8UC1, Scalar(255, 0, 0));

	normalize(hist, aux_hist, 0, histogram_height, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < 256; i++) {

		Point p1(bin_w * (i - 1), histogram_height - cvRound(aux_hist.at<float>(i - 1)));
		Point p2(bin_w * (i), histogram_height - cvRound(aux_hist.at<float>(i)));
		line(norm_hist, p1, p2, Scalar(0, 0, 0), 2);

	}

	Mat eq_img;
	Mat eq_hist;
	equalizeHist(backl, eq_img);
	calcHist(&eq_img, 1, 0, Mat(), eq_hist, 1, &hist_size, ranges);

	Mat eq_aux_hist;
	Mat eq_norm_hist(histogram_height, histogram_width, CV_8UC1, Scalar(255, 0, 0));

	normalize(eq_hist, eq_aux_hist, 0, histogram_height, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < 256; i++) {

		Point p1(bin_w * (i - 1), histogram_height - cvRound(eq_aux_hist.at<float>(i - 1)));
		Point p2(bin_w * (i), histogram_height - cvRound(eq_aux_hist.at<float>(i)));
		line(eq_norm_hist, p1, p2, Scalar(0, 0, 0), 2);

	}

	cout << "Original" << endl;
	cout << hist << endl;
	cout << "Normalizado" << endl;
	cout << aux_hist << endl;
	cout << "Ecualizado original" << endl;
	cout << eq_hist << endl;
	cout << "Ecualizado normalizado" << endl;
	cout << eq_aux_hist << endl;

	namedWindow("original", CV_WINDOW_AUTOSIZE);
	namedWindow("histograma", CV_WINDOW_AUTOSIZE);
	namedWindow("ecualizada", CV_WINDOW_AUTOSIZE);
	namedWindow("histograma ecualizado", CV_WINDOW_AUTOSIZE);
	imshow("original", backl);
	imshow("histograma", norm_hist);
	imshow("ecualizada", eq_img);
	imshow("histograma ecualizado", eq_norm_hist);

	waitKey(0);
	destroyAllWindows();
}*/

//Ejercicio 3
/*int main() {
	Mat bird;
	bird = imread("Imagenes/backlighting2.jpg", IMREAD_GRAYSCALE);

	if (!bird.data) {
		cout << "Error loading image" << endl;
		return 1;
	}

	float range[] = { 0 , 256 };
	const float* ranges[] = { range };
	int hist_size = 256;
	Mat hist;

	calcHist(&bird, 1, 0, Mat(), hist, 1, &hist_size, ranges);

	int histogram_width = 512;
	int histogram_height = 400;
	int bin_w = cvRound((double)histogram_width / hist_size);
	Mat aux_hist;
	Mat norm_hist(histogram_height, histogram_width, CV_8UC1, Scalar(255, 0, 0));

	normalize(hist, aux_hist, 0, histogram_height, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < 256; i++) {

		Point p1(bin_w * (i - 1), histogram_height - cvRound(aux_hist.at<float>(i - 1)));
		Point p2(bin_w * (i), histogram_height - cvRound(aux_hist.at<float>(i)));
		line(norm_hist, p1, p2, Scalar(0, 0, 0), 2);

	}

	Mat lut_bird;
	Mat lookUpTable(1, 256, CV_8UC1);

	for (int i = 0; i < 256; ++i)
	{
		//Inverso.
		lookUpTable.at<uchar>(0, i) = uchar(255 - i);
	}

	LUT(bird, lookUpTable, lut_bird);

	Mat lut_hist;

	calcHist(&lut_bird, 1, 0, Mat(), lut_hist, 1, &hist_size, ranges);

	Mat lut_aux_hist;
	Mat lut_norm_hist(histogram_height, histogram_width, CV_8UC1, Scalar(255, 0, 0));

	normalize(lut_hist, lut_aux_hist, 0, histogram_height, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < 256; i++) {

		Point p1(bin_w * (i - 1), histogram_height - cvRound(lut_aux_hist.at<float>(i - 1)));
		Point p2(bin_w * (i), histogram_height - cvRound(lut_aux_hist.at<float>(i)));
		line(lut_norm_hist, p1, p2, Scalar(0, 0, 0), 2);

	}

	cout << "Original" << endl;
	cout << hist << endl;
	cout << "Normalizado" << endl;
	cout << aux_hist << endl;
	cout << "Original tras LUT" << endl;
	cout << lut_hist << endl;
	cout << "Normalizado tras LUT" << endl;
	cout << lut_aux_hist << endl;

	namedWindow("original", CV_WINDOW_AUTOSIZE);
	namedWindow("histograma", CV_WINDOW_AUTOSIZE);
	namedWindow("lut bird", CV_WINDOW_AUTOSIZE);
	namedWindow("histograma lut", CV_WINDOW_AUTOSIZE);

	imshow("original", bird);
	imshow("histograma", norm_hist);
	imshow("lut bird", lut_bird);
	imshow("histograma lut", lut_norm_hist);

	waitKey(0);
	destroyAllWindows();
}*/