#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Insira o texto: ");
    int letter = 0;
    int word = 1;
    int sentence = 0;
    int L = 0;
    int S = 0;
    float grade = 0;

    //check every character in the string 'text'
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //check if it's a letter or not
        if (text[i] >= 'A' && text[i] <= 'z')
        {
            letter++;
        }
        else if (text[i] == ' ')
        {
            //count a word every space
            word++;
        }
        else if (text[i] == '.' || text[i] == '?')
        {
            //count a sentence every ponctuation
            sentence++;
        }
        else if (text[i] == '!')
        {
            sentence++;
        }
    }
    //Get average letters and sentences in 100 words
    L = 100 * letter / word;
    S = 100 * sentence / word;
    //get grade by Coleman-Liau formula
    grade =  0.0588 * L - 0.296 * S - 15.8;
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", grade);
    }
}