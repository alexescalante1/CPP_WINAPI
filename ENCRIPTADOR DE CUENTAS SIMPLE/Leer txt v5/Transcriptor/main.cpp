#include <iostream>
#include <fstream>

using namespace std;

void SEPARADOR_CARACTER(string CAD,ofstream *COMPRIMIDO){

    for(int i=0,R=0;CAD[i];i++){
        if(CAD[i]==' '&&R==0){
         cout<<" ";R=1;
         *COMPRIMIDO<<" ";
        }
        if(CAD[i]=='"'){
         cout<<(char)34<<"<<(char)34<<"<<(char)34;
         *COMPRIMIDO<<(char)34<<"<<(char)34<<"<<(char)34;
        }
        if(CAD[i]!=' '&&CAD[i]!='"'){
            cout<<CAD[i];R=0;
            *COMPRIMIDO<<CAD[i];
        }
    }


}

int main()
{
    string LII;
    ofstream COMPRIMIDO("Comprimido.html");
    ifstream MY_ENCRIPTT ("01.DESENCRIPTADOR DE CUENTA.html");
    cout<<"*SALIDA_HTML<<"<<(char)34;
    COMPRIMIDO<<"*SALIDA_HTML<<"<<(char)34;
    if (MY_ENCRIPTT.is_open())
    {
        while ( getline (MY_ENCRIPTT,LII) )
        {
          SEPARADOR_CARACTER(LII,&COMPRIMIDO);
        }
        MY_ENCRIPTT.close();
    }
    cout<<(char)34<<";\n";
    COMPRIMIDO<<(char)34<<";\n";

    COMPRIMIDO.close();
    return 0;
}
