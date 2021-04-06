#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
string giveWinner(int scoreOne, int scoreTwo);


int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    printf("%s\n", giveWinner(score1, score2));
}

int compute_score(string word)
{
    int calculatedScore = 0;
    int letterScore;
    
    for (int i = 0, n = strlen(word); i < n; i++) 
    {
        // Gets the character at place i in the string and makes it lowercase
        char letter = tolower(word[i]);
        // Goes to ASCII number - 97 in array, - 97 because the first letter 'a' is at place 97 in table
        letterScore = POINTS[letter - 97];
        if (letter >= 'a' && letter <= 'z')    
        {
            calculatedScore += letterScore;
        }
        
    }
    
    return calculatedScore;
}

string giveWinner(int scoreOne, int scoreTwo)
{
    if (scoreOne > scoreTwo)
    {
        return "Player 1 wins!";
    }
    else if (scoreTwo > scoreOne)
    {
        return "Player 2 wins!";
    }
    else 
    {
        return "Tie!";
    }
}