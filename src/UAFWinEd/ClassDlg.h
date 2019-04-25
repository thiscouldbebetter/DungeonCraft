/******************************************************************************
* Filename: ClassDlg.h
* Copyright (c) 2000, UAF Development Team (email CocoaSpud@hotmail.com)
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
******************************************************************************/

/////////////////////////////////////////////////////////////////////////////
// CClassDlg dialog
#include "items.h"
#include "SortableListCtrl.h"

class CClassDlg : public CDialog
{
// Construction
public:
	//CClassDlg(int selectedClassesMask, CWnd* pParent = NULL);   // standard constructor
	CClassDlg(CArray<BASECLASS_ID, BASECLASS_ID&> *pBaseclasses, CWnd* pParent = NULL);   // standard constructor

	//void GetClassList(ITEM_LIST& list);


// Dialog Data
	//{{AFX_DATA(CClassDlg)
	enum { IDD = IDD_CLASSES };
	CSortableListCtrl	m_ChosenList;
	CSortableListCtrl	m_AvailList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClassDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
  //int  m_selectedClassesMask;
  BASECLASS_LIST  m_selectedBaseclasses;
  BASECLASS_LIST  m_availableBaseclasses;
  BASECLASS_LIST  m_allBaseclasses;  // Perhaps some that are not in baseclassData!
protected:
  //void AddToChosenList(CLASS_DATA *pClassData);
  void AddToChosenList(int indx);
  //void AddToAvailList(CLASS_DATA *pClassData);
  void AddToAvailList(int indx);
  BOOL FindItemInList(GLOBAL_ITEM_ID giID);
  void UnselectAllAvailableClasses();
  void UnselectAllChosenClasses();

	// Generated message map functions
	//{{AFX_MSG(CClassDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkAvaillist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkChosenlist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	//afx_msg void OnDeleteall();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
