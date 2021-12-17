// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int N, M;
//     cin >> N >> M;
//     char board[3000][3000] = {
//         '.',
//     };
//     string word;
//     for (int i = 0; i < N; i++)
//     {
//         cin >> word;
//         for (int j = 0; j < word.size(); j++)
//         {
//             board[i][j] = word[j];
//         }
//     }
//     vector<string> word_list;
//     for (int i = 0; i < M; i++)
//     {
//         cin >> word;
//         word_list.push_back(word);
//     }
//     int direction = 0;
//     for (int i = 0; i < M; i++)
//     {
//         direction = 0;
//         for (int j = 0; j < N; j++)
//         {
//             for (int k = 0; k < N; k++)
//             {
//                 if (board[j][k] == word_list[i][0])
//                 {
//                     if (board[j][k + 1] == word_list[i][1])
//                     {
//                         direction = 1;
//                     }
//                     else if (board[j + 1][k] == word_list[i][1])
//                     {
//                         direction = 2;
//                     }
//                     else if (board[j + 1][k + 1] == word_list[i][1])
//                     {
//                         direction = 3;
//                     }
//                     else
//                     {
//                         direction = 0;
//                     }
//                 }
//                 if (direction == 0)
//                     continue;
//                 else
//                 {
//                     if (direction == 1)
//                     {
//                         word = "";
//                         for (int l = 0; l < word_list[i].size(); l++)
//                         {
//                             word += board[j][k + l];
//                         }
//                         if (word == word_list[i])
//                         {
//                             cout << 1 << endl;
//                             goto end;
//                         }
//                         else
//                         {
//                             direction = 0;
//                         }
//                     }
//                     else if (direction == 2)
//                     {
//                         word = "";
//                         for (int l = 0; l < word_list[i].size(); l++)
//                         {
//                             word += board[j + l][k];
//                         }
//                         if (word == word_list[i])
//                         {
//                             cout << 1 << endl;
//                             goto end;
//                         }
//                         else
//                         {
//                             direction = 0;
//                         }
//                     }
//                     else if (direction == 3)
//                     {
//                         word = "";
//                         for (int l = 0; l < word_list[i].size(); l++)
//                         {
//                             word += board[j + l][k + l];
//                         }
//                         if (word == word_list[i])
//                         {
//                             cout << 1 << endl;
//                             goto end;
//                         }
//                         else
//                         {
//                             direction = 0;
//                         }
//                     }
//                 }
//             }
//         }
//     end:
//         continue;
//     }

//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

int N, M;
string Puzzle[3000];
int F[3000];

void FailureFunction(string P)
{
    F[0] = 0;
    int i = 1;
    int j = 0;
    while(i < P.size())
    {
        if(P[i] == P[j])
        {
            F[i] = j + 1;
            i++;
            j++;
        }
        else if(j > 0)
        {
            j = F[j - 1];
        }
        else
        {
            F[i] = 0;
            i++;
        }
    }
}

bool KMPMatch(string T, string P)
{
    int i = 0;
    int j = 0;
    while(i < T.size())
    {
        if(T[i] == P[j])
        {
            if(j == P.size() - 1)
            {
                return true;
            }
            i++;
            j++;
        }
        else if(j > 0)
        {
            j = F[j - 1];
        }
        else
        {
            i++;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> Puzzle[i];
    }
    string Text, Word;
    for(int i = 0; i < N; i++)
    {
        Text += Puzzle[i];
        Text += "$";
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            Text += Puzzle[j][i];
        }
        Text += "$";
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N - i; j++)
        {
            Text += Puzzle[j][i + j];
        }
        Text += "$";
    }
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < N - i; j++)
        {
            Text += Puzzle[i + j][j];
        }
        Text += "$";
    }
    while(M--)
    {
        cin >> Word;
        FailureFunction(Word);
        if(KMPMatch(Text, Word) == true)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}