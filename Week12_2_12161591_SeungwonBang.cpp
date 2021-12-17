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
//     vector<int> rate;
//     vector<int> dist;
//     while (T--)
//     {
//         int N;
//         cin >> N;
//         int count = 0;
//         for (int j = 0; j < N; j++)
//         {
//             int a, b;
//             cin >> a >> b;
//             if (j == 0)
//             {
//                 rate.push_back(a);
//                 dist.push_back(b);
//                 count++;
//             }
//             else
//             {

//                 for (int i = 0; i < rate.size(); i++)
//                 {
//                     if (rate[i] > a && dist[i] < b)
//                     {
//                         break;
//                     }
//                     else if (rate[i] < a && dist[i] > b)
//                     {
//                         rate.push_back(a);
//                         dist.push_back(b);

//                         break;
//                     }
//                     rate.push_back(a);
//                     dist.push_back(b);
//                     count++;
//                 }
//             }
//             for (int i = 0; i < rate.size(); i++)
//             {
//                 cout << rate[i] << " " << dist[i] << endl;
//             }
//         }
//         cout << count << '\n';
//         rate.clear();
//         dist.clear();
//     }
//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N;
vector<pair<int, int> > Rooms;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--)
    {
        cin >> N;
        Rooms.push_back(make_pair(0, 0));
        for (int i = 1; i <= N; i++)
        {
            int f, s;
            cin >> f >> s;
            Rooms.push_back(make_pair(f, s));
        }
        sort(Rooms.begin() + 1, Rooms.end(), greater<pair<int, int> >());
        int Answer = 1;
        int Dist = Rooms[1].second;
        for (int i = 2; i <= N; i++)
        {
            if (Rooms[i].second < Dist)
            {
                Answer++;
                Dist = Rooms[i].second;
            }
        }
        cout << Answer << '\n';
        Rooms.clear();
    }
    return 0;
}