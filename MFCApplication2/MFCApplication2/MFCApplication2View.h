
// MFCApplication2View.h : CMFCApplication2View 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "DlgTab1.h"


class CMFCApplication2View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CMFCApplication2View();
	DECLARE_DYNCREATE(CMFCApplication2View)

public:
	enum{ IDD = IDD_MFCAPPLICATION2_FORM };

// 특성입니다.
public:
	CMFCApplication2Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CMFCApplication2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_Tab1;
	void InitControl(void);
	CDlgTab1 m_DlgTab1;
	void CreateTabDlg(void);
};

#ifndef _DEBUG  // MFCApplication2View.cpp의 디버그 버전
inline CMFCApplication2Doc* CMFCApplication2View::GetDocument() const
   { return reinterpret_cast<CMFCApplication2Doc*>(m_pDocument); }
#endif

