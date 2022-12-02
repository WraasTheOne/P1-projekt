

typedef struct STRUCT_STREET
{
    int street_nr;
    int amount_house_street;
    int length_of_street;
    int open_street;
    int distance_start;
    int street_include;
} STRUCT_STREET;

typedef struct STRUCT_HOUSE
{
    int street_name;
    int house_name;
    int fill_amount_procent;
    int last_empty_days;
    int house_include;
    int house_color;
} STRUCT_HOUSE;

// for (i = 0; i < amount_street; i++)
    // {
    //     printf("%d,%d,%d,%d,%d\n", p_array_street[i].street_nr
    //                     ,p_array_street[i].amount_house_street
    //                     ,p_array_street[i].length_of_street
    //                     ,p_array_street[i].open_street
    //                     ,p_array_street[i].distance_start );
    // }
    
    // for (int i = 0; i < amount_street; i++)
    // {
    //     for(int k = 0; k <= p_array_street[i].amount_house_street; k++){
    //         printf("%d,%d,%d,%d\n",p_array_house[i][k].street_name
    //         ,p_array_house[i][k].house_name, p_array_house[i][k].fill_amount_procent, p_array_house[i][k].last_empty_days);}
    // }