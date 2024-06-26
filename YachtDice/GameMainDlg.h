﻿#pragma once

#include "CTransparentPNGButton.h"

class CYachtDiceDlg;


// GameMainDlg form view

class GameMainDlg : public CFormView
{
	DECLARE_DYNCREATE(GameMainDlg)

public:
	GameMainDlg();
	virtual ~GameMainDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAME_MAIN_DIALOG };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnPaint();
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();

	afx_msg void OnBnClickedStartBtn();

	void SetParentDlg(CYachtDiceDlg* pParentDlg);

private:
	CImage m_CImage;
	CYachtDiceDlg* m_pParentDlg;

	CTransparentPNGButton m_start_btn;
};


