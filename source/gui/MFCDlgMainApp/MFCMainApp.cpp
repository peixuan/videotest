/*****************************************************************************
 *
 * Copyright (C) 2015-2017 PoeticFlower Studio. All Rights Reserved.
 *
 * CONFIDENTIALITY:  This software source code is considered confidential
 * information. It must be kept confidential in accordance with the terms
 * and conditions of your Software License Agreement.
 *
 *
 * FILE    : MFCMainApp.cpp
 * PURPOSE : Defines the class behaviors for the application.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: References the example code in Visual Studio.
 *
 *****************************************************************************/

#include "stdafx.h"
#include "MFCMainApp.h"
#include "MFCMainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/*****************************************************************************
 *
 * CLASS   : CMFCMainApp
 * PURPOSE : Entry class for the MFC application.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: References the example code in Visual Studio.
 *
 *****************************************************************************/

BEGIN_MESSAGE_MAP(CMFCMainApp, CWinApp)
  ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

// The one and only CMFCMainApp object
CMFCMainApp theApp;

/*****************************************************************************
 *
 * FUNCTION: CMFCMainApp()
 * PURPOSE : CMFCMainApp construction.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: References the example code in Visual Studio.
 *
 *****************************************************************************/

CMFCMainApp::CMFCMainApp()
{
  // support Restart Manager
  m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

  // TODO: add construction code here,
  // Place all significant initialization in InitInstance
}

/*****************************************************************************
 *
 * FUNCTION: InitInstance()
 * PURPOSE : CMFCMainApp initialization.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: References the example code in Visual Studio.
 *
 *****************************************************************************/

BOOL CMFCMainApp::InitInstance()
{
  // InitCommonControlsEx() is required on Windows XP if an application
  // manifest specifies use of ComCtl32.dll version 6 or later to enable
  // visual styles.  Otherwise, any window creation will fail.
  INITCOMMONCONTROLSEX InitCtrls;
  InitCtrls.dwSize = sizeof(InitCtrls);
  // Set this to include all the common control classes you want to use in
  // your application.
  InitCtrls.dwICC = ICC_WIN95_CLASSES;
  InitCommonControlsEx(&InitCtrls);

  CWinApp::InitInstance();

  AfxEnableControlContainer();

  // Create the shell manager, in case the dialog contains any shell tree
  // view or shell list view controls.
  CShellManager *pShellManager = new CShellManager;

  // Activate "Windows Native" visual manager for enabling themes in
  // MFC controls
  CMFCVisualManager::SetDefaultManager(
    RUNTIME_CLASS(CMFCVisualManagerWindows));

  // Standard initialization
  // If you are not using these features and wish to reduce the size of your
  // final executable, you should remove from the following the
  // specific initialization routines you do not need
  // Change the registry key under which our settings are stored
  // TODO: You should modify this string to be something appropriate such as
  // the name of your company or organization
  SetRegistryKey(_T("Local AppWizard-Generated Applications"));

  CMFCMainDlg dlg;
  m_pMainWnd = &dlg;
  INT_PTR nResponse = dlg.DoModal();
  if (nResponse == IDOK)
  {
    // TODO: Place code here to handle when the dialog is dismissed with OK
  }
  else if (nResponse == IDCANCEL)
  {
    // TODO: Place code here to handle when the dialog is dismissed with
    // Cancel
  }
  else if (nResponse == -1)
  {
    TRACE(traceAppMsg, 0,
      "Warning: dialog creation failed, so application is terminating "
      "unexpectedly.\n");
    TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the "
      "dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
  }

  // Delete the shell manager created above.
  if (pShellManager != NULL)
  {
    delete pShellManager;
  }

#ifndef _AFXDLL
  ControlBarCleanUp();
#endif

  // Since the dialog has been closed, return FALSE so that we exit the
  // application, rather than start the application's message pump.
  return FALSE;
}
