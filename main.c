#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int nun_houses;
    int lenth;
    int open;
    int dist_start;

}GADE;

typedef struct{
    int gade_name;
    int nr;
    int curnnt_grabge;
}HOUSEHOLD;

int main(void){

    int numOfGade=4;
    int x;
    int numOne;
    srand(time(NULL));
    numOne = rand();
    printf("%d \n", numOne);
    GADE * gades = malloc(numOfGade * sizeof *gades);
    for (int x = 0; x < numOfGade; ++x) {
        gades[x].nun_houses = rand()%10;
        gades[x].lenth = rand()%20;
        gades[x].dist_start = rand()%20;
        gades[x].open = rand() & 1;
    }
    for (int x = 0; x < numOfGade; ++x) {
        printf("\n--------------------------------------\n");
        printf(" GadeNavn: %d \n antalof houses on the street %d \n lenth of the rode %d \n "
               "lenth of the dist of start %d \n "
               "is open %d", x, gades[x].nun_houses, gades[x].lenth, gades[x].dist_start, gades[x].open);

    }
    return 0;
}

