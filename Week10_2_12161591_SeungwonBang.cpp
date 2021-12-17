// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int T, N, A, temp1, temp2;
//     vector<int> list;
//     cin >> T;
//     while (T--)
//     {
//         cin >> N;
//         while (N--)
//         {
//             cin >> A;
//             list.push_back(A);
//         }
//         temp1 = 0;
//         temp2 = 0;
//         for (int i = 1; i < list.size(); i++)
//         {

//             if (list[i + 1] > list[i - 1] && list[i + 1] < list[i])
//             {
//                 list.erase(list.begin() + i);
//                 i--;
//                 continue;
//             }
//             if (list[i] < list[i - 1])
//             {
//                 list.erase(list.begin() + i);
//                 i--;
//                 continue;
//             }
//         }
//         // cout << list.size() << "\n";
//         for (int i = 0; i < list.size(); i++)
//         {
//             cout << list[i] << " ";
//         }
//         cout << "\n";
//         list.clear();
//     }
// }

#include <iostream>
using namespace std;

int T, N, Answer;
int Matryoshka[501], DP[501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> Matryoshka[i];
        }
        Answer = 0;
        for (int i = 1; i <= N; i++)
        {
            DP[i] = 1;
            for (int j = 1; j <= i - 1; j++)
            {
                if (Matryoshka[i] > Matryoshka[j])
                {
                    DP[i] = max(DP[i], DP[j] + 1);
                }
            }
            Answer = max(Answer, DP[i]);
        }
        cout << Answer << "\n";
    }
    return 0;
}
