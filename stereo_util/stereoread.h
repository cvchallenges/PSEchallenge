/** \copyright Copyright (C) 2022 NODAR Inc. All rights reserved.
 *  
 *  This software is intellectual property of NODAR Inc.
 * 
 *  \file stereoread.h
 *  \brief This is the header file to read image pair and the camera parameters.
 * 
 *  \author      Developer A
 *  \modified by Developer B
 *  \date        Thu May 12 06:10:01 2022
*/

#ifndef STEREO_UTIL_STEREOREAD_H
#define STEREO_UTIL_STEREOREAD_H

#include <opencv2/opencv.hpp>

#include "stereostruct.h"

using namespace cv;
using namespace std;

namespace stereo3d
{

class stereoread
{
	public:
		stereoread(std::string left, std::string right, std::string intrinsic)
		: left_path(left), right_path(right), intrinsic_path(intrinsic)
		{
		}
		stereo_data_struct readStereo();
	private:
		string left_path, right_path, intrinsic_path;
};

}

#endif
