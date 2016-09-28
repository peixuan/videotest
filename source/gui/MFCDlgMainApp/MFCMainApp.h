/*****************************************************************************
 *
 * Copyright (C) 2015-2017 PoeticFlower Studio. All Rights Reserved.
 *
 * CONFIDENTIALITY:  This software source code is considered confidential
 * information. It must be kept confidential in accordance with the terms
 * and conditions of your Software License Agreement.
 *
 *
 * FILE    : MFCMainApp.h
 * PURPOSE : Main header file for the MFCMainApp application.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: References the example code in Visual Studio.
 *
 *****************************************************************************/

#pragma once

#ifndef __AFXWIN_H__
#error "include 'stdafx.h' before including this file for PCH"
#endif

// Main symbols
#include "resource.h"

/*****************************************************************************
 *
 * CLASS   : CMFCMainApp
 * PURPOSE : Entry class for the MFC application.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: References the example code in Visual Studio.
 *           See MFCMainApp.cpp for the implementation of this class.
 *
 *****************************************************************************/

class CMFCMainApp : public CWinApp
{
public:
  CMFCMainApp();

  // Overrides
public:
  virtual BOOL InitInstance();

  // Implementation

  DECLARE_MESSAGE_MAP()
};

extern CMFCMainApp theApp;
