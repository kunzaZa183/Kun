#include <bits/stdc++.h>
using namespace std;
string s;
const string check = "URDL?";
int ct = 0;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, dimen = 7;
bool visited[dimen + 2][dimen + 2];
int arr[dimen * dimen - 1];
void recur(int curx, int cury, int numvis)
{
    if (curx == dimen && cury == 1)
    {
        if (numvis == dimen * dimen)
            ct++;
        return;
    }
    if (visited[curx + 1][cury] && visited[curx - 1][cury] && !visited[curx][cury + 1] && !visited[curx][cury - 1])
        return;
    if (!visited[curx + 1][cury] && !visited[curx - 1][cury] && visited[curx][cury + 1] && visited[curx][cury - 1])
        return;
    visited[curx][cury] = 1;
    if (arr[numvis - 1] == 4)
    {
        for (int i = 0; i < 4; i++)
            if (!visited[curx + dx[i]][cury + dy[i]])
                recur(curx + dx[i], cury + dy[i], numvis + 1);
    }
    else if (!visited[curx + dx[arr[numvis - 1]]][cury + dy[arr[numvis - 1]]])
        recur(curx + dx[arr[numvis - 1]], cury + dy[arr[numvis - 1]], numvis + 1);
    visited[curx][cury] = 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        arr[i] = check.find(s[i]);
    for (int i = 0; i <= dimen + 1; i++)
        for (int j = 0; j <= dimen + 1; j++)
            if (i >= 1 && i <= dimen && j >= 1 && j <= dimen)
                visited[i][j] = 0;
            else
                visited[i][j] = 1;
    recur(1, 1, 1);
    cout << ct << "\n";
}