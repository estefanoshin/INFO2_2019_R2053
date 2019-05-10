#include <stdlib.h>
#include "filemanager.h"

#define FILE_PATH "/home/oem/test_file"

int main()
{
    char input = 0;

    while(input != '3')
    {
        if( input != 0x0A )
        {
            puts("      1_Crear un archivo \n           ");
            puts("      2_Leer el archivo \n            ");
            puts("      3_ Salir\n                      ");
            puts("      Seleccione alguna opcion: "      );
            scanf("%c", &input);
        }
        else
        {
            input = 0;
            scanf("%c", &input);
        }

        if( input == '1' )
        {
            system("clear");
            createMyFile(FILE_PATH);
        }

        else if( input == '2' )
        {
            system("clear");
            readMyFile(FILE_PATH);
        }

        else if ( input == '3' )
        {
            return 0;
        }
    }

}
