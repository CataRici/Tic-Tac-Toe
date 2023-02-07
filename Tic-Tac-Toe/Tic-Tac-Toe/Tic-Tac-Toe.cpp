#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

const int MAX_SIZE = 4;
string table[MAX_SIZE][MAX_SIZE];

// Function which prints the actual Tic-Tac-Toe table
void printTable() {
    cout << "Current Game Board:" << endl;
    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = 0; j < MAX_SIZE; ++j) {
            cout << setw(2) << table[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Function which verify player's inserted position
bool checkTablePosition(int r, int c) {
    if ((r >= 1 && r < MAX_SIZE) && (c >= 1 && c < MAX_SIZE)) {
        if (table[r][c] == "_") {
            return true;
        }
    }
    cout << "INVALID CHOICE, PLEASE TRY AGAIN" << endl;
    return false;
}

// Function which checks if there is a winner
bool checkWinner() {
    vector<string> symbol1;
    vector<string> symbol2;
    for (int i = 1; i < MAX_SIZE; ++i) {
        for (int j = 1; j < MAX_SIZE; ++j) {
            symbol1[j] = table[i][j]; // Move symbol from row into vector
            symbol2[j] = table[j][i]; // Move symbol from colomn into vector
        }
        if ((symbol1[1] == symbol1[2]) && (symbol1[2] == symbol1[3])) {
            return true;
        }
        else if ((symbol2[1] == symbol2[2]) && (symbol2[2] == symbol2[3])) {
            return true;
        }
    }
    for (int i = 1; i < MAX_SIZE; ++i) {
        symbol1[i] = table[i][i]; // Move symbol from main diagonal into vector
        symbol2[i] = table[i][MAX_SIZE - i]; // Move symbol from second diagonal into vector
    }
    if ((symbol1[1] == symbol1[2]) && (symbol1[2] == symbol1[3])) {
        return true;
    }
    else if ((symbol2[1] == symbol2[2]) && (symbol2[2] == symbol2[3])) {
        return true;
    }
    return false;
    

    /*
   if (table[1][1] != "_" && ((table[1][1] == table[1][2]) && (table[1][2] == table[1][3]))) {
        return true;
    }
    else if (table[2][1] != "_" && ((table[2][1] == table[2][2]) && (table[2][2] == table[2][3]))) {
        return true;
    }
    else if (table[3][1] != "_" && ((table[3][1] == table[3][2]) && (table[3][2] == table[3][3]))) {
        return true;
    }
    else if (table[1][1] != "_" && ((table[1][1] == table[2][1]) && (table[2][1] == table[3][1]))) {
        return true;
    }
    else if (table[1][2] != "_" && ((table[1][2] == table[2][2]) && (table[2][2] == table[3][2]))) {
        return true;
    }
    else if (table[1][3] != "_" && ((table[1][3] == table[2][3]) && (table[2][3] == table[3][3]))) {
        return true;
    }
    else if (table[1][1] != "_" && ((table[1][1] == table[2][2]) && (table[2][2] == table[3][3]))) {
        return true;
    }
    else if (table[1][3] != "_" && ((table[1][3] == table[2][2]) && (table[2][2] == table[3][1]))) {
        return true;
    }
    return false;
    */
}


int main() {
    string Player1, Player2;
    cout << "Welcome to Tic-Tac-Toe game" << endl << "To quit the game press '0'" << "\n\n";
    // Build the initial table
    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = 0; j < MAX_SIZE; ++j) {
            if (i > 0 || j > 0) {
                table[i][j] = "_";
            }
            if (i > 0 && j == 0) {
                string i_string = to_string(i);
                table[i][j] = i_string;
            }
            if (j > 0 && i == 0) {
                string j_string = to_string(j);
                table[i][j] = j_string;
            }
        }
    }
    printTable();

    // Players choose symbol
    bool correctSymbol = false;
    do {
        cout << "Player 1 choose your symbol: X or O?" << endl;
        cin >> Player1;
        if (Player1 == "X" || Player1 == "x") {
             Player1 = "X";
             Player2 = "O";
             correctSymbol = true;
        } else if (Player1 == "O" || Player1 == "o") {
            Player1 = "O";
            Player2 = "X";
            correctSymbol = true;
        } else if (correctSymbol == false) {
            cout << "YOU HAVE CHOSEN THE WRONG SYMBOL. PLEASE TRY AGAIN :)" << endl;
        }

    } while (correctSymbol == false);

    // Players start to play
    int turns = 0, row = -1, colomn = -1;
    bool gameIsOn = true;
    while (gameIsOn == true) {
        if (turns % 2 == 0) {
            do {
                cout << "Player 1's turn" << endl;
                cout << "Select a row: ";
                cin >> row;
                if (row == 0) {
                    cout << "Player 1 quit the game";
                    break;
                }
                cout << "Select a colomn: ";
                cin >> colomn;
                if (colomn == 0) {
                    cout << "Player 1 quit the game";
                    break;
                }
            } while (checkTablePosition(row, colomn) == false);
            if (row == 0 || colomn == 0) {
                break;
            }
            table[row][colomn] = "X"; // Place symbol in the table
            printTable();
            ++turns;  
            // If there are more than 4 turns, start checking the board for winner
            if (turns > 4 && checkWinner() == true) {
                cout << "Player 1 WIN THE GAME!" << "\n" << "GAME WON AFTER " << turns << " TURNS";              
                gameIsOn = false;
            }
            // If board is full and there is no winner
            if (turns == 9 && gameIsOn == true) {
                cout << "IT'S A DRAW AFTER " << turns << " TURNS";
                gameIsOn = false;
            }
        } else {
            do {
                cout << "Player 2's turn" << endl;
                cout << "Select a row: ";
                cin >> row;
                if (row == 0) {
                    cout << "Player 2 quit the game";
                    break;
                }
                cout << "Select a colomn: ";
                cin >> colomn;
                if (colomn == 0) {
                    cout << "Player 2 quit the game";
                    break;
                }
            } while (checkTablePosition(row, colomn) == false);
            if (row == 0 || colomn == 0) {
                break;
            }
            table[row][colomn] = "O"; // Place symbol in the table
            printTable();
            ++turns;
            // If there are more than 4 turns, start checking the board for winner
            if (turns > 4 && checkWinner() == true) { 
                cout << "Player 2 WIN THE GAME!" << "\n" << "GAME WON AFTER " << turns << " turns";
                gameIsOn = false;
            }
            // If board is full and there is no winner
            if (turns == 9 && gameIsOn == true) {
                cout << "IT'S A DRAW AFTER " << turns << " TURNS";
                gameIsOn = false;
            }
        }
    }
    return 0;
}

