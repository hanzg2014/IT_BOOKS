#coding:utf8
#!/usr/bin/python

import random
import collections
Card = collections.namedtuple('Card', ['rank', 'suit'])

class FrenchDeck:
	ranks = ['A'] + [str(n) for n in range(2, 11)] + list('JQK')
		#['A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']
	suits = 'spades diamonds clubs hearts'.split()
	def __init__(self):
		self._cards = [Card(rank, suit) for suit in self.suits for rank in self.ranks]
	def __len__(self):
		return len(self._cards)
	def __getitem__(self, position):
		return self._cards[position]


deck = FrenchDeck()
print deck.ranks
print deck.suits
print deck._cards

print ['A'] + [str(n) for n in range(2, 11)] + list('JQK')
print len(deck)
print random.choice(deck)

for card in reversed(deck):
	print card

print Card('Q', 'hearts') in deck

print "##############"
random.shuffle(deck)
print "##############"

suit_values = dict(spades=3, hearts=2,diamonds=1,clubs=0)
print suit_values


def spades_high(card):
	rank_value = FrenchDeck.ranks.index(card.rank)
	return rank_value * len(suit_values) + suit_values[card.suit]

for card in sorted(deck, key=spades_high): # doctest: +ELLIPSIS
	print(card)


