file(GLOB COMMON_HEADER_FILES
    LIST_DIRECTORIES false
    common.h
    threading_wrapper.h
    )
file(GLOB COMMON_SOURCE_FILES
    LIST_DIRECTORIES false
    common.cpp
    threading_wrapper.cpp
    )

add_library(common STATIC
    ${COMMON_HEADER_FILES}
    ${COMMON_SOURCE_FILES}
    )
