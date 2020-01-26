#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "GenerateC.h"

#define GetSize(array_enteros) (sizeof(array_enteros)/sizeof(*(array_enteros)))

using namespace std;

//ObjMenu busca ser una estructura para
//describir los elementos de un menu y submenu

struct ObjMenu
{
    char number;
    string name;

};

ObjMenu Basic_Components[] =
{
    {'1', "Contador"},
    {'2', "Full adder"}
};

ObjMenu Vars_Perfil[] =
{
    {'1', "Autor-es"},
    {'2', "Nombre proyecto"},
    {'3', "Nombre institucion"}
};

void Generate_spacer(int n) //Genera un separador estetico de -----
{
    cout << "    ";
    for (int i = 0 ;i < n ;i++ )
    {
        cout << "-";
    }
}

void Spacer(int n) //Genera saltos de linea
{
    for (int i = 0 ;i < n ;i++ )
    {
        cout << endl;
    }
}

void GS(int n)//Abreviacion de Generate_spacer
{
    Generate_spacer(n);
}

void S(int n)//Abreviacion de Spacer
{
    Spacer(n);
}

void MainMenu(ObjMenu a[], int length)
{
    cout << "\tVHDGenerate";
    S(3);
    GS(40);
    S(3);
    for (int i = 0 ;i < length ;i++ )
    {
        cout << "\t" << a[i].number << ".  " << a[i].name << endl;
    }
    S(2);
    GS(40);
    S(3);

}

void GetMainMenu()
{
    cout << "    Ingrese una de las opciones: ";
    char opc = getch();
    cout << opc << endl << endl;
    cout << "\tSe selecciono la opccion " << opc;

    Sleep(2000);
    system("clear");

    switch (opc)
    {
    case '1':
        MainMenu(Basic_Components, GetSize(Basic_Components));
        break;
    case '2':
        cout << "Opcion en construccion";
        break;
    case '3':
        MainMenu(Vars_Perfil, GetSize(Vars_Perfil));
        break;
    default:
        cout << "Opcion invalida";
        break;
    }
}
