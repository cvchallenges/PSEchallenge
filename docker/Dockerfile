FROM 622618148766.dkr.ecr.us-east-1.amazonaws.com/cvchallenges:cv4.2.0
COPY . /src/PSEchallenge/
WORKDIR /src/PSEchallenge
RUN  cmake . && make && ./challenge data/img_left.png data/img_right.png data/intrinsics.yml \
     && cd tests && cmake . && make && ./stereo_util_test && cd CMakeFiles/stereo_util_test.dir/ \
     && gcov stereo_util_test.cpp.gcno && pip3 install gcovr \
     && cd ../.. && gcovr CMakeFiles/stereo_util_test.dir/ \
     && gcovr --html-details CMakeFiles/stereo_util_test.dir/coverage.html CMakeFiles/stereo_util_test.dir/
