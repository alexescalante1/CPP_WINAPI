#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
using namespace std;

string INS_AP[3];
string INS_CT[15];

void INSERTA_AP(){
    cout<<INS_AP[0]<<"\n"
        <<INS_AP[1]<<"\n"
        <<INS_AP[2]<<"\n";
}
void INSERTA_CT(){
    cout<<INS_AP[0]<<"\n"
        <<INS_CT[1]<<"\n"
        <<INS_CT[2]<<"\n"
        <<INS_CT[3]<<"\n"
        <<INS_CT[4]<<"\n"
        <<INS_CT[5]<<"\n"
        <<INS_CT[6]<<"\n"
        <<INS_CT[7]<<"\n"
        <<INS_CT[8]<<"\n"
        <<INS_CT[9]<<"\n"
        <<INS_CT[10]<<"\n"
        <<INS_CT[11]<<"\n"
        <<INS_CT[12]<<"\n"
        <<INS_CT[13]<<"\n"
        <<INS_CT[14]<<"\n";
}

char AUX_CAD[65];void CONCATENAR(string CAD){
    int i = 0;for(;AUX_CAD[i];i++);
    AUX_CAD[i]=CAD[0];
    AUX_CAD[i+1]='\0';
}

bool CREAR_APP(string LINEA, int *i){
    int POSITION=0;
    for(int j = *i; LINEA[j] != '\0' ; j++){

        if(LINEA[j]=='<'&&LINEA[j+1]=='>'){*i=j=j+2;

            INS_AP[POSITION] = AUX_CAD;
            AUX_CAD[0]='\0';POSITION++;

            for(; LINEA[j] != '\0';j++){

                if(LINEA[j]=='<'&&LINEA[j+1]=='>'){*i=j=j-1;break;}
                if(LINEA[j]=='$'&&LINEA[j+1]=='$'&&LINEA[j+2]=='$'){*i=j=j+3;
                    INS_AP[POSITION] = AUX_CAD;
                    AUX_CAD[0]='\0';
                    return 1;
                }

                CONCATENAR(&LINEA[j]);

            }
        }else{

            CONCATENAR(&LINEA[j]);

        }

    }
    return 1;
}

bool CREAR_CUENTA(string LINEA, int *i){
    int POSITION=0;
    for(int j = *i; LINEA[j] != '\0' ; j++){

        if(LINEA[j]=='<'&&LINEA[j+1]=='>'){*i=j=j+2;

            INS_CT[POSITION] = AUX_CAD;
            AUX_CAD[0]='\0';POSITION++;

            for(; LINEA[j] != '\0' ; j++){

                if(LINEA[j]=='<'&&LINEA[j+1]=='>'){*i=j=j-1;break;}
                if(LINEA[j]=='$'&&LINEA[j+1]=='$'&&LINEA[j+2]=='$'){*i=j=j+3;
                    INS_CT[POSITION] = AUX_CAD;
                    AUX_CAD[0]='\0';
                    return 1;
                }

                CONCATENAR(&LINEA[j]);

            }
        }else{

            CONCATENAR(&LINEA[j]);

        }

    }
    return 1;
}

void INTERPRETE(string LINEA){

    for(int i = 0 ;LINEA[i];i++){ ///AVANZA TODA LA CADENA

        if(LINEA[i]==':'&&LINEA[i+1]==':'&&LINEA[i+2]==':'){i+=3;

            CREAR_APP(LINEA,&i);
            INSERTA_AP();

        }
        if(LINEA[i]=='@'&&LINEA[i+1]=='@'&&LINEA[i+2]=='@'){i+=3;

            CREAR_CUENTA(LINEA,&i);
            INSERTA_CT();

        }
    }
}

void LEER_DATOS(){
    string LINEA;

    ifstream MI_ARCHIVO ("RESULTADO.txt");
    if (MI_ARCHIVO.is_open())
    {
        while ( getline (MI_ARCHIVO,LINEA) )
        {
          INTERPRETE(LINEA);

          cout<<"\n";
        }
        MI_ARCHIVO.close();
    }
}

int main()
{
    //INTERPRETE(M);
    LEER_DATOS();
    return 0;
}
