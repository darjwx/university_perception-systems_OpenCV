
//Ejercicio 1
/*#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat img;

    img = imread("Imagenes/lena.jpg");
    if (!img.data) {
        cout << "error loading image" << endl;
        return 1;
    }

    Point start(img.rows / 2, img.cols / 2);
    Point endL(0, 0);
    Point endR(img.rows / 4, img.cols / 4);
    int radius = 25;

    line(img, start, endL, Scalar(0, 0, 255));
    rectangle(img, start, endR, Scalar(255, 255, 0));
    circle(img, start, radius, Scalar(0, 255, 255),-1);


    namedWindow("original", CV_WINDOW_AUTOSIZE);

    imshow("original", img);

    waitKey(0);

    destroyWindow("original");

    return 0;
}*/

//Ejercicio 2
/*#include "opencv\cv.hpp"
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

int main() {
    Mat img;

    img = imread("Imagenes/mandril.jpg",CV_LOAD_IMAGE_GRAYSCALE);

    if (!img.data) {
        cout << "error loading image" << endl;
        return 1;
    }

    int hist_size = 256;
    vector<int> bins(hist_size, 0);
    for (size_t row = 0; row < img.rows; row++) {
        for (size_t col = 0; col < img.cols; col++) {
            uchar graylevel = img.at<uchar>(row, col);
            bins[graylevel]++;
        }
    }

    int max = *std::max_element(bins.begin(), bins.end());
    for (int graylevel = 0; graylevel < hist_size; ++graylevel) {
        bins[graylevel] = bins[graylevel] * 400 / max;
        cout << graylevel << " : " << bins[graylevel] << endl;
    }
    Mat histImage(400, 256, CV_8UC1, Scalar(0));

    for (int graylevel = 0; graylevel < hist_size; ++graylevel) {
        line(histImage, Point(graylevel, 400), Point(graylevel, 400 - bins[graylevel]), Scalar(255), 1, 8, 0);
    }

    imshow("original", img);
    imshow("Histogram", histImage);

    waitKey(0);

    destroyWindow("original");

    return 0;
}*/

//Ejercicio 3
/*#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat img;

    img = imread("Imagenes/lena.jpg", IMREAD_GRAYSCALE);
    if (!img.data) {
        cout << "error loading image" << endl;
        return 1;
    } else {

        int histogram_size = 256;
        float histogram_range[] = { 0 , 256 };
        const float* histogram_ranges[] = { histogram_range };
        Mat histogram;

        calcHist (&img, 1, 0, Mat(), histogram, 1, &histogram_size, histogram_ranges);

        for (int i = 0; i < histogram_size; i++) {
            float bin_value = histogram.at<float>(i);
        }

        int bin_width = 2;
        int histogram_width = 512;
        int histogram_height = 400;
        Mat normalized_histogram;

        Mat image_histogram(histogram_height, histogram_width, CV_8UC1, Scalar(255, 0, 0));
        normalize(histogram, normalized_histogram, 0, histogram_height, NORM_MINMAX, -1, Mat());

        for (int i = 1; i < histogram_size; i++) {
            Point p1(bin_width * (i - 1), histogram_height - cvRound(normalized_histogram.at<float>(i - 1)));
            Point p2(bin_width * (i), histogram_height - cvRound(normalized_histogram.at<float>(i)));
            line(image_histogram, p1, p2, Scalar(0, 0, 0), 2);
        }

        namedWindow("Original", CV_WINDOW_AUTOSIZE);
        namedWindow("Histograma", CV_WINDOW_AUTOSIZE);

        imshow("original", img);
        imshow("Histograma", image_histogram);

        waitKey(0);

        destroyAllWindows();
    }

    return 0;
}*/