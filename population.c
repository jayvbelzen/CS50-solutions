#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    // Asks the user for the starting and ending size of the population
    int startingSize;
    do
    {
        startingSize = get_int("What is the populations starting size? ");
    }
    while (startingSize < 9);

    int endingSize;
    do
    {
        endingSize = get_int("What is the populations ending size? ");
    }
    while (endingSize < startingSize);

    // Calculates how many years it takes for the population to reach its final size
    int n = 0;

    for (int i = startingSize; i < endingSize;) 
    {

        int populationBorn = i / 3;
        int populationPassed = i / 4;

        i = i + populationBorn - populationPassed;
        n++;
    }

    // Prints the amount of years it takes
    printf("Years: %i\n", n);
}
