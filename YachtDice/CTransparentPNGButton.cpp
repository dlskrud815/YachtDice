#include "pch.h"
#include "CTransparentPNGButton.h"

IMPLEMENT_DYNAMIC(CTransparentPNGButton, CButton)

BEGIN_MESSAGE_MAP(CTransparentPNGButton, CButton)
    ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

CTransparentPNGButton::CTransparentPNGButton() : m_pImage(NULL)
{
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);
}

CTransparentPNGButton::~CTransparentPNGButton()
{
    if (m_pImage)
    {
        delete m_pImage;
    }
    Gdiplus::GdiplusShutdown(m_gdiplusToken);
}

BOOL CTransparentPNGButton::LoadPNGFromResource(UINT nResourceID)
{
    HINSTANCE hInstance = AfxGetResourceHandle();
    HRSRC hResource = FindResource(hInstance, MAKEINTRESOURCE(nResourceID), _T("PNG"));
    if (!hResource)
        return FALSE;

    DWORD imageSize = SizeofResource(hInstance, hResource);
    HGLOBAL hGlobal = LoadResource(hInstance, hResource);
    if (!hGlobal)
        return FALSE;

    LPVOID pResourceData = LockResource(hGlobal);
    if (!pResourceData)
        return FALSE;

    HGLOBAL hBuffer = GlobalAlloc(GMEM_MOVEABLE, imageSize);
    if (hBuffer)
    {
        void* pBuffer = GlobalLock(hBuffer);
        if (pBuffer)
        {
            CopyMemory(pBuffer, pResourceData, imageSize);
            IStream* pStream = NULL;
            if (SUCCEEDED(CreateStreamOnHGlobal(hBuffer, TRUE, &pStream)))
            {
                m_pImage = Gdiplus::Image::FromStream(pStream);
                pStream->Release();
                if (m_pImage)
                {
                    GlobalUnlock(hBuffer);
                    return TRUE;
                }
            }
            GlobalUnlock(hBuffer);
        }
        GlobalFree(hBuffer);
    }
    return FALSE;
}

void CTransparentPNGButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
    CRect rect = lpDrawItemStruct->rcItem;

    if (m_pImage)
    {
        Gdiplus::Graphics graphics(pDC->GetSafeHdc());
        graphics.DrawImage(m_pImage, rect.left, rect.top, rect.Width(), rect.Height());
    }
}

void CTransparentPNGButton::PreSubclassWindow()
{
    ModifyStyle(0, BS_OWNERDRAW);
    CButton::PreSubclassWindow();
}

BOOL CTransparentPNGButton::OnEraseBkgnd(CDC* pDC)
{
    return TRUE;
}