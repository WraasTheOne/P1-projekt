#include <stdio.h>
#define force_empty 60
double calculate_pickup_priority(double pickup_priority, double *fill_amount_procent, double *last_empty_days);

int main (void){
double last_empty_days;
double fill_amount_procent;
double pickup_priority;

last_empty_days = 10;
fill_amount_procent = 59;
 
    if(fill_amount_procent <= force_empty){
        printf("%lf", calculate_pickup_priority(pickup_priority, &fill_amount_procent, &last_empty_days));
    }
    return (0);
}


double calculate_pickup_priority(double pickup_priority, double *fill_amount_procent, double *last_empty_days){
    pickup_priority = *fill_amount_procent * (*last_empty_days / 100 + 0.9);
    return (pickup_priority);
} 