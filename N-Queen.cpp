#include <iostream>
#include <vector>
using namespace std;

class Queen {
private:
    int N;
    vector<vector<int>> board;

public:
    // Initialize the board with size N
    Queen(int n) : N(n), board(n, vector<int>(n, 0)) {}

    // Display the board
    void disp_board() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1) {
                    cout << " Q "; // Queen symbol
                } else {
                    cout << " ❌ "; // Cross mark emoji
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    // Check if the queen can be attacked
    bool is_attack(int row, int col) {
        // Check this row on the left
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 1) {
                return true;
            }
        }

        // Check upper diagonal on the left
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return true;
            }
        }

        // Check lower diagonal on the left
        for (int i = row, j = col; i < N && j >= 0; i++, j--) {
            if (board[i][j] == 1) {
                return true;
            }
        }

        return false;
    }

    // Solve the N-Queens problem
    bool N_queen(int col) {
        if (col >= N) {
            return true;
        }

        for (int i = 0; i < N; i++) {
            if (!is_attack(i, col)) {
                board[i][col] = 1; // Place the queen

                if (N_queen(col + 1)) { // Recur to place the rest of the queens
                    return true;
                }

                // Backtrack if placing queen in this position doesn't work
                board[i][col] = 0;
            }
        }

        return false;
    }

    // Get the positions of the queens
    vector<pair<int, int>> queen_positions() {
        vector<pair<int, int>> positions;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1) {
                    positions.push_back({i, j});
                }
            }
        }
        return positions;
    }
};

int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;

    // Create Queen object
    Queen Q(N);

    cout << "Initial State:" << endl;
    Q.disp_board();

    // Solve the N-Queens problem
    if (Q.N_queen(0)) {
        cout << "\nFinal State:" << endl;
        Q.disp_board();

        // Get and display the positions of the queens
        vector<pair<int, int>> positions = Q.queen_positions();
        cout << "\nPositions of the queens:" << endl;
        for (int i = 0; i < positions.size(); i++) {
            cout << "Queen " << i + 1 << ": Row " << positions[i].first + 1 << ", Column " << positions[i].second + 1 << endl;
        }
    } else {
        cout << "No solution exists for the given number of queens." << endl;
    }

    return 0;
}
