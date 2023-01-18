STRUCT_STREET *load_streets(int *amount_streets)
{
    int count = 0, reads = 0;
    char c;
    STRUCT_STREET street;
    STRUCT_STREET *array_street;

    FILE *file_streets;

    file_streets = fopen("streets2.csv", "r");

    if (file_streets == NULL)
    {
        printf("Error opening file.\n");
    }

    for (c = getc(file_streets); c != EOF; c = getc(file_streets))
    {
        if (c == '\n') // Increment count if this character is newline
        {
            count = count + 1;
        }
    }

    array_street = malloc(count * sizeof(street));
    rewind(file_streets);
    do
    {
        reads = fscanf(file_streets,"%d,%d,%d,%d,%d\n",
                       &array_street[*amount_streets].street_no,
                       &array_street[*amount_streets].amount_house_street,
                       &array_street[*amount_streets].length_of_street,
                       &array_street[*amount_streets].open_street,
                       &array_street[*amount_streets].distance_start);

        if (reads == 5)(*amount_streets)++;

        if (reads != 5 && !feof(file_streets))
        {
            printf("File format incorrect.\n");
        }

        if (ferror(file_streets))
        {
            printf("Error reading file.\n");
        }

    } while (!feof(file_streets));

    fclose(file_streets);

    return (array_street); 
}

STRUCT_HOUSE **load_houses(STRUCT_STREET *array_streets, int amount_street)
{
    int i;
    int j;


    FILE *file;
    file = fopen("houses2.csv", "r");

    STRUCT_HOUSE house;
    STRUCT_HOUSE **array_houses;
    array_houses = malloc(amount_street * sizeof(house));

    for (j = 0; j < amount_street; j++)
    {

        array_houses[j] = malloc((array_streets[j].amount_house_street + 1) * sizeof(house));

        for (i = 0; i <= array_streets[j].amount_house_street; i++)
        {
            fscanf(file, "%d,%d,%d,%d,%d\n",
                   &array_houses[j][i].street_no,
                   &array_houses[j][i].house_no,
                   &array_houses[j][i].fill_amount_procent,
                   &array_houses[j][i].last_empty_days,
                   &array_houses[j][i].house_include);
        }
    }
    fclose(file);

    return array_houses;
}






STRUCT_STREET *generate_street_array(int amount_street)
{
    int i;
    STRUCT_STREET *array_street;

    srand(time(NULL));
    array_street = malloc(amount_street * sizeof(STRUCT_STREET));
    for (i = 0; i < amount_street; ++i)
    {
        array_street[i].street_no = (i+1);
        array_street[i].amount_house_street = 1 + rand() % MAXHOUSE;
        array_street[i].length_of_street = 1 + rand() % 20;
        array_street[i].distance_start = 1 +rand() % 20;
        array_street[i].open_street = rand() & 1;

    }
    return array_street;
}

STRUCT_HOUSE **generate_house_array(int amount_street, int amount_house_total, STRUCT_STREET *p_array_street)
{

    STRUCT_HOUSE **array_house;
    array_house = malloc(amount_street * sizeof(STRUCT_HOUSE));
    if (array_house == NULL)
    {
        printf("Memory not allocated \n");
        exit(0);
    }
    else
    {
        for (int x = 0; x < amount_street; ++x)


        {
            array_house[x] = malloc((p_array_street[x].amount_house_street + 1) * sizeof(STRUCT_HOUSE));
            for (int j = 0; j <= p_array_street[x].amount_house_street; ++j)
            {
                array_house[x][j].fill_amount_procent = rand() % 100;
                array_house[x][j].last_empty_days = rand() % 30;
                array_house[x][j].street_no = x + 1;
                array_house[x][j].house_no = j + 1;
            }
        }
    }
    return (array_house);
}