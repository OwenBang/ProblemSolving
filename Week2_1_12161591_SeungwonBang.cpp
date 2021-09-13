#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, M, K;
    vector<string> W;

    string temp;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;

        vector<vector<string> > S(N);

        for (int j = 0; j < M; j++)
        {
            cin >> temp;
            W.push_back(temp);
        }

        for (int j = 0; j < N; j++)
        {
            cin >> K;

            for (int k = 0; k < K; k++)
            {
                cin >> temp;
                S[j].push_back(temp);
            }
        }

        for (int j = 0; j < M; j++)
        {
            int tmp = 0;
            while (1)
            {
                if (W[0] == S[tmp][0])
                {
                    W.erase(W.begin());
                    S[tmp].erase(S[tmp].begin());
                    break;
                }
                tmp++;
                if (tmp == N)
                {

                    break;
                }
            }
        }
        if (W.empty())
        {
            cout << 1 << "\n";
        }
        else
            cout << 0 << "\n";
        W.clear();
    }
    return 0;
}
