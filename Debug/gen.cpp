#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "w", stdout);
    srand(time(NULL));
    int n = 10;
    int trues = rand() % n;
    int falses = n - trues;
    string vi;
    for (int i = 0; i < trues; i++)
        vi.push_back('T');
    for(int i=0;i<falses;i++)
        vi.push_back('F');
    shuffle(vi.begin(),vi.end());
        cout << "\n";
    while (q--)
        cout << rand() % 2 + 1 << " " << rand() % n + 1 << ' ' << rand() % n + 1 << '\n';
}