# def make_change(amount, coins = [1,2,5,10,20,50][::-1], hand = None):
#     hand = [] if hand is None else hand
#     if (amount == 0):
#         yield hand
#     else:
#         for coin in coins:
#             if (amount < coin) or (len(hand) > 0 and hand[-1] < coin):
#                 continue 
#             for result in make_change(amount - coin, coins = coins, hand = hand +[coin]):
#                 yield result


# hands = make_change(100)

# for hand in hands:
#     print hand
#     print "\n"

# print [1,2,5,10,20,50,100][::-1]


import itertools
first_letter = lambda x: x[0]
names = ['Alan', 'Adam', 'Wes', 'Will', 'Albert', 'Steven']

for letter, names in itertools.groupby(names, first_letter):
    print letter, list(names) # names is a generator