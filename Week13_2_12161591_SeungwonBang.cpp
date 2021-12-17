// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int T;
//     cin >> T;
//     vector<int> v;
//     vector<int> board;
//     vector<int> result;
//     while (T--)
//     {
//         int N, M;
//         cin >> N >> M;
//         int temp;
//         for (int i = 0; i < M; i++)
//         {
//             cin >> temp;
//             v.push_back(temp);
//         }
//         for (int i = 0; i < N; i++)
//         {
//             board.push_back(0);
//         }
//         int cnt = N;
//         for (int i = M - 1; i >= 0; i--)
//         {
//             if (board[v[i] - 1] == 0)
//             {
//                 board[v[i] - 1] = 1;
//                 cnt--;
//             }
//             result.push_back(cnt);
//         }
//         for (int i = M - 1; i >= 0; i--)
//         {
//             cout << result[i] << '\n';
//         }

//         v.clear();
//         board.clear();
//         result.clear();
//     }
//     return 0;
// }

#include <iostream>
#include <set>
using namespace std;

int T, N, M;
int Messenger[500001];
int Answer[500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        for(int i = 1; i <= M; i++)
        {
            cin >> Messenger[i];
        }
        set<int> Readers;
        for(int i = M; i >= 1; i--)
        {
            if(Readers.find(Messenger[i]) == Readers.end())
            {
                Readers.insert(Messenger[i]);
            }
            Answer[i] = N - Readers.size();
        }
        for(int i = 1; i <= M; i++)
        {
            cout << Answer[i] << '\n';
        }
    }
    return 0;
}