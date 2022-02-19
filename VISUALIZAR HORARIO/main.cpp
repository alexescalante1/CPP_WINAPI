#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"
#include <iostream>
#include <ctime>
#include <vector>
HINSTANCE hInst;

using namespace std;
int NSEMANA=1;
bool ONE=1;
int HDCRECTANGLE=8;
HBRUSH brushBlack;
HBRUSH brushWhite;
HPEN greenPen;

char AUX_CAD[65];void CONCATENAR(string CAD,bool B){
    int i = 0;
    if(B){
//        for(;ENTRADA_C[i];i++);
//        ENTRADA_C[i]=CAD[0];
//        ENTRADA_C[i+1]='\0';
    }else{
        for(;AUX_CAD[i];i++);
        AUX_CAD[i]=CAD[0];
        AUX_CAD[i+1]='\0';
    }
}

void CONCATENAR_S(string CAD,bool B){
    int i = 0;
    if(B){
//        for(;ENTRADA_C[i];i++);
//        ENTRADA_C[i]=CAD[0];
//        ENTRADA_C[i+1]='\0';
    }else{
        for(;*(AUX_CAD+i);i++);
        for(int j=0;CAD[j];j++,i++){
            *(AUX_CAD+i)=CAD[j];
        }
        *(AUX_CAD+i)='\0';
    }
}

string CONVERSOR_INT_A_STRING(int M){
    char C[6];int N=M;
    int i = 0;for(;N>9;N/=10,i++);C[i+1]='\0';
    while(M>9){
         C[i]=(char)(M%10+48);
         M/=10;i--;
    }
    if(M<10){
        C[0]=(char)(M+48);
    }else{
        C[i]=(char)(M+48);
    }
    return C;
}


class NODO_DIAS{
    public:
    int POS[6];
    NODO_DIAS *SIGUIENTE;
    NODO_DIAS(int *P = NULL,NODO_DIAS *SIG=NULL){
        POS[0]=P[0];
        POS[1]=P[1];
        POS[2]=P[2];
        POS[3]=P[3];
        POS[4]=P[4];
        POS[5]=P[5];
        SIGUIENTE=SIG;
    }
};

class INTERCALADO{
    public:
    NODO_DIAS *Raiz;
    INTERCALADO(){
        Raiz = NULL;
    }
    void INSERTAR(int *POS){
        INS(POS,Raiz);
    }
    void INS(int *POS, NODO_DIAS *&R){
        if(R){
            INS(POS,R->SIGUIENTE);
        }else{
            R = new NODO_DIAS(POS);
        }
    }
    int Mostrar(int DIA_ACT,int MES_ACT,HWND hwndDlg){
        return MOS(Raiz,DIA_ACT,MES_ACT,hwndDlg);
    }
    int MOS(NODO_DIAS *R,int DIA_ACT,int MES_ACT,HWND hwndDlg){

        while(R){
            if(DIA_ACT>=R->POS[0]&&DIA_ACT<=R->POS[2]){
                if(MES_ACT>=R->POS[1]&&MES_ACT<=R->POS[3]){

                    CONCATENAR_S("SEMANA: ",0);
                    CONCATENAR_S(CONVERSOR_INT_A_STRING(R->POS[5]),0);
//                    for(int i=0;[i];i++){
//                        CONCATENAR(&CONVERSOR_INT_A_STRING(R->POS[5])[i],0);
//                    }
                    SetDlgItemText(hwndDlg,ESTADO1,AUX_CAD);AUX_CAD[0]='\0';
                    return R->POS[4];
                }
            }
            R=R->SIGUIENTE;
        }
        return 3;
    }

}I;

void INSERTAR_HORARIO(int a,int b,int c,int d,int e){
    int DIAS_INTER[5];
    DIAS_INTER[0]=a;DIAS_INTER[1]=b;DIAS_INTER[2]=c;DIAS_INTER[3]=d;DIAS_INTER[4]=e;DIAS_INTER[5]=NSEMANA;NSEMANA++;
    I.INSERTAR(DIAS_INTER);
}

class NODO_HORARIO{
    public:
    int Xx,Yy;
    NODO_HORARIO *SIGUIENTE;
    NODO_HORARIO(int x=0,int y=0,NODO_HORARIO *SIG=NULL){
        Xx=x;
        Yy=y;
        SIGUIENTE=SIG;
    }
};

class HORARIO{
    public:
    NODO_HORARIO *Raiz;
    HORARIO(){
        Raiz = NULL;
    }
    void INSERTAR(int x,int y){
        INS(x,y,Raiz);
    }
    void INS(int x,int y, NODO_HORARIO *&R){
        if(R){
            INS(x,y,R->SIGUIENTE);
        }else{
            R = new NODO_HORARIO(x,y);
        }
    }
    void Mostrar(string CURSO,HWND hwndDlg){
        MOS(Raiz,CURSO,hwndDlg);
    }
    void MOS(NODO_HORARIO *R,string CURSO,HWND hwndDlg){

        while(R){
            if(R->Xx==0&&R->Yy==0){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID00,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==1&&R->Yy==0){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID10,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==2&&R->Yy==0){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID20,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==3&&R->Yy==0){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID30,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==4&&R->Yy==0){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID40,AUX_CAD);AUX_CAD[0]='\0';
            }



            if(R->Xx==0&&R->Yy==1){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID01,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==1&&R->Yy==1){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID11,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==2&&R->Yy==1){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID21,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==3&&R->Yy==1){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID31,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==4&&R->Yy==1){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID41,AUX_CAD);AUX_CAD[0]='\0';
            }


            if(R->Xx==0&&R->Yy==2){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID02,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==1&&R->Yy==2){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID12,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==2&&R->Yy==2){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID22,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==3&&R->Yy==2){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID32,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==4&&R->Yy==2){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID42,AUX_CAD);AUX_CAD[0]='\0';
            }


            if(R->Xx==0&&R->Yy==3){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID03,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==1&&R->Yy==3){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID13,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==2&&R->Yy==3){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID23,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==3&&R->Yy==3){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID33,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==4&&R->Yy==3){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID43,AUX_CAD);AUX_CAD[0]='\0';
            }


            if(R->Xx==0&&R->Yy==4){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID04,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==1&&R->Yy==4){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID14,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==2&&R->Yy==4){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID24,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==3&&R->Yy==4){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID34,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==4&&R->Yy==4){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID44,AUX_CAD);AUX_CAD[0]='\0';
            }


            if(R->Xx==0&&R->Yy==5){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID05,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==1&&R->Yy==5){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID15,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==2&&R->Yy==5){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID25,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==3&&R->Yy==5){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID35,AUX_CAD);AUX_CAD[0]='\0';
            }
            if(R->Xx==4&&R->Yy==5){
                for(int i=0;CURSO[i];i++){CONCATENAR(&CURSO[i],0);}
                SetDlgItemText(hwndDlg,ID45,AUX_CAD);AUX_CAD[0]='\0';
            }

//            cout<<"\n         "<<R->Xx<<R->Yy<<"\n";
            R=R->SIGUIENTE;
        }
    }

};

class NODO{
    public:
    string CURSO;
    int id;
    NODO *SIGUIENTE;
    HORARIO HORAS;
    NODO(string CUR="",int i=0,NODO *SIG=NULL){
        CURSO=CUR;
        id=i;
        SIGUIENTE=SIG;
    }
};

class CURSOS{
    public:
    NODO *Raiz;
    CURSOS(){
        Raiz = NULL;
    }
    void INSERTAR(string CURSO,int id){
        INS(CURSO,id,Raiz);
    }
    void INS(string CURSO,int id, NODO *&R){
        if(R){
            INS(CURSO,id,R->SIGUIENTE);
        }else{
            R = new NODO(CURSO,id);
        }
    }
    void INSERTAR_HORA(string CURSO, int x, int y){
        INST_H(CURSO,x,y,Raiz);
    }
    void INST_H(string CURSO, int x, int y, NODO *R){
        while(R){
            if(R->CURSO==CURSO){
                R->HORAS.INSERTAR(x,y);
                break;
            }
            R=R->SIGUIENTE;
        }
    }
    bool Mostrar(int VAL,HWND hwndDlg){
        return MOS(Raiz,VAL,hwndDlg);
    }
    bool MOS(NODO *R,int VAL,HWND hwndDlg){

        while(R){
            if(R->id==VAL){
//                cout<<R->CURSO<<" Id: "<<R->id<<"\n";
                R->HORAS.Mostrar(R->CURSO,hwndDlg);
            }
            R=R->SIGUIENTE;
        }
        return 0;
    }

}C;

void INSERTAR_HORAS(string Curso,int x,int y){
    C.INSERTAR_HORA(Curso,x,y);
}

void SEMANA_ACT(HWND hwndDlg){
    time_t now = time(0);
    tm *time = localtime(&now);
    int ANIO = 1900+time->tm_year;

    vector<string> Dias;
    Dias.push_back("DOMINGO");
    Dias.push_back("LUNES");
    Dias.push_back("MARTES");
    Dias.push_back("MIERCOLES");
    Dias.push_back("JUEVES");
    Dias.push_back("VIERNES");
    Dias.push_back("SABADO");
    vector<string> Mes;
    Mes.push_back("ENERO");
    Mes.push_back("FEBRERO");
    Mes.push_back("MARZO");
    Mes.push_back("ABRIL");
    Mes.push_back("MAYO");
    Mes.push_back("JUNIO");
    Mes.push_back("JULIO");
    Mes.push_back("AGOSTO");
    Mes.push_back("SEPTIEMBRE");
    Mes.push_back("OCTUBRE");
    Mes.push_back("NOVIEMBRE");
    Mes.push_back("DICIEMBRE");

    CONCATENAR_S("HOY ES ",0);
    for(int i=0;Dias[time->tm_wday][i];i++){
        CONCATENAR(&Dias[time->tm_wday][i],0);
    }
    CONCATENAR_S(" ",0);
    for(int i=0;CONVERSOR_INT_A_STRING(time->tm_mday)[i];i++){
        CONCATENAR(&CONVERSOR_INT_A_STRING(time->tm_mday)[i],0);
    }
    CONCATENAR_S(" DE ",0);
    for(int i=0;Mes[time->tm_mon][i];i++){
        CONCATENAR(&Mes[time->tm_mon][i],0);
    }
    CONCATENAR_S(" DEL ",0);
    for(int i=0;CONVERSOR_INT_A_STRING(ANIO)[i];i++){
        CONCATENAR(&CONVERSOR_INT_A_STRING(ANIO)[i],0);
    }
    CONCATENAR_S(", ",0);
    for(int i=0;CONVERSOR_INT_A_STRING(time->tm_hour)[i];i++){
        CONCATENAR(&CONVERSOR_INT_A_STRING(time->tm_hour)[i],0);
    }
    CONCATENAR(":",0);
    for(int i=0;CONVERSOR_INT_A_STRING(time->tm_min)[i];i++){
        CONCATENAR(&CONVERSOR_INT_A_STRING(time->tm_min)[i],0);
    }
    CONCATENAR(":",0);
    for(int i=0;CONVERSOR_INT_A_STRING(time->tm_sec)[i];i++){
        CONCATENAR(&CONVERSOR_INT_A_STRING(time->tm_sec)[i],0);
    }

    SetDlgItemText(hwndDlg,ESTADO2,AUX_CAD);AUX_CAD[0]='\0';
    C.Mostrar(I.Mostrar(time->tm_mday,time->tm_mon+1,hwndDlg),hwndDlg);
}

void INIT()
{
    ///INSERTAR SEMANAS
    INSERTAR_HORARIO(1,6,5,6,1);
    INSERTAR_HORARIO(8,6,12,6,0);
    INSERTAR_HORARIO(15,6,19,6,1);
    INSERTAR_HORARIO(22,6,26,6,0);

    INSERTAR_HORARIO(29,6,3,7,1);
    INSERTAR_HORARIO(6,7,10,7,0);
    INSERTAR_HORARIO(13,7,17,7,1);
    INSERTAR_HORARIO(20,7,24,7,0);
    INSERTAR_HORARIO(27,7,31,7,1);

    INSERTAR_HORARIO(3,8,7,8,0);
    INSERTAR_HORARIO(10,8,14,8,1);
    INSERTAR_HORARIO(17,8,21,8,0);
    INSERTAR_HORARIO(24,8,28,8,1);

    INSERTAR_HORARIO(31,8,4,9,0);
    INSERTAR_HORARIO(7,9,11,9,1);
    INSERTAR_HORARIO(14,9,18,9,0);
    INSERTAR_HORARIO(21,9,25,9,1);
    INSERTAR_HORARIO(28,9,2,10,0);
    ///INSERTAR SEMANAS



    ///INSERTAR CURSOS
    C.INSERTAR("PROGRAMACION",0);
    C.INSERTAR("SIMULACION",1);
    C.INSERTAR("PARALELISMO",1);
    C.INSERTAR("REDACCION",0);
    C.INSERTAR("INTELIGENCIA",1);
    C.INSERTAR("ANALISIS",1);
    C.INSERTAR("AUDITORIA",0);
    ///INSERTAR CURSOS


    ///INSERTAR HORAS
    INSERTAR_HORAS("PARALELISMO",0,3);
    INSERTAR_HORAS("PARALELISMO",2,4);
    INSERTAR_HORAS("PARALELISMO",4,3);

    INSERTAR_HORAS("PROGRAMACION",0,4);
    INSERTAR_HORAS("PROGRAMACION",4,4);

    INSERTAR_HORAS("SIMULACION",0,5);
    INSERTAR_HORAS("SIMULACION",4,5);

    INSERTAR_HORAS("REDACCION",1,3);
    INSERTAR_HORAS("REDACCION",3,3);

    INSERTAR_HORAS("INTELIGENCIA",1,4);
    INSERTAR_HORAS("INTELIGENCIA",2,5);

    INSERTAR_HORAS("AUDITORIA",1,5);
    INSERTAR_HORAS("AUDITORIA",3,5);

    INSERTAR_HORAS("ANALISIS",2,3);
    INSERTAR_HORAS("ANALISIS",3,4);
    ///INSERTAR HORAS

}

void VISUAL_DESING(HDC hdc){
        brushBlack=CreateSolidBrush(RGB(0, 0, 0));
        brushWhite=CreateSolidBrush(RGB(255, 255, 255));
        greenPen=CreatePen(PS_SOLID, 2, RGB(51, 204, 255));

        SelectObject(hdc,brushBlack);
        Rectangle(hdc,-5,-5,1400,800);
        DeleteObject(brushBlack);

        SelectObject(hdc,greenPen);
        SelectObject(hdc,brushWhite);

        switch(HDCRECTANGLE){
            case 8://CUENTA MOD
                Rectangle(hdc,10,10,1250,580);
                break;
        }
        for(int i=80;i<1200;i+=233){
            MoveToEx(hdc,i,77,NULL);
            LineTo(hdc,i,580);
        }
        for(int i=77;i<550;i+=70){
            MoveToEx(hdc,10,i,NULL);
            LineTo(hdc,1250,i);
        }



        DeleteObject(brushWhite);
        DeleteObject(greenPen);
}

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_PAINT:
        {   HDC hdc;
            PAINTSTRUCT ps;
            hdc=BeginPaint(hwndDlg,&ps);

            VISUAL_DESING(hdc);

            EndPaint(hwndDlg,&ps);
        }
    case WM_INITDIALOG:
    {
        if(ONE){ONE=0;
            INIT();
            SEMANA_ACT(hwndDlg);
        }
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
    return DialogBox(hInst, MAKEINTRESOURCE(HORARIO_DG), NULL, (DLGPROC)DlgMain);
}
