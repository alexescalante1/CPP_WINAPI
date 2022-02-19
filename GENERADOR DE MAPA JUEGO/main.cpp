#include <iostream>
#include <windowsx.h>
#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <cmath>
#include "resource.h"

using namespace std;

HINSTANCE hInst;
HBRUSH brush;
HPEN greenPen;
COLORREF COLOR;

bool ONE = 1;
string HEX="J",HEY="A";
string DIRECCIONES[8] = {"IZQUIERDA","DERECHA","ARRIBA","ABAJO"
                        ,"IZQUIERDA-ABAJO","IZQUIERDA-ARRIBA"
                        ,"DERECHA-ABAJO","DERECHA-ARRIBA"};

class NODO;
class EDITORDEMAPA;

void DIBUJAR_PUNTOS(HDC,double,double,int);
void DIBUJAR_UNION_PUNTOS(HDC,double,double,double,double,int);
void DIBUJAR_TABLA_COORD(HDC);

int CONVERTIR_STRING_A_CHAR(string H,char **CAD){int TAM=0,i=0;
    for(;H[TAM];TAM++);TAM+=1;
    *CAD = new char [TAM];
    for(;H[i];i++){
        *(*(CAD)+i) = H[i];
    }*(*(CAD)+i) = '\0';
    return i;
}

int CONCATENAR(string A,string B,char **R){int TAM=0,i=0;
    for(;A[TAM];TAM++);
    for(;B[i];i++,TAM++);TAM+=1;
    *R = new char [TAM];TAM=0;
    for(i=0;A[i];i++,TAM++){
        *(*(R)+TAM)=A[i];
    }
    for(i=0;B[i];i++,TAM++){
        *(*(R)+TAM)=B[i];
    }*(*(R)+TAM) = '\0';
    return TAM;
}

int CONVERTIR_DOUBLE_A_CAD(char **R,double DOBL,int PFLOAT){int NINT=0,DECI=0,i=0,TAM=0,DFLOAT=1;
    NINT=DOBL;for(;PFLOAT;PFLOAT--){DFLOAT*=10;}
    if(NINT==0){*R = new char [2];*(*(R)+0)='0';*(*(R)+1)='\0';return 1;}
    DECI=(DOBL-NINT)*DFLOAT;
    for(int AUX=NINT;AUX!=0;i++,AUX/=10);
    for(int AUX=DECI;AUX!=0;i++,AUX/=10);i+=1;
    *R = new char [i];TAM=i;*(*(R)+i)='\0';i-=1;
    for(;DECI;i--,DECI/=10){
        *(*(R)+i)=(char)(DECI%10+48);
    }*(*(R)+i)='.';i-=1;
    for(;NINT;i--,NINT/=10){
        *(*(R)+i)=(char)(NINT%10+48);
    }
    return TAM;
}

class NODO{
    public:
    int PX,PY;
    NODO *SIG,*DR[8];

    NODO(int x,int y){
        PX  = x;
        PY  = y;
        SIG = NULL;
        for(int i=0;i<8;i++){
            DR[i] = NULL;
        }
    }
};

class EDITORDEMAPA{
    public:
    NODO *RAIZ;
    EDITORDEMAPA(){
        RAIZ=NULL;
    }
    void INSERTAR_NODO(double x,double y){
        INS(x,y,RAIZ);
    }
    void INS(double x,double y,NODO *&R){
        if(R){
            INS(x,y,R->SIG);
        }else{
            R = new NODO(x,y);
        }
    }

    void ENLAZARNODOS(int xa,int ya,int xb,int yb){
        cout<<"("<<xa<<","<<ya<<");("<<xb<<","<<yb<<")\n";
        if(xa!=xb||ya!=yb){
            if(ya==yb){
                if(xa<xb){
                    cout<<"DERECHA\n";
                    ENLACE(xa,ya,xb,yb,1);
                    ENLACE(xb,yb,xa,ya,0);
                }else{
                    cout<<"IZQUIERDA\n";
                    ENLACE(xa,ya,xb,yb,0);
                    ENLACE(xb,yb,xa,ya,1);
                }
            }
            if(xa==xb){
                if(ya<yb){
                    cout<<"ARRIBA\n";
                    ENLACE(xa,ya,xb,yb,2);
                    ENLACE(xb,yb,xa,ya,3);
                }else{
                    cout<<"ABAJO\n";
                    ENLACE(xa,ya,xb,yb,3);
                    ENLACE(xb,yb,xa,ya,2);
                }
            }
            if(xa<xb&&ya<yb){
                cout<<"DERECHA-ARRIBA\n";
                ENLACE(xa,ya,xb,yb,7);
                ENLACE(xb,yb,xa,ya,4);
            }
            if(xa>xb&&ya>yb){
                cout<<"IZQUIERDA-ABAJO\n";
                ENLACE(xa,ya,xb,yb,4);
                ENLACE(xb,yb,xa,ya,7);
            }
            if(xa>xb&&ya<yb){
                cout<<"IZQUIERDA-ARRIBA\n";
                ENLACE(xa,ya,xb,yb,5);
                ENLACE(xb,yb,xa,ya,6);
            }
            if(xa<xb&&ya>yb){
                cout<<"DERECHA-ABAJO\n";
                ENLACE(xa,ya,xb,yb,6);
                ENLACE(xb,yb,xa,ya,5);
            }
        }else{
            cout<<"PUNTO INMUTADO\n";
        }
    }

    void ENLACE(int xa,int ya,int xb,int yb,int DIR){
        E(RAIZ,xa,ya,xb,yb,DIR);
    }
    void E(NODO *R,int xa,int ya,int xb,int yb,int DIR){
        while(R){
            if(R->PX==xa&&R->PY==ya){
                F(RAIZ,xb,yb,R,DIR);
                break;
            }
            R=R->SIG;
        }
    }
    void F(NODO *R,int xb,int yb,NODO *S,int DIR){
        while(R){
            if(R->PX==xb&&R->PY==yb){
                if(!S->DR[DIR]){
                    S->DR[DIR] = R;
                }
                return;
            }
            R=R->SIG;
        }
    }

    void MOSTRAR_LINEAS(HDC hdc){
        ML(RAIZ,hdc);
    }

    void ML(NODO *R,HDC hdc){
        while(R){
            for(int i=0;i<8;i++){
                if(R->DR[i]){
                    DIBUJAR_UNION_PUNTOS(hdc,R->PX,R->PY,R->DR[i]->PX,R->DR[i]->PY,2);
                }
            }
            DIBUJAR_PUNTOS(hdc,R->PX,R->PY,1);
            R=R->SIG;
        }
    }

    bool BUSCAR(int BX,int BY){
//        cout<<"BUSCANDO ("<<BX<<","<<BY<<"): ";
        return BSC(RAIZ,BX,BY);
    }
    bool BSC(NODO *R,int BX,int BY){
        while(R){
            if(R->PX==BX&&R->PY==BY){
                for(int i=0;i<8;i++){
                    if(R->DR[i]){
                    cout<<DIRECCIONES[i]<<" ";
                    }
                }
                return 1;
            }
            R=R->SIG;
        }return 0;
    }

    int MOSTRARNODOS(){
        return MOSN(RAIZ);
    }
    int MOSN(NODO *R){int CONT = 0;
        while(R){
            cout<<":("<<R->PX<<","<<R->PY<<")\n";
            R=R->SIG;CONT++;
        }return CONT;
    }

}A;

void CREARGRANJA(int LX,int LY,int V){
    if(!A.BUSCAR(LX,LY)){
        A.INSERTAR_NODO(LX,LY);
    }
    for(int i = 1; i< V;i++){
        A.INSERTAR_NODO(LX,LY-i);
        A.INSERTAR_NODO(LX+i,LY-i);
        A.INSERTAR_NODO(LX-i,LY-i);

        A.ENLAZARNODOS(LX,LY-i,LX+i,LY-i);
        A.ENLAZARNODOS(LX,LY-i,LX-i,LY-i);
    }
    if(A.BUSCAR(LX,LY)){
        A.ENLAZARNODOS(LX,LY,LX,LY-1);
        A.ENLAZARNODOS(LX,LY,LX+1,LY-1);
        A.ENLAZARNODOS(LX,LY,LX-1,LY-1);
    }
    for(int i = 2; i< V;i++){
        A.ENLAZARNODOS(LX,LY-i,LX,LY-i+1);
        A.ENLAZARNODOS(LX+i,LY-i,LX+i-1,LY-i+1);
        A.ENLAZARNODOS(LX-i,LY-i,LX-i+1,LY-i+1);
    }
}

int VERIFICAR_C_NODOS(int LX,int LY){int CONT = 0;
    if(A.BUSCAR(LX,LY))    {CONT++;}
    if(A.BUSCAR(LX,LY+1))  {CONT++;}
    if(A.BUSCAR(LX,LY-1))  {CONT++;}
    if(A.BUSCAR(LX+1,LY))  {CONT++;}
    if(A.BUSCAR(LX-1,LY))  {CONT++;}
    if(A.BUSCAR(LX-1,LY-1)){CONT++;}
    if(A.BUSCAR(LX-1,LY+1)){CONT++;}
    if(A.BUSCAR(LX+1,LY-1)){CONT++;}
    if(A.BUSCAR(LX+1,LY+1)){CONT++;}
    if(CONT>3){
        return 0;
    }else{
        return 1;
    }
}

void CREARPISTA(int LX,int LY){

//    if(VERIFICAR_C_NODOS(LX,LY)){

        A.INSERTAR_NODO(LX,LY);

        if(!A.BUSCAR(LX,LY+1)){A.INSERTAR_NODO(LX,LY+1);}
        if(!A.BUSCAR(LX,LY-1)){A.INSERTAR_NODO(LX,LY-1);}
        if(!A.BUSCAR(LX+1,LY)){A.INSERTAR_NODO(LX+1,LY);}
        if(!A.BUSCAR(LX-1,LY)){A.INSERTAR_NODO(LX-1,LY);}

        if(!A.BUSCAR(LX-1,LY-1)){A.INSERTAR_NODO(LX-1,LY-1);}
        if(!A.BUSCAR(LX-1,LY+1)){A.INSERTAR_NODO(LX-1,LY+1);}
        if(!A.BUSCAR(LX+1,LY-1)){A.INSERTAR_NODO(LX+1,LY-1);}
        if(!A.BUSCAR(LX+1,LY+1)){A.INSERTAR_NODO(LX+1,LY+1);}

        A.ENLAZARNODOS(LX-1,LY-1,LX,LY-1);
        A.ENLAZARNODOS(LX+1,LY-1,LX,LY-1);
        A.ENLAZARNODOS(LX,LY+1,LX+1,LY+1);
        A.ENLAZARNODOS(LX,LY+1,LX-1,LY+1);
        A.ENLAZARNODOS(LX,LY,LX+1,LY);
        A.ENLAZARNODOS(LX,LY,LX-1,LY);

        A.ENLAZARNODOS(LX,LY,LX,LY-1);
        A.ENLAZARNODOS(LX,LY,LX,LY+1);
        A.ENLAZARNODOS(LX+1,LY,LX+1,LY+1);
        A.ENLAZARNODOS(LX+1,LY,LX+1,LY-1);
        A.ENLAZARNODOS(LX-1,LY,LX-1,LY+1);
        A.ENLAZARNODOS(LX-1,LY,LX-1,LY-1);

        A.ENLAZARNODOS(LX,LY,LX-1,LY-1);
        A.ENLAZARNODOS(LX,LY,LX+1,LY+1);
        A.ENLAZARNODOS(LX,LY,LX-1,LY+1);
        A.ENLAZARNODOS(LX,LY,LX+1,LY-1);

//    }else{
//        cout<<"\nERROR, OBSTRUCCION DE NODOS\n";
//        return 0;
//    }
//    return 1;
}

int INICIALIZACION(){

    CREARPISTA(2,4);
    CREARPISTA(4,4);

    CREARPISTA(2,6);
    CREARPISTA(4,6);

    CREARGRANJA(3,3,3);

    cout<<"\n\n";
    A.BUSCAR(3,5);
//    cout<<"\nCANTIDA DE NODOS: "<<A.MOSTRARNODOS();
    return 0;
}

///GRAFICA

void DIBUJAR_PUNTOS(HDC hdc,double X,double Y,int COLOR){                     ///GRAFICAR PUNTOS
    if(COLOR==0){greenPen=CreatePen(PS_SOLID, 5, RGB(255, 0, 0));}
    else if(COLOR==1){greenPen=CreatePen(PS_SOLID, 5, RGB(255, 255, 0));}
    else if(COLOR==2){greenPen=CreatePen(PS_SOLID, 7, RGB(0, 0, 255));}
    else{
       greenPen=CreatePen(PS_SOLID, 10, RGB(255, 255, 255));
    }
    /// x 250-1190
    /// y 10-625

    X*=20;
    Y*=-20;

    SelectObject(hdc,greenPen);
    MoveToEx(hdc,10+X,625+Y,NULL);
    LineTo(hdc,10+X,625+Y);
    DeleteObject(greenPen);
}

void DIBUJAR_UNION_PUNTOS(HDC hdc,double X_INI,double Y_INI,double X,double Y,int COLOR){                     ///GRAFICAR PUNTOS
    if(COLOR==0){greenPen=CreatePen(PS_SOLID, 2, RGB(255, 0, 0));}
    else if(COLOR==1){greenPen=CreatePen(PS_SOLID, 2, RGB(255, 255, 0));}
    else if(COLOR==2){greenPen=CreatePen(PS_SOLID, 1, RGB(255, 255, 255));}
    else if(COLOR==4){greenPen=CreatePen(PS_SOLID, 15, RGB(255, 255, 255));}
    else{
       greenPen=CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
    }
    /// x 250-1190
    /// y 10-625

    X*=20;
    Y*=-20;
    X_INI*=20;
    Y_INI*=-20;

    SelectObject(hdc,greenPen);
    MoveToEx(hdc,10+X_INI,625+Y_INI,NULL);
    LineTo(hdc,10+X,625+Y);
    DeleteObject(greenPen);
}

void DIBUJAR_TABLA_COORD(HDC hdc){                                  ///GRAFICAR LINEAS TABLA
    for(int i=30,j=0;j<46;j++,i+=20){
        MoveToEx(hdc,i,10,NULL);
        LineTo(hdc,i,625);
    }
    for(int i=605,j=0;j<30;j++,i-=20){
        MoveToEx(hdc,10,i,NULL);
        LineTo(hdc,950,i);
    }
}

void Visual(HDC hdc){
    SetBkMode(hdc, TRANSPARENT);
    greenPen=CreatePen(PS_SOLID, 1, RGB(70, 70, 70));
    SelectObject(hdc,greenPen);

    brush=CreateSolidBrush(RGB(67, 68, 70));    ///FONDO
    SelectObject(hdc,brush);
    Rectangle(hdc,-1,-1,1000,1000);


    brush=CreateSolidBrush(RGB(0, 0, 0));       ///COORDENADAS
    SelectObject(hdc,brush);
    Rectangle(hdc,10,10,950,625);

    DIBUJAR_TABLA_COORD(hdc);

    greenPen=CreatePen(PS_SOLID, 1, RGB(51, 204, 255));
    SelectObject(hdc,greenPen);
    brush=CreateSolidBrush(RGB(255, 255, 255)); ///L IZQUIERDO
    SelectObject(hdc,brush);
    Rectangle(hdc,10,10,950,105);

    DeleteObject(brush);
    DeleteObject(greenPen);
}

///GRAFICA
BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
        if(ONE){ONE=0;
            INICIALIZACION();
        }
    }
    return TRUE;
    case WM_PAINT:
        {
            HDC hdc;
            PAINTSTRUCT ps;
            hdc=BeginPaint(hwndDlg,&ps);

            Visual(hdc);

            A.MOSTRAR_LINEAS(hdc);

            EndPaint(hwndDlg,&ps);
        }
    return TRUE;
    case WM_LBUTTONDOWN:
        {
            double xPos = GET_X_LPARAM(lParam)+10;
            double yPos = GET_Y_LPARAM(lParam)-5;
            if(xPos<950&&xPos>10&&yPos<625&&yPos>10){

//                A.INSERTAR_NODO(((xPos-10)/20),31-((yPos-10)/20));
                CREARPISTA(((xPos-10)/20),31-((yPos-10)/20));

                SetDlgItemText(hwndDlg,EDIT1,"INCERTADO");
                InvalidateRect(hwndDlg,NULL,true);
            }
        }
    return TRUE;
    case WM_MOUSEMOVE:
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
            char CADE1[10],CADE2[10];int Numx,Numy;

            case BTN_INSERTAR:

                GetDlgItemText(hwndDlg,EDITX,CADE1,10);//capturar evento
                GetDlgItemText(hwndDlg,EDITY,CADE2,10);
                Numx=atof(CADE1);
                Numy=atof(CADE2);

                if(Numx>0&&Numx<47&&Numy>0&&Numy<31){

//                    A.INSERTAR_NODO(Numx,Numy);

                    SetDlgItemText(hwndDlg,EDITX,"");
                    SetDlgItemText(hwndDlg,EDITY,"");
                    SetDlgItemText(hwndDlg,EDIT1,"INCERTADO");
                    InvalidateRect(hwndDlg,NULL,true);
                }else{
                    SetDlgItemText(hwndDlg,EDIT1,"LIM EXEDIDO");
                }
            return TRUE;
            case BTN_ENLAZAR:
                GetDlgItemText(hwndDlg,EDITE1,CADE1,10);//capturar evento
                GetDlgItemText(hwndDlg,EDITE2,CADE2,10);
//
//                A.ENLACE(CADE1,CADE2);
//                A.ENLACE(CADE2,CADE1);
                SetDlgItemText(hwndDlg,EDITE1,"");
                SetDlgItemText(hwndDlg,EDITE2,"");
                SetDlgItemText(hwndDlg,EDIT1,"INCERTADO");
                InvalidateRect(hwndDlg,NULL,true);

            return TRUE;
            case BTN_CALCULAR:
                GetDlgItemText(hwndDlg,EDITEE1,CADE1,10);//capturar evento
                GetDlgItemText(hwndDlg,EDITEE2,CADE2,10);
                HEX = CADE2;
                HEY = CADE1;
                SetDlgItemText(hwndDlg,EDITEE1,"");
                SetDlgItemText(hwndDlg,EDITEE2,"");
                InvalidateRect(hwndDlg,NULL,true);
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
