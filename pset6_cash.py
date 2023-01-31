from cs50 import get_float

while True:
    cents = get_float("Cash Owed: ")
    if cents > 0:
        break

cents = round(cents * 100)

count = 0

while cents > 0:
    if cents >= 25:
        cents = cents - 25
        count = count + 1
    elif cents >= 10:
        cents = cents - 10
        count = count + 1
    elif cents >= 5:
        cents = cents - 5
        count = count + 1
    elif cents >= 1:
        cents = cents - 1
        count = count + 1

print("Total Coins: ", count)
