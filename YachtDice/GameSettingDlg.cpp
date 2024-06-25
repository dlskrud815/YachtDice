// GameSettingDlg.cpp : implementation file
//

#include "pch.h"
#include "YachtDice.h"
#include "GameSettingDlg.h"
#include "YachtDiceDlg.h"
#include "GamePlayDlg.h"

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
	DDX_Control(pDX, IDC_INSERT_USERNAME, m_edit_username);
	DDX_Control(pDX, IDC_IPADDRESS1, m_serverIP);
	DDX_Control(pDX, IDC_RADIO1, m_default_radio);
}

BEGIN_MESSAGE_MAP(GameSettingDlg, CFormView)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BACK_BTN, &GameSettingDlg::OnBnClickedBackBtn)
	ON_BN_CLICKED(IDC_OK_BTN, &GameSettingDlg::OnBnClickedOkBtn)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO1, IDC_RADIO3, &GameSettingDlg::OnBnClickedRadio)
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

	m_serverIP.ShowWindow(SW_HIDE);
	m_CImage.Load(_T("res\\background\\BACKGROUND.png"));
	m_default_radio.SetCheck(TRUE);
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


void GameSettingDlg::OnBnClickedOkBtn()
{
	// m_username = 사용자명, m_radio = 라디오 버튼
	m_edit_username.GetWindowTextW(m_username);
	
	if (!m_username.IsEmpty())
	{
		GameManager gamemanager(m_radio);

		gamemanager.SetUsername(m_username);
		gamemanager.SetRadio(m_radio);

		GamePlayDlg gamePlayDlg;
		gamePlayDlg.SetGameManager(&gamemanager);
	}
	else
	{
		AfxMessageBox(_T("닉네임을 입력해주세요."));
	}
}

afx_msg void GameSettingDlg::OnBnClickedRadio(UINT id)
{
	switch (id)
	{
	case IDC_RADIO1:
		m_radio = 0;
		m_serverIP.ShowWindow(SW_HIDE);
		break;

	case IDC_RADIO2:
		m_radio = 1;
		m_serverIP.ShowWindow(SW_HIDE);
		break;

	case IDC_RADIO3:
		m_radio = 2;
		m_serverIP.ShowWindow(SW_SHOW);
		break;

	default:
		break;
	}
}