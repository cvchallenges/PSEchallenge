# PSEchallenge

## In this repo:
```
- Main:    main.cpp
- Util:    stereo_util/stereostruct.h
                      /stereostruct.h
                      /stereostruct.h
                      /stereostruct.h
                      /stereostruct.h
- Testing: tests/stereo_util_test.cpp
- Docker:  docker/Dockerfile
                 /Dockerfile.cmake3.14
                 /Dockerfile.cv4.2.0
```
## Dependencies:
```
- cmake 3.14
- opencv 4.2.0
```
## Run:
```
- git pull <https/git this repo>
- docker build -t opencv4.2.0 -f docker/Dockerfile.cv4.2.0 .
- in docker container:
      cmake . && make -j8
      cd tests && cmake . && make -j8
```