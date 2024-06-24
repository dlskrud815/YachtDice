// GameSettingDlg.cpp : implementation file
//

#include "pch.h"
#include "YachtDice.h"
#include "GameSettingDlg.h"
#include "YachtDiceDlg.h"

// GameSettingDlg

IMPLEMENT_DYNCREATE(GameSettingDlg, CFormView)

GameSettingDlg::GameSettingDlg()
	: CFormView(IDD_GAME_SETTING_DIALOG)
{

}

GameSettingDlg::~GameSettingDlg()
{

}

void GameSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(GameSettingDlg, CFormView)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BACK_BTN, &GameSettingDlg::OnBnClickedBackBtn)
END_MESSAGE_MAP()


// GameSettingDlg diagnostics

#ifdef _DEBUG
void GameSettingDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void GameSettingDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// GameSettingDlg message handlers


BOOL GameSettingDlg::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void GameSettingDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class

	m_CImage.Load(_T("res\\background\\BACKGROUND.png"));
}

void GameSettingDlg::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO: Add your message handler code here
    // Do not call CFormView::OnPaint() for painting messages
    CRect rect;
    GetClientRect(&rect);

    m_CImage.StretchBlt(dc.m_hDC, 0, 0, rect.Width(), rect.Height(), SRCCOPY); // 이미지를 픽쳐 컨트롤 크기로 조정
}

void GameSettingDlg::SetParentDlg(CYachtDiceDlg* pParentDlg)
{
	m_pParentDlg = pParentDlg;
}

void GameSettingDlg::OnBnClickedBackBtn()
{
	// TODO: Add your control notification handler code here
	m_pParentDlg->HideForm_GameSettingDlg();
	m_pParentDlg->AllocForm_GameSettingDlg();
	m_pParentDlg->ShowForm_GameMainDlg();
}
