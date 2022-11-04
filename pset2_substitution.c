#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2) //argc has to be equal to 2
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }

    //Validate that the key consists only alphabets
    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters. \n");
            return 1;
        }
    }

    // Validate that the key consists of 26 characters
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters. \n");
        return 1;
    }

//Validate taht each alphabet in the key is unique.
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }

        }
    }

    // Prompt the user for the plaintext
    string plaintext = get_string("Plaintext: ");

    // Convert all alphabets in the key uppercase
    for (int i = 0; i < strlen(key); i++)
    {
        if(islower(key[i]))
        {
            key[i] = key[i] - 32;
        }
    }

    //Print cyphertext
    printf("Ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            int letter = plaintext[i] - 65;
            printf("%c", key[letter]);
        }

        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i] - 97;
            printf("%c", key[letter] + 32);
        }

        else printf("%c", plaintext[i]);
    }
    printf("\n");

}
