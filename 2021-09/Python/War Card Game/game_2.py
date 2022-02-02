import random
suits = ('Hearts', 'Diamonds', 'Spades', 'Clubs')
ranks = ('Two', 'Three', 'Four', 'Five', 'Six', 'Seven',
         'Eight', 'Nine', 'Ten', 'Jack', 'Queen', 'King', 'Ace')

values = {'Two': 2, 'Three': 3, 'Four': 4, 'Five': 5, 'Six': 6, 'Seven': 7, 'Eight': 8,
          'Nine': 9, 'Ten': 10, 'Jack': 11, 'Queen': 12, 'King': 13, 'Ace': 14}


class Card:

    def __init__(self, suit, rank):
        self.suit = suit
        self.rank = rank
        self.value = values[rank]

    def __str__(self):
        return f"{self.rank} of {self.suit}"


class Deck:

    def __init__(self):
        self.deck = []
        for suit in suits:
            for rank in ranks:
                self.deck.append(Card(suit, rank))

    def shuffle(self):
        random.shuffle(self.deck)

    def pop_card(self):
        return self.deck.pop()


class Player:

    def __init__(self):
        self.playerDeck = []

    def pop_card(self):
        return self.playerDeck.pop()

    def add_cards(self, cards):
        if type(cards) == type([]):
            self.playerDeck.extend(cards)
        else:
            self.playerDeck.append(cards)


# print(type([1, 2, 3]), type([]))

# ********** Game Setting **********
GameDeck = Deck()
GameDeck.shuffle()

Player1 = Player()
Player2 = Player()

for i in range(26):
    Player1.add_cards(GameDeck.pop_card())
    Player2.add_cards(GameDeck.pop_card())

# ********** Game Play **********

isPlaying = True
round_num = 0

while isPlaying:
    round_num += 1
    print(f"-------------------\nround {round_num}\n")

    if len(Player1.playerDeck) == 0:
        print("Player1 has no card left!")
        print("Player2 won the game!\n")

        isPlaying = False
        break

    if len(Player2.playerDeck) == 0:
        print("Player2 has no card left!")
        print("Player1 won the game!\n")

        isPlaying = False
        break

    Player1_card = Player1.pop_card()
    Player2_card = Player2.pop_card()

    print(f"Player1's Card : {Player1_card}")
    print(f"Player2's Card : {Player2_card}")

    container = []
    container.append(Player1_card)
    container.append(Player2_card)

    # print(Player1_card.value)
    # print(Player2_card.value)
    # break
    if Player1_card.value > Player2_card.value:
        print("Player1 win!\n")
        Player1.add_cards(container)

    if Player1_card.value < Player2_card.value:
        print("Player2 win!\n")
        Player2.add_cards(container)

    if Player1_card.value == Player2_card.value:
        isWar = True
        while isWar:
            print("\nWar!\n")

            if len(Player1.playerDeck) < 2:
                print("Player1 don't have enough card to play war!")
                print("Player2 won the game!\n")

                isWar = False
                isPlaying = False
                break

            if len(Player2.playerDeck) < 2:
                print("Player2 don't have enough card to play war!")
                print("Player1 won the game!\n")

                isWar = False
                isPlaying = False
                break

            for i in range(2):
                Player1_card = Player1.pop_card()
                Player2_card = Player2.pop_card()

                container.append(Player1_card)
                container.append(Player2_card)

            print("War result : ")
            print(f"Player1's Card : {Player1_card}")
            print(f"Player2's Card : {Player2_card}\n")

            if Player1_card.value > Player2_card.value:
                print("Player1 win the war!")
                Player1.add_cards(container)
                isWar = False

            if Player1_card.value < Player2_card.value:
                print("Player2 win the war!")
                Player2.add_cards(container)
                isWar = False

# print(len(Player1))
