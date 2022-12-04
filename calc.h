int cmpfunc(const void *a, const void *b)
{

    STRUCT_STREET *data1 = (STRUCT_STREET *)a;
    STRUCT_STREET *data2 = (STRUCT_STREET *)b;

    return (data1->distance_start - data2->distance_start);
}

void cal_inc_streets(int amount_streets, STRUCT_HOUSE **p_array_house, STRUCT_STREET *p_array_street)
{
    for (int i = 0; i < amount_streets; i++)
    {
        for (int j = 0; j < p_array_street[i].amount_house_street; j++)
        {
            if (p_array_house[i][j].house_include == 1)
            {
                p_array_street[i].street_include = 1;
                break;
            }
        }
    }
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

double cal_time_saved(int amount_streets, STRUCT_HOUSE **p_array_house, STRUCT_STREET *p_array_street)
{
    double time_counter = 0;

    for (int j = 0; j < amount_streets; ++j)
    {
        if (p_array_street[j].street_include == 1)
        {
            time_counter += (p_array_street[j].amount_house_street * 0.907963595);
            for (int k = 0; k < p_array_street[j].amount_house_street; ++k)
            {
                if (p_array_house[j][k].house_include == 0)
                {
                    time_counter -= 0.907963595;
                }
            }
        }
    }
    return time_counter;
}

double cal_path(int amount_streets, STRUCT_HOUSE **p_array_house, STRUCT_STREET *p_array_street)
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

double cal_ordenary_path(int amount_streets, STRUCT_HOUSE **p_array_house, STRUCT_STREET *p_array_street)
{
    double total_distance = 0;

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
        }
    }
    return total_distance;
}

double cal_co2()
{
    double co2_emission;

    return 0;
}
