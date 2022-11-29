#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAXHOUSE 9


#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"

typedef enum color{red, green, yellow, blue} color;
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
    int house_include;
    int house_color;
} struct_house;

int amount_street = 0;

struct_street *generate_street_array(int amount_street);
struct_house **generate_house_array(int amount_street, int amount_house_total, struct_street *p_array_street);
void assign_color(struct_house **p_array_house, struct_street *p_array_street, int amount_house_total, int amount_street);
void print_house_color(struct_street* p_array_street, struct_house** p_array_house, int amount_house_total, int amount_street);
struct_street *load_streets();
struct_house **load_houses(struct_street *array_streets);

int main(void)
{
    int amount_house_total = 0;
    int i;
    int choice;
    struct_street *p_array_street;
    struct_house **p_array_house;

    printf("type 1 to generate data and 2 to load data");
    scanf("%d", &choice);


    if (choice == 1)
    {
        amount_street = 3;
        p_array_street = generate_street_array(amount_street);
        // Count total amount of houses to generate house array
        for (i = 0; i < amount_street; ++i)
        {
            amount_house_total += p_array_street[i].amount_house_street;
        }
        p_array_house = generate_house_array(amount_street, amount_house_total, p_array_street);
    }
    else if (choice == 2)
    {
        p_array_street = load_streets();
         for (i = 0; i < amount_street; ++i)
        {
            amount_house_total += p_array_street[i].amount_house_street;
        }
        p_array_house = load_houses(p_array_street);
    }



    assign_color(p_array_house,p_array_street, amount_house_total, amount_street);
    print_house_color(p_array_street, p_array_house, amount_house_total, amount_street);

    return 0;
}

struct_street *generate_street_array(int amount_street)
{
    int i;
    struct_street street;
    struct_street *array_street;

    srand(time(NULL));
    array_street = malloc(amount_street * sizeof(street));
    for (i = 0; i < amount_street; ++i)
    {
        array_street[i].street_nr = i;
        array_street[i].amount_house_street = 1 + rand() % MAXHOUSE;
        array_street[i].length_of_street = 1 + rand() % 20;
        array_street[i].distance_start = rand() % 20;
        array_street[i].open_street = rand() & 1;
    }
    return array_street;
}

struct_house **generate_house_array(int amount_street, int amount_house_total, struct_street *p_array_street)
{
    struct_house house;
    struct_house **array_house;
    array_house = malloc(amount_street * sizeof(house));
    if (array_house == NULL)
    {
        printf("Memory not allocated \n");
        exit(0);
    }
    else
    {
        for (int x = 0; x < amount_street; ++x)
        {
            array_house[x] = malloc(amount_house_total * sizeof(house));
            for (int j = 0; j < amount_house_total; ++j)
            {
                array_house[x][j].fill_amount_procent = rand() % 100;
                array_house[x][j].last_empty_days = rand() % 30;
                array_house[x][j].street_name = x + 1;
                array_house[x][j].house_name = j + 1;
            }
        }
    }


    return (array_house);
}


void assign_color(struct_house **p_array_house, struct_street *p_array_street, int amount_house_total, int amount_street)
{
    for (int i = 0; i < amount_street; i++)
    {
        for (int x = 0; x < p_array_street[i].amount_house_street; x++)
        {
            if(p_array_house[i][x].fill_amount_procent < 15)
            {
                p_array_house[i][x].house_color = red;
            }
            else if(p_array_house[i][x].fill_amount_procent > 85){
                p_array_house[i][x].house_color = green;
            }
            else if(p_array_house[i][x].fill_amount_procent > 15 && p_array_house[i][x].fill_amount_procent < 85 && p_array_house[i][x].last_empty_days < 14){
                p_array_house[i][x].house_color = yellow;
            }
             else if(p_array_house[i][x].fill_amount_procent > 15 && p_array_house[i][x].fill_amount_procent < 85 && p_array_house[i][x].last_empty_days > 14){
                p_array_house[i][x].house_color = blue;
            }
        }
    }
}

void print_house_color(struct_street *p_array_street, struct_house **p_array_house, int amount_house_total, int amount_street)
{ 
    int x;
    int z;
    for (int i = 0; i < amount_street; i++)
    {
        printf("GadeNavn: %d \n-------------\n", p_array_house[i][i].street_name);
        for (int y = 0; y < p_array_street[i].amount_house_street; ++y)
        {
            x = 0;
            if (p_array_house[i][y].house_color == red)
            {
                printf(RED "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }

            else if (p_array_house[i][y].house_color == green)
            {
                printf(GREEN "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
            else if (p_array_house[i][y].house_color == yellow)
            {
                printf(YELLOW "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
            else if (p_array_house[i][y].house_color == blue)
            {
                printf(BLUE "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
        }
        printf("\nWhich houses to include? (press enter between each house and continue with 0\n");

        do
        {
            scanf("%d", &x);
            x = x - 1;
            p_array_house[i][x].house_include = 1;
        } while (x != -1);
        
    }
    

    for (int i = 0; i < amount_street; i++)
    {
        printf("GadeNavn: %d \n-------------\n", p_array_house[i][i].street_name);
        for (int y = 0; y < p_array_street[i].amount_house_street; ++y)
        {
            if (p_array_house[i][y].house_color == red && p_array_house[i][y].house_include == 1)
            {
                printf(RED "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }

            else if (p_array_house[i][y].house_color == green && p_array_house[i][y].house_include == 1)
            {
                printf(GREEN "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
            else if (p_array_house[i][y].house_color == yellow && p_array_house[i][y].house_include == 1)
            {
                printf(YELLOW "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
            else if (p_array_house[i][y].house_color == blue && p_array_house[i][y].house_include == 1)
            {
                printf(BLUE "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
        }
    }
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
                       &array_street[amount_street].street_nr,
                       &array_street[amount_street].amount_house_street,
                       &array_street[amount_street].length_of_street,
                       &array_street[amount_street].open_street,
                       &array_street[amount_street].distance_start);

        if (reads == 5)amount_street++;

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
    array_houses = malloc(amount_street * sizeof(struct_house));

    for (j = 0; j < amount_street; j++)
    {

        array_houses[j] = malloc(array_streets[j].amount_house_street * sizeof(struct_house));

        for (i = 0; i < array_streets[j].amount_house_street; i++)
        {
            fscanf(file, "%d,%d,%d,%d,%d,%d\n",
                   &array_houses[j][i].street_name,
                   &array_houses[j][i].house_name,
                   &array_houses[j][i].fill_amount_procent,
                   &array_houses[j][i].last_empty_days,
                   &array_houses[j][i].house_color,
                   &array_houses[j][i].house_include);
        }
    }
    fclose(file);

    return array_houses;
}

