#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, temp;
    
    cin >> T;

    while(T > 0)
    {
        T--;
        vector<int> X;
        vector<int> least;
        vector<int> a;
        cin >> N;
        while(N > 0)
        {
            N--;
            cin >> temp;
            X.push_back(temp);
        }
        least.push_back(X[0]);
        while(1)
        {
            a = least;
            while(1)
            {
                if(a.size() > X.size())
                {
                    while(1)
                    {
                        if(a.size() == X.size())
                        {
                            break;
                        }
                        else
                        {
                            a.pop_back();
                        }
                    }
                    break;
                }
                else
                {
                    a.reserve(a.size() + least.size());
                    a.insert(a.end(), least.begin(), least.end());
                }
            }
            if(a == X)
            {
                for(int i = 0; i < least.size(); i++)
                {
                    cout << least[i] << " ";
                }
                cout << "\n";
                break;
            }
            else
            {
                least.push_back(X[least.size()]);
            }
        }
    }
    return 0;
}