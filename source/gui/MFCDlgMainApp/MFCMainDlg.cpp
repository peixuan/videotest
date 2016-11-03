/*****************************************************************************
 *
 * Copyright (C) 2015-2017 PoeticFlower Studio. All Rights Reserved.
 *
 * CONFIDENTIALITY:  This software source code is considered confidential
 * information. It must be kept confidential in accordance with the terms
 * and conditions of your Software License Agreement.
 *
 *
 * FILE    : MFCMainDlg.cpp
 * PURPOSE : Implementation of the main dialog box for dialog-based
 *           application.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: Make the dialog box more like a program, not just a dialog box.
 *
 *****************************************************************************/

#include "stdafx.h"
#include "MFCMainApp.h"
#include "MFCMainDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/*****************************************************************************
 *
 * CLASS   : CAboutDlg
 * PURPOSE : The About Dialog used for App About.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: References the example code in Visual Studio.
 *
 *****************************************************************************/

class CAboutDlg : public CDialogEx
{
public:
  CAboutDlg();

  // Dialog Data
#ifdef AFX_DESIGN_TIME
  enum { IDD = IDD_ABOUTBOX };
#endif

protected:
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

  // Implementation
protected:
  DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
}

/*****************************************************************************
 *
 * CLASS   : CMFCMainDlg
 * PURPOSE : Main dialog box for dialog-based application.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: Make the dialog box more like a program, not just a dialog box.
 *
 *****************************************************************************/

BEGIN_MESSAGE_MAP(CMFCMainDlg, CDialogEx)
  ON_WM_SYSCOMMAND()
  ON_WM_PAINT()
  ON_WM_QUERYDRAGICON()
  ON_WM_CLOSE()
  ON_WM_GETMINMAXINFO()
  ON_WM_SIZE()
END_MESSAGE_MAP()

/*****************************************************************************
 *
 * FUNCTION: CMFCMainDlg()
 * PURPOSE : CMFCMainDlg construction.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: References the example code in Visual Studio.
 *
 *****************************************************************************/

CMFCMainDlg::CMFCMainDlg(CWnd* pParent /*=NULL*/)
  : CDialogEx(IDD_MFCMAINAPP_DIALOG, pParent)
{
  m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

/*****************************************************************************
 *
 * FUNCTION: DoDataExchange()
 * PURPOSE : DDX/DDV support for CMFCMainDlg.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: References the example code in Visual Studio.
 *
 *****************************************************************************/

void CMFCMainDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
}

// CMFCMainDlg message handlers


/*****************************************************************************
 *
 * FUNCTION: OnInitDialog()
 * PURPOSE : Initialize the CMFCMainDlg dialog.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: References the example code in Visual Studio.
 *
 *****************************************************************************/

BOOL CMFCMainDlg::OnInitDialog()
{
  CDialogEx::OnInitDialog();

  // Add "About..." menu item to system menu.

  // IDM_ABOUTBOX must be in the system command range.
  ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
  ASSERT(IDM_ABOUTBOX < 0xF000);

  CMenu* pSysMenu = GetSystemMenu(FALSE);
  if (pSysMenu != NULL)
  {
    BOOL bNameValid;
    CString strAboutMenu;
    bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
    ASSERT(bNameValid);
    if (!strAboutMenu.IsEmpty())
    {
      pSysMenu->AppendMenu(MF_SEPARATOR);
      pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
    }
  }

  // Set the icon for this dialog.   The framework does this automatically
  // when the application's main window is not a dialog
  SetIcon(m_hIcon, TRUE);     // Set big icon
  SetIcon(m_hIcon, FALSE);    // Set small icon

  // TODO: Add extra initialization here

  return TRUE;  // return TRUE  unless you set the focus to a control
}

/*****************************************************************************
 *
 * FUNCTION: OnSysCommand()
 * PURPOSE : Response message WM_SYSCOMMAND for CMFCMainDlg.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: Response system menu message. (System menu appears when right
 *           clicking the title bar.)
 *           References the example code in Visual Studio.
 *
 *****************************************************************************/

void CMFCMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
  if ((nID & 0xFFF0) == IDM_ABOUTBOX)
  {
    CAboutDlg dlgAbout;
    dlgAbout.DoModal();
  }
  else
  {
    CDialogEx::OnSysCommand(nID, lParam);
  }
}

/*****************************************************************************
 *
 * FUNCTION: OnPaint()
 * PURPOSE : Response message WM_PAINT for CMFCMainDlg.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: If you add a minimize button to your dialog, you will need the
 *           code below to draw the icon.  For MFC applications using the
 *           document/view model, this is automatically done for you by the
 *           framework.
 *           References the example code in Visual Studio.
 *
 *****************************************************************************/

void CMFCMainDlg::OnPaint()
{
  if (IsIconic())
  {
    CPaintDC dc(this); // device context for painting

    SendMessage(WM_ICONERASEBKGND,
      reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

    // Center icon in client rectangle
    int cxIcon = GetSystemMetrics(SM_CXICON);
    int cyIcon = GetSystemMetrics(SM_CYICON);
    CRect rect;
    GetClientRect(&rect);
    int x = (rect.Width() - cxIcon + 1) / 2;
    int y = (rect.Height() - cyIcon + 1) / 2;

    // Draw the icon
    dc.DrawIcon(x, y, m_hIcon);
  }
  else
  {
    CDialogEx::OnPaint();
  }
}

/*****************************************************************************
 *
 * FUNCTION: OnQueryDragIcon()
 * PURPOSE : Response message WM_QUERYDRAGICON for CMFCMainDlg.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: The system calls this function to obtain the cursor to display
 *           while the user drags the minimized window.
 *           References the example code in Visual Studio.
 *
 *****************************************************************************/

HCURSOR CMFCMainDlg::OnQueryDragIcon()
{
  return static_cast<HCURSOR>(m_hIcon);
}

/*****************************************************************************
 *
 * FUNCTION: OnOK()
 * PURPOSE : Overload base class function OnOK() for CMFCMainDlg.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: Shield the response of Enter key to prevent the program
 *           unexpectedly quits. (We must use it, when using a dialog-based
 *           application.)
 *
 *****************************************************************************/

void CMFCMainDlg::OnOK()
{
  return;
}

/*****************************************************************************
 *
 * FUNCTION: OnCancel()
 * PURPOSE : Overload base class function OnCancel() for CMFCMainDlg.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: Shield the response of ESC key to prevent the program
 *           unexpectedly quits. (We must use it, when using a dialog-based
 *           application.)
 *
 *****************************************************************************/

void CMFCMainDlg::OnCancel()
{
  return;
}

/*****************************************************************************
 *
 * FUNCTION: OnClose()
 * PURPOSE : Response message WM_CLOSE for CMFCMainDlg.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: Clean up memory and close the main dialog. We must explicitly
 *           implement it, because we have shielded the Enter and ESC keys.
 *
 *****************************************************************************/

void CMFCMainDlg::OnClose()
{
  // TODO: Clean up memory.

  CDialogEx::OnClose();

  // Close the Main Dialog.
  CDialogEx::OnOK();
}

/*****************************************************************************
 *
 * FUNCTION: OnGetMinMaxInfo()
 * PURPOSE : Response message WM_GETMINMAXINFO for CMFCMainDlg.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: Set the minimum size of the application dialog box. If the
 *           window is too small, we can not make the appropriate control
 *           layout.
 *
 *****************************************************************************/

void CMFCMainDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
  lpMMI->ptMinTrackSize.x = 320;
  lpMMI->ptMinTrackSize.y = 240;

  CDialogEx::OnGetMinMaxInfo(lpMMI);
}

/*****************************************************************************
 *
 * FUNCTION: OnSize()
 * PURPOSE : Response message WM_SIZE for CMFCMainDlg.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: Dynamic layout controls.
 *
 *****************************************************************************/

void CMFCMainDlg::OnSize(UINT nType, int cx, int cy)
{
  CDialogEx::OnSize(nType, cx, cy);

  // TODO: Add your message handler code here
}
