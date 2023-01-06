#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//User imput a key that will be used to convert sentences
int main(int argc, char *argv[])
{
    //Check if the use introduced a key
    if (argc == 1)
    {
        printf("insert a key\n");
        return 1;
    }
    int control = strlen(argv[1]);
    for (int q = 0; q < control; q++)
    {
        for (int p = q + 1; p < control; p++)
        {
            //Check if the key is made out of alphabetic
            if (isalpha(argv[1][q]) == 0)
            {
                printf("Key must only contain alphabetic characters. \n");
                return 1;
            }
            //Check if terms and if one letter appear more than once
            if (toupper(argv[1][q]) == toupper(argv[1][p]))
            {
                printf("There's a duplicated character.");
                return 1;
            }
        }
    }
    //Check if there's only one key with 26 characters
    if (argc > 2 || argc < 2 || control != 26)
    {
        printf("Insert a valid key with 26 characters.\n");
        return 1;
    }
    else
    {
        //Get the word that will be encoded
        string Plaintext = get_string("Plaintext: ");
        int n = strlen(Plaintext);
        printf("ciphertext: ");
        for (int i = 0; i < n; i++)
        {
            //Check if the letter in position 'i' is uppercase
            if (Plaintext[i] >= 'A' && Plaintext[i] <= 'Z')
            {
                int j = Plaintext[i] - 'A';
                //convert the letter depending if the correspondent letter was lowercase or uppercase
                if (argv[1][j] > 'a')
                {
                    Plaintext[i] = argv[1][j] - 32;
                    printf("%c", Plaintext[i]);
                }
                else
                {
                    Plaintext[i] = argv[1][j];
                    printf("%c", Plaintext[i]);
                }
            }
            //Check if the letter in position 'i' is lowercase
            else if (Plaintext[i] >= 'a' && Plaintext[i] <= 'z')
            {
                int j = Plaintext[i] - 'a';
                //convert the letter depending if the correspondent letter was lowercase or uppercase
                if (argv[1][j] < 'a')
                {
                    Plaintext[i] = argv[1][j] + 32;
                    printf("%c", Plaintext[i]);
                }
                else
                {
                    Plaintext[i] = argv[1][j];
                    printf("%c", Plaintext[i]);
                }
            }
            else
            {
                //if the character was a symbol, simply print it
                printf("%c", Plaintext[i]);
            }
        }
        printf("\n");
        return 0;
    }
}