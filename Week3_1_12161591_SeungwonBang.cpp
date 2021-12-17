#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;

int T, N, A, B;
string S;

struct Node
{
    int parent = 0;
    vector<int> children;
    int length = 0;
};

// vector<Node> Tree;
// vector<int> Directory;
Node Tree[];
int Directory[];

void TreeTraversal(int u)
{
    if (u == 1)
    {
        Directory[u] = 4;
    }
    else
    {
        Directory[u] = Directory[Tree[u].parent] + 1 + Tree[u].length;
    }

    for (int i = 0; i < Tree[u].children.size(); i++)
    {
        TreeTraversal(Tree[u].children[i]);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T > 0)
    {
        cin >> N;
        memset(Tree, 0, N);
        menset(Directory, 0, N);
        int Directory[N];
        for (int i = 1; i < N; i++)
        {
            cin >> A >> B;
            Tree[A].children.push_back(B);
            Tree[B].parent = A;
        }
        for (int i = 0; i < N; i++)
        {
            cin >> S;
            Tree[i].length = S.length();
        }
        TreeTraversal(1);

        for (int i = 0; i < N; i++)
        {
            cout << Directory[i] << "\n";
        }
        T--;
        // Tree.clear();
        // Directory.clear();
    }
    return 0;
}