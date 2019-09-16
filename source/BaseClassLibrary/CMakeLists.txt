file(GLOB BASE_CLASS_LIBRARY_HEADER_FILES
    LIST_DIRECTORIES false
    BaseClassLibrary.h
    BaseDataStructure.h
    CSVFileAccess.h
    DatabaseAccess.h
    PlayerCore.h
    PlayerCoreImplFFmpeg.h
    SQLiteAccess.h
    SQLiteWrapper.h
    Timestamp.h
    )
file(GLOB BASE_CLASS_LIBRARY_SOURCE_FILES
    LIST_DIRECTORIES false
    BaseClassLibrary.cpp
    BaseDataStructure.cpp
    CSVFileAccess.cpp
    DatabaseAccess.cpp
    PlayerCore.cpp
    PlayerCoreImplFFmpeg.cpp
    SQLiteAccess.cpp
    SQLiteWrapper.cpp
    Timestamp.cpp
    )

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${FFMPEG_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIR}
    )

add_library(BaseClassLibrary STATIC
    ${BASE_CLASS_LIBRARY_HEADER_FILES}
    ${BASE_CLASS_LIBRARY_SOURCE_FILES}
    )

target_link_libraries(BaseClassLibrary
    ${OpenCV_LIBS}
    ${FFMPEG_LIBRARIES}
    ${SDL2_LIBRARY}
    )
