from cs50 import get_float

# get change owed
while True:
    n = get_float("Change owed: ")
    if n >= 0:
        break

# convert change to int cents
cents = int(n * 100)

# initialize coin counter and denominations
coins = 0
money = [25, 10, 5, 1]

# iterate over money to count coins and subtract the totals
for c in money:
    i = cents % c
    coins += (cents - i) // c
    cents -= (cents - i)

# print result
print(coins)