SET(stereo_util_src 
    stereoread.h stereoread.cpp
    stereorectify.h stereorectify.cpp
    stereodisparity.h stereodisparity.cpp
    chrono_lib.h
)

ADD_LIBRARY( stereo_util ${stereo_util_src} )

TARGET_INCLUDE_DIRECTORIES( stereo_util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
