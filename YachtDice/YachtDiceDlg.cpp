
// YachtDiceDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "YachtDice.h"
#include "YachtDiceDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

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

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CYachtDiceDlg dialog



CYachtDiceDlg::CYachtDiceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_YACHTDICE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_DICE_ICON); // 다이스 아이콘
}

void CYachtDiceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MAIN_DIALOG_FRAME, m_DialogFrame);
}

BEGIN_MESSAGE_MAP(CYachtDiceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CYachtDiceDlg message handlers

BOOL CYachtDiceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	AllocForm_GameMainDlg();
	AllocForm_GameSettingDlg();

	ShowForm_GameMainDlg();
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CYachtDiceDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CYachtDiceDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CYachtDiceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CYachtDiceDlg::AllocForm_GameMainDlg()
{
	CCreateContext context;
	ZeroMemory(&context, sizeof(context));

	CRect rectOfPanelArea;
	m_DialogFrame.GetWindowRect(&rectOfPanelArea);
	ScreenToClient(&rectOfPanelArea);

	m_GameMainDlg = new GameMainDlg();
	m_GameMainDlg->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_GAME_MAIN_DIALOG, &context);
	m_GameMainDlg->OnInitialUpdate();
	m_GameMainDlg->SetParentDlg(this);
}

void CYachtDiceDlg::ShowForm_GameMainDlg()
{
	m_GameMainDlg->ShowWindow(SW_SHOW);
}

void CYachtDiceDlg::HideForm_GameMainDlg()
{
	m_GameMainDlg->ShowWindow(SW_HIDE);
}


void CYachtDiceDlg::AllocForm_GameSettingDlg()
{
	CCreateContext context;
	ZeroMemory(&context, sizeof(context));

	CRect rectOfPanelArea;
	m_DialogFrame.GetWindowRect(&rectOfPanelArea);
	ScreenToClient(&rectOfPanelArea);

	m_GameSettingDlg = new GameSettingDlg();
	m_GameSettingDlg->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_GAME_SETTING_DIALOG, &context);
	m_GameSettingDlg->OnInitialUpdate();
	m_GameSettingDlg->SetParentDlg(this);
}

void CYachtDiceDlg::ShowForm_GameSettingDlg()
{
	m_GameSettingDlg->ShowWindow(SW_SHOW);
}

void CYachtDiceDlg::HideForm_GameSettingDlg()
{
	m_GameSettingDlg->ShowWindow(SW_HIDE);
}