/** \copyright Copyright (C) 2022 NODAR Inc. All rights reserved.
 *  
 *  This software is intellectual property of NODAR Inc.
 * 
 *  \file main.cpp
 *  \brief This is the main file to generate disparity map from image pairs and intrinsic parameters.
 * 
 *  \author      Developer A
 *  \modified by Developer B
 *  \date        Thu May 12 06:10:01 2022
*/

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "stereo_util/stereoread.h"
#include "stereo_util/stereorectify.h"
#include "stereo_util/stereodisparity.h"
#include "stereo_util/chrono_lib.h"

using namespace cv;
using namespace std;
using namespace stereo3d;
using namespace stereo3d::chrono;

/** 
 *  Example usage:
 *      ./challenge ./data/img_left.png ./data/img_right.png ./data/intrinsics.yml
 *  Input: 
 *      left image, right image, camera parameter file
 *  Output: 
 *      disparity map
 *  Default input dir:
 *      ./data
 *  Default output dir:
 *      ./result
 *  
 *  (TODO: to add a config file for default data dir & ruslt dir)
 */
int main(int argc, char* argv[])
{
	if(argc != 4){
		cout << "ERROR! Expecting 3 arguments: left-img right-img intrinsics-yml" << endl;
		return -1;
	}

    cout << "OpenCV Version: " << CV_VERSION << endl;

	// Default result path (TODO: move _hardcode_ to a separate config file)
	string result_path = "./result/disparity.png";

	time_point<high_resolution_clock> time_now = time_print_now();
	
	// Read stereo files:
	//
	stereoread stereo_read_obj(argv[1], argv[2], argv[3]);
	stereo_data_struct stereo_read_data = stereo_read_obj.readStereo();
	time_now = time_print_taken(time_now, "read stereo files");

	// Rectify pairs
	//
	stereorectify stereo_rectify_obj(stereo_read_data);
	stereo_rectify_struct stereo_rectify_data = stereo_rectify_obj.rectifyPair();
	time_now = time_print_taken(time_now, "rectify pairs");

	// Compute disparity map
	//
	stereodisparity stereo_disparity_obj(stereo_rectify_data, result_path);
	stereo_disparity_struct stereo_disparity_data = stereo_disparity_obj.disparityMap();

	time_now = time_print_taken(time_now, "compute disparity");

    return 0;
}
