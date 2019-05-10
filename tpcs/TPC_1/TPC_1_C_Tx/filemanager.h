#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <stdio.h>
#include <string.h>
#include "hexformat.h"

#define DOS_CIFRAS(suma) suma > 0xff ?(char) suma : suma //TODO: unused
#define VALIDAR_CANT_CARACTERES(i, size) (unsigned long long) i < size
#define INCREMENTAR(value) ((value + 1) > 15) ? 0 : value + 1

/**
 * @brief createMyFile Simply creates a file with 14 zeroes and
 * 2 more values with 89 at the end
 * @param filePath
 */
void createMyFile (char filePath[])
{
    char value[16] = "0000000000000089";

    FILE *file = fopen(filePath, "w");

    for( int i = 0; (unsigned long long) i < sizeof(value); i++ )
    {
        fprintf( file, "%x", convertToHexValues(value[i]) );
    }

    fclose(file);

    puts("Archivo Creado!");
}

/**
 * @brief readMyFile Read the file and increment it's value, also adds an
 * addition of each value + 0x89
 * @param filePath
 */
void readMyFile (char filePath[])
{
    FILE *file = fopen(filePath, "r+");
    char ch, readValue[16], key[3];
    unsigned short suma = 0x89; //137
    int i = 0, k = 0;

    while( (ch = (char) fgetc(file)) != EOF )
    {
        if( VALIDAR_CANT_CARACTERES(i, sizeof(readValue) - 2) )
        {
            // storing my values in a char array
            sprintf(&readValue[i], "%c", convertToHexValues(ch));
            i++;
        }
        else if ( VALIDAR_CANT_CARACTERES(i, sizeof(readValue)) )
        {
            // unused: storing my key values
            sprintf(&key[k], "%c", convertToHexValues(ch));
            k++;
        }
    }
    rewind(file);

    i--;
    while( i >= 0 ) // Incremento el valor
    {

        if( (readValue[i]+1) < 16 )
        {
            readValue[i] = INCREMENTAR(readValue[i]);
            break;
        }
        readValue[i] = INCREMENTAR(readValue[i]);
        i--;
    }

    // conversion de cada valor de char
    for ( i=0; (unsigned long long) i < sizeof(readValue)-2; i++ )
    {
        fprintf(file, "%x", readValue[i]);
        suma += convertToHexValues(readValue[i]);
    }
    fprintf(file, "%x", suma);

    fclose(file);

    puts("Valor modificado\n");
    puts("Nuevo valor: ");
    for ( i=0; (unsigned long long) i < sizeof(readValue)-2; i++ )
    {
        printf("%x", readValue[i]);
    }
    printf("%x", suma);

    puts("\n\n");

}

#endif // FILEMANAGER_H
