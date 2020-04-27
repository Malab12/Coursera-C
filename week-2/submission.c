#include<stdio.h>

typedef enum month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;

typedef struct date
{
    month m;
    int d;
} date;

void print_date(date *input)
{
    switch(input->m)
    {
        case jan: printf("January %d\n", input->d); break;
        case feb: printf("February %d\n", input->d); break;
        case mar: printf("March %d\n", input->d); break;
        case apr: printf("April %d\n", input->d); break;
        case may: printf("May %d\n", input->d); break;
        case jun: printf("June %d\n", input->d); break;
        case jul: printf("July %d\n", input->d); break;
        case aug: printf("August %d\n", input->d); break;
        case sep: printf("September %d\n", input->d); break;
        case oct: printf("October %d\n", input->d); break;
        case nov: printf("November %d\n", input->d); break;
        case dec: printf("December %d\n", input->d); break;
        default: printf("%d is an invalid input for month\n", input->m);
    }
}

month next_month(month m)
{
    return ((m + 1) % 12); 
}

void next_day(date *input)
{
    if (input->d > 31)
        printf("Invalid input for date\n");
    if (input->m == feb)
    {
        if (input->d == 28)
        {
            input->d = 1;
            input->m = next_month(input->m);
        }
        else
        {
            input->d++;
        }
    }
    else if (input->m == 3 || input->m == 5 || input->m == 8 || input->m == 10)
    {
        if (input->d == 30)
        {
            input->d = 1;
            input->m = next_month(input->m);
        }
        else
        {
            input->d++;
        } 
    }
    else
    {
        if (input->d == 31)
        {
            input->d = 1;
            input->m = next_month(input->m);
        }
        else
        {
            input->d++;
        }
    }
    
}

int main(void)
{
    date input[5]= {{jan, 1}, {feb, 28}, {mar, 14}, {oct, 31}, {dec, 31}};
    int i = 0;
    for (int i = 0; i < 5; i++){
    date *p = &input[i];
    print_date(p);
    next_day(p);
    print_date(p);
    printf("\n\n");
    }
    return 0;
}