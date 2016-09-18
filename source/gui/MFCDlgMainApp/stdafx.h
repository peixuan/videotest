/*****************************************************************************
 *
 * Copyright (C) 2015-2017 PoeticFlower Studio. All Rights Reserved.
 *
 * CONFIDENTIALITY:  This software source code is considered confidential
 * information. It must be kept confidential in accordance with the terms
 * and conditions of your Software License Agreement.
 *
 *
 * FILE    : stdafx.h
 * PURPOSE : Standard Application Framework Extensions.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: References the example code in Visual Studio.
 *           Include file for standard system include files, or project
 *           specific include files that are used frequently, but are changed
 *           infrequently.
 *
 *****************************************************************************/

#pragma once

// Exclude rarely-used stuff from Windows headers
#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

#include "targetver.h"

// Some CString constructors will be explicit
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS

// Turns off MFC's hiding of some common and often safely ignored warning
// messages
#define _AFX_ALL_WARNINGS

// MFC core and standard components
#include <afxwin.h>
// MFC extensions
#include <afxext.h>

// MFC Automation classes
#include <afxdisp.h>

// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>
#endif

// MFC support for Windows Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>
#endif // _AFX_NO_AFXCMN_SUPPORT

// MFC support for ribbons and control bars
#include <afxcontrolbars.h>


#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif
