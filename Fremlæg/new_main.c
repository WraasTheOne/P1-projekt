#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototype.h"
#include "calc.h"
#include "load_data.h"
#include "outputs.h"


int main(void)
{
    int amount_house_total = 0, included_houses, included_streets = 0, choice = 0, amount_street = 0;
    double time = 0, time_improved = 0, total_distance_improved, total_distance;
    STRUCT_STREET *p_array_street;
    STRUCT_HOUSE **p_array_house;

    printf("type 1 to generate data and 2 to load data\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        amount_street = AMOUNT_OF_STREETS;
        p_array_street = generate_street_array(amount_street);
        // Count total amount of houses to generate house array
        for (int i = 0; i < amount_street; ++i)
        {
            amount_house_total += p_array_street[i].amount_house_street;
        }
        p_array_house = generate_house_array(amount_street, amount_house_total, p_array_street);


    }
    else if (choice == 2)
    {
        p_array_street = load_streets(&amount_street);
         for (int i = 0; i < amount_street; ++i)
        {
            amount_house_total += p_array_street[i].amount_house_street;
        }
        p_array_house = load_houses(p_array_street, amount_street);
    }else{
        return 0;
    }



    assign_color(p_array_house,p_array_street, amount_house_total, amount_street);
    print_prompt_house_color(p_array_street, p_array_house, amount_house_total, amount_street);


    included_streets = calc_inc_streets(amount_street, p_array_house, p_array_street);

    included_houses = calc_houses(amount_street, p_array_house, p_array_street);

    //time_counter = cal_time_saved(amount_street, p_array_house, p_array_street);
    


   

    total_distance_improved = calc_improved_path(amount_street, p_array_house, p_array_street);
    total_distance = calc_not_imp(amount_street, p_array_house, p_array_street);

    time_improved = calc_improved_time(amount_street, p_array_house, p_array_street);
    time = calc_time(amount_street, p_array_house, p_array_street);

    print_output(p_array_street, p_array_house, amount_house_total, amount_street);
    result(total_distance_improved, total_distance, time_improved, time, included_houses, amount_house_total, amount_street, included_streets); 



    return 0;
}

