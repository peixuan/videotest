cmake_minimum_required(VERSION 2.8)
project(BaseProject)

include(CheckIncludeFileCXX)

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" "${CMAKE_MODULE_PATH}")

if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif(UNIX)

CHECK_INCLUDE_FILE_CXX(cstdint HAVE_CSTDINT)
if(HAVE_CSTDINT)
    add_definitions(-D_HAS_CSTDINT_=1)
endif(HAVE_CSTDINT)

if(MSVC)
    set(USE_STATIC_CRT_LIBRARY OFF CACHE BOOL
        "Use static version of the C run-time library.")

    if(USE_STATIC_CRT_LIBRARY)
        set(OpenCV_STATIC ON)
        foreach(CompilerFlags
            CMAKE_CXX_FLAGS
            CMAKE_CXX_FLAGS_DEBUG
            CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_MINSIZEREL
            CMAKE_CXX_FLAGS_RELWITHDEBINFO
        )
            if(${CompilerFlags} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT"
                    ${CompilerFlags} "${${CompilerFlags}}")
            endif(${CompilerFlags} MATCHES "/MD")
        endforeach(CompilerFlags)
    else(USE_STATIC_CRT_LIBRARY)
        set(OpenCV_STATIC OFF)
    endif(USE_STATIC_CRT_LIBRARY)
endif(MSVC)

find_package(FFmpeg REQUIRED)
find_package(OpenCV REQUIRED)

add_subdirectory(thirdparty)
add_subdirectory(common)
add_subdirectory(cli)
add_subdirectory(gui)
