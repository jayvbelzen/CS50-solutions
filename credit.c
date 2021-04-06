#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long long creditCard;
    
    do 
    {
        creditCard = get_long_long("Creditcard number: ");
    }
    while (creditCard < 0);
  
  
    int checkNumbers = 0;
    long long digits = creditCard;
    
    while (digits > 0)
    {
        digits = digits / 10;
        checkNumbers++;
    }
    
    if ((checkNumbers != 13) && (checkNumbers != 15) && (checkNumbers != 16))
    {
        printf("INVALID\n");
    }
    
    
    int number[checkNumbers];
    
    // Stores all numbers in an array
    for (int i = 0; i < checkNumbers; i++) 
    {
        number[i] = creditCard % 10;
        creditCard = creditCard / 10;
  
    }
  
    int originalNumber[checkNumbers];
    
    // Saves the numbers in seperate variable so you can reuse number[]
    for (int i = 1; i < checkNumbers; i++)
    {
        originalNumber[i] = number[i];
    }
    
    // Multiplies every other digit by 2, starting from the second-to-last digit
    for (int i = 1; i < checkNumbers; i += 2) 
    {
        number[i] = number[i] * 2;
    }
    
    
    // temp is used to temporarily store numbers that are then added to verify
    // verify % 10 should always be 0 for the checksum to be correct
    int verify = 0;
    int temp;
    
    // Checks if the checksum is correct for all creditcards entered with 13 numbers
    if (checkNumbers == 13)
    {
        for (int i = 0; i < checkNumbers; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            verify = verify + temp;
        }
    
        // checks for the first number on the card to be the same as VISA and if the checksum == 0
        if ((originalNumber[12] == 4) && (verify % 10 == 0)) 
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }  
    // Checks if the checksum is correct for all creditcards entered with 15 numbers
    if (checkNumbers == 15)
    {
        for (int i = 0; i < checkNumbers; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            verify = verify + temp;
        }
        
        // checks for the first and second number on the card to be the same as AMEX and if the checksum == 0
        if ((originalNumber[14] == 3) && (originalNumber[13] == 4 || originalNumber[13] == 7) && (verify % 10 == 0))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        } 
    }
    // Checks if the checksum is correct for all creditcards entered with 16 numbers
    if (checkNumbers == 16)
    {
        for (int i = 0; i < checkNumbers; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            verify = verify + temp;
        }
      
        // checks for the first number on the card to be the same as VISA or the first and second number to be the same as MASTERCARD and if the checksum == 0
        if ((originalNumber[15] == 4) && (verify % 10 == 0))
        {
            printf("VISA\n");
        }
        else if ((originalNumber[15] == 5) && ((originalNumber[14] == 1) || (originalNumber[14] == 2) || (originalNumber[14] == 3)
                                               || (originalNumber[14] == 4) || (originalNumber[14] == 5)) && (verify % 10 == 0))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}