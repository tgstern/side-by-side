#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
    // check that only one additional argument is given to be the key
    if (argc != 2)
    {
        printf("Usage ./caesar keyword\n");
        return 1;
    }
    else
    {
        // check that argv[1] is made of only alpha character, else break
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
            {
                if (! isalpha(argv[1][i]))
                {
                    printf("Usage: ./caesar keyword\n");
                    return 1;
                    break;
                }
            }
        
            // get plaintext string from user
            string plain = get_string("plaintext: ");
            
            printf("ciphertext: ");
            // applies key shift to plain text
            for (int i = 0, n = strlen(plain), j = 0; i < n; i++)
                {
                    // store the key as an int
                    int key = shift(argv[1][j % strlen(argv[1])]);
                
                    // moves uppercase letters
                    if (plain[i] >= 65 && plain[i] <= 90)
                    {
                        printf("%c", 65 + ((plain[i] + key - 65) % 26));
                        j++;
                    }
                    // moves lowercase letters
                    else if (plain[i] >= 97 && plain[i] <= 122)
                    {
                        printf("%c", 97 + ((plain[i] + key - 97) % 26));
                        j++;
                    }
                    // prints additional characters
                    else
                    {
                        printf("%c", plain[i]);
                    }
                }
            printf("\n");
            }
    }

// shift function to output int given char c in the keyword
int shift(char c)
{
   if (c <= 90)
   {
       return c - 65;
   }
   else if (c >= 97)
   {
       return c - 97;
   }
   else
   {
       return 0;
   }
}
