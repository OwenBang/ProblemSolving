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
        }

        for (int j = 0; j < N; j++)
        {
            if (j % 2 == 0)
            {
                int idx = max_element(V1.begin(), V1.end()) - V1.begin();
                //int max = V1[idx];
                result += V1[idx];
                V1[idx] = 0;
                V2[idx] = 0;
                // V1.erase(V1.begin() + idx);
                // V2.erase(V2.begin() + idx);
            }
            else if (j % 2 == 1)
            {
                int idx = max_element(V2.begin(), V2.end()) - V2.begin();
                //int max = V2[idx];
                result -= V2[idx];
                V1[idx] = 0;
                V2[idx] = 0;
                // V1.erase(V1.begin() + idx);
                // V2.erase(V2.begin() + idx);
            }
        }
        cout << result << "\n";
    }
    return 0;
}