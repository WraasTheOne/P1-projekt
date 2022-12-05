#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXHOUSE 9
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"

enum color{red, green, yellow, blue};
typedef struct struct_street
{
    int street_nr;
    int amount_house_street;
    int length_of_street;
<<<<<<< HEAD
    int open;
    int dist_start;

}GADE;

typedef struct{
    int gade_name;
    int nr;
    int current_garbage;


}HOUSEHOLD;
=======
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

int recorded = 0;

struct_street *generate_street_array(int amount_street);
struct_house **generate_house_array(int amount_street, int amount_house_total, struct_street *p_array_street);
void assign_color(struct_house **p_array_struct_house, int amount_house_total, int amount_street);
void print_house_color(struct_street* p_array_street, struct_house** p_array_house, int amount_house_total, int amount_street);
struct_street *load_streets();

int main(void)
{
    int amount_house_total = 0;
    int i;
    int choice;
    int amount_street = 5;
    struct_street *p_array_street;
    struct_house **p_array_house;

    printf("type 1 to generate data and 2 to load data");
    scanf("%d", &choice);


    if (choice == 1)
    {
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

        // p_array_street = load_streets();

        // for(i = 0; i < recorded; i++){

        // }
        printf("WIP \n");
        exit(0);
    }
    
    
    
>>>>>>> backup


    assign_color(p_array_house, amount_house_total, amount_street);
    print_house_color(p_array_street, p_array_house, amount_house_total, amount_street);

    return 0;
}

struct_street *generate_street_array(int amount_street)
{
    int i;
    struct_street street;
    struct_street *array_street;

<<<<<<< HEAD
    int numOfGade=4;
    int x, j;
    int numOne;
    srand(time(NULL));
    numOne = rand();
    //printf("%d \n", numOne);
    GADE* gades = malloc(numOfGade * sizeof *gades);
    for (x = 0; x < numOfGade; ++x) {
        gades[x].nun_houses = rand()%10;
        if (gades[x].nun_houses < 1){
            gades[x].nun_houses = 1;
        }
        gades[x].length_of_street = rand() % 20;
        gades[x].dist_start = rand()%20;
        gades[x].open = rand() & 1;
    }
    int currnt_houses = 0;
    for(int i_houses = 0; i_houses < numOfGade; ++i_houses) {
        currnt_houses += gades[i_houses].nun_houses;
=======
    srand(time(NULL));
    array_street = malloc(amount_street * sizeof(street));
    for (i = 0; i < amount_street; ++i)
    {
        array_street[i].street_nr = i;
        array_street[i].amount_house_street = 1 + rand() % MAXHOUSE;
        array_street[i].length_of_street = 1 + rand() % 20;
        array_street[i].distance_start = rand() % 20;
        array_street[i].open_street = rand() & 1;
>>>>>>> backup
    }
    return array_street;
}

<<<<<<< HEAD
    //printf("anttalet of housses: %d\n", currnt_houses);
    //HOUSEHOLD **houses = malloc(numOfGade * currnt_houses * sizeof(HOUSEHOLD *));
    HOUSEHOLD houses[numOfGade][currnt_houses];
    //if (houses == NULL){
    //    printf("Hov hov ");
    //    exit(EXIT_FAILURE);
    //}
    for (x = 0; x < numOfGade; ++x) {
        for (int j = 0; j < currnt_houses; ++j) {
            houses[x][j].current_garbage = rand()%100;
            houses[x][j].gade_name = x;
            houses[x][j].nr = j;
        }
    }

    for (x = 0; x < numOfGade; ++x) {
        printf("GadeNavn; %d \n", x);
        for (int y = 0; y < gades[x].nun_houses; ++y) {
            printf("House_nr; %d\nHouse_garbe; %d\n",houses[x][y].nr, houses[x][y].current_garbage);
	//sander is here
=======
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
            // array_house[x] = malloc(amount_house_total * sizeof(house));
            array_house[x] = malloc(p_array_street[x].amount_house_street * sizeof(house));
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
void assign_color(struct_house **p_array_house, int amount_house_total, int amount_street)
{
    for (int i = 0; i < amount_street; i++)
    {
        for (int x = 0; x < amount_house_total; x++)
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
>>>>>>> backup
        }
    }
}

void print_house_color(struct_street* p_array_street, struct_house** p_array_house, int amount_house_total, int amount_street){
    for(int i = 0; i < amount_street; i++){
        printf("GadeNavn: %d \n-------------\n", p_array_house[i][i].street_name);
        for (int y = 0; y < p_array_street[i].amount_house_street; ++y){
            if(p_array_house[i][y].house_color == red){
                printf(RED "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);                
            }
            else if(p_array_house[i][y].house_color == green){
                printf(GREEN "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
            else if(p_array_house[i][y].house_color == yellow){
                printf(YELLOW "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
            else if(p_array_house[i][y].house_color == blue){
                printf(BLUE "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);;
            }
        }
        
    }
}