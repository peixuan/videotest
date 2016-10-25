file(GLOB MFCDLGMAINAPP_HEADER_FILES
    LIST_DIRECTORIES false
    MFCMainApp.h
    MFCMainDlg.h
    Resource.h
    stdafx.h
    targetver.h
    )

file(GLOB MFCDLGMAINAPP_SOURCE_FILES
    LIST_DIRECTORIES false
    MFCMainApp.cpp
    MFCMainDlg.cpp
    stdafx.cpp
    )

file(GLOB MFCDLGMAINAPP_RESOURCE_FILES
    LIST_DIRECTORIES false
    MFCMainApp.rc
    res/MFCMainApp.ico
    res/MFCMainApp.rc2
    )

add_executable(MFCDlgMainApp WIN32
    ${MFCDLGMAINAPP_HEADER_FILES}
    ${MFCDLGMAINAPP_SOURCE_FILES}
    ${MFCDLGMAINAPP_RESOURCE_FILES}
    )

target_compile_definitions(MFCDlgMainApp
    PUBLIC -D_UNICODE
    PUBLIC -DUNICODE
    )

set(CMAKE_MFC_FLAG 2)
