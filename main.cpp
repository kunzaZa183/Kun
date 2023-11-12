#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--)
    {
        string s;
        cin >> s;
        int num = 0, num2 = 0;
        int stop = s.find(':');
        for (int i = 0; i < stop; i++)
            if (isdigit(s[i]))
            {
                num *= 10;
                num += s[i] - '0';
            }
        for (int i = stop + 1; i < s.size(); i++)
            if (isdigit(s[i]))
            {
                num2 *= 10;
                num2 += s[i] - '0';
            }
        if (num >= num2)
            cout << "SWERVE\n";
        else if (num * 5 >= num2)
            cout << "BRAKE\n";
        else
            cout << "SAFE\n";
    }
}