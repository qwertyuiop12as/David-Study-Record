import random
import time
suits = ('Hearts', 'Diamonds', 'Spades', 'Clubs')
# suits = ('Hearts', 'Diamonds')
ranks = ('Two', 'Three', 'Four', 'Five', 'Six', 'Seven',
         'Eight', 'Nine', 'Ten', 'Jack', 'Queen', 'King', 'Ace')
# ranks = ('Two', 'Three', 'Four')

values = {'Two': 2, 'Three': 3, 'Four': 4, 'Five': 5, 'Six': 6, 'Seven': 7, 'Eight': 8,
          'Nine': 9, 'Ten': 10, 'Jack': 11, 'Queen': 12, 'King': 13, 'Ace': 14}


class Card:
    def __init__(self, suit, rank):
        self.suit = suit
        self.rank = rank

    def __str__(self):
        return self.suit + " " + self.rank


class Deck:
    def __init__(self):
        self.deck = []
        for suit in suits:
            for rank in ranks:
                self.deck.append(Card(suit, rank))

    def give(self, P1, P2):
        mid = len(self.deck) // 2
        P1.deck = self.deck[:mid]
        P2.deck = self.deck[mid:]

    def shuffle(self):
        random.shuffle(self.deck)

    def __str__(self):
        deck_str = ""
        for card in self.deck:
            deck_str += card.__str__() + "\n"

        return "The deck has : " + "\n" + deck_str


class Player:
    def __init__(self):
        self.deck = []

    def pop(self):
        card = self.deck.pop(0)
        return card

    def addCard(self, card):
        self.deck.append(card)

    def shuffle(self):
        random.shuffle(self.deck)

    def __str__(self):
        deck_str = ""
        for card in self.deck:
            deck_str += card.__str__() + "\n"

        return "The deck has : " + "\n" + deck_str


# Mydeck = Deck()
# Mydeck.suffle()
# print(Mydeck)


# MyDeck = Deck()
# MyDeck.suffle()

# Player1 = Player()
# Player2 = Player()

# MyDeck.give(Player1, Player2)

# print(Player1)
# print(Player2)


def Play(Deck1, Deck2):
    # print(len(Deck1.deck))
    round = 1
    storage = []
    while len(Deck1.deck) > 0 and len(Deck2.deck) > 0:
        print("Round", round)
        print("length", len(Deck1.deck), len(Deck2.deck))

        Card1 = Deck1.pop()
        Card2 = Deck2.pop()

        storage.append(Card1)
        storage.append(Card2)

        print(values[Card1.rank], values[Card2.rank])

        if values[Card1.rank] > values[Card2.rank]:
            print("Player1 Win\n--------------")
            for card in storage:
                Deck1.addCard(card)
            storage = []

        elif values[Card1.rank] < values[Card2.rank]:
            print("Player2 Win\n--------------")
            for card in storage:
                Deck2.addCard(card)
            storage = []

        else:
            print("War!\n###################")
            for i in range(2):
                storage.append(Deck1.pop())
                storage.append(Deck2.pop())

                if len(Deck1.deck) <= 0 or len(Deck2.deck) <= 0:
                    break
            # war(Deck1, Deck2)

        Deck1.shuffle()
        Deck2.shuffle()

        round += 1

    if len(Deck1.deck) <= 0 and len(Deck2.deck) <= 0:
        print("Tie!\n************")
        return
    elif len(Deck1.deck) <= 0 :
        print("Player2 Win!\n****************")
        return
    elif len(Deck2.deck) <= 0 :
        print("player1 Win!\n****************")
        return


def ChooseDeck():
    respond = -1
    while respond not in [1, 2]:
        try:
            respond = int(
                input("Which one do you prefer? Deck 1 or Deck 2? (1 or 2) : "))
        except:
            print("Please Enter a Number between 1 and 2")

    return respond


def Game():
    GameDeck = Deck()
    GameDeck.shuffle()

    Player1 = Player()
    Player2 = Player()

    GameDeck.give(Player1, Player2)

    respond = ChooseDeck()

    if respond == 1:
        PlayerDeck = Player1
        ComputerDeck = Player2
    elif respond == 2:
        PlayerDeck = Player2
        ComputerDeck = Player1

    # print("length", len(Player1.deck), len(Player2.deck))
    # round = 1
    # print("Round", round)

    # while Compare(Player1, Player2):
    #     print("length", len(Player1.deck), len(Player2.deck))

    #     round += 1
    #     print("Round", round)

    Play(Player1, Player2)

    return "A"


isPlay = True

while isPlay:
    answer = input("Will you Start the Game? (Y or N) : ")

    if answer[0].capitalize() == "N":
        print("Don't Play!")
        isPlay = False

    elif answer[0].capitalize() == "Y":
        print("Let's Play!")
        Game()

    else:
        print("Input Value Error!")
        print("Please Enter a Correct Respond")
