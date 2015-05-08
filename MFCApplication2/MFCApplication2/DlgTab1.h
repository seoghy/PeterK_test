#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDlgTab1 ��ȭ �����Դϴ�.

class CDlgTab1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTab1)

public:
	CDlgTab1(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgTab1();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_TAB1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
	CButton m_CheckEnable;
	afx_msg void OnBnClickedCheck1Enable();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	CProgressCtrl m_ProgressRange;
	CSliderCtrl m_SliderRange;
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
};
