/*****************************************************************************
 *
 * Copyright (C) 2015-2017 PoeticFlower Studio. All Rights Reserved.
 *
 * CONFIDENTIALITY:  This software source code is considered confidential
 * information. It must be kept confidential in accordance with the terms
 * and conditions of your Software License Agreement.
 *
 *
 * FILE    : MFCMainDlg.h
 * PURPOSE : Main dialog box for dialog-based application - header file.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: Make the dialog box more like a program, not just a dialog box.
 *
 *****************************************************************************/

#pragma once

/*****************************************************************************
 *
 * CLASS   : CMFCMainDlg
 * PURPOSE : Main dialog box for dialog-based application.
 * AUTHOR  : Peixuan Zhang <Zhang@PoeticFlower.CN>
 * COMMENTS: Make the dialog box more like a program, not just a dialog box.
 *           See MFCMainDlg.cpp for the implementation of this class.
 *
 *****************************************************************************/

class CMFCMainDlg : public CDialogEx
{
  // Construction
public:
  CMFCMainDlg(CWnd* pParent = NULL);  // standard constructor

  // Dialog Data
#ifdef AFX_DESIGN_TIME
  enum { IDD = IDD_MFCMAINAPP_DIALOG };
#endif

protected:
  virtual void DoDataExchange(CDataExchange* pDX);  // DDX/DDV support

  // Implementation
protected:
  HICON m_hIcon;

  // Generated message map functions
  virtual BOOL OnInitDialog();
  afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
  afx_msg void OnPaint();
  afx_msg HCURSOR OnQueryDragIcon();
  DECLARE_MESSAGE_MAP()
public:
  virtual void OnOK();
  virtual void OnCancel();
  afx_msg void OnClose();
  afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
  afx_msg void OnSize(UINT nType, int cx, int cy);
};
