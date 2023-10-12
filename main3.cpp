#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

bool checkrange(int num)
{
    ensure(num >= 0 && num <= 20);
}

int main(int argc, char *argv[])
{
    registerGen(argc, argv);

    int minn = argv[0], maxn = argv[1], minm = argv[2], maxm = argv[3];
    checkrange(minn), checkrange(maxn), checkrange(minm), checkrange(maxm);
    /* Single random number between 1 and 1000000 inclusive. */
    cout << rnd.next(minn, maxn) << ' ' << rnd.next(minm, maxm) << endl;
}