#include <stdio.h>

#define STARTING_POPULATION_THRESHOLD 9
#define BIRTH_RATE 3
#define DEATH_RATE 4

typedef struct
{
    int starting_population;
    int ending_population;
} Population;

void get_input(Population *pop)
{
    while (1)
    {
        printf("Starting Population: ");
        scanf("%d", &(pop->starting_population));
        if (pop->starting_population < STARTING_POPULATION_THRESHOLD)
        {
            printf("Starting population must be 9 or more animals\n");
        }
        else
        {
            break;
        }
    }

    while (1)
    {
        printf("Ending Population: ");
        scanf("%d", &(pop->ending_population));
        if (pop->ending_population <= pop->starting_population)
        {
            printf("Ending population must be more than the starting population\n");
        }
        else
        {
            break;
        }
    }
}

char *calculate(Population *pop)
{
    int years = 0;
    while (pop->starting_population < pop->ending_population)
    {
        int born = pop->starting_population / BIRTH_RATE;
        int dead = pop->starting_population / DEATH_RATE;
        int growth = born - dead;
        pop->starting_population += growth;
        years++;
    }

    char *result;
    asprintf(&result, "%d Years", years);
    return result;
}

int main()
{
    Population pop;
    get_input(&pop);
    char *result = calculate(&pop);
    printf("%s\n", result);
    free(result);
    return 0;
}
