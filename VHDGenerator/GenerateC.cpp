
#include <iostream>
#include <dirent.h>
#include <string>
#include <cstring>

using namespace std;
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
    /* Contatenamos con la extencion */
    Compo = (Compo + ".cpp");
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

void NewOpenArch()
{

}

void headGenerate()
{

}

void Generate_Counter(int time, bool secons)
{

}
