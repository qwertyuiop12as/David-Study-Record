import random

suits = ('Hearts', 'Diamonds', 'Spades', 'Clubs')
ranks = ('Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten', 'Jack', 'Queen', 'King', 'Ace')
values = {'Two':2, 'Three':3, 'Four':4, 'Five':5, 'Six':6, 'Seven':7, 'Eight':8, 
            'Nine':9, 'Ten':10, 'Jack':11, 'Queen':12, 'King':13, 'Ace':14}

            
class Card:
    
    def __init__(self, suit, rank):
        self.suit = suit
        self.rank = rank
    
    def __str__(suit, rank):
        return suit + ' of ' + rank
        
class Deck:
    
    def __init__(self):
        self.deck = []
        for suit in suits:
            for rank in ranks:
                self.deck.append([Card.__str__(suit, rank), suit, rank])   
                ##printf(self.deck)
        self.shuffle(self.deck)
    
    def shuffle(self, deck):
        random.shuffle(deck)   
    
    def deal(self, deck):
        deck_pop = deck.pop()
        print(deck_pop)
        return deck_pop
    
    ##def printdeck(self, P1_card1, P2_card2):
    ##    print(P1_card1[1] + ' of ' + P1_card1[2], end = " VS ")
    ##    print(P2_card1[1] + ' of ' + P2_card1[2])
    
    def win_check(self, P1, P2):
        length_P1 = len(P1)
        length_P2 = len(P2)
        
        if not length_P1:
            return 1
        
        elif not length_P2:
            return 2
            
        else:
            return 0

class Player():
    
    def __init__(self):
        self.deck = Deck()
    
    def Playerdeck(self):
        length = len(self.deck.deck) // 2
        P1 = self.deck.deck[:length]
        P2 = self.deck.deck[length:]
        
        return P1, P2
    
    def compare(self, P1, P2, P1_card2, P2_card2):
        P1_value = values[P1_card2[2]]
        P2_value = values[P2_card2[2]]   
        
        if P1_value > P2_value:
            change_card = P2_card2[0]
            P1.append(change_card)
            P1.append(P1_card2)
            
        elif P1_value < P2_value:
            change_card = P1_card2[0]
            P2.append(change_card)
            P2.append(P2_card2)
        
        elif P1_value == P2_value:
            print("War!!")

Start = Player()
Player1, Player2 = Start.Playerdeck()
print("Execution Logic")
cnt = 1
while True:
    print('Round ', cnt)
    print("Player1 =", Player1, "\n")
    print("Player2 =", Player2, "\n")
    cnt+=1
    P1_card = Start.deck.deal(Player1)
    P2_card = Start.deck.deal(Player2)
    print(P1_card, P2_card)
    Start.compare(Player1, Player2, P1_card, P2_card)
    Start.deck.shuffle(Player1)
    Start.deck.shuffle(Player2)
    win_check = Start.deck.win_check(Player1, Player2)
    
    if win_check == 2:
        print("Player One out of cards! Game Over")
        print("Player Two Wins!")
        break
        
    elif win_check == 1:
        print("Player Two out of cards! Game Over")
        print("Player One Wins!") 
        break