#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //check
    if (argc > 2 || argc <2)
    {
        printf("./caesar key\n");
        return 1;
    }
    for (int t = 0; argv[1][t] != '\0'; t++)
    {
        //guarantee that the value is a number
        if (argv[1][t] >= 'A' && argv[1][t]  <= 'z')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        //get the plaintext
        string plaintext = get_string("Plaintext: ");
        int n = strlen(plaintext);
        int k = atoi(argv[1]);
        printf("ciphertext: ");
        for (int i = 0; i < n; i++)
        {
            //check if the letter in position i is uppercase or lowercase
            if (plaintext[i] > 'A' && plaintext[i] < 'Z')
            {
                printf("%c", ((plaintext[i] - 'A' + k) % 26) + 'A');
            }
            else if (plaintext[i] > 'a' && plaintext[i] < 'z')
            {
                printf("%c", ((plaintext[i] - 'a' + k) % 26) + 'a');
            }
            else
            {
                //if it's a symbol like comma print it without change
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        return 0;
    }
}