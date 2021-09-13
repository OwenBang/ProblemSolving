#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        int qnum, num, temp, min, max;
        vector<int> s;
        cin >> qnum;
        for (int j = 0; j < qnum; j++)
        {
            cin >> num;
            if (num == 1)
            {
                cin >> temp;
                s.push_back(temp);
                min = s[0];
                max = s[0];
                for (int k = 0; k < s.size(); k++)
                {
                    if (s[k] > max)
                        max = s[k];
                    if (s[k] < min)
                        min = s[k];
                }
                cout << min << " " << max << "\n";
            }
            else
            {
                if (s.empty())
                {
                    continue;
                }
                s.pop_back();
            }
        }
    }
    return 0;
}