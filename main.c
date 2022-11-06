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
    int current_garbage;






    
}HOUSEHOLD;

int main(void){



    int numOfGade=4;
    int x;
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
        gades[x].lenth_of_steet = rand() % 20;
        gades[x].dist_start = rand()%20;
        gades[x].open = rand() & 1;
    }
    int currnt_houses = 0;
    for(int i_houses = 0; i_houses < numOfGade; ++i_houses) {
        currnt_houses += gades[i_houses].nun_houses;
    }

    //printf("anttalet of housses: %d\n", currnt_houses);
    //HOUSEHOLD **houses = malloc(numOfGade * currnt_houses * sizeof(HOUSEHOLD *));
    HOUSEHOLD houses[numOfGade][currnt_houses];
    //if (houses == NULL){
    //    printf("Hov hov ");
    //    exit(EXIT_FAILURE);
    //}
    for (x = 0; x < numOfGade; ++x) {
        for (int j = 0; j < currnt_houses; ++j) {
            houses[x][j].curnnt_grabge = rand()%100;
            houses[x][j].gade_name = x;
            houses[x][j].nr = j;
        }
    }

    for (x = 0; x < numOfGade; ++x) {
        printf("GadeNavn; %d \n", x);
        for (int y = 0; y < gades[x].nun_houses; ++y) {
            printf("House_nr; %d\nHouse_garbe; %d\n",houses[x][y].nr, houses[x][y].curnnt_grabge);

        }
    }
    return 0;
}

