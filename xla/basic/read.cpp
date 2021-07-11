#include <iostream>
using namespace std;
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>

int main() {
    cv::Mat img = cv::imread("example.jpg");
    cout << "img.shape " << img.size << endl;
}



