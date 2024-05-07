
// CntrItem.h : interface of the CEasyDocCntrItem class
//

#pragma once

class CEasyDocDoc;
class CEasyDocView;

class CEasyDocCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CEasyDocCntrItem)

// Constructors
public:
	CEasyDocCntrItem(REOBJECT* preo = NULL, CEasyDocDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer

// Attributes
public:
	CEasyDocDoc* GetDocument()
		{ return reinterpret_cast<CEasyDocDoc*>(CRichEditCntrItem::GetDocument()); }
	CEasyDocView* GetActiveView()
		{ return reinterpret_cast<CEasyDocView*>(CRichEditCntrItem::GetActiveView()); }

// Implementation
public:
	~CEasyDocCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

