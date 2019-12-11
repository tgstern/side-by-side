#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // gets positive change amount in a float
    float dollars = -1;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    
    // rounds dollars to cents and converts to int
    int cents = round(dollars * 100);
    
    // coin counting function with remainder division
    int coins = 0;
    
    // adds greatest number of quarters needed to coins and remainder in cents
    if (cents % 25 == 0)
    {
        coins = cents / 25;
        cents = 0;
    }
    else
    {
        coins = (cents - (cents % 25)) / 25;
        cents = (cents % 25);
        
        // adds greatest number of dimes needed to coins and remainder in cents
        if (cents % 10 == 0)
        {
            coins += (cents / 10);
            cents = 0;
        }
        else
        {
            coins += (cents - (cents % 10)) / 10;
            cents = (cents % 10);
            
            // adds greatest number of nickels needed to coins and remainder in cents
            if (cents % 5 == 0)
            {
                coins += (cents / 5);
                cents = 0;
            }
            else
            {
                coins += (cents - (cents % 5)) / 5;
                cents = (cents % 5);
            }
            
            // adds remaining pennies needed to coins
            coins += cents;
        }
    }
    
    // prints number of coins
    printf("%i\n", coins);
}
