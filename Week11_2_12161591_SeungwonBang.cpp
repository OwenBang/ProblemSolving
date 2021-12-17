// #include <iostream>
// #include <algorithm>
// #include <math.h>
// #include <memory.h>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int T;
//     while (T--)
//     {
//         int N;
//         cin >> N;
//         char color;
//         char board[(int)pow(N, N)];
//         int flag[N][N] = {0};
//         for (int i = 0; i < (int)pow(N, N); i++)
//         {
//             cin >> color;
//             board[i] = color;
//         }

//         int count = 1;
//         int x = 0;
//         while (1)
//         {
//             for (int i = 0; i < count; i++)
//             {
//                 if (equal(board[(int)pow(N, N) / count], board[(int)pow(N, N) - 1], board[0]))
//                 {
//                     memset(flag, 1, sizeof(flag));
//                 }
//             }

//             for (int i = 0; i < N; i++)
//             {
//                 for (int j = 0; j < N; j++)
//                 {
//                     if (flag[i][j] == 0)
//                     {
//                         break;
//                     }
//                     else
//                     {
//                         x = 1;
//                     }
//                 }
//             }
//             if (x == 1)
//             {
//                 break;
//             }
//         }
//     }

#include <iostream>
using namespace std;

char paper[1024][1024];
int T, N;
struct paperInfo
{
    int redNumber = 0;
    int redSize = 0;
    int blueNumber = 0;
    int blueSize = 0;
};

paperInfo solution(int x, int y, int size)
{
    paperInfo ret;
    if (size == 1)
    {
        if (paper[x][y] == 'R')
        {
            ret.redNumber = ret.redSize = 1;
        }
        else
        {
            ret.blueNumber = ret.blueSize = 1;
        }
        return ret;
    }
    paperInfo status[4];
    status[0] = solution(x, y, size / 2);
    status[1] = solution(x + size / 2, y, size / 2);
    status[2] = solution(x, y + size / 2, size / 2);
    status[3] = solution(x + size / 2, y + size / 2, size / 2);
    for (int i = 0; i < 4; i++)
    {
        ret.redNumber += status[i].redNumber;
        ret.redSize += status[i].redSize;
        ret.blueNumber += status[i].blueNumber;
        ret.blueSize += status[i].blueSize;
    }
    if (ret.redNumber == 0)
    {
        ret.blueNumber = 1;
    }
    if (ret.blueNumber == 0)
    {
        ret.redNumber = 1;
    }
    return ret;
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> paper[i][j];
            }
        }
        paperInfo answer = solution(0, 0, N);
        cout << answer.redNumber << " " << answer.redSize << " " << answer.blueNumber << " " << answer.blueSize << "\n";
    }
    return 0;
}