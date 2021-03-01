#include <iostream>
using namespace std;

char play_board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
// for(int i=0; i<9; i++){
//     play_board[i=' ';
// }
char char_of_player1, char_of_player2;
void display_board();
int count_char(char);
void choice_of_player1(char);
void choice_of_player2(char);
void choice_of_computer(char);
char check_winner();

int main()
{
    // cout<<"Hello world";
    int choice_of_mode = 0;
    cout << "Welcome player1. Now choose your character: ";
    cin >> char_of_player1;
    cout << "Welcome player2. Now choose your character: ";
    cin >> char_of_player2;
    cout << "Please choose the mode of the game:" << endl;
    cout << "1. computer vs player" << endl;
    cout << "2. player vs player" << endl;
    cout << "1 or 2" << endl;
    while (1)
    {
        cin >> choice_of_mode;
        if (choice_of_mode == 1)
        {
            while (1)
            {
                if (count_char(char_of_player1) == count_char(char_of_player2))
                {
                    cout << "Computer's turn.\n";
                    choice_of_computer(char_of_player1);
                    display_board();
                }
                else
                {
                    cout << "Your turn. ";
                    choice_of_player2(char_of_player2);
                    display_board();
                }
                if (check_winner() == char_of_player1)
                {
                    cout << "You loose. Better luck next time." << endl;
                    break;
                }
                else if (check_winner() == char_of_player2)
                {
                    cout << "Congratulation ! you won." << endl;
                    break;
                }
                else if (count_char(char_of_player1) + count_char(char_of_player2) == 9)
                {
                    cout << "The game is draw." << endl;
                    break;
                }
            }
            break;
        }
        else if (choice_of_mode == 2)
        {
            while (1)
            {
                if (count_char(char_of_player1) == count_char(char_of_player2))
                {
                    cout << "Player1's turn. " << endl;
                    choice_of_player1(char_of_player1);
                    display_board();
                }
                else
                {
                    cout << "player2's turn. " << endl;
                    choice_of_player2(char_of_player2);
                    display_board();
                }
                if (check_winner() == char_of_player1)
                {
                    cout << "Player1 won." << endl;
                    break;
                }
                else if (check_winner() == char_of_player2)
                {
                    cout << "Player2 won." << endl;
                    break;
                }
                else if (count_char(char_of_player1) + count_char(char_of_player2) == 9)
                {
                    cout << "The game is draw." << endl;
                    break;
                }
            }
            break;
        }
        else
        {
            cout << "Please choose 1 or 2" << endl;
        }
    }

    return 0;
}

void display_board()
{
    for (int i = 0; i < 9; i = i + 3)
    {
        cout << "|------|"<< "------|"<< "------|" << endl;
        cout << "|  " << play_board[i] << "   |  " << play_board[i + 1] << "   |  " << play_board[i + 2] << "   |" << endl;
    }
    cout << "|------|"<< "------|"<< "------|" << endl;
}

int count_char(char given_char)
{
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        if (play_board[i] == given_char)
            count++;
    }
    return count;
}

void choice_of_computer(char char_of_player1)
{
    // srand(time(0));
    int choice = 0;
    do
    {
        choice = rand() % 10;
    } while (play_board[choice] != ' ');
    play_board[choice] = char_of_player1;
}

void choice_of_player1(char char_of_player1)
{
    int choice = 0;
    cout << "player1 please give your move: ";
    while (1)
    {
        cin >> choice;
        choice--;
        if (choice < 0 and choice > 8)
        {
            cout << "It's an invalid move please choose your correct move between 1 and 9: ";
        }
        else if (play_board[choice] != ' ')
        {

            cout << "It's an invalid move please choose your correct move from unoccupied cell: ";
        }
        else
        {
            play_board[choice] = char_of_player1;
            break;
        }
    }
}
void choice_of_player2(char char_of_player2)
{
    int choice = 0;
    cout << "player2 please give your move: ";
    while (1)
    {
        cin >> choice;
        choice--;
        if (choice < 0 and choice > 8)
        {
            cout << "It's an invalid move please choose your correct move between 1 and 9: ";
        }
        else if (play_board[choice] != ' ')
        {

            cout << "It's an invalid move please choose your correct move from unoccupied cell: ";
        }
        else
        {
            play_board[choice] = char_of_player2;
            break;
        }
    }
}

char check_winner()
{
    for (int i = 0; i < 9; i += 3)
    {
        if (play_board[i] == play_board[i + 1] && play_board[i + 1] == play_board[i + 2])
        {
            return play_board[i];
        }
    }
    for (int i = 0; i < 3; i += 1)
    {
        if (play_board[i] == play_board[i + 3] && play_board[i + 3] == play_board[i + 6])
        {
            return play_board[i];
        }
    }
    if (play_board[0] == play_board[4] && play_board[4] == play_board[8])
    {
        return play_board[0];
    }
    if (play_board[2] == play_board[4] && play_board[4] == play_board[6])
    {
        return play_board[2];
    }
    return '$';
}