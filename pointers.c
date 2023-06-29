#include <stdio.h>

int main ()
{
    int x = 14;
    int *px = &x;
    int y = *px;
    printf("o valor de x é: %d\n", y);
    printf("endereço de x: %p", px);
}