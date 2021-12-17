#include <iostream>
#include <vector>
using namespace std;

int T, N, M, A, B, Answer;
vector<int> Graph[101];
int Visit[101];

void Dfs(int u)
{
    Visit[u] = 1;
    for(int i = 0; i < Graph[u].size(); i++)
    {
        int v = Graph[u][i];
        if(Visit[v] == 0)
        {
            Dfs(v);
        }
    }
}
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
            cin >> A >> B;
            Graph[A].push_back(B);
        }
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                Visit[j] = 0;
            }
            Dfs(i);
            Answer = 0;
            for(int j = 1; j <= N; j++)
            {
                Answer = Answer + Visit[j];
            }
            cout << Answer - 1 << " ";
        }
        cout << "\n";
        for(int j = 0; j <= N; j++)
        {
            Graph[j].clear();
        }
    }
    return 0;
}