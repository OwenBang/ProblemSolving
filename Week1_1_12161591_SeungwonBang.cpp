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

    for (int a = 0; a < testcase; a++)
    {
        string str;
        cin >> str;

        int col;
        cin >> col;

        int row;
        row = (str.length() / col) + 1;

        char arr[col][row];
        int temp1, temp2 = 0;
        bool flag = true;

        for (int i = str.length(); i < col * row; i++)
        {
            str.append("\n");
        }
        for (int i = 0; i < str.length(); i++)
        {
            if ((i / col) % 2 == 0)
            {
                arr[i % col][i / col] = str[i];
            }
            else
            {
                arr[col - (i % col) - 1][i / col] = str[i];
            }
        }

        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                if (arr[i][j] == '\n')
                    continue;
                cout << arr[i][j];
            }
        }
        cout << "\n";
    }
    return 0;
}