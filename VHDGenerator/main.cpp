#include <iostream>
#include "VHDG.h"
#include "GenerateC.h"

using namespace std;

#define GetSize(array_enteros) (sizeof(array_enteros)/sizeof(*(array_enteros)))

ObjMenu Main[] =
{
    {'1', "Crear elemento basico"},
    {'2', "Crear proyecto predisenado"},
    {'3', "Variables del proyecto"}
};



int main()
{
    string Name;
    GetNameComponent(Name);
    cout << Name;
    //int Main_Length = GetSize(Main);
    //MainMenu(Main, Main_Length);
    //GetMainMenu();
    return 0;
}
