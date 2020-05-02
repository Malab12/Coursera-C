/*
    Basic File I/O code
    30/04/2020
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_HW  20

void read_data(FILE* pointer, int d[], int* size)
{
    *size = 0;
    while (fscanf(pointer, "%d", &d[*size]) == 1)
        (*size)++;
}

void print_data(int d[], int size)
{
    int i;
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", d[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
}

double average(int d[], int size)
{
    int i;
    double average = 0;
    for (i = 0; i < size; i++)
        average += d[i];
    return (average/size);
}

int main(void)
{
    int i, sz = MAX_HW;
    FILE *ifp;
    int data[MAX_HW] = {100, 0};
    ifp = fopen("myhw", "r");
    read_data(ifp, data, &sz);
    print_data(data, sz);
    printf("\n The average score of the class is: %10f", average(data, sz));
    printf("\n\n");
    fclose(ifp);
    return 0;
}