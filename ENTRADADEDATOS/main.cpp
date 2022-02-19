#include <windows.h>
#include <iostream>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"

using namespace std;
HINSTANCE hInst;

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
            char C1[100],C2[100];
//            int  N1;

            case BUTON1:

                GetDlgItemText(hwndDlg,EDIT1,C1,200);
                GetDlgItemText(hwndDlg,EDIT2,C2,200);
                system("cls");
                int NUM=0;
                for(int i = 0;C1[i];i++){
//                    NUM+=(int)C1[i];
                    cout<<(int)C1[i]<<endl;
                }
//                cout<<endl<<NUM;
//                cout<<(char)224<<endl;
                return TRUE;
        }
    }
    return TRUE;
    }
    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
