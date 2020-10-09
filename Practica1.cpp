/*#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat img;

    img = imread("Imagenes/mandril.jpg");
    if (!img.data) {
        cout << "error loading image" << endl;
        return 1;
    }

    namedWindow("original", CV_WINDOW_AUTOSIZE);

    imshow("original", img);

    waitKey(0);

    destroyWindow("original");

    return 0;
}*/

/*#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

#define ESCAPE 27

int main()
{
    Mat frame;

    VideoCapture capture;

    char pressedKey = 0;

    bool success;

    capture.open("Imagenes/honda-asimov.avi");

    if (!capture.isOpened()) {
        cout << "Error in loading the video" << endl;
    }
    else {
        namedWindow("L01_E02", CV_WINDOW_AUTOSIZE);

    }
    while (pressedKey != ESCAPE) {
        success = capture.read(frame);

        if (success == false) {
            cout << "Can't read the frame from the file" << endl;
            return 1;
        }

        imshow("L01_E02", frame);

        pressedKey = waitKey(0);
    }

    destroyWindow("L01_E02");
    capture.release();

}*/