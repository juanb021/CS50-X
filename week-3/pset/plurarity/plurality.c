#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates.
#define MAX 9

// Candidates have name and vote count.
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates.
candidate candidates[MAX];

// Number of candidates.
int candidate_count;

// Function prototypes.
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage.
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates.
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    // Decimos que los votos de cada candidato son 0 para comenzar.
    for (int i = 1; i < candidate_count; i++)
    {
        candidates[i].name = argv[i];
        candidates[i].votes = 0;
    }

    // Pedimos el numero de votos.
    int voter_count = get_int("Number of voters: ");

    // Hacemos un loop sobre los votos.
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Verificamos si el voto es valido.
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }

    }

    // Mostramos al o los ganadores.
    print_winner();
}

// Actualizamos el numero de votos.
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Imprimimos al ganador de la eleccion.
void print_winner(void)
{
    int max = 0;
    // Averiguo cual es el mayo numero de votos por cada candidato en la eleccion.
    for (int i = 0; i < candidate_count; i++)
    {
        if (max < candidates[i].votes)
        {
            max = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (max == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }



    return;
}