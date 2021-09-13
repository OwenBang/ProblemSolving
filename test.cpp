#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.erase(a.begin());
    cout << a[0];
    return 0;
}