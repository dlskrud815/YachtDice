// GamePlayDlg.cpp : implementation file
//

#include "pch.h"
#include "YachtDice.h"
#include "GamePlayDlg.h"


// GamePlayDlg

IMPLEMENT_DYNCREATE(GamePlayDlg, CFormView)

GamePlayDlg::GamePlayDlg()
	: CFormView(IDD_GAME_PLAY_DIALOG)
{

}

GamePlayDlg::~GamePlayDlg()
{
	if (gamemanager)
	{
		delete gamemanager; //메모리 해제
	}
}

void GamePlayDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXT_PLAYER1, m_player1);
	DDX_Control(pDX, IDC_TEXT_PLAYER2, m_player2);
}

BEGIN_MESSAGE_MAP(GamePlayDlg, CFormView)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// GamePlayDlg diagnostics

#ifdef _DEBUG
void GamePlayDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void GamePlayDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// GamePlayDlg message handlers


void GamePlayDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CFormView::OnPaint() for painting messages
}


BOOL GamePlayDlg::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void GamePlayDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	//m_player1.SetWindowTextW(this->gamemanager->GetUsername());
}


void GamePlayDlg::SetGameManager(GameManager* gamemanager)
{
	this->gamemanager = gamemanager;
}

void GamePlayDlg::SetParentDlg(CYachtDiceDlg* pParentDlg)
{
	m_pParentDlg = pParentDlg;
}