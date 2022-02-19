#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <conio.h>
#include <string.h>
#include <fstream>
bool BUSQPER=0;float RETVALOR=0,RETTOTAL=0,PROMEDIO=0;int CANTPERSO=0;
using namespace std;
class NODOLIST_FUN{
    public:
    string NOMBRE,COSA;
    float VALOR;
    NODOLIST_FUN *der,*PaDr;
    NODOLIST_FUN(string NOM="\0",string COS="\0",float VALO=0,NODOLIST_FUN *Padr=NULL,NODOLIST_FUN *de=NULL){
         NOMBRE=NOM;
         COSA=COS;
         VALOR=VALO;
         der=de;
         PaDr=Padr;
    }
};
class LISTA_FUN{
    public:

    NODOLIST_FUN *raiz,*padr;

    LISTA_FUN(){
        raiz=NULL;
        padr=NULL;
    }
    void InsertarLIST(string NOM,string COS,float VALO){
         ins(NOM,COS,VALO,raiz,padr);
    }
    void ins(string NOM,string COS,float VALO,NODOLIST_FUN *&R,NODOLIST_FUN *padr){
         if(R==NULL)
            R=new NODOLIST_FUN(NOM,COS,VALO,padr);
         else
            ins(NOM,COS,VALO,R->der,R);
    }

    void MostrarLIST(){
         Mos(raiz);
    }
    void Mos(NODOLIST_FUN *R){
         if(R!=NULL){
            cout<<R->NOMBRE<<" ";
            cout<<R->COSA<<" ";
            cout<<R->VALOR<<"\n";
            Mos(R->der);
         }
    }

    float BuscarLIST(string dat){
         Bus(raiz,dat);
    }
    float Bus(NODOLIST_FUN *R,string val){
         RETVALOR=0;
         if(R!=NULL){
            Bus(R->der,val);
            if(R->NOMBRE==val){
                int i;
                cout<<R->NOMBRE<<" ";
                for(i=0;R->NOMBRE[i];i++);
                for(;i<14;i++){
                    cout<<" ";
                }

                cout<<R->COSA<<" ";
                for(i=0;R->COSA[i];i++);
                for(;i<20;i++){
                    cout<<" ";
                }
                cout<<R->VALOR<<"\n";


                RETVALOR+=R->VALOR;
            }
         }
    }
}DATOSESTRUC;
///LISTA
class NODO_PERSONA{
    public:
    string NOMBRE;
    float VALOR;
    NODO_PERSONA *der;
    NODO_PERSONA(string NOM="\0",float VALO=0,NODO_PERSONA *de=NULL){
         NOMBRE=NOM;
         VALOR=VALO;
         der=de;
    }
};

class LISTA_PER{
    public:

    NODO_PERSONA *raiz;

    LISTA_PER(){
        raiz=NULL;
    }
    void InsertarLIST(string NOM,float VALO){
         ins(NOM,VALO,raiz);
    }
    void ins(string NOM,float VALO,NODO_PERSONA *&R){
         if(R==NULL)
            R=new NODO_PERSONA(NOM,VALO);
         else
            ins(NOM,VALO,R->der);
    }

    void MostrarLIST(){
         Mos(raiz);
    }
    void Mos(NODO_PERSONA *R){
         if(R!=NULL){
            cout<<R->NOMBRE<<" ";
            cout<<R->VALOR<<"\n";
            Mos(R->der);
         }
    }

    void SINODEUDA(){
         SNO(raiz);
    }
    void SNO(NODO_PERSONA *R){
         if(R!=NULL){
            int i;
            cout<<R->NOMBRE<<" ";
            for(i=0;R->NOMBRE[i];i++);
            for(;i<15;i++){
                cout<<" ";
            }
            cout<<R->VALOR<<"\n";

            if(R->VALOR<PROMEDIO){
                cout<<"DEBE:\t\t"<<PROMEDIO-R->VALOR;
            }else{
                cout<<"LE FALTA:\t"<<R->VALOR-PROMEDIO;
            }

            cout<<"\n\n";

            SNO(R->der);
         }
    }

    void TOTAL_LIST(){
         TOT(raiz);
    }
    void TOT(NODO_PERSONA *R){
         if(R!=NULL){
            CANTPERSO++;
            RETTOTAL+=R->VALOR;
            TOT(R->der);
         }
    }

    void SacarPRECIO(){
         SPRES(raiz);
    }
    void SPRES(NODO_PERSONA *R){
         if(R!=NULL){
            DATOSESTRUC.BuscarLIST(R->NOMBRE);

            R->VALOR=RETVALOR;
            SPRES(R->der);
         }
    }

    void BuscarLIST(string dat){
         Bus(raiz,dat);
    }
    void Bus(NODO_PERSONA *R,string val){
         BUSQPER=0;
         if(R!=NULL){

            Bus(R->der,val);
            if(R->NOMBRE==val){
                BUSQPER=1;
            }
         }
    }
}DATOSPRECIO;

///SELECCIONA Y SEPARA
int Separar(char *CadINI){

    int i,j,ESPACIO=0;
    char *cad;

    for(i=0;*(CadINI+i)!=NULL;i++);
    cad=new char[i+100];
    for(i=0,j=0;*(CadINI+i)!=NULL;i++){
        if(*(CadINI+i)!=' '&&i==0){
            *(cad+0)='*';j++;
        }
        if(*(CadINI+i)=='-'){
            *(cad+j)='*';j++;
        }else{
            *(cad+j)=*(CadINI+i);j++;
        }
    }*(cad+j)='\0';

    char **CAD_FINAL;
    int NC=0,NP=0,in=0,fin=0;
    for(i=0;*(cad+i);i++){
        if(*(cad+i)=='*'){NP++;}
    }
    CAD_FINAL=new char*[NP+15];
    NP=0;

    for(i=0;*(cad+i)!=NULL;i++){
        if(*(cad+i)=='*'&&*(cad+i+1)!='*'){
            int pl;in=i+1;
            for(fin=in;*(cad+fin)!='*'&&*(cad+fin)!=NULL;fin++){NC++;}

            CAD_FINAL[NP]=new char[NC+15];

            for(pl=0;in<fin;in++,pl++){
                *(*(CAD_FINAL+NP)+pl)=*(cad+in);
            }

            *(*(CAD_FINAL+NP)+pl)='\0';
            NP++;NC=0;
        }
    }

    for(i=0;i<NP;i++){

        float NUM1;
        NUM1=atof(*(CAD_FINAL+i+2));

        DATOSPRECIO.BuscarLIST(*(CAD_FINAL+i));
        if(BUSQPER==0){
            DATOSPRECIO.InsertarLIST(*(CAD_FINAL+i),NUM1);
        }

        DATOSESTRUC.InsertarLIST(*(CAD_FINAL+i),*(CAD_FINAL+i+1),NUM1);
        i+=2;
    }
    return 0;

    ///DATOS SEPARADOS

}

int main(){

    fstream ficheroEntrada;
    string frase;

    int Num_FILA=1;
    char CAD[1000];

    ficheroEntrada.open ("DEUDAS.txt",ios::in);
    if (ficheroEntrada.is_open()) {
        while (! ficheroEntrada.eof() ) {

            getline(ficheroEntrada,frase);
            strcpy(CAD,frase.c_str());

            Separar(CAD);
        }
        ficheroEntrada.close();
    }
    else{
        cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;
    }
    cout<<"\t\t LISTA\n\n";
    DATOSPRECIO.SacarPRECIO();
    cout<<"\n\n\n";

    DATOSPRECIO.TOTAL_LIST();
    PROMEDIO=RETTOTAL/CANTPERSO;

    cout<<"SUMA TOTAL:        "<<RETTOTAL
        <<"\nCANTIDAD PERSONAS: "<<CANTPERSO
        <<"\nPROMEDIO:          "<<PROMEDIO;

    cout<<"\n\n\n\n\n";

    DATOSPRECIO.SINODEUDA();

    system("PAUSE");
    return 0;
}
