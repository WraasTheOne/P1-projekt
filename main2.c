#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct struct_street{
        int amount_house_street;
        int length_of_street;
        int open_street;
        int distance_start;

    }struct_street;

    typedef struct struct_house{
        int street_name;
        int house_name;
        int fill_amount_procent;
        int last_empty_days;

    }struct_house;

int generator(struct_street *p_struct_street, struct_house *p_struct_house, int *amount_house_total, int amount_street);

int main (void){
    struct_house *p_struct_street;
    struct_street *p_struct_house;
    int amount_house_total = 0;
    int choice;
    int amount_street = 4;

    printf("Type 1 for generation or 2 for data file");
    scanf("%d", &choice);
    
    if(choice == 1){
        generator(&p_struct_street, &p_struct_house, &amount_house_total, amount_street);
       printf("%d", amount_house_total);
    };
    //elseif(choice == 2){
    //    data_loader();
    //}
    return 0;
}
 
int generator(struct_street *p_struct_street, struct_house *p_struct_house, int *amount_house_total, int amount_street){
    int i;
    srand(time(NULL));
    struct_street *street = malloc(amount_street * sizeof street);
    for (i = 0; i < amount_street; ++i){
        street[i].amount_house_street = 1 + rand()%9;
        street[i].length_of_street = 1 + rand()%20;
        street[i].distance_start =rand()%20;
        street[i].open_street = rand() & 1;
    }

   
    for (i = 0; i < amount_street; ++i){
        *amount_house_total += street[i].amount_house_street;
    } 
    
    // struct_house **house = malloc(amount_house_total * amount_house_total *sizeof house); 
    struct_house house[amount_street][*amount_house_total];
    for (i = 0; i < amount_street; ++i) {
        for (int j = 0; j < *amount_house_total; ++j) {
            house[i][j].fill_amount_procent = rand()%100;
            house[i][j].last_empty_days = rand()%30;
            house[i][j].street_name = i + 1;
            house[i][j].house_name = j + 1;
        }
    }

    for (i = 0; i < amount_street; ++i) {
        printf("GadeNavn: %d \n-------------\n", house[i][i].street_name);
        for (int y = 0; y < street[i].amount_house_street; ++y) {
            printf("House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n",house[i][y].house_name, house[i][y].fill_amount_procent, house[i][y].last_empty_days);
	//sander is here
        }
    }
    return 0;
}