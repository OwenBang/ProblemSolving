#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;
    vector<int> x;
    vector<int> y;
    vector<int> x_rank;
    vector<int> y_rank;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        x.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        y.push_back(b);
    }

    for (int i = 0; i < m; i++)
    {
        x_rank.push_back(x[i].rank());
    }
    return 0;
}