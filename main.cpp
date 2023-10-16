#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int arrpar[maxn], color[maxn], arrhead[maxn], arrdepth[maxn], mod[maxn];
vector<int> adjlist[maxn];
void init(int cur, int head, int depth)
{
    arrhead[cur] = head;
    arrdepth[cur] = depth;
    for (auto a : adjlist[cur])
        if (a != arrpar[cur])
            init(a, head, depth + 1);
}
void col3(int cur)
{
    for (auto a : adjlist[cur])
        if (a != arrpar[cur])
        {
            if (color[cur] == 1)
                color[a] = 2;
            else if (color[cur] == 2)
                color[a] = 3;
            else if (color[cur] == 3)
                color[a] = 1;
            col3(a);
        }
}
void col2(int cur)
{
    for (auto a : adjlist[cur])
        if (a != arrpar[cur])
        {
            if (color[cur] == 1)
                color[a] = 2;
            else if (color[cur] == 2)
                color[a] = 1;
            col2(a);
        }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    arrpar[0] = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> arrpar[i];
        arrpar[i]--;
        adjlist[i].push_back(arrpar[i]), adjlist[arrpar[i]].push_back(i);
    }
    int tmp;
    for (int i = 1; i < n; i++)
        if (adjlist[i].size() != 1)
            goto A;
    cout << 1 << endl;
    for (int i = 1; i < n; i++)
        cout << 1 << " ";
    cout << endl;
    while (cin >> tmp)
    {
        if (tmp != 0)
            return 0;
        int x;
        cin >> x;
        cout << 1 << endl;
    }
A:
    for (int i = 1; i < n; i++)
        mod[i] = -1;
    for (auto a : adjlist[0])
        init(a, a, 0);
    bool three = 0;
    for (int i = 1; i < n; i++)
        if (adjlist[i].size() == 2)
        {
            if (mod[arrhead[i]] == -1)
                mod[arrhead[i]] = arrdepth[i] % 2;
            else if (mod[arrhead[i]] != arrdepth[i] % 2)
                three = 1;
        }
    if (three)
    {
        cout << 3 << endl;
        for (auto a : adjlist[0])
        {
            color[a] = 1;
            col3(a);
        }
        for (int i = 1; i < n; i++)
            cout << color[i] << " ";
        cout << endl;
        int num;
        while (cin >> num)
        {
            if (num != 0)
                return 0;
            int arr[3];
            for (int i = 0; i < 3; i++)
                cin >> arr[i];
            int sum = 0;
            for (int i = 0; i < 3; i++)
                sum += arr[i];
            if (sum == 1)
            {
                for (int i = 0; i < 3; i++)
                    if (arr[i] == 1)
                    {
                        cout << i + 1 << endl;
                        break;
                    }
            }
            else if (arr[0] == 0)
                cout << 2 << endl;
            else if (arr[1] == 0)
                cout << 3 << endl;
            else if (arr[2] == 0)
                cout << 1 << endl;
        }
    }
    else
    {
        cout << 2 << endl;
        for (auto a : adjlist[0])
            if (mod[a] <= 0)
            {
                color[a] = 1;
                col2(a);
            }
            else if (mod[a] == 1)
            {
                color[a] = 2;
                col2(a);
            }
        for (int i = 1; i < n; i++)
            cout << color[i] << " ";
        cout << endl;
        int num;
        while (cin >> num)
        {
            if (num != 0)
                return 0;
            int r, b;
            cin >> r >> b;
            if (r == 1)
                cout << 1 << endl;
            else if (b == 1)
                cout << 2 << endl;
        }
    }
}