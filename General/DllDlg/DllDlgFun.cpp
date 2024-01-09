#include "pch.h"
#include "DllDlgFun.h"
#include "CDlgDll.h"

unsigned int ShowDllDlg()
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    CDlgDll dlg;
    dlg.DoModal();
    return dlg.m_iEditInput;
}
