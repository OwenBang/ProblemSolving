#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, temp1, temp2, result;
    vector<int> V1;
    vector<int> V2;
    vector<pair<int, int> > sum; 
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        result = 0;
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> temp1 >> temp2;
            V1.push_back(temp1);
            V2.push_back(temp2);
            sum.push_back(make_pair(temp1 + temp2, j));
        }
        sort(sum.begin(), sum.end(), greater<>());
        int flag = 1;
        for(int j = 0; j < N; j++)
        {
            if(flag == 1)
            {
                result += V1[sum[j].second];
                flag = 0;
            }
            else
            {
                result -= V2[sum[j].second];
                flag = 1;
            }
        }
        cout << result << "\n";
    }
    return 0;
}