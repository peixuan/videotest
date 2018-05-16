file(GLOB CLI_SOURCE_FILES
    LIST_DIRECTORIES false
    cli_main.cpp
    )

include_directories(
    .
    ${OpenCV_INCLUDE_DIRS}
    ${FFMPEG_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIR}
    )

add_executable(cli_app
    ${CLI_SOURCE_FILES}
    )

if   (WIN32)
    target_link_libraries(cli_app
        common
        ${OpenCV_LIBS}
        ${FFMPEG_LIBRARIES}
        ${SDL2_LIBRARY}
        )
else (WIN32)
    target_link_libraries(cli_app
        common
        ${OpenCV_LIBS}
        ${FFMPEG_LIBRARIES}
        ${SDL2_LIBRARY}
        )
endif(WIN32)
