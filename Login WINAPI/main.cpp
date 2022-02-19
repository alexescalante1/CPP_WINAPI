#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"

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
            case BTN_LOGIN_INGRESAR:
                EndDialog(hwndDlg, 0);

                DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), NULL, (DLGPROC)DlgMain);
            return TRUE;

            case BTN_LOGIN_CREAR_C:
                EndDialog(hwndDlg, 0);

                DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgMain);
            return TRUE;

            case BTN_C_CUENTA:
                EndDialog(hwndDlg, 0);

                DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
            return TRUE;

            case BTN_C_ATRAS:
                EndDialog(hwndDlg, 0);

                DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
            return TRUE;

            case BTN_CERRAR_SESION:
                EndDialog(hwndDlg, 0);

                DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
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
