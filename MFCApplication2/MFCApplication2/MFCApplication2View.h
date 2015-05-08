
// MFCApplication2View.h : CMFCApplication2View Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "DlgTab1.h"


class CMFCApplication2View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CMFCApplication2View();
	DECLARE_DYNCREATE(CMFCApplication2View)

public:
	enum{ IDD = IDD_MFCAPPLICATION2_FORM };

// Ư���Դϴ�.
public:
	CMFCApplication2Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CMFCApplication2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_Tab1;
	void InitControl(void);
	CDlgTab1 m_DlgTab1;
	void CreateTabDlg(void);
};

#ifndef _DEBUG  // MFCApplication2View.cpp�� ����� ����
inline CMFCApplication2Doc* CMFCApplication2View::GetDocument() const
   { return reinterpret_cast<CMFCApplication2Doc*>(m_pDocument); }
#endif

