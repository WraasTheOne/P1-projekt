

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
        if (p_array_street[i].street_include == 1)
        {
            printf("%d", p_array_street[i].street_include);
        }
    }
}

int cal_houses(int amount_streets, STRUCT_HOUSE **p_array_house, STRUCT_STREET *p_array_street)
{
    int house_counter;

    for (int j = 0; j < amount_streets; ++j)
    {
        for (int k = 0; k < p_array_street[j].amount_house_street; ++k)
        {
            if(p_array_house[j][k].house_include == 1){
                house_counter += 1;
            }
        }
    }
    house_counter -= 1;

    return house_counter;
}

double cal_time_saved(int amount_streets, STRUCT_HOUSE **p_array_house, STRUCT_STREET *p_array_street)
{   
    double time_counter;
    for (int j = 0; j < amount_streets; ++j)
    {
        if(p_array_street[j].street_include == 1){
            time_counter += 2.15;
        }
        for (int k = 0; k < p_array_street[j].amount_house_street; ++k)
        {
            if(p_array_house[j][k].house_include == 1 ){
                time_counter += 1;
            }
        }
    }

    return 0;
}

double cal_path()
{

    return 0;
}

double cal_co2()
{

    return 0;
}
