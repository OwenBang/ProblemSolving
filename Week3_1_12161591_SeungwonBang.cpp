#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
class Node
{
    int num;
    string name;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, temp1, temp2;
    
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> N;
        map<Node, pair<Node, Node>> tree;
        for(int j = 0; j < N - 1; j++)
        {
            cin >> temp1 >> temp2;
            dir[temp1 - 1].push_back(temp2 - 1);
        }
        for(int j = 0; j < N; j++)
        {
            cin >> name;
            dirname.push_back(name);
        }
        for(int j = 0; j < N; j++)
        {
            if(j == 0) cout << "4\n";
            else
            {
                
            }
        }
    }
}