# Black Jack

```python
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
```

```suits``` : Card의 모양들

```rank``` : Card의 숫자들

```values``` : Card의 숫자가 str형식("Two", "Three"...)으로 저장되어있을 때 str을 **key**값으로 int를 **value**값으로 저장하는 dictionary



## class Card

![img](https://cdn-images-1.medium.com/max/1000/1*_mi4Qe_srKora4kwb6BdBw.png)

```python
class Card:
    def __init__(self, suit, rank):
        self.suit = suit
        self.rank = rank
        
    def __str__(self):
        return self.rank + ' of ' + self.suit
```

```__init__``` : suit(모양, 무늬)와 rank(숫자)를 저