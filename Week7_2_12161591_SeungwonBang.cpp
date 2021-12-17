#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int T, M, N, K, x, y;

struct Point
{
    int X;
    int Y;
    double Dist;
};
struct compare
{
    bool operator()(const Point &a, const Point &b)
    {
        if(a.Dist != b.Dist)
            return a.Dist < b.Dist;
        else if(a.X != b.X)
            return a.X < b.X;
        else
            return a.Y < b.Y;
    }
};


Point P;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--)
    {
        cin >> M >> N >> K;
        priority_queue<Point, vector<Point>, compare> Stores;
        for(int i = 1; i <= M; i++)
        {
            cin >> x >> y;
            P.X = x;
            P.Y = y;
            P.Dist = sqrt(pow(x, 2) + pow(y, 2));
            
            Stores.push(P);
            
            if(Stores.size() > K)
            {
                Stores.pop();
            }
        }
        for(int i = 1; i <= N; i++)
        {
            cin >> x >> y;
            P.X = x;
            P.Y = y;
            P.Dist = sqrt(pow(x, 2) + pow(y, 2));
            Stores.push(P);
            Stores.pop();
            cout << Stores.top().X << " " << Stores.top().Y << "\n";
        }
        while(!Stores.empty())
        {
            Stores.pop();
        }
    }
    return 0;
}