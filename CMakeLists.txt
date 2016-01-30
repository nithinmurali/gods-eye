cmake_minimum_required(VERSION 2.8)

project( GOD'S_EYE )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")  
include_directories( "${PROJECT_BINARY_DIR}" )
find_package( OpenCV REQUIRED )

#add_executable( godseye main.cpp color_constancy.cpp color_constancy.hpp )
add_executable( godseye main1.cpp )
target_link_libraries( godseye ${OpenCV_LIBS}  )
