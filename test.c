#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

int mystrlen(const char **str, const char ***strstr)
{
    return (*(*strstr + 1) - *str);
}

int a[] = {1,2,3,4,5};

int arr[3][3] = 
{
    {0x112233,0x223344,0x334455},
    {0x445566,0x556677,0x667788},
    {0x778899,0x889910,0x991011}
};

int main()
{
    // printf("0x%X \n", *(*(arr + 1) + 2));
    // printf("%i \n", mystrlen(a, &a));
    char *str = "Microchip";
    str++;
    printf("%s \n", str);
    printf("%s \n", str);

    return 0;
}