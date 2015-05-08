#pragma once
#include "afxwin.h"


// CDlgTab1 대화 상자입니다.

class CDlgTab1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTab1)

public:
	CDlgTab1(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgTab1();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_TAB1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_EditItem;
	CListBox m_ListBoxItem;
	void InitControl(void);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1Add();
	afx_msg void OnBnClickedButton2Delete();
	CComboBox m_ComboItem;
	afx_msg void OnCbnSelchangeComboItem();
};
