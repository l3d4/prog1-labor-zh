/*
3. Számjegyek duplikálása (végjelig olvasás) - P105204t

A függvény:
Írj egy double_digits nevű függényt, 
mely visszaadja azt a stringet, melyet a paraméterként megkapott string számjegyeinek megkettözésével kapunk!
Paraméterlista
1. original - az eredeti string (egy legalább 1, legfeljebb 30 karakter hosszúságú string)
Visszaadott érték
• az átalakított string
Példák
original                        Visszaadott ertek
"abcdefghijkImnopqrstuvwxyz"    "abcdefghijklmnopqrstuvwxyz"
"ABCDEFGHIJKLMNOPORSTUVWXYZ"    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"|
"0123456789"                    "00112233445566778899"
"a-b•c-d-e-f•gh"                "a-b-c-d-e•f-g-h"
"aA......bB"                    "aA.....-bB"
"A-•a•....b.. •B"               "A••a•....b..•B"
"aB1CD2eF3gH4"                  "aB11CD22eF33gH44"
A paraméterekhez tartozó literálokban minden ' ' (szóköz) karakter a *• ' (pont) karakterrel kerül helyettesítésre.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void double_digits(char*, char*);

int main()
{
    int line_length = 30;
    char* original = calloc(line_length, sizeof(char));
    char* result = calloc(2 * line_length, sizeof(char));

    printf("Bemenet:\n");
    fgets(original, line_length, stdin);

    double_digits(original, result);

    printf("Az átalakított sztring:\n%s\n", result);

    free(original);
    free(result);

    return 0;
}

void double_digits(char* original, char* result) {
    int length = strlen(original);
    int idx = 0; // másolás során helyiérték nyomon követése az új tömbben

    for (int i = 0; i<length; i++) {
        if (isdigit(original[i])) {
            result[idx++] = original[i];
            result[idx++] = original[i];
        } else {
            result[idx++] =original[i];
        }
    }
    result[idx] = '\0';
}