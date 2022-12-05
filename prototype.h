#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"

typedef enum color{red, green, yellow, blue} color;

#define MAXHOUSE 8

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


STRUCT_STREET *generate_street_array(int amount_street);
STRUCT_STREET *load_streets(int *amount_streets);
STRUCT_HOUSE **generate_house_array(int amount_street, int amount_house_total, STRUCT_STREET *p_array_street); 
STRUCT_HOUSE **load_houses(STRUCT_STREET *array_streets, int amount_street);
void assign_color(STRUCT_HOUSE **p_array_house, STRUCT_STREET *p_array_street, int amount_house_total, int amount_street);
void print_house_color(STRUCT_STREET* p_array_street, STRUCT_HOUSE** p_array_house, int amount_house_total, int amount_street);
void print_output(STRUCT_STREET *p_array_street, STRUCT_HOUSE **p_array_house, int amount_house_total, int amount_street);



// category 4 (the highest priority) (green)
#define fill_amount_green 85

// category 3 (the lowest priority)(blue)
#define fill_amount_blue 85
#define last_empty_days_blue 15


// category 2 (the highest priority) (yellow)
#define fill_amount_yellow 50
#define last_empty_days_yellow 14

// category 1 (the lowest priority)(red)
#define fill_amount_red 25