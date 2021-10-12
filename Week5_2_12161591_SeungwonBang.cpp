#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, min;
    int resultmin = 0;
    vector<int> map;
    int temp;
    string s = "";
    cin >> N >> M;
    while(N > 0)
    {
        N--;
        cin >> temp;
        map.push_back(temp);
    }

    int len = map.size();
    
    vector<bool> v(len - M, false);
    v.insert(v.end(), M, true);
    do
    {
        vector<int> a;
        for(int k = 0; k < len; k++)
        {
            if(v[k]) a.push_back(map[k]);
        }
        min = a[1] - a[0];
        for(int i = 0; i < a.size() - 1; i++)
        {
            for(int j = i + 1; j < a.size(); j++)
            {
                if(min > a[j] - a[i])
                {
                    min = a[j] - a[i];
                }
            }
        }
        if(resultmin < min)
        {
            resultmin = min;
        }
        for(int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << " " << min << endl;
    }while (next_permutation(v.begin(), v.end()));

    cout << resultmin << "\n";
    return 0;
}