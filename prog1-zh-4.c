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
    char line[100];

    FILE *file_to_red = fopen("be.txt", "r");
    int sum = 0;
    char name[30];

    while(fgets(line, 100, file_to_red) != NULL)
    {
        line[strlen(line) - 1] = '\0'; // sor végi new line '\n' helyettesítése '\0'-val (=string end)

        char *token;
        token = strtok(line, ";"); // Neptun-kód (nem kell)
        token = strtok(NULL, ";"); // Név
        strcpy(name, token);

        while((token = strtok(NULL, ";")) != NULL)
        {
            sum += atoi(token);
        }
        
        printf("%s összpontszám: %d\n", name, sum);

        sum = 0;
    }
    return 0;
}