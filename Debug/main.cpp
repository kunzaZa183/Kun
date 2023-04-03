#include <iostream>
#include <vector>
using namespace std;
#define int long long
struct point
{
    int x, y, dist_from_slope1, dist_from_slope_1;
    vector<int> vi;
};
vector<int> convert(int x, int y, int k)
{
    vector<int> vi;
    while (k--)
    {
        int tmp = 1LL << k;
        if (x < tmp && y >= tmp)
            vi.push_back(0);
        else if (x >= tmp && y >= tmp)
            vi.push_back(1);
        else if (x < tmp && y < tmp)
            vi.push_back(2);
        else if (x >= tmp && y < tmp)
            vi.push_back(3);
        if (x >= tmp)
            x -= tmp;
        if (y >= tmp)
            y -= tmp;
    }
    return vi;
}
void convertp(point *a, int k)
{
    a->x = 0, a->y = 0;
    for (auto it = a->vi.rbegin(); it != a->vi.rend(); it++)
    {
        int k2 = 1LL << (it - a->vi.rbegin());
        if (*it == 0)
            a->y += k2;
        else if (*it == 1)
            a->x += k2, a->y += k2;
        else if (*it == 3)
            a->x += k2;
    }
    a->dist_from_slope1 = a->y - a->x;
    a->dist_from_slope_1 = a->y + a->x - ((1LL << k) - 1);
}
int distance(point a, point *b, int noteq, int k)
{
    if (a.vi == b->vi)
        return 0;
    if (noteq == k)
        return 0;
    for (; 1; noteq++)
        if (a.vi[noteq] != b->vi[noteq])
        {
            int tmp = a.vi[noteq];
            while (a.vi.size() > noteq)
                a.vi.pop_back();
            a.vi.push_back(b->vi[noteq]);
            if (tmp + b->vi[noteq] != 3)
            {
                while (a.vi.size() < b->vi.size())
                    a.vi.push_back(tmp);
                convertp(&a, k);
                return (1LL << (k - noteq - 1)) + distance(a, b, noteq + 1, k);
            }
            else
            {
                if (tmp == 0 || tmp == 3)
                {
                    int check = b->dist_from_slope_1 + a.dist_from_slope_1;
                    for (int i = 0; i < noteq; i++)
                        if (a.vi[i] == 1)
                            check -= 2 * (1LL << (k - i - 1));
                        else if (a.vi[i] == 2)
                            check += 2 * (1LL << (k - i - 1));
                    if (check >= 0)
                        while (a.vi.size() < b->vi.size())
                            a.vi.push_back(1);
                    else
                        while (a.vi.size() < b->vi.size())
                            a.vi.push_back(2);
                }
                else if (tmp == 1 || tmp == 2)
                {
                    int check = b->dist_from_slope1 + a.dist_from_slope1;
                    for (int i = 0; i < noteq; i++)
                        if (a.vi[i] == 0)
                            check -= 2 * (1LL << (k - i - 1));
                        else if (a.vi[i] == 3)
                            check += 2 * (1LL << (k - i - 1));
                    if (check >= 0)
                        while (a.vi.size() < b->vi.size())
                            a.vi.push_back(0);
                    else
                        while (a.vi.size() < b->vi.size())
                            a.vi.push_back(3);
                }
                convertp(&a, k);
                return 2 + 3 * ((1LL << (k - noteq - 1)) - 1) + distance(a, b, noteq + 1, k);
            }
        }
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, x1, y1, x2, y2;
    cin >> k >> x1 >> y1 >> x2 >> y2;
    point target1, target2;
    target1.vi = convert(x1, y1, k), target2.vi = convert(x2, y2, k);
    convertp(&target1, k), convertp(&target2, k);
    for (int i = 0; i < k; i++)
        if (target1.vi[i] != target2.vi[i])
        {
            if (target1.vi[i] > target2.vi[i])
                swap(target1, target2);
            point tmp1, tmp2;
            for (int j = 0; j < i; j++)
                tmp1.vi.push_back(target1.vi[j]), tmp2.vi.push_back(target1.vi[j]);
            tmp1.vi.push_back(target1.vi[i]), tmp2.vi.push_back(target2.vi[i]);
            if (target1.vi[i] + target2.vi[i] != 3)
            {
                while (tmp1.vi.size() < k)
                    tmp1.vi.push_back(target2.vi[i]);
                while (tmp2.vi.size() < k)
                    tmp2.vi.push_back(target1.vi[i]);
                convertp(&tmp1, k), convertp(&tmp2, k);
                cout << 1 + distance(tmp1, &target1, i + 1, k) + distance(tmp2, &target2, i + 1, k) << "\n";
            }
            else if (target1.vi[i] == 0)
            {
                int check = target1.dist_from_slope_1 + target2.dist_from_slope_1;
                for (int j = 0; j < i; j++)
                    if (target1.vi[j] == 1)
                        check -= 2 * (1LL << (k - j - 1));
                    else if (target1.vi[j] == 2)
                        check += 2 * (1LL << (k - j - 1));
                if (check > 0)
                {
                    while (tmp1.vi.size() < k)
                        tmp1.vi.push_back(1), tmp2.vi.push_back(1);
                    convertp(&tmp1, k), convertp(&tmp2, k);
                    cout << (1LL << (k - i)) + distance(tmp1, &target1, i + 1, k) + distance(tmp2, &target2, i + 1, k) << '\n';
                }
                else
                {
                    while (tmp1.vi.size() < k)
                        tmp1.vi.push_back(2), tmp2.vi.push_back(2);
                    convertp(&tmp1, k), convertp(&tmp2, k);
                    cout << (1LL << (k - i)) + distance(tmp1, &target1, i + 1, k) + distance(tmp2, &target2, i + 1, k) << '\n';
                }
            }
            else if (target1.vi[i] == 1)
            {
                int check = target1.dist_from_slope1 + target2.dist_from_slope1;
                for (int j = 0; j < i; j++)
                    if (target1.vi[j] == 0)
                        check -= 2 * (1LL << (k - j - 1));
                    else if (target1.vi[j] == 3)
                        check += 2 * (1LL << (k - j - 1));
                if (check > 0)
                {
                    while (tmp1.vi.size() < k)
                        tmp1.vi.push_back(0), tmp2.vi.push_back(0);
                    convertp(&tmp1, k), convertp(&tmp2, k);
                    cout << (1LL << (k - i)) + distance(tmp1, &target1, i + 1, k) + distance(tmp2, &target2, i + 1, k) << '\n';
                }
                else
                {
                    while (tmp1.vi.size() < k)
                        tmp1.vi.push_back(3), tmp2.vi.push_back(3);
                    convertp(&tmp1, k), convertp(&tmp2, k);
                    cout << (1LL << (k - i)) + distance(tmp1, &target1, i + 1, k) + distance(tmp2, &target2, i + 1, k) << '\n';
                }
            }
            return 0;
        }
    cout << "0\n";
}