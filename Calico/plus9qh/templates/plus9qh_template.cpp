#include <iostream>
#include <vector>

using namespace std;

/**
 * Find an HQ9+ program that outputs exactly the given text or return IMPOSSIBLE
 * if no solutions exist.
 *
 * N: the number of lines of text
 * X: a list containing the lines of the text
 */

const string nine[6] = {"99 bottles of beer on the wall, 99 bottles of beer.", "Take one down and pass it around, 98 bottles of beer on the wall.", "98 bottles of beer on the wall, 98 bottles of beer.", "Take one down and pass it around, 97 bottles of beer on the wall.", "97 bottles of beer on the wall, 97 bottles of beer.", "Take one down and pass it around, 96 bottles of beer on the wall."};
const string hello = "Hello, world!";
string solve(int N, vector<string> &X)
{
    string command = "";
    for (auto a : X)
    {
        for (auto b : a)
            if (b != 'H' && b != 'Q' && b != '9' && b != '+')
                goto A;
        if (command == "")
            command = a;
        else if (command != a)
            return "IMPOSSIBLE";
    A:;
    }
    if (command == "")
    {
        for (int i = 0; i < N; i++)
            if (X[i] == hello)
                command.push_back('H');
            else if (X[i] == nine[0])
            {
                command.push_back('9');
                i += 5;
            }
    }
    vector<string> vs;
    for (auto a : command)
        if (a == '9')
            for (int i = 0; i < 6; i++)
                vs.push_back(nine[i]);
        else if (a == 'H')
            vs.push_back(hello);
        else if (a == 'Q')
            vs.push_back(command);
    if (vs == X)
        return command;
    return "IMPOSSIBLE";
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        cin.get();
        vector<string> X(N);
        for (int j = 0; j < N; j++)
        {
            getline(cin, X[j]);
        }
        cout << solve(N, X) << '\n';
    }
}
