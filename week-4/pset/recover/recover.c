#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // El argumento de la linea de comando debe ser igual a 2.
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    // Leer el archivo.
    FILE *input_file = fopen(argv[1], "r");

    // Abrir el archivo para verificar si es valido.
    if (input_file == NULL)
    {
        printf("Error");
        return 2;
    }

    // Contador que se inicia en 0.
    int img_count = 0;

    // Guardar bloques de 512 Bytes en un array.
    unsigned char buffer[512];

    // Creo un Pointer a las imagenes recuperadas.
    FILE  *output_file = NULL;

    char *filename = malloc(8 * sizeof(char));

    // Leer los bloques de 512 BYTES.
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        // Verificar si es un JEPG.
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Verifico si hay un archivo anterior abierto y, en tal caso lo cierro.
            if (img_count > 0)
            {
                fclose(output_file);
            }

            sprintf(filename, "%03i.jpg", img_count);

            output_file = fopen(filename, "w");

            // Incrementar el contador.
            img_count ++;
        }
        // Verificar si el output ha sido utilizado.
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}