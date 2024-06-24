// GameMainDlg.cpp : implementation file
//

#include "pch.h"
#include "YachtDice.h"
#include "GameMainDlg.h"
#include "YachtDiceDlg.h"

// GameMainDlg

IMPLEMENT_DYNCREATE(GameMainDlg, CFormView)

GameMainDlg::GameMainDlg()
	: CFormView(IDD_GAME_MAIN_DIALOG)
{

}

GameMainDlg::~GameMainDlg()
{
}

void GameMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_START_BTN, m_start_btn);
}

BEGIN_MESSAGE_MAP(GameMainDlg, CFormView)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_START_BTN, &GameMainDlg::OnBnClickedStartBtn)
END_MESSAGE_MAP()


// GameMainDlg diagnostics

#ifdef _DEBUG
void GameMainDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void GameMainDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// GameMainDlg message handlers


void GameMainDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CFormView::OnPaint() for painting messages
	CRect rect;
	GetClientRect(&rect);
	m_CImage.StretchBlt(dc.m_hDC, 0, 0, rect.Width(), rect.Height(), SRCCOPY); // 이미지를 픽쳐 컨트롤 크기로 조정
}


BOOL GameMainDlg::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void GameMainDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class

	m_CImage.Load(_T("res\\background\\MAIN_BG.png")); //메인 이미지 로드

	m_start_btn.LoadPNGFromResource(IDB_START_BTN);
}


void GameMainDlg::OnBnClickedStartBtn()
{
	// TODO: Add your control notification handler code here
	if (m_pParentDlg)
	{
		m_pParentDlg->HideForm_GameMainDlg();
		m_pParentDlg->ShowForm_GameSettingDlg();
	}
}

void GameMainDlg::SetParentDlg(CYachtDiceDlg* pParentDlg)
{
	m_pParentDlg = pParentDlg;
}