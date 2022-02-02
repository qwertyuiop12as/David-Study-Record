import random
suits = ('Hearts', 'Diamonds', 'Spades', 'Clubs')
ranks = ('Two', 'Three', 'Four', 'Five', 'Six', 'Seven',
         'Eight', 'Nine', 'Ten', 'Jack', 'Queen', 'King', 'Ace')
values = {'Two': 2, 'Three': 3, 'Four': 4, 'Five': 5, 'Six': 6, 'Seven': 7, 'Eight': 8, 'Nine': 9, 'Ten': 10, 'Jack': 10,
          'Queen': 10, 'King': 10, 'Ace': 11}


class Card :
    def __init__(self, suit, rank) :
        self.suit = suit
        self.rank = rank
        self.value = values[rank]
    
    def __str__(self) :
        return f"{self.rank} of {self.suit} ({self.value})"

class Deck :
    def __init__(self) :
        self.deck = []
        for suit in suits :
            for rank in ranks :
                self.deck.append(Card(suit, rank))

    def shuffle(self):
        random.shuffle(self.deck)

    def dealOne(self) :
        return self.deck.pop()
    
    def __str__(self) :
        DeckStr = ""
        for card in self.deck :
            DeckStr += f"{card}\n"

        return DeckStr

class Hand :
    def __init__(self, name) :
        self.cards = []
        self.name = name
        self.point = 0
        self.AceCount = 0

    def addCard(self, card) :
        self.cards.append(card)
        if card.rank == "Ace" :
            self.AceCount += 1

        self.point += values[card.rank]

    def checkAce(self) :
        if self.point > 21 and self.AceCount > 0 :
            self.point -= 10
            self.AceCount -= 1
    
    def __str__(self):
        CardsStr = f"\n\n{self.name}'s Card\n\n"
        for card in self.cards :
            CardsStr += f"{card}\n"

        return CardsStr

class Chips:
    def __init__(self) :
        self.chip = 100
        self.bet = 0

    def WinBet(self):
        self.chip += self.bet
    
    def LoseBet(self):
        self.chip -= self.bet

    def __str__(self) :
        return f"Player has {self.chip} Chips!"


def ShowOneCard(Hand) :
    print("\n\nDealer's Card\n")
    print(Hand.cards[0])
    print("<Hidden Card> (?)")

def Betting(Chips) :
    Bet = 0
    while Bet <= 0 or Bet > Chips.chip :
        Bet = int(input(f"How many Chips would you like to Bet? (You have {Chips.chip} Chips) "))

        if (Bet > Chips.chip) :
            print(f"\nYou can't bet more than {Chips.chip} Chips!\n")
        if (Bet <= 0) :
            print(f"\nYou should bet more than 0 Chips!\n")

    return Bet


def PlayerWin(Chip) :
    Chip.WinBet()
    print(f"You won {Chip.bet} Chips.")


def PlayerLose(Chip) :
    Chip.LoseBet()
    print(f"You lost {Chip.bet} Chips.")


def PlayerBust(PlayerHand, Chip) :
    print(f"You are {PlayerHand.point} Points now.")
    print("Bust!\n")
    PlayerLose(Chip)


def DealerBust(DealerHand, Chip) :
    print("Bust!\n")
    PlayerWin(Chip)


def BlackJack(Chips) :
    print("You are 21 Points!\nBlackJack!")
    print("\nYou Win")
    PlayerWin(Chips)


def HitOrStand(PlayerHand, GameDeck) :
    Answer = "Y"

    while Answer == "Y" and PlayerHand.point < 21:
        print(f"You are {PlayerHand.point} Points now. ({PlayerHand.AceCount} Ace(s))")
        Answer = input("Would you like to Hit? (Y or N): ")[0].upper()

        if Answer == "Y" :
            Card = GameDeck.dealOne()
            print(f"\nThe Card is\n{Card}\n")
            PlayerHand.addCard(Card)
            PlayerHand.checkAce()
    

def DealerHit(DealerHand, GameDeck) :
    print(f"Dealer is {DealerHand.point} Points now. ({DealerHand.AceCount} Ace(s))")

    while DealerHand.point <= 16 :
        print("Dealer Hits one more Card...")
        Card = GameDeck.dealOne()
        print(f"\nThe Card is\n{Card}\n")
        DealerHand.addCard(Card)
        DealerHand.checkAce()
        print(f"Dealer is {DealerHand.point} Points now.")


print("\nWelcome to Black Jack")

isPlay = "Y"
while isPlay == "Y" :

    Chip = Chips()
    # One Game (Until Player lose all chips)
    while Chip.chip > 0 :
        GameDeck = Deck()
        GameDeck.shuffle()
        print("--------------------------")

        DealerHand = Hand("Dealer")
        PlayerHand = Hand("Player")

        for i in range(2) :
            DealerHand.addCard(GameDeck.dealOne())
            PlayerHand.addCard(GameDeck.dealOne())

        Chip.bet = Betting(Chip)
        print(f"Betting: {Chip.bet}")

        ShowOneCard(DealerHand)
        print(PlayerHand)
        PlayerHand.checkAce()
        print("--------------------------")

        if PlayerHand.point == 21 :
            BlackJack(Chip)
        else :
            HitOrStand(PlayerHand, GameDeck)

            if PlayerHand.point > 21 :
                PlayerBust(PlayerHand, Chip)
            elif PlayerHand.point == 21 :
                BlackJack(Chip)
            else :
                print(DealerHand)
                DealerHit(DealerHand, GameDeck)

                if DealerHand.point > 21 :
                    DealerBust(DealerHand, Chip)

                else :
                    print("\nResult")
                    print("---------------")
                    print(f"Dealer : {DealerHand.point}\nPlayer : {PlayerHand.point}\n")
                    if PlayerHand.point > DealerHand.point :
                        PlayerWin(Chip)
                    elif PlayerHand.point < DealerHand.point :
                        PlayerLose(Chip)
                    else :
                        print("Tie!")

    print("You have 0 chips remaining\nGame Over!")
    print("---------------")
    
    isPlay = input("Would you like to play again? (Y or N): ")[0].upper()