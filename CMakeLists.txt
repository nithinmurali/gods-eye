cmake_minimum_required(VERSION 2.8)

project( GOD'S_EYE )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")  
include_directories( "${PROJECT_BINARY_DIR}" )
find_package( OpenCV REQUIRED )

add_executable( godseye main.cpp )
target_link_libraries( godyeye ${OpenCV_LIBS}  )
