/** \copyright Copyright (C) 2022 NODAR Inc. All rights reserved.
 *  
 *  This software is intellectual property of NODAR Inc.
 * 
 *  \file stereorectify.h
 *  \brief This is the header file for stereorectify class.
 * 
 *  \author      Developer A
 *  \modified by Developer B
 *  \date        Thu May 12 06:10:01 2022
*/

#ifndef STEREO_UTIL_STEREORECTIFY_H
#define STEREO_UTIL_STEREORECTIFY_H

#include <opencv2/opencv.hpp>

#include "stereostruct.h"

using namespace cv;
using namespace std;

namespace stereo3d
{

class stereorectify
{
	public:
		stereorectify(stereo_data_struct stereo_read_data)
		: stereo_read_data(stereo_read_data)
		{
		}
		stereo_rectify_struct rectifyPair();
	private:
		stereo_data_struct stereo_read_data;
};

}

#endif
