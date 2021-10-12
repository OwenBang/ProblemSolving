#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, ax, ay, bx, by, cx, cy, dx, dy;

    cin >> T;
    while(T > 0)
    {
        cin >> N;
        cin >> ax >> ay >> bx >> by;
        cin >> cx >> cy >> dx >> dy;

        vector<vector<int> > v(N, vector<int>(N, 0));

        ax--;
        ay--;
        bx--;
        by--;
        cx--;
        cy--;
        dx--;
        dy--;

        v[cx - 1][cy + 1] = 1;
        v[cx][cy + 1] = 1;
        v[cx + 1][cy + 1] = 1;
        v[cx - 1][cy] = 1;
        v[cx + 1][cy] = 1;
        v[cx - 1][cy - 1] = 1;
        v[cx][cy - 1] = 1;
        v[cx + 1][cy - 1] = 1;

        for(int i = 0; i < N; i++)
        {
            v[i][dy] = 1;
        }
        T--;
    }
}