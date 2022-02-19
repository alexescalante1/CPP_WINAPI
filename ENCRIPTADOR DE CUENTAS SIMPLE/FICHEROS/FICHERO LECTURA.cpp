#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
using namespace std;

bool CREAR_APP(string LINEA, int *i){

        for(int j = *i; LINEA[j] != '\0' ; j++){

            if(LINEA[j]=='$'&&LINEA[j+1]=='$'&&LINEA[j+2]=='$'){*i=j=j+3;cout<<"\n";return 1;}

            if(LINEA[j]=='<'&&LINEA[j+1]=='>'){*i=j=j+2;cout<<"\n";

                for(; LINEA[j] != '\0';j++){

                    if(LINEA[j]=='<'&&LINEA[j+1]=='>'){*i=j=j-1;break;}
                    if(LINEA[j]=='$'&&LINEA[j+1]=='$'&&LINEA[j+2]=='$'){*i=j=j+3;cout<<"\n";return 1;}
                    cout << LINEA[j];

                }
            }else{

                cout << LINEA[j];

            }

        }cout<<endl;
        return 1;
}

bool CREAR_CUENTA(string LINEA, int *i){

        for(int j = *i; LINEA[j] != '\0' ; j++){

            if(LINEA[j]=='$'&&LINEA[j+1]=='$'&&LINEA[j+2]=='$'){*i=j=j+3;cout<<"\n";return 1;}

            if(LINEA[j]=='<'&&LINEA[j+1]=='>'){*i=j=j+2;cout<<"\n=";

                for(; LINEA[j] != '\0' ; j++){

                    if(LINEA[j]=='<'&&LINEA[j+1]=='>'){*i=j=j-1;break;}
                    if(LINEA[j]=='$'&&LINEA[j+1]=='$'&&LINEA[j+2]=='$'){*i=j=j+3;cout<<"\n";return 1;}
                    cout << LINEA[j];

                }
            }else{

                cout << LINEA[j];

            }

        }cout<<endl;
        return 1;
}

bool INTERPRETE(string LINEA){

    for(int i = 0 ;LINEA[i];i++){ ///AVANZA TODA LA CADENA
        if(LINEA[i]==':'&&LINEA[i+1]==':'&&LINEA[i+2]==':'){i+=3;
            cout<<">"<<LINEA[i]<<"\n";
            if(CREAR_APP(LINEA,&i)){
                 return 1;
            }
        }
        if(LINEA[i]=='@'&&LINEA[i+1]=='@'&&LINEA[i+2]=='@'){i+=3;
            cout<<">"<<LINEA[i]<<"\n";
            if(CREAR_CUENTA(LINEA,&i)){
                 return 1;
            }
        }
    }
    return 0;
}

void LEER_DATOS(){
    string LINEA;

    ifstream MI_ARCHIVO ("RESULTADO.txt");
    if (MI_ARCHIVO.is_open())
    {
        while ( getline (MI_ARCHIVO,LINEA) )
        {
          INTERPRETE(LINEA);cout<<"\n\n";
        }
        MI_ARCHIVO.close();
    }
}

int main()
{
    string M = ":::facebook<>red social<>www.facebook.com$$$@@@1<>alexescalanteONE<>sonie2020$$$";
    cout<<M<<endl;
    //INTERPRETE(M);
    LEER_DATOS();
    return 0;
}
