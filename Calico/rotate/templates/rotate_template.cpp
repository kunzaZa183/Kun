#include <iostream>

using namespace std;
#define int long long

/**
 * Return the position of the card labelled K after shuffling a deck with N
 * cards, where the topmost card is in position 1, the second from topmost card
 * is position 2, and so on.
 *
 * N: the number of cards in the deck
 * K: the label of the target card
 */
int solve(int N, int K)
{
    if (N == 1)
        return 1;
    int cursiz = N, jump = 0, start = 2, past = 0;
    bool startsec = 1;
    while (cursiz > 1)
    {
        if ((K - start) % (1 << jump) == 0)
            return past + (K - start) / (1 << jump) + 1;
        if (startsec)
        {
            if (cursiz % 2 == 0)
            {
                startsec = 0;
                past += cursiz/2;
                cursiz/=2;
            }
            else
            {
                past +=cursiz/2;
                cursiz/=2;
                cursiz++;
            }
        }
        else
        {
            start += (1<<jump);
            if(cursiz%2==0)
            {
                past += cursiz/2;
                cursiz/=2;
            }
            else
            {
                startsec = 1;
                past += (cursiz+1)/2;
                cursiz/=2;   
            }
        }
        jump++;
    }
}

signed main()
{
    int T;
    int N, K;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> K;
        cout << solve(N, K) << '\n';
    }
}
