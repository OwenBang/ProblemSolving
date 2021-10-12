#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, time, price, total_time, flag1, flag2;
    cin >> N >> M;
    total_time = 0;
    vector<pair<int, int> >v(N, make_pair(0, 0));

    while(M > 0)
    {
        cin >> time >> price;
        flag2 = 1;
        while(flag2 == 1)
        {
            if(flag1 == 1)
            {
                for(int i = 0; i < N; i++)
                {
                    if(v[i].first == 0)
                    {
                        v[i].first = time;
                        v[i].second += price;
                        flag2 = 0;
                        break;
                    }
                    if(i == N - 1) flag1 = 0;
                }
            }
            else
            {
                for(int i = 0; i < N; i++)
                {
                    v[i].first--;
                    total_time++;
                }
                flag1 = 1;
            }
            if(flag2 == 0) break;
        }
        M--;
    }

    cout << total_time << "\n";
    for(int i = 0 ; i < N; i++)
    {
        cout << v[i].second << "\n";
    }

    return 0;
}