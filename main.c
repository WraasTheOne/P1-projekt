#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int nun_houses;
    int lenth_of_steet;
    int open;
    int dist_start;

}GADE;

typedef struct{
    int gade_name;
    int nr;
    int curnnt_grabge;
}HOUSEHOLD;

int main(void){
    int numOfGade=7;
    int x;
    int numOne;
    srand(time(NULL));
    numOne = rand();
    printf("%d \n", numOne);
    GADE* gades = malloc(numOfGade * sizeof *gades);
    for (x = 0; x < numOfGade; ++x) {
        gades[x].nun_houses = (rand()%9)+1;
        gades[x].lenth_of_steet = rand() % 20;
        gades[x].dist_start = rand()%20;
        gades[x].open = rand() & 1;
    }
    int currnt_houses = 0;
    for(int i_houses = 0; i_houses < numOfGade; ++i_houses) {
        currnt_houses += gades[i_houses].nun_houses;
    }

    printf("anttalet of housses: %d", currnt_houses);
    //HOUSEHOLD **houses = malloc(numOfGade * currnt_houses * sizeof(HOUSEHOLD *));
    HOUSEHOLD houses[numOfGade][currnt_houses];
    //if (houses == NULL){
    //    printf("Hov hov ");
    //    exit(EXIT_FAILURE);
    //}
    for (x = 0; x < numOfGade; ++x) {
        for (int j = 0; j < currnt_houses; ++j) {
            //houses[x][j].curnnt_grabge = rand()%100;
            houses[x][j].gade_name = x;
            houses[x][j].nr = j;
        }
    }


    for (x = 0; x < numOfGade; ++x) {
        printf("\n--------------------------------------\n");
        printf(" GadeNavn: %d \n antal of houses on the street %d \n lenth_of_steet of the rode %d \n "
               "lenth_of_steet of the dist of start %d \n "
              "is open %d\n", x, gades[x].nun_houses, gades[x].lenth_of_steet, gades[x].dist_start, gades[x].open);
        for (int y = 0; y < gades[x].nun_houses; ++y) {
            printf("| ");
            printf("House gade: %d ", houses[x][y].gade_name);


        }
        printf("|");
    }
    return 0;
}

