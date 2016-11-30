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

if(UNIX)
    set(PLATFORM_LIBRARIES ${CMAKE_DL_LIBS})
    list(APPEND PLATFORM_LIBRARIES m pthread)
endif(UNIX)

add_library(common STATIC
    ${COMMON_HEADER_FILES}
    ${COMMON_SOURCE_FILES}
    )

if(UNIX)
    target_link_libraries(common
        ${PLATFORM_LIBRARIES}
        )
endif(UNIX)
