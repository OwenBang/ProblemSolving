#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point
{
    int X, Y;
    double Dist;
};
struct compare
{
    bool operator()(const Point &a, const Point &b)
    {
        if(a.Dist != b.Dist)
        {
            return a.Dist < b.Dist;
        }
        else if(a.X != b.X)
        {
            return a.X < b.X;
        }
        else if(a.Y != b.Y)
        {
            return a.Y < b.Y;
        }
    }
};
int T, M, N, K, x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<Point, vector<Point>, compare> pq;
    Point P;
    cin >> T;
    while(T--)
    {
        cin >> M >> N >> K;
        for(int i = 0; i < M; i++)
        {
            cin >> x >> y;
            P.X = x;
            P.Y = y;
            P.Dist = sqrt(pow(x, 2) + pow(y, 2));
            pq.push(P);
            if(pq.size() > K)
            {
                pq.pop();
            }
        }
        for(int i = 0; i < N; i++)
        {
            cin >> x >> y;
            P.X = x;
            P.Y = y;
            P.Dist = sqrt(pow(x, 2) + pow(y, 2));
            pq.push(P);
            pq.pop();
            cout << pq.top().X << pq.top().Y << "\n";
        }
        while(!pq.empty())
        {
            pq.pop();
        }
    }
    return 0;
}