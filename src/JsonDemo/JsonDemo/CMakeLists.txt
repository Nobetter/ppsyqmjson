# CMakeList.txt : CMake project for JsonDemo, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/vendor/include
)

# Add source to this project's executable.
add_executable (JsonDemo "JsonDemo.cpp" "JsonDemo.h")

# TODO: Add tests and install targets if needed.
