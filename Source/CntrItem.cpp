
// CntrItem.cpp : implementation of the CEasyDocCntrItem class
//

#include "stdafx.h"
#include "EasyDoc.h"

#include "EasyDocDoc.h"
#include "EasyDocView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEasyDocCntrItem implementation

IMPLEMENT_SERIAL(CEasyDocCntrItem, CRichEditCntrItem, 0)

CEasyDocCntrItem::CEasyDocCntrItem(REOBJECT* preo, CEasyDocDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: add one-time construction code here
}

CEasyDocCntrItem::~CEasyDocCntrItem()
{
	// TODO: add cleanup code here
}


// CEasyDocCntrItem diagnostics

#ifdef _DEBUG
void CEasyDocCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CEasyDocCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

