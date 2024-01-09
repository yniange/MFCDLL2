// CDlgDll.cpp: 实现文件
//

#include "pch.h"
#include "DllDlg.h"
#include "afxdialogex.h"
#include "CDlgDll.h"


// CDlgDll 对话框

IMPLEMENT_DYNAMIC(CDlgDll, CDialogEx)

CDlgDll::CDlgDll(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLL_DLG, pParent)
	, m_iEditInput(0)
{

}

CDlgDll::~CDlgDll()
{
}

void CDlgDll::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_INPUT, m_Slider_Input);
	DDX_Text(pDX, IDC_EDT_INPUT, m_iEditInput);
	DDV_MinMaxUInt(pDX, m_iEditInput, 0, 1000);
}


BEGIN_MESSAGE_MAP(CDlgDll, CDialogEx)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_INPUT, &CDlgDll::OnCustomdrawSliderInput)
END_MESSAGE_MAP()


// CDlgDll 消息处理程序


BOOL CDlgDll::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_iEditInput = 0;
	m_Slider_Input.SetRange(0, 1000);
	m_Slider_Input.SetPos(m_iEditInput);
	m_Slider_Input.SetLineSize(40);
	m_Slider_Input.SetPageSize(100);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlgDll::OnCustomdrawSliderInput(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	m_iEditInput = m_Slider_Input.GetPos();
	//CString strPos;
	//strPos.Format(_T("%d"), m_iEditInput);
	UpdateData(FALSE);
	*pResult = 0;
}
