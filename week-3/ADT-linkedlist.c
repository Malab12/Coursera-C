/*
    The ADT list
    29/04/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

typedef struct list
{
    int data;
    struct list* next;
}list;

int is_empty(const list* l){return (l == NULL);}

list* create_list(int d) //replace int d with the required datatype being stored in the list
{
    list* head = malloc(sizeof(list));
    head->data = d;
    head->next = NULL;
    return head;
}

list* add_to_front(int d, list* h)
{
    list* head = create_list(d);
    head->next = h;
    return head;
}

list* array_to_list(int d[], int size) // converting an array to a list
{
    list* head = create_list(d[0]);
    int i;
    for (i = 1; i < size; i++)
    {
        head = add_to_front(d[i], head);
    }
    return head;
}

void print_list(list*h, char* title)
{
    printf("%s\n", title);
    while (h != NULL )
    {
        printf("%d->", h->data);
        h = h->next;
    }
}

int count(list*h)
{
    if (h == NULL)
        return 0;
    else
        return(1 + count(h->next));
}

void concat(list* h1, list* h2)
{
    assert(h1 != NULL);
    if (h1->next == NULL)
        h1->next = h2;
    else
        concat(h1->next, h2);    
}

void insert(list* p1, list*p2, list* input)
{
    p1->next = input;
    input->next = p2;
}

int main(void)
{
    list list_of_int;
    list* head = NULL;
    int data[6] = {2, 3 ,5 ,7, 11, 13};
    head = array_to_list(data, 6);
    print_list(head, "multiple element list");
    printf("\n\n");
    printf("The list is has %d elements\n\n", count(head) );
    return 0;
}


