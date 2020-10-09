#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//Ejercicio 1
/*int main () {
	Mat lena_color;
	Mat lena_gris;

	lena_color = imread("Imagenes/lena.jpg");
	lena_gris = imread("Imagenes/lena.jpg", IMREAD_GRAYSCALE);

	if (!lena_color.data) {
		cout << "Error loading the image" << endl;
		return 1;
	}

	if (!lena_gris.data) {
		cout << "Error loading the image" << endl;
		return 1;
	}

	int channels_color = lena_color.channels();
	int channels_gris = lena_gris.channels();

	putText(lena_color, to_string(channels_color), Point(lena_color.rows / 6, lena_color.cols / 6), FONT_HERSHEY_PLAIN, 6, (255, 255, 255));
	putText(lena_gris, to_string(channels_gris), Point(lena_gris.rows / 6, lena_gris.cols / 6), FONT_HERSHEY_PLAIN, 6, (255, 255, 255));

	//cout << " Color: " << channels_color << endl <<" Gris "<< channels_gris << endl;

	namedWindow("lena color", CV_WINDOW_AUTOSIZE);
	namedWindow("lena gris", CV_WINDOW_AUTOSIZE);
	imshow("lena color", lena_color);
	imshow("lena gris", lena_gris);

	waitKey(0);
	destroyAllWindows();

	return 0;
}*/

//Ejercicio 2
/*int main () {
	Mat bolas_original;
	Mat bolas_splitted[3];

	bolas_original = imread("Imagenes/lightballs.jpg");

	if (!bolas_original.data) {
		cout << "Error loading the image" << endl;
		return 1;
	}

	split(bolas_original, bolas_splitted);

	namedWindow("original", CV_WINDOW_AUTOSIZE);
	imshow("original", bolas_original);

	namedWindow("B", CV_WINDOW_AUTOSIZE);
	namedWindow("G", CV_WINDOW_AUTOSIZE);
	namedWindow("R", CV_WINDOW_AUTOSIZE);
	imshow("B", bolas_splitted[0]);
	imshow("G", bolas_splitted[1]);
	imshow("R", bolas_splitted[2]);

	waitKey(0);
	destroyAllWindows();

	return 0;
}*/

//Ejercicio 3
/*int main() {
	Mat mandril_brg;
	Mat mandril_hsv;
	Mat mandril_splitted[3];

	mandril_brg = imread("Imagenes/mandril_c.jpg");

	if (!mandril_brg.data) {
		cout << "Error loading the image" << endl;
		return 1;
	}

	namedWindow("original", CV_WINDOW_AUTOSIZE);
	imshow("original", mandril_brg);

	cvtColor(mandril_brg, mandril_hsv, CV_BGR2HSV);
	namedWindow("hsv", CV_WINDOW_AUTOSIZE);
	imshow("hsv", mandril_hsv);

	split(mandril_hsv, mandril_splitted);
	namedWindow("H", CV_WINDOW_AUTOSIZE);
	namedWindow("S", CV_WINDOW_AUTOSIZE);
	namedWindow("V", CV_WINDOW_AUTOSIZE);
	imshow("H", mandril_splitted[0]);
	imshow("S", mandril_splitted[1]);
	imshow("V", mandril_splitted[2]);

	float range_h[] = { 0 , 180 };
	float range_s[] = { 0 , 256 };
	float range_v[] = { 0 , 256 };
	const float* hist_ranges_h[] = { range_h };
	const float* hist_ranges_s[] = { range_s };
	const float* hist_ranges_v[] = { range_v };
 
	int hist_size_h = 180;
	int hist_size_sv = 256;

	Mat h_hist;
	Mat s_hist;
	Mat v_hist;
	calcHist(&mandril_splitted[0], 1, 0, Mat(), h_hist, 1 , &hist_size_h, hist_ranges_h);
	calcHist(&mandril_splitted[1], 1, 0, Mat(), s_hist, 1, &hist_size_sv, hist_ranges_s);
	calcHist(&mandril_splitted[2], 1, 0, Mat(), v_hist, 1, &hist_size_sv, hist_ranges_v);


	int histogram_width = 512;
	int histogram_height = 400;
	int bin_w = cvRound((double)histogram_width / hist_size_sv);
	Mat hsv_hist(histogram_height, histogram_width, CV_8UC3, Scalar(255, 255, 255));

	normalize(h_hist, h_hist, 0, histogram_height, NORM_MINMAX, -1, Mat());
	normalize(s_hist, s_hist, 0, histogram_height, NORM_MINMAX, -1, Mat());
	normalize(v_hist, v_hist, 0, histogram_height, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < 180; i++) {

		Point p1_h(bin_w * (i - 1), histogram_height - cvRound(h_hist.at<float>(i - 1)));
		Point p2_h(bin_w * (i), histogram_height - cvRound(h_hist.at<float>(i)));
		line(hsv_hist, p1_h, p2_h, Scalar(255, 0, 0), 2);

	}

	for (int i = 1; i < 256; i++) {

		Point p1_s(bin_w * (i - 1), histogram_height - cvRound(s_hist.at<float>(i - 1)));
		Point p2_s(bin_w * (i), histogram_height - cvRound(s_hist.at<float>(i)));
		line(hsv_hist, p1_s, p2_s, Scalar(0, 255, 0), 2);

	}

	for (int i = 1; i < 256; i++) {

		Point p1_v(bin_w * (i - 1), histogram_height - cvRound(v_hist.at<float>(i - 1)));
		Point p2_v(bin_w * (i), histogram_height - cvRound(v_hist.at<float>(i)));
		line(hsv_hist, p1_v, p2_v, Scalar(0, 0, 255), 2);

	}

	imshow("histogram", hsv_hist);

	waitKey(0);
	destroyAllWindows();

	return 0;
}*/