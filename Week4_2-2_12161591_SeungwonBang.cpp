#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> T;
    while(T > 0)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;

        int temp;

        if(x1 > x2)
        {
            temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        if(x3 > x4)
        {
            temp = x3;
            x3 = x4;
            x4 = temp;
            temp = y3;
            y3 = y4;
            y4 = temp;
        }

        int flag;

        if((x2 - x1)/(y2 - y1) == (x4 - x3)/(y4 - y3))
        {
            //평행
            
        cout << flag << "\n";
        T--;
    }

    return 0;
}