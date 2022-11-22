#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXHOUSE 9
typedef struct struct_street{
        int amount_house_street;
        int length_of_street;
        int open_street;
        int distance_start;
        int street_rating;
    }struct_street;
typedef struct struct_house{
        int street_name;
        int house_name;
        int fill_amount_procent;
        int last_empty_days;
        int house_rating;
    }struct_house;

struct_street* generate_street_array(int amount_street);
struct_house** generate_house_array(int amount_street, int amount_house_total, struct_street *p_array_street);
void house_rating(struct_house** p_array_struct_house, int amount_house_total, int amount_street);
void street_rating(struct_house** p_array_house, struct_street* p_array_street, int amount_house_total, int amount_street);

int main (void){
    int amount_house_total = 0;
    int choice;
    int amount_street = 4;
    struct_street* p_array_street;
    struct_house** p_array_house;

   printf("type 1 to generate data and 2 to load data");
    scanf("%d", &choice);
    if(choice == 1){
        p_array_street = generate_street_array(amount_street);
        //Count total amount of houses to generate house array
        for (int i = 0; i < amount_street; ++i){
            amount_house_total += p_array_street[i].amount_house_street; 
        }
        p_array_house = generate_house_array(amount_street, amount_house_total, p_array_street);
    }
    else if (choice == 2){
        printf("WIP \n");
        exit(0);
    }
    //Printer
    for (int i = 0; i < amount_street; ++i){
        printf("GadeNavn: %d \n-------------\n", p_array_house[i][i].street_name);
        for (int y = 0; y < p_array_street[i].amount_house_street ; ++y) {
            printf("House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n",p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
        }
    } 
    house_rating(p_array_house, amount_house_total, amount_street);
    street_rating(p_array_house, p_array_street, amount_house_total, amount_street);
    return 0;
}
 
struct_street* generate_street_array(int amount_street){
    int i;
    struct_street street;
    struct_street* array_street;

    srand(time(NULL));
    array_street = malloc(amount_street * sizeof street);
    for (i = 0; i < amount_street; ++i){
        array_street[i].amount_house_street = 1 + rand()%MAXHOUSE;
        array_street[i].length_of_street = 1 + rand()%20;
        array_street[i].distance_start =rand()%20;
        array_street[i].open_street = rand() & 1;
    }   
    return array_street;
}

struct_house** generate_house_array(int amount_street, int amount_house_total,struct_street *p_array_street){
    struct_house house;
    struct_house** array_house;
    array_house = malloc(amount_street * sizeof(house));
    if (array_house == NULL){
        printf("Memory not allocated \n");
        exit(0);
    }
    else{
        for (int x = 0; x < amount_street; ++x) {
            //array_house[x] = malloc(amount_house_total * sizeof(house));
            array_house[x] = malloc(p_array_street[x].amount_house_street * sizeof(house));
            for (int j = 0; j < amount_house_total; ++j) {
                array_house[x][j].fill_amount_procent = rand()%100;
                array_house[x][j].last_empty_days = rand()%30;
                array_house[x][j].street_name = x+1;
                array_house[x][j].house_name = j + 1;
            }
        }
     }
    return (array_house);
}

void house_rating(struct_house** p_array_house, int amount_house_total, int amount_street){
    for(int i = 0; i < amount_street; i++){
        for(int x = 0; x < amount_house_total; x++){
            p_array_house[i][x].house_rating = p_array_house[i][x].fill_amount_procent * p_array_house[i][x].last_empty_days; // placeholder for equation.
            printf("House rating: %d\n", p_array_house[i][x].house_rating);
        }
    }
}
void street_rating(struct_house** p_array_house, struct_street* p_array_street, int amount_house_total, int amount_street){
    for(int i = 0; i < amount_street; i++){
       for(int x = 0; x < amount_house_total; x++){
            p_array_street[i].street_rating += p_array_house[i][x].house_rating;
        }
    printf("Street rating: %d\n", p_array_street[i].street_rating);
    }


}



struct_street* load_streets(){
    int i;
    struct_street street;
    struct_street* array_street;

    FILE *file_streets;
    
    

    

    return array_street;
}



