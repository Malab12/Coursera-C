/*
    Option 2: Social and Science Base
    29/04/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

// element structure containing the name, symbol and the weight of the element
typedef struct element
{
    char name[20];
    char symbol[3];
    double weight;
} element;

// structure to define the nodes of the link list
typedef struct list
{
    element data;
    struct list* next;
}list;

// function to print out the data in a element structure instance
void print_element(element d)
{
    printf("Name: %s\nSymbol: %s\nWeight: %lf\n\n", d.name, d.symbol, d.weight);
}

// to check that the linked list is not empty
int is_empty(const list* l){return (l == NULL);}

// function to create a node instance
list* create_list(element d) 
{
    list* head = malloc(sizeof(list));
    head->data = d;
    head->next = NULL;
    return head;
}

// function to add the newly created node in the beginning of a prexisting linked list
list* add_to_front(element d, list* h)
{
    list* head = create_list(d);
    head->next = h;
    return head;
}

// function to convert data in an array into a linked list. note: the linked list will have the data elements in reverse order from the array
list* array_to_list(element d[], int size)
 {
    list* head = create_list(d[0]);
    int i;
    for (i = 1; i < size; i++)
    {
        head = add_to_front(d[i], head);
    }
    return head;
}

// printing the whole list element by element
void print_list(list*h, char* title)
{
    printf("%s\n", title);
    while (h != NULL )
    {
        print_element(h->data);
        h = h->next;
    }
}

int main(void)
{
    list periodic_table;
    list* head = NULL;

    /* 
        This can be considered ass hard coding but for the purposes of the specific problem it works.
        For a more general solution I would use the ability to concatinate a linked to list to add elements one node at a time.
    */
    element table[10] = {
        {"Neon", "Ne", 20.180}, {"Flourine", "F", 18.998}, {"Oxygen", "O", 15.999}, {"Nitrogen", "N", 	14.007}, {"Carbon", "C", 12.011},
        {"Boron", "B", 10.811}, {"Beryllium", "Be", 9.012}, {"Lithium", "Li", 6.941}, {"Helium", "He", 4.003}, {"Hydrogen", "H", 1.008}
    };

    head = array_to_list(table, 10);
    print_list(head, "Periodic Table");
    printf("\n\n");
    return 0;
}

/*
//function to concatinate. For our purposes we would take h1 as the actual linked list and h2 as the individual new node created every interation
void concat(list* h1, list* h2)
{
    if (h1 == NULL)
        h1 = h2;
        return;
    else if (h1->next == NULL)
        h1->next = h2;
    else
        concat(h1->next, h2);    
}
*/