
// MFCApplication2View.cpp : CMFCApplication2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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

// CMFCApplication2View ����/�Ҹ�

CMFCApplication2View::CMFCApplication2View()
	: CFormView(CMFCApplication2View::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

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


// CMFCApplication2View ����

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View �޽��� ó����


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
