if    (FFMPEG_INCLUDE_DIRS AND FFMPEG_LIBRARIES)
    # FFmpeg alread found.
    set(FFMPEG_FOUND TRUE)
else  (FFMPEG_INCLUDE_DIRS AND FFMPEG_LIBRARIES)
    if   (WIN32)
        set(__FFMPEG_LIBRARY_DIRS__ ${PROJECT_SOURCE_DIR}/../library/ffmpeg/win64)
        set(__FFMPEG_AVCODE_INCLUDE_DIRS
            ${PROJECT_SOURCE_DIR}/../include/ffmpeg
            )
        set(__FFMPEG_AVCODEC_LIBRARY_DIRS
            ${__FFMPEG_LIBRARY_DIRS__}
            )
        set(__FFMPEG_AVFORMAT_LIBRARY_DIRS
            ${__FFMPEG_LIBRARY_DIRS__}
            )
        set(__FFMPEG_AVUTIL_LIBRARY_DIRS
            ${__FFMPEG_LIBRARY_DIRS__}
            )
    else (WIN32)
        # Use pkg-config to get the include dirs and libraries.
        find_package(PkgConfig)
        if    (PKG_CONFIG_FOUND)
            pkg_check_modules(__FFMPEG_AVCODEC    libavcodec )
            pkg_check_modules(__FFMPEG_AVFORMAT   libavformat)
            pkg_check_modules(__FFMPEG_AVUTIL     libavutil  )
        endif (PKG_CONFIG_FOUND)
    endif(WIN32)

    find_path(__FFMPEG_INCLUDE_DIRS
        NAMES libavcodec/avcodec.h
        PATHS ${__FFMPEG_AVCODE_INCLUDE_DIRS}
        PATH_SUFFIXES ffmpeg libav
        )
    find_library(__LIBAVCODEC
        NAMES avcodec
        PATHS ${__FFMPEG_AVCODEC_LIBRARY_DIRS}
        )
    find_library(__LIBAVFORMAT
        NAMES avformat
        PATHS ${__FFMPEG_AVFORMAT_LIBRARY_DIRS}
        )
    find_library(__LIBAVUTIL
        NAMES avutil
        PATHS ${__FFMPEG_AVUTIL_LIBRARY_DIRS}
        )

    if    (__LIBAVCODEC AND __LIBAVFORMAT)
        set(FFMPEG_FOUND TRUE)
    endif (__LIBAVCODEC AND __LIBAVFORMAT)

    if    (FFMPEG_FOUND)
        set(FFMPEG_INCLUDE_DIRS ${__FFMPEG_INCLUDE_DIRS})
        set(FFMPEG_LIBRARIES
            ${__LIBAVCODEC}
            ${__LIBAVFORMAT}
            ${__LIBAVUTIL}
            )

        if    (NOT FFMPEG_FIND_QUIETLY)
            message(STATUS "Found FFmpeg or Libav: ${FFMPEG_INCLUDE_DIRS}, ${FFMPEG_LIBRARIES}")
        endif (NOT FFMPEG_FIND_QUIETLY)

    else  (FFMPEG_FOUND)
        if    (FFMPEG_FIND_REQUIRED)
            message(FATAL_ERROR "Failed to find FFmpeg or Libav.")
        endif (FFMPEG_FIND_REQUIRED)
    endif (FFMPEG_FOUND)

endif (FFMPEG_INCLUDE_DIRS AND FFMPEG_LIBRARIES)
