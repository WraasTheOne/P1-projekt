typedef enum color{red, green, yellow, blue} color;

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

