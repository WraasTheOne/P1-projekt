#include <stdio.h>
#define force_empty 60

int calculate_pickup_priority(int pickup_priority, int fill_amount_procent, int last_empty_days);

int main (void){
int last_empty_days;
int fill_amount_procent;
int pickup_priority = 0;
int street_amount;
int x;
//Temporary placeholder for array data
last_empty_days = 11;
fill_amount_procent = 59;
 

    for(x = 0; x < street_amount; ++x){


    }
    if(fill_amount_procent <= force_empty){
        printf("%d", calculate_pickup_priority(pickup_priority, fill_amount_procent, last_empty_days));
    }
    return (0);
}

int calculate_pickup_priority(int pickup_priority, int fill_amount_procent, int last_empty_days){
    // Temporary math formula for pickup priority
    pickup_priority = fill_amount_procent * (last_empty_days / 100 + 0.9);
    return (pickup_priority);
} 