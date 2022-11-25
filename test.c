#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct struct_street
{
    int street_nr;
    int amount_house_street;
    int length_of_street;
    int open_street;
    int distance_start;
} struct_street;

typedef struct struct_house
{
    int street_name;
    int house_name;
    int fill_amount_procent;
    int last_empty_days;
    int house_color;
} struct_house;

struct_street *load_streets();

int recorded = 0;

int main(void)
{
    int i = 0;

    struct_street *array;
    array = load_streets();

    for (i = 0; i < recorded; i++)
    {
        printf("%d, %d\n", array[i].street_nr, recorded);
    }

    return 0;
}

struct_street *load_streets()
{
    int i, count = 0, reads = 0;
    char c;
    struct_street street;
    struct_street *array_street;

    FILE *file_streets;

    file_streets = fopen("streets.csv", "r");

    if (file_streets == NULL)
    {
        printf("Error opening file.\n");
    }

    srand(time(NULL));

    for (c = getc(file_streets); c != EOF; c = getc(file_streets))
    {
        if (c == '\n') // Increment count if this character is newline
        {
            count = count + 1;
        }
    }

    array_street = malloc(count * sizeof(street));
    rewind(file_streets);
    do
    {
        reads = fscanf(file_streets,"%d,%d,%d,%d,%d\n",
                       &array_street[recorded].street_nr,
                       &array_street[recorded].amount_house_street,
                       &array_street[recorded].length_of_street,
                       &array_street[recorded].open_street,
                       &array_street[recorded].distance_start);

        if (reads == 5)recorded++;

        if (reads != 5 && !feof(file_streets))
        {
            printf("File format incorrect.\n");
        }

        if (ferror(file_streets))
        {
            printf("Error reading file.\n");
        }

    } while (!feof(file_streets));

    fclose(file_streets);

    return (array_street);
}

struct_house **load_houses(){

    
}
