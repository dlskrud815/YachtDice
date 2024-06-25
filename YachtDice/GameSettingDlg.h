#pragma once

#include "GameManager.h"

class CYachtDiceDlg;


// GameSettingDlg form view

class GameSettingDlg : public CFormView
{
	DECLARE_DYNCREATE(GameSettingDlg)

public:
	GameSettingDlg();
	virtual ~GameSettingDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAME_SETTING_DIALOG };
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
	
	afx_msg void OnBnClickedBackBtn();
	afx_msg void OnBnClickedOkBtn();
	afx_msg void OnBnClickedRadio(UINT id);

	void SetParentDlg(CYachtDiceDlg* pParentDlg);
	
private:
	CImage m_CImage;

	CYachtDiceDlg* m_pParentDlg;
	CEdit m_edit_username;

	CString m_username;
	CIPAddressCtrl m_serverIP;
	int m_radio;
	CButton m_default_radio;
};


