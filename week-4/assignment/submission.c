/*
    Week 4 Peer Graded Assignment submission
    Option 1 general
    02/05/2020
*/

#include <stdio.h>
#include <stdlib.h>

//read data reads the input file and fills an array with the data from it, lastly, it replaces the size of the array as the first element
void read_data(FILE* pointer, int d[], int* size)
{
    rewind(pointer);
    *size = 0;
    while (fscanf(pointer, "%d", &d[*size]) == 1)
        (*size)++;
    *size = d[0];
    printf("size = %d\n\n", *size);
}

//This function calculates the maximum and the average of the array provided, the iteration starts from i =1 as d[0] stores the size of the array
void max_avg(FILE *optr, int d[],  int size)
{
    int i;
    int max = 0;
    double average = 0;
    fprintf(optr, "The array read is: ");
    for (i = 1; i <= size; i++){
        average += d[i];
        if (d[i] > max)
            max = d[i];
        fprintf(optr, "%d ", d[i]); //Element by element the array is written into the output file
    }
    average = average/size;
    //printf("max and avg are: %d %10f\n\n", max, average); this is a line for debugging to check that values calculated for max and avg are correct

    fprintf(optr, "\n\nThe average of the array is: %10f\n\n", average);
    fprintf(optr, "The Maximum of the array is: %d\n\n", max);

}

//This function prints out a given file and data in it
void print_file(FILE* fptr) 
{
    int c;
    rewind(fptr);
    while ((c = getc(fptr)) != EOF)
        putc(c, stdout);
}


int main(int argc, char* argv[])
{
    //This if statement checks wether the exe is being run with proper formatingd
    if (argc != 3){
        printf("Please reformat as: ./submission inputfile outputfile\n\n");
        exit(1);}

    int i, sz = 20;
    FILE *ifp, *ofp;
    int data[20] = {0};
    ifp = fopen(argv[1], "r+"); // the second element of the argv is taken as the input file
    ofp = fopen(argv[2], "w+"); // the third element of the argv is taken as the output file

    //this set of functions operate on the read file, first we print out the contents of the file then we compute and write the avg and max into the output
    printf("The read file is as follows \n\n");
    print_file(ifp);
    printf("\n\n");
    read_data(ifp, data, &sz);
    max_avg(ofp, data, sz);

    //this set of functions desplay the output file then close the input and output file
    printf("The write file is as follows \n\n");
    print_file(ofp);
    printf("\n\n");
    fclose(ifp);
    fclose(ofp);
    printf("The program has ended\n");
    return 0;
}