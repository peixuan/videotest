cmake_minimum_required(VERSION 2.8)
project(BaseProject)

include(CheckIncludeFileCXX)

if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif(UNIX)

CHECK_INCLUDE_FILE_CXX(cstdint HAVE_CSTDINT)
if(HAVE_CSTDINT)
    add_definitions(-D_HAS_CSTDINT_=1)
endif(HAVE_CSTDINT)

add_subdirectory(thirdparty)
add_subdirectory(common)
add_subdirectory(cli)
add_subdirectory(gui)
