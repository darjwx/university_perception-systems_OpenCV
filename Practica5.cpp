#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//Ejercicio 1
/*int main() {
	Mat gaussian_noise;
	gaussian_noise = imread("Imagenes/moon_gaussian_noise.jpg", IMREAD_GRAYSCALE);

	if (!gaussian_noise.data) {
		cout << "Error loading the image" << endl;

		return 1;
	}

	Mat filtered_blur;
	Mat filtered_median;
	Mat filtered_gaussian;

	blur(gaussian_noise, filtered_blur, Size(3,3));
	medianBlur(gaussian_noise, filtered_median, 5);
	GaussianBlur(gaussian_noise, filtered_gaussian, Size(3, 3), 0, 0);

	namedWindow("original", CV_WINDOW_AUTOSIZE);
	namedWindow("filtered blur", CV_WINDOW_AUTOSIZE);
	namedWindow("filtered median", CV_WINDOW_AUTOSIZE);
	namedWindow("filtered gaussian", CV_WINDOW_AUTOSIZE);
	imshow("original", gaussian_noise);
	imshow("filtered blur", filtered_blur);
	imshow("filtered median", filtered_median);
	imshow("filtered gaussian", filtered_gaussian);

	waitKey(0);
	destroyAllWindows();

	return 0;

}*/

//Ejercicio 2
/*int main() {
	Mat lena_img;
	lena_img = imread("Imagenes/lena.jpg", IMREAD_GRAYSCALE);

	if (!lena_img.data) {
		cout << "Error loading the image" << endl;

		return 1;
	}

	Mat filtered_sobel(lena_img.size(), CV_16SC1);
	Mat filtered_sobel_x(lena_img.size(), CV_8UC1);
	Mat filtered_sobel_y(lena_img.size(), CV_8UC1);


	Sobel(lena_img, filtered_sobel, -1, 1, 0);
	filtered_sobel.convertTo(filtered_sobel_x, CV_8UC1);

	Sobel(lena_img, filtered_sobel, -1, 0, 1);
	filtered_sobel.convertTo(filtered_sobel_y, CV_8UC1);


	namedWindow("original", CV_WINDOW_AUTOSIZE);
	namedWindow("sobel x", CV_WINDOW_AUTOSIZE);
	namedWindow("sobel y", CV_WINDOW_AUTOSIZE);

	imshow("original", lena_img);
	imshow("sobel x", filtered_sobel_x);
	imshow("sobel y", filtered_sobel_y);

	waitKey(0);
	destroyAllWindows();

	return 0;
}*/

//Ejercicio 3
int main() {
	Mat car_img;
	car_img = imread("Imagenes/googleCar.jpg", IMREAD_GRAYSCALE);

	if (!car_img.data) {
		cout << "Error loading the image" << endl;

		return 1;
	}

	Mat filtered_canny;
	Canny(car_img, filtered_canny, 50, 100);

	namedWindow("original", CV_WINDOW_AUTOSIZE);
	namedWindow("canny", CV_WINDOW_AUTOSIZE);
	imshow("original", car_img);
	imshow("canny", filtered_canny);

	waitKey(0);
	destroyAllWindows();

	return 0;
}