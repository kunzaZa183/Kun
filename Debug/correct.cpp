#include <iostream>

using namespace std;

string seq;

long long dp[100001][4];
long long matrix[100001][4][4];
long long mod = 1000000007;

int chrToNum(char c)
{
    switch (c)
    {
    case 'A':
        return 0;
    case 'G':
        return 1;
    case 'C':
        return 2;
    case 'T':
        return 3;
    default:
        return 4;
    }
}

int main()
{
    
    freopen("input.txt", "r", stdin);
    freopen("correctoutput.txt", "w", stdout);
    cin >> seq;

    if (seq[0] == '?')
    {
        for (int i = 0; i < 4; i++)
        {
            dp[0][i] = 1;
        }
    }
    else
    {
        dp[0][chrToNum(seq[0])] = 1;
    }

    for (int i = 1; i < seq.length(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int z = 0; z < 4; z++)
            {
                matrix[i][j][z] = 0;
            }
            if (seq[i] == '?' || chrToNum(seq[i]) == j)
            {
                matrix[i][j][j] = 1;
            }
            dp[i][j] += matrix[i][j][j] * dp[i - 1][j];
            dp[i][j] %= mod;
        }

        for (int j = i - 1; j >= 0; j--)
        {
            if (seq[j] != '?' && seq[j] == seq[j + 1])
            {
                break;
            }
            for (int k = 0; k < 4; k++)
            {
                for (int z = 0; z < 4; z++)
                {
                    matrix[j][k][z] = 0;
                    if (seq[j] == '?' || chrToNum(seq[j]) == k)
                    {
                        for (int m = 0; m < 4; m++)
                        {
                            if (m != k)
                            {
                                matrix[j][k][z] += matrix[j + 1][m][z];
                                matrix[j][k][z] %= mod;
                            }
                        }
                    }
                    if (j == 0)
                    {
                        dp[i][k] += matrix[j][k][z];
                    }
                    else
                    {
                        dp[i][k] += matrix[j][k][z] * dp[j - 1][z];
                    }
                    dp[i][k] %= mod;
                }
            }
        }
    }

    long long tot = 0;
    for (int i = 0; i < 4; i++)
    {
        tot += dp[seq.length() - 1][i];
        tot %= mod;
    }
    cout << tot << endl;
}

// #include <iostream>

// using namespace std;

// string seq;

// long long dp[100001][5][4][4];
// long long mod = 1000000007;

// int chrToNum(char c) {
//   switch(c) {
//     case 'A':
//       return 0;
//     case 'G':
//       return 1;
//     case 'C':
//       return 2;
//     case 'T':
//       return 3;
//     default:
//       return 4;
//   }
// }

// int main() {
//   cin >> seq;

//   if (seq[0] == '?') {
//     for (int j = 0; j < 4; j++) {
//       dp[0][4][j][j] = 1;
//     }
//   } else {
//     int c = chrToNum(seq[0]);
//     dp[0][4][c][c] = 1;
//   }

//   for (int i = 1; i < seq.length(); i++) {
//     for (int j = 0; j < 4; j++) {
//       for (int k = 0; k < 4; k++) {
//         if (seq[i] == '?') {
//           for (int l = 0; l < 4; l++) {
//             for (int m = 0; m < 4; m++) {
//               if (m != l) {
//                 dp[i][j][k][l] += dp[i-1][j][k][m];
//                 dp[i][j][k][l] %= mod;
//               }
//             }
//             dp[i][k][l][l] += dp[i-1][j][k][j];
//               dp[i][k][l][l] %= mod;
//           }
//         } else {
//           int l = chrToNum(seq[i]);
//             for (int m = 0; m < 4; m++) {
//               if (m != l) {
//                 dp[i][j][k][l] += dp[i-1][j][k][m];
//                 dp[i][j][k][l] %= mod;
//               }
//             }
//               dp[i][k][l][l] += dp[i-1][j][k][j];
//               dp[i][k][l][l] %= mod;
//         }
//       }
//     }

//       for (int k = 0; k < 4; k++) {
//         if (seq[i] == '?') {
//           for (int l = 0; l < 4; l++) {
//             for (int m = 0; m < 4; m++) {
//               if (m != l) {
//                 dp[i][4][k][l] += dp[i-1][4][k][m];
//                 dp[i][4][k][l] %= mod;
//               }
//             dp[i][k][l][l] += dp[i-1][4][k][m];
//               dp[i][k][l][l] %= mod;
//             }
//           }
//         } else {
//           int l = chrToNum(seq[i]);
//             for (int m = 0; m < 4; m++) {
//               if (m != l) {
//                 dp[i][4][k][l] += dp[i-1][4][k][m];
//                 dp[i][4][k][l] %= mod;
//               }
//               dp[i][k][l][l] += dp[i-1][4][k][m];
//               dp[i][k][l][l] %= mod;
//             }
//         }
//       }
//   }

//   long long tot = 0;
//   for (int i = 0; i < 4; i++) {
//     for (int k = 0; k < 4; k++) {
//       tot += dp[seq.length() - 1][i][k][i];
//         tot += dp[seq.length() - 1][4][i][k];
//       tot %= mod;
//     }
//   }
//   cout << tot << endl;
// }