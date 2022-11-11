#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct struct_street{
        int amount_house_street;
        int length_of_street;
        int open_street;
        int distance_start;
    }struct_street;


struct_street generate_street (int amount_stree );

int main (void){
    int amount_house_total = 0;
    int choice;
    int amount_street = 4;
    int i;
    struct_street *street;

    printf("Type 1 for generation or 2 for data file");
    scanf("%d", &choice);
    
    if(choice == 1){
        *street = generate_street(amount_street);
    };
    for (i = 0; i < amount_street; ++i){
        amount_house_total += street[i].amount_house_street;
    } 
    printf("%d", amount_house_total);
    
    //elseif(choice == 2){
    //    data_loader();
    //}
    return 0;
}
 
struct_street generate_street(int amount_street ){
    int i;
    srand(time(NULL));
    struct_street *street = malloc(amount_street * sizeof street);
    for (i = 0; i < amount_street; ++i){
        street[i].amount_house_street = 1 + rand()%9;
        street[i].length_of_street = 1 + rand()%20;
        street[i].distance_start =rand()%20;
        street[i].open_street = rand() & 1;
    }
    return (*street);
}