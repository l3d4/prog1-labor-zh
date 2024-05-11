/*
2. Keressük meg és írjuk ki az első n darab Fibonacci-szám közül a legnagyobb páros
számot. Az n értékét a standard inputról olvassuk be.
Útmutatás:
A Fibonacci-számokat az alábbi rekurzív összefüggéssel definiáljuk:
F0 = 0, F1 = 1, Fi = Fi–1 + Fi–2, ahol i >= 2 (*)
Minden Fibonacci-szám tehát a megelőző kettőnek az összege (kivétel az első kettő,
amelyek adottak).
A Fibonacci-számok sorozata: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, …
*/

#include <stdio.h>
#include <stdlib.h>

int* crt_fib_arr(int n)
{
    int* fib_arr = calloc(n, sizeof(n));
    
    fib_arr[0] = 0;
    fib_arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        fib_arr[i] = fib_arr[i-1] + fib_arr[i-2];
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d, ", fib_arr[i]);
    }
    printf("\n");

    return fib_arr;
}

int lrgst_even_fib_num(int* array, int n)
{
    int lefn = 0; // Largest Even Fibonacci Number

    for (int i = 0; i < n; i++)
    {
        if (array[i] > lefn && array[i] % 2 == 0)
        {
            lefn = array[i];
        }
    }

    return lefn;
}

int main()
{
    int n;
    printf("Adja meg n értékét. n = ");
    scanf("%d", &n);
    printf("\n");

    printf("A legnagyobb páros Fibonacci szám: %d\n", lrgst_even_fib_num(crt_fib_arr(n), n));

    return 0;
}