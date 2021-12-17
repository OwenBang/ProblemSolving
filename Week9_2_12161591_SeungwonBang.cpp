#include <iostream>
#include <set>
#include <vector>
using namespace std;

int grid[21][21];
struct point_info
{
    int x, y;
}
set<point_info> candidate;
vector<int> check[21][21][3];
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};
int N, Q, T;

int CandidateCheckFunc()
{
    int ret = 0;
    for(int )
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--)
    {
        cin >> N >> Q;
        grid[N / 2][N / 2] = grid[N / 2 + 1][N / 2 + 1] = 1;
        grid[N / 2 + 1][N / 2] = grid[N / 2][N / 2 + 1] = 2;
        for(int i = 0; i <= 1; i++)
        {
            for(int j = 0; j <= 1; j++)
            {
                aroundCandidateFunc(N / 2 + i, N / 2 + j);
            }
        }
        int turn = 1;
        while(Q--)
        {
            int x, y;
            cin >> x >> y;
            int flag = CandidateCheckFunc();
            if((flag & turn) == 0)
            {
                turn = flag;
            }
            if(grid[x][y] != 0)
            {
                continue;
            }
            if(check[x][y][turn].empty() == true)
            {
                continue;
            }
            for(int k = 1; k <=check[x][y][turn].size(); k++)
            {
                int i = check[x][y][turn][k];
                for(int j = 1; j <= N; j++)
                {
                    if(grid[x + dx[i] * j][y + dy[i] * j] == turn)
                    {
                        break;
                    }
                    grid[x + dx[i] * j][y + dy[i] * j] = turn;
                }
            }
            grid[x][y] = turn;
            if(turn == 1)
            {
                turn = 2;
            }
            else
            {
                turn = 1;
            }
            candidate.erase(point_info{x, y});
            aroundCandidateFunc(x, y);
            int ansCheck = 0;
            for(int i = 1; i <= N; i++)
            {
                for(int j = 1; j <= N; j++)
                {
                    if(grid[i][j] == 1)
                    {
                        ansCheck++;
                    }
                    else if(grid[i][j] == 2)
                    {
                        ansCheck--;
                    }
                }
            }
            if(ansCheck > 0)
            {
                cout << 2;
            }
            else if(ansCheck < 0)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
    }
}