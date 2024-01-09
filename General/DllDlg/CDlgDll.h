#pragma once
#include "afxdialogex.h"


// CDlgDll 对话框

class CDlgDll : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgDll)

public:
	CDlgDll(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgDll();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLL_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// Slider控件变量
	CSliderCtrl m_Slider_Input;
	virtual BOOL OnInitDialog();
	// 文本编辑框控件unsigned int变量
	unsigned int m_iEditInput;
	afx_msg void OnCustomdrawSliderInput(NMHDR* pNMHDR, LRESULT* pResult);
};
