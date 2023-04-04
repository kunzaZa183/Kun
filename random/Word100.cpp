#include <bits/stdc++.h>
using namespace std;
vector<string> vs;
int main()
{
    int sm = 0;
    string s;
    ifstream file;
    file.open("Words.txt");
    while (file >> s)
        vs.push_back(s);
    for (auto &a : vs)
    {
        sm=0;
        for (auto &b : a)
            sm += b - 'A' + 1;
        if (sm == 100)
            cout << a << '\n';
    }
}