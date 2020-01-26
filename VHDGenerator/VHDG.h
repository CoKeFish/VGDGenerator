
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct ObjMenu
{
    char number;
    string name;
};

void MainMenu(ObjMenu a[], int length); //Encargado de generar el menu principal
void GetMainMenu();
void GS(int n); //Genera un separador horizontal
void S(int n); //Genera un salto de linea
