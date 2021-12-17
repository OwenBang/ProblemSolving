#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;
    cin >> T;
    int tri[100][100];
    int dp[100][100];
    while (T--)
    {
        memset(tri, 0, sizeof(tri));
        memset(dp, 0, sizeof(dp));
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> tri[i][j];
            }
        }

        int max = 0;
        int col = 0;
        // for (int i = 0; i < N; i++)
        // {
        //     if (i == 0)
        //     {
        //         max += tri[i][i];
        //     }
        //     else
        //     {
        //         if (tri[i][col] < tri[i][col + 1])
        //         {
        //             max += tri[i][col];
        //         }
        //         else
        //         {
        //             max += tri[i][col + 1];
        //             col++;
        //         }
        //     }
        // }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = tri[i][j];
                }
                else
                {
                    if (i == j)
                    {
                        dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
                    }
                    else if (j == 0)
                    {
                        dp[i][j] = dp[i - 1][j] + tri[i][j];
                    }
                    else if (dp[i - 1][j - 1] > dp[i - 1][j])
                    {
                        dp[i][j] = dp[i - 1][j] + tri[i][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
                    }
                }
            }
        }
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j <= i; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        cout << *min_element(dp[N - 1], dp[N - 1] + N) << '\n';
    }
    return 0;
}