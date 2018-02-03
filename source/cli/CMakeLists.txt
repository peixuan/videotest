file(GLOB CLI_SOURCE_FILES
    LIST_DIRECTORIES false
    cli_main.cpp
    )

include_directories(
    .
    ${OpenCV_INCLUDE_DIRS}
    )

add_executable(cli_app
    ${CLI_SOURCE_FILES}
    )

if   (WIN32)
    target_link_libraries(cli_app
        common
        ${OpenCV_LIBS}
        ${FFMPEG_LIBRARIES}
        )
else (WIN32)
    target_link_libraries(cli_app
        common
        ${OpenCV_LIBS}
        ${FFMPEG_LIBRARIES}
        )
endif(WIN32)
