
// MFCApplication2View.cpp : CMFCApplication2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CFormView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CFormView)
END_MESSAGE_MAP()

// CMFCApplication2View 생성/소멸

CMFCApplication2View::CMFCApplication2View()
	: CFormView(CMFCApplication2View::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCApplication2View::~CMFCApplication2View()
{
}

void CMFCApplication2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_Tab1);
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMFCApplication2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CreateTabDlg();

	InitControl();

}


// CMFCApplication2View 진단

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View 메시지 처리기


void CMFCApplication2View::InitControl(void)
{
	m_Tab1.InsertItem(0,"Tab1");
	m_Tab1.InsertItem(1,"Tab2");
}


void CMFCApplication2View::CreateTabDlg(void)
{
	CRect	rCtrl;

	m_Tab1.GetWindowRect(&rCtrl);
	ScreenToClient(&rCtrl);
	rCtrl.top += 20;
	rCtrl.left += 5;
	rCtrl.right -= 5;
	rCtrl.bottom -= 5;

	m_DlgTab1.Create(CDlgTab1::IDD,this);
	m_DlgTab1.MoveWindow(rCtrl);
	m_DlgTab1.ShowWindow(SW_SHOW);
}
