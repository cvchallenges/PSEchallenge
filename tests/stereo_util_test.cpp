/** \copyright Copyright (C) 2022 NODAR Inc. All rights reserved.
 *  
 *  This software is intellectual property of NODAR Inc.
 * 
 *  \file stereo_util_test.cpp
 *  \brief This is the TEST file to gtest the stereo util functions.
 * 
 *  \author      Developer A
 *  \modified by Developer B
 *  \date        Thu May 12 06:10:01 2022
*/

#include <gtest/gtest.h>

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "../stereo_util/stereoread.h"
#include "../stereo_util/stereorectify.h"
#include "../stereo_util/stereodisparity.h"

using namespace cv;
using namespace std;
using namespace stereo3d;

namespace stereo3d
{
namespace stereo_util_test
{

string left_path, right_path, intrinsic_path, result_path;
stereo_data_struct stereo_read_data;
stereo_rectify_struct stereo_rectify_data;
stereo_disparity_struct stereo_disparity_data;

//  To test stereoread::readStereo() function
//
TEST(StereoUtilTest, StereoReadTest)
{
	// Prepare the testing inputs
	// TODO: move the _hardcode_ environments to separate config file
	//
	left_path = "./data/img_left.png";
	right_path = "./data/img_right.png";
	intrinsic_path = "./data/intrinsics.yml";
	result_path = "./result/disparity.png";

	// Read stereo files
	//
	stereoread stereo_read_obj(left_path, right_path, intrinsic_path);
	stereo_read_data = stereo_read_obj.readStereo();
	EXPECT_EQ(stereo_read_data.left_im.size()==stereo_read_data.right_im.size(), true);
}

//  To test stereorectify::rectifyPair() function
//
TEST(StereoUtilTest, StereoRectifyTest)
{
	// Rectify pairs
	//
	stereorectify stereo_rectify_obj(stereo_read_data);
	stereo_rectify_data = stereo_rectify_obj.rectifyPair();
	EXPECT_EQ(stereo_rectify_data.left_rectified.size()==stereo_rectify_data.right_rectified.size(), true);
}

//  To test stereoparity::disparityMap() function
//
TEST(StereoUtilTest, StereoParityTest)
{
	// Compute disparity map
	//
	stereodisparity stereo_disparity_obj(stereo_rectify_data, result_path);
	stereo_disparity_data = stereo_disparity_obj.disparityMap();
	EXPECT_EQ(stereo_disparity_data.disparity.size()==stereo_rectify_data.left_rectified.size(), true);
}

}
}