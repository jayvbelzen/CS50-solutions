#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    
    // The amount of change owed plus the same amount converted to cents
    float changeOwed;
    int cents;
   
   
    // Asks user for the amount of change he's owed in dollars
    do 
    {
        changeOwed = get_float("How much change are you owed? ");
        cents = round(changeOwed * 100);
    }
    while (changeOwed <= 0.0);
   
    // Initializing the coins the user is getting back
    int coins = 0;
   
    // Conditions for what kind of coins the user is getting back
    while (cents >= 25) 
    {
        coins++;
        cents -= 25;
    }
    while (cents >= 10 && cents < 25) 
    {
        coins++;
        cents -= 10;
    }
    while (cents >= 5 && cents < 10) 
    {
        coins++;
        cents -= 5;
    }
    while (cents >= 1 && cents < 5) 
    {
        coins++;
        cents -= 1;
    }
    
    //The final amount of coins the user is getting back
    printf("%i\n", coins);
         
}