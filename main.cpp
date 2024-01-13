#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int arr[10];
    for (int i = 0; i < s.size(); i++)
        if (isdigit(s[i]))
            arr[s[i] - '0' - 1] = 1;
        else
        {
            arr[s[i + 1] - '0' - 1] = 0;
            i++;
        }
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == 1)
            cout << "1";
        else
            cout << "-";
        cout << " ";
    }
}