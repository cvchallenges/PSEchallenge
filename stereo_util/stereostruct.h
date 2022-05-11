#ifndef STEREO_UTIL_STEREOSTRUCT_H
#define STEREO_UTIL_STEREOSTRUCT_H

// #include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

namespace stereo3d
{
struct stereo_params_struct {
	Mat K1, K2, distCoeffs1, distCoeffs2, R, T;
	int height, width;
};

struct stereo_data_struct {
	Mat left_im, right_im;
	stereo_params_struct cam_param;
};

struct stereo_rectify_struct {
	Mat left_rectified, right_rectified;
};

struct stereo_disparity_struct {
	Mat disparity;
};
}

#endif
