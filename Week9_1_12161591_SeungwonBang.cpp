#include <iostream>
#include <algorithm>
using namespace std;

int T, X, N, M;
pair<long, long> GeoSeries(long long x, long long n)
{
    pair<int, int> ret;
    if (n == 1)
    {
        ret.first = x % M;
        ret.second = x % M;
        return ret;
    }
    pair<long long, long long> half = GeoSeries(x, n / 2);
    long long exp = half.first;
    long long sum = half.second;
    if(n % 2 == 0)
    {
        ret.first = (exp * exp) % M;
        ret.second = (1 + exp) * sum % M;
        return ret;
    }
    else
    {
        ret.first = (x * exp * exp) % M;
        ret.second = (x + x * (exp + 1) * sum) % M;
        return ret;
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
        cin >> X >> N >> M;
        pair<long, long> result = GeoSeries(X, N);
        cout << result.second << "\n";
    }
    return 0;
}