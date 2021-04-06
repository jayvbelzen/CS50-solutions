#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int countAverage(string text);


int main(void)
{
    
    //Prompts for input
    string givenText = get_string("Text: ");
    
    //Checks the text grade level
    if (countAverage(givenText) > 16)
    {
        printf("Grade 16+\n");
    }
    else if (countAverage(givenText) < 1)
    {
        printf("Before Grade 1\n");
    }
    else 
    {
        printf("Grade %i\n", countAverage(givenText));
    }
    
}

//Function to return reading grade
int countAverage(string text) 
{
    double letters = 0;
    double words = 1;
    double sentences = 0;
    
    //Loops through entire text and checks for letters, words and sentences
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (isalpha(text[i]))
        {
            letters++;
        }
    }
    
    //Formula for average letters, sentences and index
    double averageLetters = (letters / words) * 100;
    double averageSentences = (sentences / words) * 100;
    
    double index = 0.0588 * averageLetters - 0.296 * averageSentences - 15.8;
    
    //returns a rounded number
    return round(index);
}

