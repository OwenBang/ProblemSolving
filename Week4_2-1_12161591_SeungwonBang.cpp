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
        int flag1, flag2;
        if(x1 - x2 == 0) flag1 = 1;
        else flag1 = 0;
        if(x3 - x4 == 0) flag2 = 1;
        else flag2 = 0;

        if(flag1 == 1)
        {
            if(y1 > y2)
            {
                temp = y1;
                y1 = y2;
                y2 = temp;
            }
        }
        else
        {
            if(x1 > x2)
            {
                temp = x1;
                x1 = x2;
                x2 = temp;
            }
        }
        if(flag2 == 1)
        {
            if(y3 > y4)
            {
                temp = y3;
                y3 = y4;
                y4 = temp;
            }
        }
        else
        {
            if(x3 > x4)
            {
                temp = x3;
                x3 = x4;
                x4 = temp;
            }
        }
        int flag;
        if(flag1 == flag2)
        {
            if(flag1 == 1)
            {
                if(x1 != x3)
                {
                    flag = 1;
                }
                else
                {
                    if(y1 >= y3 && y2 <= y4)
                    {
                        flag = 4;
                    }
                    else if(y1 <= y3 && y2 >= y4)
                    {
                        flag = 4;
                    }
                    else if(y2 == y3 || y1 == y4)
                    {
                        flag = 2;
                    }
                    else if(y2 < y3 || y1 > y4)
                    {
                        flag = 1;
                    }
                    else flag = 3;
                }
            }
            else
            {
                if(y1 != y3)
                {
                    flag = 1;
                }
                else
                {
                    if(x1 >= x3 && x2 <= x4)
                    {
                        flag = 4;
                    }
                    else if(x1 <= x3 && x2 >= x4)
                    {
                        flag = 4;
                    }
                    else if(x2 == x3 || x1 == x4)
                    {
                        flag = 2;
                    }
                    else if(x2 < x3 || x1 > x4)
                    {
                        flag = 1;
                    }
                    else flag = 3;
                }
            }
        }
        else
        {
            if(flag1 == 1)
            {
                if(x1 >= x3 && x1 <= x4)
                {
                    if(y3 >= y1 && y3 <= y2)
                    {
                        flag = 2;
                    }
                    else flag = 1;
                }
                else flag = 1;
            }
            else
            {
                if(y1 >= y3 && y1 <= y4)
                {
                    if(x3 >= x1 && x3 <= x2)
                    {
                        flag = 2;
                    }
                    else flag = 1;
                }
                else flag = 1;
            }
        }
        cout << flag << "\n";
        T--;
    }

    return 0;
}