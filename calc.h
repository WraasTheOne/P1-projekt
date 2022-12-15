#define TIME_PER_HOUSE 0.907963595

int cmpfunc(const void *a, const void *b)
{

    STRUCT_STREET *data1 = (STRUCT_STREET *)a;
    STRUCT_STREET *data2 = (STRUCT_STREET *)b;

    return (data1->distance_start - data2->distance_start);
}

int cal_inc_streets(int amount_streets, STRUCT_HOUSE **p_array_house, STRUCT_STREET *p_array_street)
{
    int street_counter = 0;
    for (int i = 0; i < amount_streets; i++)
    {
        for (int j = 0; j < p_array_street[i].amount_house_street; j++)
        {
            if (p_array_house[i][j].house_include == 1)
            {
                street_counter++;
                p_array_street[i].street_include = 1;
                break;
            }
        }
    }
    return street_counter;
}

int cal_houses(int amount_streets, STRUCT_HOUSE **p_array_house, STRUCT_STREET *p_array_street)
{
    int house_counter = 0;

    for (int j = 0; j < amount_streets; ++j)
    {
        for (int k = 0; k < p_array_street[j].amount_house_street; ++k)
        {
            if (p_array_house[j][k].house_include == 1)
            {
                house_counter += 1;
            }
        }
    }
    house_counter -= 1;

    return house_counter;
}

double cal_time(int amount_streets, STRUCT_HOUSE **p_array_house, STRUCT_STREET *p_array_street){
    double time_counter = 0;
    
    for (int j = 0; j < amount_streets; ++j)
    {
        time_counter += (p_array_street[j].amount_house_street * 0.907963595);         
        
    }
    return time_counter;

}


double cal_time_saved(int amount_streets, STRUCT_HOUSE **p_array_house, STRUCT_STREET *p_array_street)
{
    double time_counter = 0;

    for (int j = 0; j < amount_streets; ++j)
    {
        if (p_array_street[j].street_include == 1)
        {
            time_counter += (p_array_street[j].amount_house_street * TIME_PER_HOUSE);
            for (int k = 0; k < p_array_street[j].amount_house_street; ++k)
            {
                if (p_array_house[j][k].house_include == 0)
                {
                    time_counter -= TIME_PER_HOUSE;
                }
            }
        }
    }
    return time_counter;
}

double calc_improved_path(int amount_streets, STRUCT_HOUSE **p_array_house, STRUCT_STREET *p_array_street)
{
    double total_distance = 0;

    qsort(p_array_street, amount_streets, sizeof(STRUCT_STREET), cmpfunc);

    for (int i = amount_streets - 1; i >= 0; i--)
    {
        if (p_array_street[i].street_include == 1)
        {
            total_distance += p_array_street[i].distance_start;
            break;
        }
    }

    for (int i = 0; i < amount_streets; i++)
    {
        if (p_array_street[i].street_include == 1 && p_array_street[i].open_street == 0)
        {
            total_distance += p_array_street[i].length_of_street * 2;
        }
        else if (p_array_street[i].street_include == 1 && p_array_street[i].open_street == 1)
        {
            for (int j = i + 1; j < amount_streets; j++)
            {
                if (p_array_street[j].open_street == 1 && p_array_street[j].street_include == 1)
                {
                    total_distance += p_array_street[i].length_of_street + p_array_street[j].length_of_street;
                    i++;
                    break;
                }
                else if (p_array_street[j].street_include == 1 && p_array_street[j].open_street == 0)
                {
                    total_distance += p_array_street[i].length_of_street * 2;
                    break;
                }
            }
        }
    }

    return total_distance;
}

double cal_not_imp(int amount_streets, STRUCT_HOUSE **p_array_house, STRUCT_STREET *p_array_street)
{
    double total_distance;

    total_distance = p_array_street[amount_streets-1].distance_start;

    for (int i = 0; i < amount_streets; i++)
    {
        if (p_array_street[i].open_street == 0 )
        {
            total_distance += p_array_street[i].length_of_street * 2;
        }
        else if (p_array_street[i].open_street == 1 && p_array_street[i+1].open_street == 1)
        {
            total_distance += p_array_street[i].length_of_street + p_array_street[i+1].length_of_street;
            i++;
        }
        else if (p_array_street[i].open_street == 1 && p_array_street[i+1].open_street == 0)
        {
            total_distance += p_array_street[i].length_of_street * 2;
        }
    }
    return total_distance;
}



void result(double total_distance_improved, double total_distance, double time_saved, double time_original, int included_houses, int amount_house_total, int amount_street, int included_streets)
{
    double percent_distance = (total_distance - total_distance_improved) / total_distance * 100;
    double percent_time = (time_original - time_saved) / time_original * 100;
    double percent_houses_inc = (double)(amount_house_total - included_houses) / amount_house_total * 100;
    double percent_streets_inc = (double)(amount_street - included_streets) / amount_street * 100;
    int houses_saved = amount_house_total - included_houses;

    printf(RED "\nNot improved distance = %.2lf " RESET ": ", total_distance);
    printf(GREEN "Improved distance = %.2lf\n" RESET, total_distance_improved);
    printf(RED"Not improved time = %.2lf "RESET": ", time_original);
    printf(GREEN "Improved time  = %.2lf\n" RESET, time_saved);
    printf(RED"Houses total = %d " RESET ": ", amount_house_total);
    printf(GREEN "Houses skipped = %d\n" RESET, (amount_house_total - included_houses));
    printf(RED"Streets total = %d "RESET ": ", amount_street);
    printf(GREEN"Streets skipped = %d\n"RESET, (amount_street - included_streets));
    printf("----------------------------------------------------\n");
    printf(BLUE "Saved distance = %.2lf\n", (total_distance - total_distance_improved));
    printf(BLUE "Distance improvement in percent = %.2lf%% \n" RESET, percent_distance);
    printf(BLUE "Time improvement in percent = %.2lf%%\n" RESET, percent_time);
    printf(BLUE "Houses skipped in percent = %.2lf%%\n" RESET, percent_houses_inc);
    printf(BLUE"Streets skipped in percent = %.2lf%%\n" RESET, percent_streets_inc);

}
