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
struct_house **load_houses(struct_street *array_streets);

int recorded = 0;

int main(void)
{
    int i = 0;

    struct_street *array_streets;
    array_streets = load_streets();

    for (i = 0; i < recorded; i++)
    {
        printf("%d, %d\n", array_streets[i].street_nr, recorded);
    }

    struct_house **array_houses;
    array_houses = load_houses(array_streets);

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
        reads = fscanf(file_streets, "%d,%d,%d,%d,%d\n",
                       &array_street[recorded].street_nr,
                       &array_street[recorded].amount_house_street,
                       &array_street[recorded].length_of_street,
                       &array_street[recorded].open_street,
                       &array_street[recorded].distance_start);

        if (reads == 5)
            recorded++;

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

struct_house **load_houses(struct_street *array_streets)
{
    int i;
    int j;

    FILE *file;
    file = fopen("houses.csv", "r");

    struct_house **array_houses;
    array_houses = malloc(recorded * sizeof(struct_house));

    for (j = 0; j < recorded; j++)
    {
        array_houses[j] = malloc(array_streets[j].amount_house_street * sizeof(struct_house));
        for (i = 0; i < array_streets[j].amount_house_street; i++)
        {
            fscanf(file, "%d,%d,%d,%d,%d",
                   &array_houses[j][i].street_name,
                   &array_houses[j][i].house_name,
                   &array_houses[j][i].fill_amount_procent,
                   &array_houses[j][i].last_empty_days,
                   &array_houses[j][i].house_color);
        }
    }

    fclose(file);

    return array_houses;
}
