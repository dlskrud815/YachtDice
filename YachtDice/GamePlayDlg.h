#pragma once

#include "GameManager.h"

class CYachtDiceDlg;

// GamePlayDlg form view

class GamePlayDlg : public CFormView
{
	DECLARE_DYNCREATE(GamePlayDlg)

public:
	GamePlayDlg();
	virtual ~GamePlayDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAME_PLAY_DIALOG };
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

	void SetGameManager(GameManager* gamemanager);
	void SetPlayer1Name();
	void SetParentDlg(CYachtDiceDlg* pParentDlg);

private:
	CImage m_CImage;

	GameManager* gamemanager;
	CYachtDiceDlg* m_pParentDlg;

	CStatic m_player1;
	CStatic m_player2;
};


