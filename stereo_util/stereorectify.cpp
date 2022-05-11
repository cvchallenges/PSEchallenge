#include "stereorectify.h"


namespace stereo3d
{

stereo_rectify_struct stereorectify::rectifyPair()
{
	stereo_params_struct cam_param = stereo_read_data.cam_param;

    // Create rectification maps
    Mat R1, R2, P1, P2, Q; // outputs 
	stereoRectify(cam_param.K1, cam_param.distCoeffs1,
				  cam_param.K2, cam_param.distCoeffs2,
            Size(cam_param.width, cam_param.height),
				 cam_param.R, cam_param.T, R1, R2, P1, P2, Q);

	Mat map1x, map1y; // outputs
    initUndistortRectifyMap(cam_param.K1, cam_param.distCoeffs1, R1, P1, 
            Size(cam_param.width, cam_param.height), CV_32FC1, map1x, map1y);

    Mat map2x, map2y; // outputs
    initUndistortRectifyMap(cam_param.K2, cam_param.distCoeffs2, R2, P2, 
            Size(cam_param.width, cam_param.height), CV_32FC1, map2x, map2y);

	// Rectify input images
	Mat left_rectified, right_rectified;  // outputs

    cv::remap(stereo_read_data.left_im, left_rectified, map1x, map1y, cv::INTER_LINEAR, 
		cv::BORDER_CONSTANT, 0);

    cv::remap(stereo_read_data.right_im, right_rectified, map2x, map2y, cv::INTER_LINEAR, 
		cv::BORDER_CONSTANT, 0);

	stereo_rectify_struct stereo_rectify_data = {left_rectified, right_rectified};

	return stereo_rectify_data;
}

}