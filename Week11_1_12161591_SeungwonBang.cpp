// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int alpabet[26] = {
//         0,
//     };
//     int in_alpabet[26] = {
//         0,
//     };

//     for (int i = 0; i < 26; i++)
//     {
//         cin >> alpabet[i];
//     }

//     int word_count = 0;
//     cin >> word_count;

//     vector<string> word_list;
//     vector<int> score_list;
//     for (int i = 0; i < word_count; i++)
//     {
//         string word;
//         int score;
//         cin >> word >> score;
//         word_list.push_back(word);
//         score_list.push_back(score);
//     }

//     int max_score = 0;
//     int aaa = 0;
//     vector<int> min_list;
//     while (true)
//     {
//         for (int i = 0; i < word_count; i++)
//         {
//             int score = 0;

//             for (int j = 0; j < word_list.size(); j++)
//             {
//                 min_list.push_back(min_element(score_list.begin(), score_list.end()) - score_list.begin());
//                 score = (int)(word_list[i][j] - 'a');
//                 in_alpabet[score]++;
//             }
//         }
//         for (int i = 0; i < 26; i++)
//         {
//             if (alpabet[i] < in_alpabet[i])
//             {
//                 in_alpabet[26] = {
//                     0,
//                 };
//                 break;
//             }
//             else if (i == 25)
//             {
//             }
//         }
//         aaa++;
//     }
//     return 0;
// }

#include <iostream>
#include <string>

using namespace std;
constexpr int pow(int base, int exp) noexcept
{
    auto result = 1;
    for(int i = 0; i < exp; ++i) result += base;
    return result;
}
int score[24];
int needAlpabet[24][27];
constexpr int X = pow(2, 24);
int restAlpabet[X + 1][27];
int M, answer;
string word;
int getScore[X + 1];

void solution()
{
    getScore[0] = 0;
    for (int i = 1; i <= M; i++)
    {
        int status = 1 << (i - 1);
        for (int j = 0; j < status - 1; j++)
        {
            bool flag = false;
            for (int k = 1; k <= 26; k++)
            {
                if (restAlpabet[j][k] < needAlpabet[i][k])
                {
                    flag = true;
                }
            }
            if (flag == true)
            {
                continue;
            }
            for (int k = 1; k <= 26; k++)
            {
                restAlpabet[j + status][k] = restAlpabet[j][k] - needAlpabet[i][k];
            }
            getScore[j + status] = getScore[j] + score[i];
            answer = max(answer, getScore[j + status]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 26; i++)
    {
        cin >> restAlpabet[0][i];
    }
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> word >> score[i];
        for (int j = 1; j <= word.length(); j++)
        {
            needAlpabet[i][word[j - 1] - 'a' + 1]++;
        }
    }
    solution();
    cout << answer;
    return 0;
}