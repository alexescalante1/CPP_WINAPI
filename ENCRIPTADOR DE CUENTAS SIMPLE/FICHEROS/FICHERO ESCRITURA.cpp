#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
using namespace std;
int main()
{

    ofstream salida;salida.open("RESULTADO.txt");

    salida<<"HOLA MUNDO"<<"\n";

    return 0;
}
