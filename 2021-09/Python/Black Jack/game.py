import random
suits = ('Hearts', 'Diamonds', 'Spades', 'Clubs')
ranks = ('Two', 'Three', 'Four', 'Five', 'Six', 'Seven',
         'Eight', 'Nine', 'Ten', 'Jack', 'Queen', 'King', 'Ace')
values = {'Two': 2, 'Three': 3, 'Four': 4, 'Five': 5, 'Six': 6, 'Seven': 7, 'Eight': 8, 'Nine': 9, 'Ten': 10, 'Jack': 10,
          'Queen': 10, 'King': 10, 'Ace': 11}


class Card:
    def __init__(self, suit, rank):
        self.suit = suit
        self.rank = rank
        self.value = values[self.rank]

    def __str__(self):
        return self.rank + " of " + self.suit


class Deck:
    def __init__(self):
        self.deck = []
        for suit in suits:
            for rank in ranks:
                self.deck.append(Card(suit, rank))

    def suffle(self):
        random.shuffle(self.deck)

    def deal(self):
        return self.deck.pop()

    def __str__(self):
        deck_comp = ""
        for card in self.deck:
            deck_comp += "\n" + card.__str__()

        return "The deck has:" + deck_comp


class Player:
    def __init__(self):
        self.chips = 100
        # self.sum = 0
        self.bet = 0

    def winbet(self):
        self.chips += self.bet

    def losebet(self):
        self.chips -= self.bet


# ---------------- Functions ----------------
def bet(player) :
    bet = -1

    while True:
        print(f"You have {player.chips} chips remaining.")

        try:
            bet = int(input("\nHow many chips would you bet? "))
        except ValueError:
            print("Please input a number!")

        if bet < 1:
            print("Please bet more than 0 chip!\n")
        elif bet > player.chips :
            print(f"\nYou have {player.chips} chips remaining.\nPlease do not bet more than {player.chips} chips!\n")
        else :
            break

    return bet


def winMessage() :
    print("\nUser Win!")
    return

def loseMessage() :
    print("\nDealer Win!")
    return

def chooseWinner(userPoint, dealerPoint) :
    if userPoint > dealerPoint :
        return "User"
    elif userPoint < dealerPoint :
        return "Dealer"
    else :
        return "Tie"

def playerBustCheck(userPoint) :
    if userPoint > 21:
        print(f"\nYou are {userPoint} Points now.\nYou Bust!")
        return True
    else :
        return False


def dealerBustCheck(dealerPoint) :
    if dealerPoint > 21:
        print(f"\nDealer is {dealerPoint} Points now.\nDealer Bust!")
        return True
    else :
        return False

def AceCheck(AceCount, sum) :
    while AceCount > 0 and sum > 21 :
        sum -= 10
        AceCount -= 1
        print(f"\nUsed one Ace card. {AceCount} Ace Card(s) left.")

    return AceCount, sum

def playerPopCard(GameDeck) :
    sum = 0
    AceCount = 0

    print("\nYour cards are : ")
    for turn in range(2):
        card = GameDeck.deal()
        print(card, f"({card.value})")
        sum += card.value

        if card.rank == "Ace" :
            AceCount += 1
            
    if sum > 21 and AceCount > 0 :
        (AceCount, sum) = AceCheck(AceCount, sum)

    while sum < 21:
        print(f"\nYou are {sum} Points now. (You have {AceCount} Ace Card(s))")
        if input(f"\nWould you like to deal one more card?(Y or N) ").upper() == 'Y':
            card = GameDeck.deal()
            sum += card.value

            if card.rank == "Ace" :
                AceCount += 1


            print(card, f"({card.value})", sum)
        else:
            break

    if sum > 21 and AceCount > 0 :
        (AceCount, sum) = AceCheck(AceCount, sum)

    print(f"Final point : {sum}")
    return sum


def dealerPopCard(GameDeck) :
    sum = 0
    AceCount = 0

    print("\nDealer's cards are : ")
    for turn in range(2):
        card = GameDeck.deal()
        print(card, f"({card.value})")
        sum += card.value

        if card.rank == "Ace" :
            AceCount += 1
        
    if sum > 21 and AceCount > 0 :
        (AceCount, sum) = AceCheck(AceCount, sum)

    print(f"Dealer is {sum} Points now. (Dealer has {AceCount} Ace Card(s))\n")

    while sum <= 17:
        print("Dealer is getting one more card...")
        card = GameDeck.deal()
        print(card, f"({card.value})")

        if card.rank == "Ace" :
            AceCount += 1

        sum += card.value

        print(f"Dealer is {sum} Points now. (Dealer has {AceCount} Ace Card(s))\n")

    if sum > 21 and AceCount > 0 :
        (AceCount, sum) = AceCheck(AceCount, sum)

    print(f"Final point : {sum}")
    return sum


# ---------------- Game ----------------
while True :

    GameDeck = Deck()
    GameDeck.suffle()
    User = Player()

    while User.chips > 0:
        winCheck = 0 # 0 = Tie, 1 = Win, -1 = lose

        # User Turn
        print("\nYour Turn\n")
        User.bet = bet(User)
        userPoint = playerPopCard(GameDeck)

        # Check if Player's point exceeds 21
        if playerBustCheck(userPoint) == True :
            loseMessage()
            User.losebet()

        # Dealer Turn
        else:
            Dealer = Player()
            print("\nDealer's Turn")

            dealerPoint = dealerPopCard(GameDeck)

            # Check if Dealer's point exceeds 21
            if dealerBustCheck(dealerPoint) == True :
                winMessage()
                User.winbet()
            else:
                print(f"\nYou : {userPoint} Points")
                print(f"Dealer : {dealerPoint} Points")

                winner = chooseWinner(userPoint, dealerPoint)

                if winner == "User" :
                    winMessage()
                    User.winbet()
                if winner == "Dealer" :
                    loseMessage()
                    User.losebet()
                if winner == "Tie" :
                    print("\nTie!")
            
    print("\n----------------------------\nNo chip remaining.\nGame Over")

    if input("\nDo you want to play again? (Y or N): ")[0].upper() != "Y" :
        break

    print("===============================")