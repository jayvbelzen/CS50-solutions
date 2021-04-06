#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    
    //If there's less or more than two inputs return an error
    if (argc != 2)
    {
        printf("ERROR\n");
        return 1;
    }
    
    //Loops through given command-line argument to check if its all numerical digits
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i])) 
        {
            printf("Usage is ./caesar key\n");
            return 1;
        }
    }
    
    //Turns argument into an int
    int key = atoi(argv[1]);
    
    if (key < 0)
    {
        printf("ERROR\n");
        return 1;
    }
    else
    {
        //Prompts user for plaintext input
        string plaintext = get_string("Plaintext: ");
        
        printf("Ciphertext: ");
        
        // Loop through every character in string
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            if (islower(plaintext[i]))
            {
                //formula for cipher - 97 to account for ascii number
                printf("%c", (((plaintext[i] + key) - 97) % 26) + 97);
            }
            else if (isupper(plaintext[i]))
            {
                printf("%c", (((plaintext[i] + key) - 65) % 26) + 65);
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
    }
    printf("\n");
    return 0;
}
