import random
#suffle 할 때 사용

suits = ("Hearts", "Diamonds", "Spades", "Clubs")
ranks = ('Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten', 'Jack', 'Queen', 'King', 'Ace')
values = {
    'Two': 2, 
    'Three': 3, 
    'Four': 4, 
    'Five': 5, 
    'Six': 6, 
    'Seven': 7, 
    'Eight': 8, 
    'Nine': 9, 
    'Ten': 10, 
    'Jack': 10,
    'Queen':10, 
    'King':10, 
    'Ace':11
}

playing = True

class Card : 

    def __init__(self, suit, rank) :
        self.suit = suit    #모양, 무늬
        self.rank = rank    #숫자(str)
    
    def __str__(self) :
        return self.rank + ' of ' + self.suit

class Deck :

    def __init__(self):
        self.deck = []
        for suit in suits :
            for rank in ranks :
                self.deck.append(Card(suit, rank))  #class Card 52개를 저장하는 list

    
    def __str__(self) :
        deck_comp = ''
        for card in self.deck:
            deck_comp += '\n ' + card.__str__()
        return 'The deck has:' + deck_comp

    def shuffle(self):
        random.shuffle(self.deck)   #deck 섞어주기

    def deal(self):
        single_card = self.deck.pop()
        return single_card  #Card를 return 해줌
    

class Hand :

    def __init__(self) :
        self.cards = [] #class Card들을 저장할 list
        self.value = 0  #카드의 숫자값 합을 저장하는 변수
        self.aces = 0   #ace카드의 갯수를 저장하는 함수

    def add_card(self, card):
        self.cards.append(card)
        self.value += values[card.rank] #카드의 숫자값을 values dictionary를 통해서 정수형으로 더해줌
        if card.rank == 'Ace' :         #만약 ace카드가 있다면 aces변수에 1 더하기
            self.aces += 1

    def adjust_for_ace(self):           #특수상황(ace카드가 있고 합이 21이 넘을 때)
        while self.value > 21 and self.aces:
            self.value -= 10
            self.aces -= 1

test_deck = Deck()
test_deck.shuffle()
test_player = Hand()
test_player.add_card(test_deck.deal())
print(test_player.value)
test_player.add_card(test_deck.deal())
print(test_player.value)


class Chips:
    
    def __init__(self) :
        self.total = 100    #시작 값
        self.bet = 0        #베팅 값

    def win_bet(self) :
        self.total += self.bet

    def lose_bet(self) :
        self.total -= self.bet

def take_bet(chips) :

    while True :
        try :
            chips.bet = int(input("How many chips would you like to bet?"))
        except ValueError:
            print("Sorry, a bet must be an interger")
        else :
            if chips.bet > chips.total:
                print("Sorry, your bet can't exceed", chips.total)
            else:
                break

chip = Chips()
take_bet(chip)

def hit(deck, hand):

    hand.add_card(deck.deal())
    hand.adjust_for_ace()

def hit_or_stand(deck, hand) :
    global playing
    
    while True :
        x = input("Would you like to Hit or Stand? Enter 'h', or 's' ")

        if x[0].lower() == 'h' :
            hit(deck, hand)

        elif x[0].lower() == 's':
            print("Player stands, Dealer is playing")
            playing = False
        
        else :
            print("Sorry, please try again")
            continue
    
        break