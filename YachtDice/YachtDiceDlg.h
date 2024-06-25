
// YachtDiceDlg.h : header file
//

#pragma once

#include "GameMainDlg.h"
#include "GameSettingDlg.h"
#include "GamePlayDlg.h"

// CYachtDiceDlg dialog
class CYachtDiceDlg : public CDialogEx
{
// Construction
public:
	CYachtDiceDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YACHTDICE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()

private:
	CStatic m_DialogFrame;

	GameMainDlg* m_GameMainDlg;
	GameSettingDlg* m_GameSettingDlg;
	GamePlayDlg* m_GamePlayDlg;

public:
	void AllocForm_GameSettingDlg();
	void AllocForm_GameMainDlg();
	void AllocForm_GamePlayDlg();

	void ShowForm_GameMainDlg();
	void HideForm_GameMainDlg();

	void ShowForm_GameSettingDlg();
	void HideForm_GameSettingDlg();

	void ShowForm_GamePlayDlg();
	void HideForm_GamePlayDlg();
};
