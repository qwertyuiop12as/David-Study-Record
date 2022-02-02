import random
# from IPython.display import clear_output

def display_board(board):
    # clear_output()  # Remember, this only works in jupyter!

    print()
    print('   |   |')
    print(' ' + board[7] + ' | ' + board[8] + ' | ' + board[9])
    print('   |   |')
    print('-----------')
    print('   |   |')
    print(' ' + board[4] + ' | ' + board[5] + ' | ' + board[6])
    print('   |   |')
    print('-----------')
    print('   |   |')
    print(' ' + board[1] + ' | ' + board[2] + ' | ' + board[3])
    print('   |   |')


# test_board = ['#', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X']
# display_board(test_board)


def player_input(marker):
    index = -1
    while (index < 1 or index > 9) :
        try :
            print(f"please choose the position (1 ~ 9). Your marker : {marker}")
            index = int(input())
        except :
            print("Please input a integer (1 ~ 9)")
    
    return index

    
def space_check(board, position):
    print(position, type(position))
    if board[position] == ' ' :
        return True
    else :
        return False

def place_marker(board, marker, position):
    # print(f"before : {board}")
    if space_check(board, position) == True :
        board[position] = marker
        return True
    else :
        return False
        # print("mark success")
    # print(f"after : {board}")


def win_check(board, mark):
    if board[1] == mark and board[2] == mark and board[3] == mark :
        return True

    elif board[4] == mark and board[5] == mark and board[6] == mark :
        return True
        
    elif board[7] == mark and board[8] == mark and board[9] == mark :
        return True
        
    elif board[1] == mark and board[4] == mark and board[7] == mark :
        return True
        
    elif board[2] == mark and board[5] == mark and board[8] == mark :
        return True
        
    elif board[3] == mark and board[6] == mark and board[9] == mark :
        return True
        
    elif board[1] == mark and board[5] == mark and board[9] == mark :
        return True
        
    elif board[7] == mark and board[5] == mark and board[3] == mark :
        return True
    
    else :
        return False


def choose_first():
    if random.randint(0, 1) == 0:
        return ['Player 2', 'Player 1']
    else:
        return ['Player 1', 'Player 2']


def full_board_check(board) :
    for index in range(1, 10) :
        if space_check(board, index) :
            return False

    return True

def replay():
    replay = " "

    while replay != 'Y' and replay != 'N' :
        print("Are you going to play agian? (Y or N)")
        replay = input()[0].upper()
        if replay == 'Y':
            return True
        elif replay == 'N':
            return False

def play_game() :
    while True :
        board = ['#'] + [' '] * 9

        whose_first = choose_first()

        first_player = whose_first[0]
        second_player = whose_first[1]

        print(f"first player is {first_player}, your marker is \'O\'")

        for turn in range(9):
            if turn % 2 == 0:
                marker = "O"
                display_board(board)

                position = player_input(marker)
                while place_marker(board, marker, position) == False :
                    print("The position is not empty!")
                    position = player_input(marker)


                if win_check(board, marker) == True :
                    display_board(board)
                    print("first player win!")
                    break
                
                elif full_board_check(board) == True :
                    display_board(board)
                    print("Tie!")

                print("C")

            elif turn % 2 == 1 :
                marker = "X"
                display_board(board)

                position = player_input(marker)
                while place_marker(board, marker, position) == False :
                    print("The position is not empty!")
                    position = player_input(marker)


                if win_check(board, marker) == True :
                    display_board(board)
                    print("second player win!")
                    break
                
                elif full_board_check(board) == True :
                    display_board(board)
                    print("Tie!")


        # print(first_player, second_player)

        
        if replay() == False :
            break

play_game()