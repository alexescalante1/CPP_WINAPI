#include <iostream>
#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"

using namespace std;

HINSTANCE hInst;
HBRUSH brush;
HPEN greenPen;

void Limpiar(HWND hwndDlg){
        SetDlgItemText(hwndDlg,BTN_7,"_");
        SetDlgItemText(hwndDlg,BTN_8,"_");
        SetDlgItemText(hwndDlg,BTN_9,"_");
        SetDlgItemText(hwndDlg,BTN_10,"_");
        SetDlgItemText(hwndDlg,BTN_11,"_");
        SetDlgItemText(hwndDlg,BTN_12,"_");
        SetDlgItemText(hwndDlg,BTN_13,"_");
        SetDlgItemText(hwndDlg,BTN_14,"_");
        SetDlgItemText(hwndDlg,BTN_15,"_");
        SetDlgItemText(hwndDlg,BTN_16,"_");
        SetDlgItemText(hwndDlg,BTN_17,"_");
        SetDlgItemText(hwndDlg,BTN_18,"_");
        SetDlgItemText(hwndDlg,BTN_19,"_");
        SetDlgItemText(hwndDlg,BTN_20,"_");
        SetDlgItemText(hwndDlg,BTN_21,"_");
        SetDlgItemText(hwndDlg,BTN_22,"_");
        SetDlgItemText(hwndDlg,BTN_23,"_");
        SetDlgItemText(hwndDlg,BTN_24,"_");
        SetDlgItemText(hwndDlg,BTN_25,"_");
        SetDlgItemText(hwndDlg,BTN_26,"_");
        SetDlgItemText(hwndDlg,BTN_27,"_");
        SetDlgItemText(hwndDlg,BTN_28,"_");
        SetDlgItemText(hwndDlg,BTN_29,"_");
        SetDlgItemText(hwndDlg,BTN_30,"_");
        SetDlgItemText(hwndDlg,BTN_31,"_");
        SetDlgItemText(hwndDlg,BTN_32,"_");
        SetDlgItemText(hwndDlg,BTN_33,"_");
        SetDlgItemText(hwndDlg,BTN_34,"_");
        SetDlgItemText(hwndDlg,BTN_35,"_");
        SetDlgItemText(hwndDlg,BTN_36,"_");
        SetDlgItemText(hwndDlg,BTN_37,"_");
        SetDlgItemText(hwndDlg,BTN_38,"_");
        SetDlgItemText(hwndDlg,BTN_39,"_");
        SetDlgItemText(hwndDlg,BTN_40,"_");
        SetDlgItemText(hwndDlg,BTN_41,"_");
        SetDlgItemText(hwndDlg,BTN_42,"_");
        SetDlgItemText(hwndDlg,BTN_43,"_");
        SetDlgItemText(hwndDlg,BTN_44,"_");
        SetDlgItemText(hwndDlg,BTN_45,"_");
        SetDlgItemText(hwndDlg,BTN_46,"_");
        SetDlgItemText(hwndDlg,BTN_47,"_");
        SetDlgItemText(hwndDlg,BTN_48,"_");
}

void InCerTBOTTON(HWND hwndDlg,int PBOTO,char *H){
    for(int TT=7;TT<=48;TT++){
        switch(PBOTO){
                        case 7:
                                SetDlgItemText(hwndDlg,BTN_7,H);
                        break;
                        case 8:
                                SetDlgItemText(hwndDlg,BTN_8,H);
                        break;
                        case 9:
                                SetDlgItemText(hwndDlg,BTN_9,H);
                        break;
                        case 10:
                                SetDlgItemText(hwndDlg,BTN_10,H);
                        break;
                        case 11:
                                SetDlgItemText(hwndDlg,BTN_11,H);
                        break;
                        case 12:
                                SetDlgItemText(hwndDlg,BTN_12,H);
                        break;
                        case 13:
                                SetDlgItemText(hwndDlg,BTN_13,H);
                        break;
                        case 14:
                                SetDlgItemText(hwndDlg,BTN_14,H);
                        break;
                        case 15:
                                SetDlgItemText(hwndDlg,BTN_15,H);
                        break;
                        case 16:
                                SetDlgItemText(hwndDlg,BTN_16,H);
                        break;
                        case 17:
                                SetDlgItemText(hwndDlg,BTN_17,H);
                        break;
                        case 18:
                                SetDlgItemText(hwndDlg,BTN_18,H);
                        break;
                        case 19:
                                SetDlgItemText(hwndDlg,BTN_19,H);
                        break;
                        case 20:
                                SetDlgItemText(hwndDlg,BTN_20,H);
                        break;
                        case 21:
                                SetDlgItemText(hwndDlg,BTN_21,H);
                        break;
                        case 22:
                                SetDlgItemText(hwndDlg,BTN_22,H);
                        break;
                        case 23:
                                SetDlgItemText(hwndDlg,BTN_23,H);
                        break;
                        case 24:
                                SetDlgItemText(hwndDlg,BTN_24,H);
                        break;
                        case 25:
                                SetDlgItemText(hwndDlg,BTN_25,H);
                        break;
                        case 26:
                                SetDlgItemText(hwndDlg,BTN_26,H);
                        break;
                        case 27:
                                SetDlgItemText(hwndDlg,BTN_27,H);
                        break;
                        case 28:
                                SetDlgItemText(hwndDlg,BTN_28,H);
                        break;
                        case 29:
                                SetDlgItemText(hwndDlg,BTN_29,H);
                        break;
                        case 30:
                                SetDlgItemText(hwndDlg,BTN_30,H);
                        break;
                        case 31:
                                SetDlgItemText(hwndDlg,BTN_31,H);
                        break;
                        case 32:
                                SetDlgItemText(hwndDlg,BTN_32,H);
                        break;
                        case 33:
                                SetDlgItemText(hwndDlg,BTN_33,H);
                        break;
                        case 34:
                                SetDlgItemText(hwndDlg,BTN_34,H);
                        break;
                        case 35:
                                SetDlgItemText(hwndDlg,BTN_35,H);
                        break;
                        case 36:
                                SetDlgItemText(hwndDlg,BTN_36,H);
                        break;
                        case 37:
                                SetDlgItemText(hwndDlg,BTN_37,H);
                        break;
                        case 38:
                                SetDlgItemText(hwndDlg,BTN_38,H);
                        break;
                        case 39:
                                SetDlgItemText(hwndDlg,BTN_39,H);
                        break;
                        case 40:
                                SetDlgItemText(hwndDlg,BTN_40,H);
                        break;
                        case 41:
                                SetDlgItemText(hwndDlg,BTN_41,H);
                        break;
                        case 42:
                                SetDlgItemText(hwndDlg,BTN_42,H);
                        break;
                        case 43:
                                SetDlgItemText(hwndDlg,BTN_43,H);
                        break;
                        case 44:
                                SetDlgItemText(hwndDlg,BTN_44,H);
                        break;
                        case 45:
                                SetDlgItemText(hwndDlg,BTN_45,H);
                        break;
                        case 46:
                                SetDlgItemText(hwndDlg,BTN_46,H);
                        break;
                        case 47:
                                SetDlgItemText(hwndDlg,BTN_47,H);
                        break;
                        case 48:
                                SetDlgItemText(hwndDlg,BTN_48,H);
                        break;
        }
    }
}

int CalendarMes(HWND hwndDlg,int NumDias,int DIaInicio,bool AniO,int MeS,int M){
    int PosBOTTON=7;
    for(int DiaNum=1;DiaNum<=NumDias;){
        int i=0;
        if(DIaInicio>0){
                for(;0<DIaInicio;DIaInicio--){
                    if(AniO){
                        if(M==MeS){
                            PosBOTTON++;
                        }
                    }
                    i++;
                }
        }
        for(;i<7;i++){

            if(AniO){
                if(M==MeS){
                    int NUM=DiaNum;
                    char CADNum[3];
                    if(NUM%10==NUM){
                        CADNum[0]=(char)(NUM%10+48);
                        CADNum[1]='\0';
                    }else{
                        CADNum[1]=(char)(NUM%10+48);
                        CADNum[2]='\0';
                    }
                    if(NUM/10!=0){
                        CADNum[0]=(char)(NUM/10+48);
                    }
                    InCerTBOTTON(hwndDlg,PosBOTTON,CADNum);PosBOTTON++;
                }
            }
            DiaNum++;if(DiaNum>NumDias){
                i++;
                return i;
            }
        }
    }
}

int Meses(HWND hwndDlg,int diaIni,bool Bisiesto,bool AniO,int MeS){
    for(int i=1;i<=12;i++){
        switch(i){
            case 1:
                diaIni=CalendarMes(hwndDlg,31,diaIni,AniO,MeS,i);
            break;
            case 2:
                if(Bisiesto){
                    diaIni=CalendarMes(hwndDlg,29,diaIni,AniO,MeS,i);
                }else{
                    diaIni=CalendarMes(hwndDlg,28,diaIni,AniO,MeS,i);
                }
            break;
            case 3:
                diaIni=CalendarMes(hwndDlg,31,diaIni,AniO,MeS,i);
            break;
            case 4:
                diaIni=CalendarMes(hwndDlg,30,diaIni,AniO,MeS,i);
            break;
            case 5:
                diaIni=CalendarMes(hwndDlg,31,diaIni,AniO,MeS,i);
            break;
            case 6:
                diaIni=CalendarMes(hwndDlg,30,diaIni,AniO,MeS,i);
            break;
            case 7:
                diaIni=CalendarMes(hwndDlg,31,diaIni,AniO,MeS,i);
            break;
            case 8:
                diaIni=CalendarMes(hwndDlg,31,diaIni,AniO,MeS,i);
            break;
            case 9:
                diaIni=CalendarMes(hwndDlg,30,diaIni,AniO,MeS,i);
            break;
            case 10:
                diaIni=CalendarMes(hwndDlg,31,diaIni,AniO,MeS,i);
            break;
            case 11:
                diaIni=CalendarMes(hwndDlg,30,diaIni,AniO,MeS,i);
            break;
            case 12:
                diaIni=CalendarMes(hwndDlg,31,diaIni,AniO,MeS,i);
                return diaIni;
            break;
        }
    }
}

void Anios(HWND hwndDlg,int AniO,int MeS){
    for(long N=2019,DI=1;N<=AniO;N++){
        if(N%4==0){
            if(N==AniO){
                DI=Meses(hwndDlg,DI,1,1,MeS);
            }else{
                DI=Meses(hwndDlg,DI,1,0,MeS);
            }
        }else{
            if(N==AniO){
                DI=Meses(hwndDlg,DI,0,1,MeS);
            }else{
                DI=Meses(hwndDlg,DI,0,0,MeS);
            }
        }
    }
}

void PintarDia(HDC hdc,int PBOTS){
    for(int TT=7;TT<=48;TT++){
        switch(PBOTS){
            case 7:
                MoveToEx(hdc,20,117,NULL);
                LineTo(hdc,20+39,117);

                break;
            case 8:
                MoveToEx(hdc,66,117,NULL);
                LineTo(hdc,66+39,117);

                break;
            case 9:
                MoveToEx(hdc,112,117,NULL);
                LineTo(hdc,112+39,117);

                break;
            case 10:
                MoveToEx(hdc,158,117,NULL);
                LineTo(hdc,158+39,117);

                break;
            case 11:
                MoveToEx(hdc,204,117,NULL);
                LineTo(hdc,204+39,117);

                break;
            case 12:
                MoveToEx(hdc,250,117,NULL);
                LineTo(hdc,250+39,117);

                break;
            case 13:
                MoveToEx(hdc,296,117,NULL);
                LineTo(hdc,296+39,117);

                break;


            case 14:
                MoveToEx(hdc,20,153,NULL);
                LineTo(hdc,20+39,153);

                break;
            case 15:
                MoveToEx(hdc,66,153,NULL);
                LineTo(hdc,66+39,153);

                break;
            case 16:
                MoveToEx(hdc,112,153,NULL);
                LineTo(hdc,112+39,153);

                break;
            case 17:
                MoveToEx(hdc,158,153,NULL);
                LineTo(hdc,158+39,153);

                break;
            case 18:
                MoveToEx(hdc,204,153,NULL);
                LineTo(hdc,204+39,153);

                break;
            case 19:
                MoveToEx(hdc,250,153,NULL);
                LineTo(hdc,250+39,153);

                break;
            case 20:
                MoveToEx(hdc,296,153,NULL);
                LineTo(hdc,296+39,153);

                break;


            case 21:
                MoveToEx(hdc,20,189,NULL);
                LineTo(hdc,20+39,189);

                break;
            case 22:
                MoveToEx(hdc,66,189,NULL);
                LineTo(hdc,66+39,189);

                break;
            case 23:
                MoveToEx(hdc,112,189,NULL);
                LineTo(hdc,112+39,189);

                break;
            case 24:
                MoveToEx(hdc,158,189,NULL);
                LineTo(hdc,158+39,189);

                break;
            case 25:
                MoveToEx(hdc,204,189,NULL);
                LineTo(hdc,204+39,189);

                break;
            case 26:
                MoveToEx(hdc,250,189,NULL);
                LineTo(hdc,250+39,189);

                break;
            case 27:
                MoveToEx(hdc,296,189,NULL);
                LineTo(hdc,296+39,189);

                break;


            case 28:
                MoveToEx(hdc,20,225,NULL);
                LineTo(hdc,20+39,225);

                break;
            case 29:
                MoveToEx(hdc,66,225,NULL);
                LineTo(hdc,66+39,225);

                break;
            case 30:
                MoveToEx(hdc,112,225,NULL);
                LineTo(hdc,112+39,225);

                break;
            case 31:
                MoveToEx(hdc,158,225,NULL);
                LineTo(hdc,158+39,225);

                break;
            case 32:
                MoveToEx(hdc,204,225,NULL);
                LineTo(hdc,204+39,225);

                break;
            case 33:
                MoveToEx(hdc,250,225,NULL);
                LineTo(hdc,250+39,225);

                break;
            case 34:
                MoveToEx(hdc,296,225,NULL);
                LineTo(hdc,296+39,225);

                break;


            case 35:
                MoveToEx(hdc,20,261,NULL);
                LineTo(hdc,20+39,261);

                break;
            case 36:
                MoveToEx(hdc,66,261,NULL);
                LineTo(hdc,66+39,261);

                break;
            case 37:
                MoveToEx(hdc,112,261,NULL);
                LineTo(hdc,112+39,261);

                break;
            case 38:
                MoveToEx(hdc,158,261,NULL);
                LineTo(hdc,158+39,261);

                break;
            case 39:
                MoveToEx(hdc,204,261,NULL);
                LineTo(hdc,204+39,261);

                break;
            case 40:
                MoveToEx(hdc,250,261,NULL);
                LineTo(hdc,250+39,261);

                break;
            case 41:
                MoveToEx(hdc,296,261,NULL);
                LineTo(hdc,296+39,261);

                break;


            case 42:
                MoveToEx(hdc,20,297,NULL);
                LineTo(hdc,20+39,297);

                break;
            case 43:
                MoveToEx(hdc,66,297,NULL);
                LineTo(hdc,66+39,297);

                break;
            case 44:
                MoveToEx(hdc,112,297,NULL);
                LineTo(hdc,112+39,297);

                break;
            case 45:
                MoveToEx(hdc,158,297,NULL);
                LineTo(hdc,158+39,297);

                break;
            case 46:
                MoveToEx(hdc,204,297,NULL);
                LineTo(hdc,204+39,297);

                break;
            case 47:
                MoveToEx(hdc,250,297,NULL);
                LineTo(hdc,250+39,297);

                break;
            case 48:
                MoveToEx(hdc,296,297,NULL);
                LineTo(hdc,296+39,297);

                break;

        }
    }
}




BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    switch(uMsg)
    {
    case WM_PAINT:
        {   HDC hdc;
            PAINTSTRUCT ps;
            hdc=BeginPaint(hwndDlg,&ps);
            greenPen=CreatePen(PS_SOLID, 2, RGB(51, 204, 255));
            SelectObject(hdc,greenPen);

            brush=CreateSolidBrush(RGB(0, 0, 0));
            SelectObject(hdc,brush);
            Rectangle(hdc,5,5,355,310);
            DeleteObject(brush);

            greenPen=CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
            SelectObject(hdc,greenPen);
            /// 7 - 48
            PintarDia(hdc,10);
            DeleteObject(greenPen);

            EndPaint(hwndDlg,&ps);
        }
        case WM_INITDIALOG:
        {
        }
        return TRUE;

        case WM_CLOSE:
        {   EndDialog(hwndDlg, 0);
        }
        return TRUE;

        case WM_COMMAND:
        {   switch(LOWORD(wParam))
            {
                case BTN_1:
                    cout<<"\n";

                    cout<<"\n";
                    InvalidateRect(hwndDlg,NULL,true);
                    return TRUE;
                case BTN_INSERTAR:
                    char Cad0[50],Cad1[10],Cad2[10];
                    int Anio,Mes;
                    GetDlgItemText(hwndDlg,EDIT0,Cad0,50);
                    GetDlgItemText(hwndDlg,EDIT1,Cad1,10);
                    GetDlgItemText(hwndDlg,EDIT2,Cad2,10);
                    Anio=atoi(Cad1);
                    Mes=atoi(Cad2);
                    if(Mes>0&&Mes<=12){
                        cout<<Cad0<<" "<<Anio<<" "<<Mes<<"\n";
                    }
                    Limpiar(hwndDlg);
                    Anios(hwndDlg,Anio,Mes);

                    InvalidateRect(hwndDlg,NULL,true);
                    return TRUE;
                /*case BTN_BUSCAR:
                    char Cad1[20];
                    int Num1;
                    GetDlgItemText(hwndDlg,EDIT2,Cad1,10);//capturar evento
                    Num1=atoi(Cad1);
                    cout<<" Buscando: "<<Num1<<endl;

                    if(valor==1){
                        SetDlgItemText(hwndDlg,EDIT0,"ENCONTRADO");
                    }else{
                        SetDlgItemText(hwndDlg,EDIT0,"NO ENCONTRADO");
                        valor2=-1;
                    }valor=0;
                    SetDlgItemText(hwndDlg,EDIT2,"");
                    InvalidateRect(hwndDlg,NULL,true);
                    return TRUE;
                case BTN_ELIMINAR:
                    char *Y;Y = (char *) malloc(30);
                    GetDlgItemText(hwndDlg,EDIT3,Y,30);
                    int nume=0,i,NuD=1;
                    for(i=0;*(Y+i)!=NULL;i++);
                    for(int Mp=i,j=0;Mp>0;Mp--,j++){
                        for(int O=1;O<Mp;O++){
                            NuD=NuD*10;
                        }
                        nume+=(int)((int(*(Y+j))-48)*NuD);
                        NuD=1;
                    }

                    SetDlgItemText(hwndDlg,EDIT0,"ELIMINADO");
                    cout<<" Eliminado: "<<nume<<endl;
                    SetDlgItemText(hwndDlg,EDIT3,"");
                    InvalidateRect(hwndDlg,NULL,true);
                    return TRUE;*/
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
