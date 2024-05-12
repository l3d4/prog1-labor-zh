/*
Minta ZH
1. Írjunk egy programot, amely beolvas a standard benetről egy 10 elemű pozitív egész
számokat tartalmazó tömböt és megkeresi, majd kiírja a tömb azon elemeit, melyek
egyenlőek számjegyeik köbének összegével.
A programnak kötelezően kell tartalmaznia egy függvényt, amely paraméterként kap
egy egész számot, és igazzal tért tér vissza, ha a paraméterként átadott szám egyenlő a
számjegyeinek köbének összegével:
int szamjegyek_kobenek_osszege(int szam)
A program ezen kívül más függvényeket is tartalmazhat.
Példa bemenet:
0 1 8 27 153 201 370 371 419 1632
Kimenet:
0 1 153 370 371
*/

#include <stdio.h>
#include <stdlib.h>

int szamjegyek_kobenek_osszege(int);

int main()
{
    int size_of_array = 10;
    int* numbers = calloc(size_of_array, sizeof(int));
    
    printf("Kérem adjon meg %d pozitív egész számot:\n", size_of_array);
    
    for (int i = 0; i < size_of_array; i++)
    {
        scanf("%d", &numbers[i]);
        if (numbers[i] < 0)
        {
            printf("Csak pozitív számot adjon meg.\n");
            printf("Kérem adjon meg 10 pozitív egész számot:\n");
            i = 0;
        }
    }

    for (int i = 0; i < size_of_array; i++)
    {
        if (szamjegyek_kobenek_osszege(numbers[i]))
        {
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");

    free(numbers);

    return 0;
}

int szamjegyek_kobenek_osszege(int szam)
{
    int true_or_false = 0;
    int sum = 0;
    int number = szam;

    while (number != 0)
    {
        int digit = number % 10;
        sum = sum + digit * digit * digit;
        number /= 10;
    }
    
    if (sum == szam)
    {
        true_or_false = 1;
    }

    return true_or_false;
}
