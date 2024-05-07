
// EasyDocView.h : interface of the CEasyDocView class
//

#pragma once

class CEasyDocCntrItem;

class CEasyDocView : public CRichEditView
{
protected: // create from serialization only
	CEasyDocView();
	DECLARE_DYNCREATE(CEasyDocView)

// Attributes
public:
	CEasyDocDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CEasyDocView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnDestroy();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in EasyDocView.cpp
inline CEasyDocDoc* CEasyDocView::GetDocument() const
   { return reinterpret_cast<CEasyDocDoc*>(m_pDocument); }
#endif

