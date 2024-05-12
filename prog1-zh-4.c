/*
4.
Írjon eljárást, amely a be.txt fájlból legfeljebb 100 karaktert tartalmazó sorokat olvas be
állományvégjelig (EOF). Mindegyik sor egy-egy hallgató Neptun-kódját és nevét, valamint
az ebben a félévben a Magas szintű programozási nyelvek 1 című tárgyból a
számonkéréseken szerzett pontszámait tartalmazza, az adatokat egy-egy pontosvesszővel
választva el egymástól. A program soronként írja a standard kimenetre a hallgatók nevét és az
egy-egy hallgató által megszerzett pontok összegét! Egy lehetséges példa bemenet a
következő:
ABCDEF;Gipsz Jakab;1;0;2;2;0;3;4;0;5;5;0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int sum = 0;
    
    char *line_from_file = calloc(100, sizeof(char));
    if (line_from_file == NULL)
    {
        return 1;
    }

    char *name = calloc(30, sizeof(char));
    if (name == NULL)
    {
        return 1;
    }

    FILE *file_to_read = fopen("be.txt", "r");
    if (file_to_read == NULL)
    {
        return 1;
    }

    while(fgets(line_from_file, 100, file_to_read) != NULL)
    {
        // sor végi new line '\n' helyettesítése '\0'-val (=string end):
        line_from_file[strlen(line_from_file) - 1] = '\0';

        // input tokenizálása ";" szerint:
        char *token;
        token = strtok(line_from_file, ";"); // Neptun-kód (nem kell)
        token = strtok(NULL, ";"); // Név
        strcpy(name, token);

        sum = 0;
        while((token = strtok(NULL, ";")) != NULL)
        {
            sum += atoi(token);
        }
        
        printf("%s, összpontszám: %d\n", name, sum);
    }

    free(name);
    free(line_from_file);
    fclose(file_to_read);

    return 0;
}