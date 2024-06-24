#pragma once
#include <afxwin.h>
#include <gdiplus.h>

class CTransparentPNGButton : public CButton
{
    DECLARE_DYNAMIC(CTransparentPNGButton)

public:
    CTransparentPNGButton();
    virtual ~CTransparentPNGButton();

    BOOL LoadPNGFromResource(UINT nResourceID);

protected:
    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
    virtual void PreSubclassWindow();

    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    DECLARE_MESSAGE_MAP()

private:
    Gdiplus::Image* m_pImage;
    ULONG_PTR m_gdiplusToken;
};