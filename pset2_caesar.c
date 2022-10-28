#include <cs50.h>
#include <stdio.h>
#include <stdlib.h> //to convert a string into a number - use the function atoi
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) //argc has to be equal to 2
    {
        printf("Usage: ./caeser key");
        return 1;
    }

    for (int i = 0; i < strlen (argv[1]); i++) // argv must contain only digits
    {
        if (!isdigit(argv[1][i]))
        {
        printf("Usage: ./caeser key");
        return 1;
        }

        int k = atoi(argv[1]); //convert a string into a integer

        string plaintext = get_string("Plaintext: ");
        printf("Ciphertext: ");

        for (int j = 0; j < strlen(plaintext); j++)
        {
            if (isupper(plaintext[j]))
            {
            printf("%c", (plaintext[j] - 65 + k) % 26 + 65);
            }

            else if (islower(plaintext[j]))
            {
            printf("%c", (plaintext[j] - 97 + k) % 26 + 97);
            }

            else
            {
                printf("%c", plaintext[j]);
            }

        }

        printf("\n");

    }

}
