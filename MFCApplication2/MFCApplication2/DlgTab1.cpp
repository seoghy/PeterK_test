// DlgTab1.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "DlgTab1.h"
#include "afxdialogex.h"


// CDlgTab1 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgTab1, CDialogEx)

CDlgTab1::CDlgTab1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgTab1::IDD, pParent)
{

}

CDlgTab1::~CDlgTab1()
{
}

void CDlgTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EditItem);
	DDX_Control(pDX, IDC_LIST1, m_ListBoxItem);
	DDX_Control(pDX, IDC_COMBO_ITEM, m_ComboItem);
}


BEGIN_MESSAGE_MAP(CDlgTab1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1_ADD, &CDlgTab1::OnBnClickedButton1Add)
	ON_BN_CLICKED(IDC_BUTTON2_DELETE, &CDlgTab1::OnBnClickedButton2Delete)
	ON_CBN_SELCHANGE(IDC_COMBO_ITEM, &CDlgTab1::OnCbnSelchangeComboItem)
END_MESSAGE_MAP()


// CDlgTab1 �޽��� ó�����Դϴ�.


void CDlgTab1::InitControl(void)
{
	CString strItem[] = {"¥�İ�Ƽ", "���׶���", "���ڿϽ�"};
	int i =0, nItemCount = 3;

	for(i=0; i< nItemCount; i++)
	{
		m_ListBoxItem.AddString(strItem[i]);
	}
}


BOOL CDlgTab1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	InitControl();

	return TRUE;  // return TRUE unless you set the focus to a control

}


void CDlgTab1::OnBnClickedButton1Add()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString	strItem;

	m_EditItem.GetWindowTextA(strItem);
	if(strItem.GetLength() <1 )
		return;

	m_ListBoxItem.AddString(strItem);
}


void CDlgTab1::OnBnClickedButton2Delete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nSelItem=0;

	nSelItem = m_ListBoxItem.GetCurSel();
	if( nSelItem == LB_ERR )
		return;

	m_ListBoxItem.DeleteString(nSelItem);
}


void CDlgTab1::OnCbnSelchangeComboItem()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString	strItem;

	m_ComboItem.GetLBText(m_ComboItem.GetCurSel(),strItem);
	m_EditItem.SetWindowTextA(strItem);
}
