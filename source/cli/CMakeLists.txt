file(GLOB CLI_SOURCE_FILES
    LIST_DIRECTORIES false
    cli_main.cpp
    )

add_executable(cli_app
    ${CLI_SOURCE_FILES}
    )

target_link_libraries(cli_app
    common
    )
