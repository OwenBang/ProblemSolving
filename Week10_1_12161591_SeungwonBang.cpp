// #include <iostream>
// #include <string>

// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int T;
//     string A, B;
//     cin >> T;
//     while (T--)
//     {
//         cin >> A >> B;
//         while (1)
//         {
//             if (A.length() < 4)
//             {
//                 A = "0" + A;
//             }
//             else
//                 break;
//         }
//         while (1)
//         {
//             if (B.length() < 4)
//             {
//                 B = "0" + B;
//             }
//             else
//                 break;
//         }
//         cout << A << endl
//              << B << endl;
//         if ((int)A[0] * 10 + (int)A[1] == (int)B[0] * 10 + (int)B[1])
//         {
//             cout << abs((int)A[2] * 10 + (int)A[3] - (int)B[2] * 10 - (int)B[3]) << "\n";
//         }
//         else if ((int)A[3] * 10 + (int)A[2] == (int)B[0] * 10 + (int)B[1])
//         {
//             cout << abs((int)A[1] * 10 + (int)A[0] - (int)B[2] * 10 - (int)B[3]) + 1 << "\n";
//         }
//         else if ((int)A[2] * 10 + (int)A[3] == (int)B[2] * 10 + (int)B[3])
//         {
//             cout << abs((int)A[1] * 10 + (int)A[0] - (int)B[1] * 10 - (int)B[2]) + 2 << "\n";
//         }
//         else if ((int)A[1] * 10 + (int)A[0] == (int)B[2] * 10 + (int)B[3])
//         {
//             cout << abs((int)A[2] * 10 + (int)A[3] - (int)B[1] * 10 - (int)B[0]) + 1 << "\n";
//         }
//         else
//         {
//             if (abs((int)A[0] * 10 + (int)A[1] - (int)B[0] * 10 - (int)B[1] > 0) > abs((int)A[3] * 10 + (int)A[2] - (int)B[0] * 10 - (int)B[1] > 0))
//             {
//                 cout << "A" << endl;
//             }
//             else if (abs((int)A[0] * 10 + (int)A[1] - (int)B[0] * 10 - (int)B[1] > 0) < abs((int)A[3] * 10 + (int)A[2] - (int)B[0] * 10 - (int)B[1] > 0))
//             {
//                 cout << "B" << endl;
//             }
//             else
//             {
//                 cout << "D" << endl;
//             }
//         }
//     }
// }
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, A, B;
vector<int> road[10000];
int check[10000];
queue<int> que;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 10000; i++)
    {
        if (i != 0)
        {
            road[i].push_back(i - 1);
        }
        if (i != 9999)
        {
            road[i].push_back(i + 1);
        }
        int num = 0;
        int temp = i;
        for (int j = 0; j < 4; j++)
        {
            num = num * 10 + temp % 10;
            temp = temp / 10;
        }
        road[i].push_back(num);
    }

    cin >> T;
    while (T--)
    {
        for (int i = 0; i < 10000; i++)
        {
            check[i] = 10000;
        }
        cin >> A >> B;
        check[A] = 0;
        que.push(A);
        while (que.empty() == false)
        {
            int now = que.front();
            que.pop();
            for (int i = 0; i < road[now].size(); i++)
            {
                if (check[road[now][i]] > check[now] + 1)
                {
                    que.push(road[now][i]);
                    check[road[now][i]] = check[now] + 1;
                }
            }
        }
        cout << check[B] << "\n";
        while (!que.empty())
        {
            que.pop();
        }
    }
    return 0;
}