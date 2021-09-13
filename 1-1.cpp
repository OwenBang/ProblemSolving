#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;

    string str;
    cin >> str;

    int col;
    cin >> col;

    int row;
    row = (str.length() / col) + 1;

    char arr[col][row];
    int temp1, temp2 = 0;
    bool flag = true;
    // for (int i = 0; i < str.length(); i++)
    // {
    //     arr[temp1][temp2] = str[i];
    //     if (temp1 == 0 && temp2 == 0)
    //     {
    //         temp1++;
    //         continue;
    //     }
    //     if (flag == true && (temp1 == 0 || temp1 == (col - 1)))
    //     {
    //         temp2++;
    //         flag = false;
    //     }
    //     else
    //     {
    //         flag = true;
    //         if ((i / col) / 2 == 0)
    //         {
    //             temp1++;
    //         }
    //         else
    //             temp1--;
    //     }
    // }

    for (int i = 0; i < str.length(); i++)
    {
        if ((i / col) / 2 == 0)
        {
            arr[i % col][i / col] = str[i];
        }
        else
        {
            arr[col - (i % col) - 1][i / col] = str[i];
        }
    }
    //cout << str[0];
    //cout << arr[1][1];
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << arr[i][j];
        }
    }

    return 0;
}