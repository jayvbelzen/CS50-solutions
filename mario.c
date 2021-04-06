#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // Asks user for height of pyramid between 1 and 8 blocks
    int height;
    do
    {
        height = get_int("What height do you want the pyramid to be? ");
    }
    while (height < 1 || height > 8);


    // Builds the pyramid based on height
    for (int i = 0; i < height;)
    {
        i++;
        // Makes sure that the left side of the pyramid has the correct indentation
        for (int k = 0; k < (height - i); k++)
        {
            printf(" ");
        }

        // Makes the left part of the pyramid
        for (int j = 0; j < i; j++)
        {

            printf("#");
        }

        printf("  ");

        // Makes the right part of the pyramid
        for (int z = 0; z < i; z++)
        {
            printf("#");
        }

        printf("\n");
    }
}
