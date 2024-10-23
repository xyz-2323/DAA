class Queen:
    # Initialize the board with size N
    def __init__(self, n):
        self.N = n
        self.board = [[0] * n for _ in range(n)]

    # Display the board
    def disp_board(self):
        for row in self.board:
            for col in row:
                if col == 1:
                    print(" ", end=" ")  # Queen emoji
                else:
                    print("❌", end=" ")  # Cross mark emoji
            print()  # Newline after each row
        print()

    # Check if the queen can be attacked
    def is_attack(self, row, col):
        # Check this row on the left
        for i in range(col):
            if self.board[row][i] == 1:
                return True

        # Check upper diagonal on the left
        for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
            if self.board[i][j] == 1:
                return True

        # Check lower diagonal on the left
        for i, j in zip(range(row, self.N, 1), range(col, -1, -1)):
            if self.board[i][j] == 1:
                return True

        return False

    # Solve the N-Queens problem
    def N_queen(self, col):
        if col >= self.N:
            return True

        for i in range(self.N):
            if not self.is_attack(i, col):
                self.board[i][col] = 1  # Place the queen

                if self.N_queen(col + 1):  # Recur to place the rest of the queens
                    return True

                # Backtrack if placing queen in this position doesn't work
                self.board[i][col] = 0

        return False

    # Get the positions of the queens
    def queen_positions(self):
        positions = []
        for i in range(self.N):
            for j in range(self.N):
                if self.board[i][j] == 1:
                    positions.append((i, j))
        return positions


# Input number of queens
N = int(input("Enter the number of queens: "))

# Create Queen object
Q = Queen(N)

print("Initial State:")
Q.disp_board()

# Solve the N-Queens problem
if Q.N_queen(0):
    print("\nFinal State:")
    Q.disp_board()

    # Get and display the positions of the queens
    positions = Q.queen_positions()
    print("\nPositions of the queens:")
    for idx, pos in enumerate(positions):
        print(f"Queen {idx + 1}: Row {pos[0] + 1}, Column {pos[1] + 1}")
else:
    print("No solution exists for the given number of queens.")
