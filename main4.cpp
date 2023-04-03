#include <bits/stdc++.h>
using namespace std;
int main()
{
    string tmp;
    vector<string> ss, ss2;
    ifstream out("out.txt");
    while (getline(out, tmp))
        ss.push_back(tmp);
    ifstream out2("out2.txt");
    while (getline(out2, tmp))
        ss2.push_back(tmp);
    for (int i = 0; i < ss.size(); i++)
        if (ss[i] != ss2[i])
        {
            cout << i << "\n";
            cout << "NO\n";
            return 0;
        }
    cout << "YES\n";
}