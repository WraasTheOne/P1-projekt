#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int nun_houses;
    int length_of_street;
    int open;
    int dist_start;

}GADE;

typedef struct{
    int gade_name;
    int nr;
    int fill_amount_procent;
    int last_empty_days;

}HOUSEHOLD;

int main(void){
    int numOfGade = 4;
    int x;
    int numOne;
    srand(time(NULL));
    numOne = rand();
    //printf("%d \n", numOne);

    GADE* gades = malloc(numOfGade * sizeof *gades); //Opret numOfGade struct variable ved navn gades
    for (x = 0; x < numOfGade; ++x) {                // Lav array ud af struct variablerne gades
        gades[x].nun_houses = rand()%10;
        if (gades[x].nun_houses < 1){
            gades[x].nun_houses = 1;
        }
        gades[x].length_of_street = rand() % 20;
        gades[x].dist_start = rand()%20;
        gades[x].open = rand() & 1;
    }
    int amount_houses = 0;
    for(int i_houses = 0; i_houses < numOfGade; ++i_houses) {
        amount_houses += gades[i_houses].nun_houses;
    }

    //printf("anttalet of housses: %d\n", currnt_houses);
    //HOUSEHOLD **houses = malloc(numOfGade * currnt_houses * sizeof(HOUSEHOLD *));
    HOUSEHOLD houses[numOfGade][amount_houses];
    //if (houses == NULL){
    //    printf("Hov hov ");
    //    exit(EXIT_FAILURE);
    //}
    for (x = 0; x < numOfGade; ++x) {
        for (int j = 0; j < amount_houses; ++j) {
            houses[x][j].fill_amount_procent = rand()%100;
            houses[x][j].last_empty_days = rand()%30;
            houses[x][j].gade_name = x + 1;
            houses[x][j].nr = j + 1;
        }
    }

    for (x = 0; x < numOfGade; ++x) {
        printf("GadeNavn: %d \n-------------\n", houses[x][x].gade_name);
        for (int y = 0; y < gades[x].nun_houses; ++y) {
            printf("House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n",houses[x][y].nr, houses[x][y].fill_amount_procent, houses[x][y].last_empty_days);
	//sander is here
        }
    }
    return 0;
}

