
// EasyDocView.cpp : implementation of the CEasyDocView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "EasyDoc.h"
#endif

#include "EasyDocDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "EasyDocView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEasyDocView

IMPLEMENT_DYNCREATE(CEasyDocView, CRichEditView)

BEGIN_MESSAGE_MAP(CEasyDocView, CRichEditView)
	ON_WM_DESTROY()
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEasyDocView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CEasyDocView construction/destruction

CEasyDocView::CEasyDocView()
{
	// TODO: add construction code here

}

CEasyDocView::~CEasyDocView()
{
}

BOOL CEasyDocView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

void CEasyDocView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// Set the printing margins (720 twips = 1/2 inch)
	SetMargins(CRect(720, 720, 720, 720));
}


// CEasyDocView printing


void CEasyDocView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CEasyDocView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}


void CEasyDocView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CRichEditView::OnDestroy();
}


void CEasyDocView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CEasyDocView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CEasyDocView diagnostics

#ifdef _DEBUG
void CEasyDocView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CEasyDocView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CEasyDocDoc* CEasyDocView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEasyDocDoc)));
	return (CEasyDocDoc*)m_pDocument;
}
#endif //_DEBUG


// CEasyDocView message handlers
