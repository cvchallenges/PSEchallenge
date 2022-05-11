#ifndef STEREO_UTIL_STEREODISPARITY_H
#define STEREO_UTIL_STEREODISPARITY_H

#include <opencv2/opencv.hpp>

#include "stereostruct.h"

using namespace cv;
using namespace std;

namespace stereo3d
{

class stereodisparity
{
	public:
		stereodisparity(stereo_rectify_struct stereo_rectify_data, string result_path)
		: stereo_rectify_data(stereo_rectify_data), result_path(result_path)
		{
		}
		stereo_disparity_struct disparityMap();
	private:
		stereo_rectify_struct stereo_rectify_data;
		string result_path;

		// Initialize values for StereoSGBM parameters
		int numDisparities = 256;
		int blockSize = 5;
		int preFilterType = 1;
		int preFilterSize = 1;
		int preFilterCap = 31;
		int minDisparity = 0;
		int textureThreshold = 10;
		int uniquenessRatio = 15;
		int speckleRange = 0;
		int speckleWindowSize = 0;
		int disp12MaxDiff = -1;
		int dispType = CV_16S;		
};

}

#endif
