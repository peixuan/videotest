cmake_minimum_required(VERSION 2.8)
project(BaseProject)

include(CheckIncludeFileCXX)

CHECK_INCLUDE_FILE_CXX(cstdint HAVE_CSTDINT)
if(HAVE_CSTDINT)
    add_definitions(-D_HAS_CSTDINT_=1)
endif(HAVE_CSTDINT)

add_subdirectory(thirdparty)
add_subdirectory(common)
add_subdirectory(cli)
add_subdirectory(gui)
