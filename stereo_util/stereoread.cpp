/** \copyright Copyright (C) 2022 NODAR Inc. All rights reserved.
 *  
 *  This software is intellectual property of NODAR Inc.
 * 
 *  \file stereoread.cpp
 *  \brief This is the cpp file to read stereo pairs and camera parameters.
 * 
 *  \author      Developer A
 *  \modified by Developer B
 *  \date        Thu May 12 06:10:01 2022
*/

#include "stereoread.h"

namespace stereo3d
{

//	Function: stereoread::readStereo()
//  	To load left image, right image and camera parameters
//  Output:
//		Loaded into stereo_data_struct
//
stereo_data_struct stereoread::readStereo()
{
	stereo_data_struct stereo_data;
	
	// Read left image file
    stereo_data.left_im = imread( left_path, 1 );

	// Read right image file
	stereo_data.right_im = imread( right_path, 1 );

	// Read camera parameters file
	stereo_params_struct param;
	cv::FileStorage opencv_file( intrinsic_path, cv::FileStorage::READ );
	opencv_file["K1"] >> param.K1;
	opencv_file["K2"] >> param.K2;
	opencv_file["distCoeffs1"] >> param.distCoeffs1;
	opencv_file["distCoeffs2"] >> param.distCoeffs2;
	opencv_file["R"] >> param.R;
	opencv_file["T"] >> param.T;
	opencv_file["height"] >> param.height;
	opencv_file["width"] >> param.width;
	opencv_file.release();
	
	stereo_data.cam_param = param;

	return stereo_data;
}
}