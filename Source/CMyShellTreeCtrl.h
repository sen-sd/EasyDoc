// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

#include "afxcontrolbarutil.h"
// #include "afxshellmanager.h"

#ifdef _AFX_PACKING
#pragma pack(push, _AFX_PACKING)
#endif

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, off)
#endif

class CMyShellTreeCtrl;

/////////////////////////////////////////////////////////////////////////////
// CMyShellTreeCtrl window

class CMyShellTreeCtrl : public CTreeCtrl
{
	//friend class CMFCShellListCtrl;

	DECLARE_DYNAMIC(CMyShellTreeCtrl)

// Construction
public:
	CMyShellTreeCtrl();

// Attributes
public:
	BOOL GetItemPath(CString& strPath, HTREEITEM htreeItem = NULL /* NULL - selected */) const;
	CMFCShellListCtrl* GetRelatedList() const;

	// Flags are same as in IShellFolder::EnumObjects
	DWORD GetFlags() const { return m_dwFlags; }
	void SetFlags(DWORD dwFlags, BOOL bRefresh = TRUE);

// Operations
public:
	void Refresh();
    void InitTree();
    void FillRootItems(const CString& strStartupFilePath);
	BOOL SelectPath(LPCTSTR lpszPath);
	BOOL SelectPath(LPCITEMIDLIST lpidl);

	void EnableShellContextMenu(BOOL bEnable = TRUE);

	void SetRelatedList(CMFCShellListCtrl* pShellList);

// Overrides
public:
	virtual CString OnGetItemText(LPAFX_SHELLITEMINFO pItem);
	virtual int OnGetItemIcon(LPAFX_SHELLITEMINFO pItem, BOOL bSelected);

public:
	virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult);

protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual void PreSubclassWindow();

// Implementation
public:
	virtual ~CMyShellTreeCtrl();

protected:
	//{{AFX_MSG(CMyShellTreeCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeleteitem(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	afx_msg LRESULT OnInitControl(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

	BOOL GetRootItems(const CString& strStartupFilePath);
	BOOL GetChildItems(HTREEITEM hParentItem);
	virtual HRESULT EnumObjects(HTREEITEM hParentItem, LPSHELLFOLDER pParentFolder, LPITEMIDLIST pidlParent);
	void OnShowContextMenu(CPoint point);


	static int CALLBACK CompareProc(LPARAM, LPARAM, LPARAM);

	// static IContextMenu2* m_pContextMenu2;

	BOOL  m_bContextMenu;
	BOOL  m_bNoNotify;
	HWND  m_hwndRelatedList;
	DWORD m_dwFlags;  // Flags for IShellFolder::EnumObjects

    CString m_strStartupFilePath;
};

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, on)
#endif

#ifdef _AFX_PACKING
#pragma pack(pop)
#endif
