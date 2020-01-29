
#include <iostream>
#include <dirent.h>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

void headGenerate(ofstream &archivo);


void error(const char *s)
{
    /* perror() devuelve la cadena S y el error (en cadena de caracteres) que tenga errno */
    perror (s);
    exit(EXIT_FAILURE);
}

bool checkFilesExist(string Chain)
{
    /* Con un puntero a DIR abriremos el directorio */
    DIR *dir;
    /* en *ent habrá información sobre el archivo que se está "sacando" a cada momento */
    dirent *ent;
    /* Empezaremos a leer en el directorio actual */
    dir = opendir (".");

    /* Miramos que no haya error */
    if (dir == NULL)
        error("No puedo abrir el directorio");

    /* Una vez nos aseguramos de que no hay error, ¡vamos a jugar! */
    /* Leyendo uno a uno todos los archivos que hay */
    while ((ent = readdir (dir)) != NULL)
    {
        /* Nos devolverá el directorio actual (.) y el anterior (..), como hace ls */
        string ConverstringDir = ent->d_name, ConverstringChain = Chain;
        if (ConverstringDir == ConverstringChain)
        {
            return false;
        }
    }
    /* Cerramos el archivo abierto anteriormente */
    closedir (dir);
    return true;
}

bool GetNameComponent(string &Name)
{
    /* Obtenemos el nombre del usuario */
    string Compo;
    getline(cin, Compo);
    /* Concatenamos con la extencion */
    Compo = (Compo + ".vhd");
    /* Devolvemos 1 si se ha obtenido correctamente el nombre */
    if(checkFilesExist(Compo))
    {
        Name = Compo;
        return true;
    }
        return true;
    return false;
}

void ConfProgram()
{

}

void NewOpenArch(ofstream &archivo)
{
    string Name;

    if(GetNameComponent(Name))
        archivo.open(Name, ios::out);
}

void mainGen()
{
    ofstream archivo;
    NewOpenArch(archivo);
    headGenerate(archivo);
    archivo.close();
}

void headGenerate(ofstream &archivo)
{
    archivo << endl;
    archivo << "--******************************************************--" << endl;
    archivo << "--        PONTIFICIA UNIVERSIDAD JAVERIANA              --" << endl;
    archivo << "--                Disegno Digital                       --" << endl;
    archivo << "--              PROYECTO CAJA FUERTE                    --" << endl;
    archivo << "-- 							                            --" << endl;
    archivo << "-- Titulo :    Sumador Decimal digito		            --" << endl;
    archivo << "-- Fecha  :  	D:01 M:10 Y:2019                        --" << endl;
    archivo << "--******************************************************--" << endl;
}

void Generate_Counter(int time, bool secons)
{

}
