
#include <dirent.h>
#include <string>
#include <cstring>

/* Funci�n para devolver un error en caso de que ocurra */
void error(const char *s);
/* Funci�n que hace algo con un archivo */
void procesoArchivo(char *archivo);


int main()
{
  /* Con un puntero a DIR abriremos el directorio */
  DIR *dir;
  /* en *ent habr� informaci�n sobre el archivo que se est� "sacando" a cada momento */
  dirent *ent;
  /* Empezaremos a leer en el directorio actual */
  dir = opendir (".");

  /* Miramos que no haya error */
  if (dir == NULL)
    error("No puedo abrir el directorio");

  /* Una vez nos aseguramos de que no hay error, �vamos a jugar! */
  /* Leyendo uno a uno todos los archivos que hay */
  while ((ent = readdir (dir)) != NULL)
    {
      /* Nos devolver� el directorio actual (.) y el anterior (..), como hace ls */
      if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0) )
    {
      /* Una vez tenemos el archivo, lo pasamos a una funci�n para procesarlo. */
      procesoArchivo(ent->d_name);
    }
    }
  closedir (dir);

  getwchar();

  return EXIT_SUCCESS;
}

void error(const char *s)
{
  /* perror() devuelve la cadena S y el error (en cadena de caracteres) que tenga errno */
  perror (s);
  exit(EXIT_FAILURE);
}

void procesoArchivo(char *archivo)
{
  /* Para "procesar", o al menos, hacer algo con el archivo, vamos a decir su tama�o en bytes */
  /* para ello haremos lo que vemos aqu�: https://poesiabinaria.net/2010/04/tamano-de-un-fichero-en-c/ */
  FILE *fich;
  long ftam;

  fich=fopen(archivo, "r");
  if (fich)
    {
      fseek(fich, 0L, SEEK_END);
      ftam=ftell(fich);
      fclose(fich);
      /* Si todo va bien, decimos el tama�o */
      printf ("%20s (%ld bytes)\n", archivo, ftam);
    }
  else
    /* Si ha pasado algo, s�lo decimos el nombre */
    printf ("%30s (No info.)\n", archivo);
}
