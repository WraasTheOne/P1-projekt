

void print_house_color(STRUCT_STREET *p_array_street, STRUCT_HOUSE **p_array_house, int amount_house_total, int amount_street)
{ 
    int x;

    for (int i = 0; i < amount_street; i++)
    {
        
        printf("GadeNavn: %d\nDistFromstart: %d \n-------------\n", p_array_street[i].street_nr, p_array_street[i].distance_start );
        for (int y = 0; y < p_array_street[i].amount_house_street; ++y)
        {
            x = 0;
            if (p_array_house[i][y].house_color == red)
            {
                printf(RED "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }

            else if (p_array_house[i][y].house_color == green)
            {
                printf(GREEN "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
            else if (p_array_house[i][y].house_color == yellow)
            {
                printf(YELLOW "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
            else if (p_array_house[i][y].house_color == blue)
            {
                printf(BLUE "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_name, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
        }
        printf("\nWhich houses to include? (press enter between each house and continue with 0\n");

        do
        {
            scanf(" %d", &x);
            x = x - 1;
            if (x < 0)
            {
                break;
            }else{
                p_array_house[i][x].house_include = 1;
            }
        } while (x != -1);
        
    }
} 

void print_output(STRUCT_STREET *p_array_street, STRUCT_HOUSE **p_array_house, int amount_house_total, int amount_street){

    for (int i = 0; i < amount_street; i++)
    {
        if(p_array_street[i].street_include == 1){
            printf("GadeNavn: %d\nDistFromstart: %d\nStreet lenght %d \n-------------\n", p_array_street[i].street_nr, p_array_street[i].distance_start, p_array_street[i].length_of_street);
        for (int y = 0; y < p_array_street[i].amount_house_street; ++y)
        {
            if (p_array_house[i][y].house_color == red && p_array_house[i][y].house_include == 1)
            {
                printf(RED "Street number: %d\nHouse_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].street_name, p_array_house[i][y].house_name,p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }

            else if (p_array_house[i][y].house_color == green && p_array_house[i][y].house_include == 1)
            {
                printf(GREEN "Street number: %d\nHouse_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].street_name, p_array_house[i][y].house_name,p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
            else if (p_array_house[i][y].house_color == yellow && p_array_house[i][y].house_include == 1)
            {
                printf(YELLOW "Street number: %d\nHouse_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].street_name, p_array_house[i][y].house_name,p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
            else if (p_array_house[i][y].house_color == blue && p_array_house[i][y].house_include == 1)
            {
                printf(BLUE "Street number: %d\nHouse_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET,p_array_house[i][y].street_name, p_array_house[i][y].house_name,p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
        }
        }
    }

}

void assign_color(STRUCT_HOUSE **p_array_house, STRUCT_STREET *p_array_street, int amount_house_total, int amount_street)
{
    for (int i = 0; i < amount_street; i++)
    {
        for (int x = 0; x < p_array_street[i].amount_house_street; x++)
        {
            if(p_array_house[i][x].fill_amount_procent <= fill_amount_red)
            {
                p_array_house[i][x].house_color = red;
            }
            else if(p_array_house[i][x].fill_amount_procent >= fill_amount_green){
                p_array_house[i][x].house_color = green;
            }
            else if(p_array_house[i][x].fill_amount_procent > fill_amount_red && p_array_house[i][x].fill_amount_procent < fill_amount_blue && p_array_house[i][x].last_empty_days <= last_empty_days_yellow){
                p_array_house[i][x].house_color = yellow;
            }
             else if(p_array_house[i][x].fill_amount_procent > last_empty_days_blue && p_array_house[i][x].fill_amount_procent < fill_amount_blue && p_array_house[i][x].last_empty_days > last_empty_days_yellow){
                p_array_house[i][x].house_color = blue;
            }
        }
    }
}