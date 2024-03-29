﻿// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// MFCMainProgramView.cpp: CMFCMainProgramView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCMainProgram.h"
#endif

#include "MFCMainProgramDoc.h"
#include "MFCMainProgramView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "DllDlgFun.h"

// CMFCMainProgramView

IMPLEMENT_DYNCREATE(CMFCMainProgramView, CView)

BEGIN_MESSAGE_MAP(CMFCMainProgramView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCMainProgramView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_BTN_CALLDLLDLG, &CMFCMainProgramView::OnBtnCallDllDlg)
END_MESSAGE_MAP()

// CMFCMainProgramView 构造/析构

CMFCMainProgramView::CMFCMainProgramView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCMainProgramView::~CMFCMainProgramView()
{
}

BOOL CMFCMainProgramView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCMainProgramView 绘图

void CMFCMainProgramView::OnDraw(CDC* /*pDC*/)
{
	CMFCMainProgramDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCMainProgramView 打印


void CMFCMainProgramView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCMainProgramView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCMainProgramView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCMainProgramView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCMainProgramView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCMainProgramView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCMainProgramView 诊断

#ifdef _DEBUG
void CMFCMainProgramView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMainProgramView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMainProgramDoc* CMFCMainProgramView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMainProgramDoc)));
	return (CMFCMainProgramDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMainProgramView 消息处理程序


void CMFCMainProgramView::OnBtnCallDllDlg()
{
	// TODO: 在此添加命令处理程序代码
	CMFCMainProgramDoc* pDoc = GetDocument();
	pDoc->gDataSet.iFromDllDlg = ShowDllDlg();
	CString str;
	str.Format(_T("从 DLL 对话框返回 %d 。"), pDoc->gDataSet.iFromDllDlg);
	MessageBox(str, _T("反馈"));
}
