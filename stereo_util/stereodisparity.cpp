#include "stereodisparity.h"
#include <opencv2/core/utils/filesystem.hpp>

namespace stereo3d
{

stereo_disparity_struct stereodisparity::disparityMap()
{
	// Create an object of StereoSGBM algorithm
	cv::Ptr<cv::StereoBM> stereo = cv::StereoBM::create(numDisparities, blockSize);

	// Convert rectified images from RGB to grayscale
	cv::Mat left_rectified_gray, right_rectified_gray;
	cv::cvtColor(stereo_rectify_data.left_rectified, left_rectified_gray, cv::COLOR_BGR2GRAY);
	cv::cvtColor(stereo_rectify_data.right_rectified, right_rectified_gray, cv::COLOR_BGR2GRAY);

	// Run stereo matching algorithm
	Mat disparity; // output
	stereo->compute(left_rectified_gray, right_rectified_gray, disparity);

    // Convert disparity values to CV_8UC1 from CV_16S
    // before saving as an 8-bit grayscale image
    disparity.convertTo(disparity, CV_8UC1, 1.0);

	// Save output

	string result_path_base = result_path.substr(0, result_path.rfind('/'));
	bool path_ready = cv::utils::fs::createDirectory(result_path_base);
	// cout << result_path_base << " is ready? " << path_ready << endl;
	imwrite(result_path, disparity);
	cout << "Saved disparity result: " << result_path << endl;

	stereo_disparity_struct stereo_disparity_data = {disparity};

	return stereo_disparity_data;
}

}