#ifndef STEREO_UTIL_CHRONO_LIB_H
#define STEREO_UTIL_CHRONO_LIB_H

#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

namespace stereo3d
{
namespace chrono
{
time_point<high_resolution_clock> time_print_now()
{
    time_point<high_resolution_clock> start_point; // creating time points
    start_point = high_resolution_clock::now(); // storing the starting time point in start 
    // cout<<"Time now = "<< start_point <<" microseconds"<<endl;

    return start_point;
};

time_point<high_resolution_clock> time_print_taken(time_point<high_resolution_clock> start_point, string task)
{
    time_point<high_resolution_clock> end_point = high_resolution_clock::now(); //storing the ending time in end 
	auto start = time_point_cast<microseconds>(start_point).time_since_epoch().count(); 
	// casting the time point to microseconds and measuring the time since time epoch
	auto end = time_point_cast<microseconds>(end_point).time_since_epoch().count();
	cout<<"Time taken ["<<task<<"] = "<<(end-start)<<" microseconds"<<endl;
    return end_point;
};
}
}
#endif
