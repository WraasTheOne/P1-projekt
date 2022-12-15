

void print_prompt_house_color(STRUCT_STREET *p_array_street, STRUCT_HOUSE **p_array_house, int amount_house_total, int amount_street)
{ 
    int x;

    for (int i = 0; i < amount_street; i++)
    {
        
        printf("Street number: %d\nDistFromstart: %d \n-------------\n", p_array_street[i].street_no, p_array_street[i].distance_start );
        for (int y = 0; y < p_array_street[i].amount_house_street; ++y)
        {
            x = 0;
            if (p_array_house[i][y].house_color == red)
            {
                printf(RED "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_no, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }

            else if (p_array_house[i][y].house_color == green)
            {
                printf(GREEN "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_no, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
            else if (p_array_house[i][y].house_color == yellow)
            {
                printf(YELLOW "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_no, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
            else if (p_array_house[i][y].house_color == blue)
            {
                printf(BLUE "House_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].house_no, p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
        }
        printf("\nWhich houses to include?\n (press enter between each house and continue with 0\n");

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
    printf("----------------------------------------------------\n");
    printf("All included houses:\n");
    for (int i = 0; i < amount_street; i++)
    {
        if(p_array_street[i].street_include == 1){
            printf("Street number: %d\nDistFromstart: %d\nStreet lenght %d \n-------------\n", p_array_street[i].street_no, p_array_street[i].distance_start, p_array_street[i].length_of_street);
        for (int y = 0; y < p_array_street[i].amount_house_street; ++y)
        {
            if (p_array_house[i][y].house_color == red && p_array_house[i][y].house_include == 1)
            {
                printf(RED "Street number: %d\nHouse_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].street_no, p_array_house[i][y].house_no,p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }

            else if (p_array_house[i][y].house_color == green && p_array_house[i][y].house_include == 1)
            {
                printf(GREEN "Street number: %d\nHouse_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].street_no, p_array_house[i][y].house_no,p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
            else if (p_array_house[i][y].house_color == yellow && p_array_house[i][y].house_include == 1)
            {
                printf(YELLOW "Street number: %d\nHouse_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET, p_array_house[i][y].street_no, p_array_house[i][y].house_no,p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
            }
            else if (p_array_house[i][y].house_color == blue && p_array_house[i][y].house_include == 1)
            {
                printf(BLUE "Street number: %d\nHouse_number: %d\nBin_fill_amount: %d%%\nDays since last empty: %d\n\n" RESET,p_array_house[i][y].street_no, p_array_house[i][y].house_no,p_array_house[i][y].fill_amount_procent, p_array_house[i][y].last_empty_days);
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