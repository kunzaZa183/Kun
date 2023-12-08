string = input()
board = []
while string != "Q":
    board.append(string)
    string = input()
group = [[-1 for j in range(len(board[0]))] for i in range(len(board))]
for i in range(len(board)):
    