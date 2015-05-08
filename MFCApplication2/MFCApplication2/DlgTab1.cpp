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
	DDX_Control(pDX, IDC_CHECK1_ENABLE, m_CheckEnable);
	DDX_Control(pDX, IDC_PROGRESS1, m_ProgressRange);
	DDX_Control(pDX, IDC_SLIDER1, m_SliderRange);
}


BEGIN_MESSAGE_MAP(CDlgTab1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1_ADD, &CDlgTab1::OnBnClickedButton1Add)
	ON_BN_CLICKED(IDC_BUTTON2_DELETE, &CDlgTab1::OnBnClickedButton2Delete)
	ON_CBN_SELCHANGE(IDC_COMBO_ITEM, &CDlgTab1::OnCbnSelchangeComboItem)
	ON_BN_CLICKED(IDC_CHECK1_ENABLE, &CDlgTab1::OnBnClickedCheck1Enable)
	ON_BN_CLICKED(IDC_RADIO1, &CDlgTab1::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDlgTab1::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CDlgTab1::OnBnClickedRadio3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CDlgTab1::OnNMCustomdrawSlider1)
END_MESSAGE_MAP()


// CDlgTab1 �޽��� ó�����Դϴ�.


void CDlgTab1::InitControl(void)
{
	CString strItem[] = {"���", "��õ", "����"};
	int i =0, nItemCount = 3;

	for(i=0; i< nItemCount; i++)
	{
		m_ListBoxItem.AddString(strItem[i]);
	}
	m_CheckEnable.SetCheck(TRUE);

	m_ProgressRange.SetRange(0,100);
	m_ProgressRange.SetPos(50);

	m_SliderRange.SetRange(0,100);
	m_SliderRange.SetPos(50);

//	Console::Write(L"Hello");
//	Console::WriteLine(L"World");
//	Console::Write(L"Enter Your name:");
//	String^ name = Console::ReadLine();
//	Console::Write(L"Good day, ");
//	Console::Write( name );
//Console::WriteLine( L"!");
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


void CDlgTab1::OnBnClickedCheck1Enable()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL	bEnable=FALSE;

	bEnable = m_CheckEnable.GetCheck();
	m_ComboItem.EnableWindow(bEnable);
}


void CDlgTab1::OnBnClickedRadio1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_EditItem.SetWindowTextA("Radio1");
}


void CDlgTab1::OnBnClickedRadio2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_EditItem.SetWindowTextA("Radio2");
}


void CDlgTab1::OnBnClickedRadio3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_EditItem.SetWindowTextA("Radio3");
}


void CDlgTab1::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nPos = 0;
	nPos = m_SliderRange.GetPos();
	m_ProgressRange.SetPos(nPos);

	*pResult = 0;
}
