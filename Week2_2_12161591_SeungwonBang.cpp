// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int T, N, temp1, temp2, result;
//     vector<int> V1;
//     vector<int> V2;
//     vector<pair<int, int> > sum;
//     cin >> T;
//     for (int i = 0; i < T; i++)
//     {
//         result = 0;
//         cin >> N;
//         for (int j = 0; j < N; j++)
//         {
//             cin >> temp1 >> temp2;
//             V1.push_back(temp1);
//             V2.push_back(temp2);
//             sum.push_back(make_pair(temp1 + temp2, j));
//         }
//         sort(sum.begin(), sum.end(), greater<>());
//         int flag = 1;
//         for(int j = 0; j < N; j++)
//         {
//             if(flag == 1)
//             {
//                 result += V1[sum[j].second];
//                 flag = 0;
//             }
//             else
//             {
//                 result -= V2[sum[j].second];
//                 flag = 1;
//             }
//         }
//         cout << result << "\n";
//     }
//     return 0;
// }

// // Read T
// // While T--
// // 	Read N
// // 	for i = 1 to N
// // 		Read resourceA[i], resourceB[i]
// // 		resourceSum[i] = make_pair(resourceA[i] + resourceB[i], i)
// // 	sort(&resourceSum[1], &resourceSum[N])
// // 	answer = 0, flag = 1
// // 	for i = 1 to N
// // 		if flag == 1
// // 			answer += resourceA[resourceSum[i].second]
// // 			flag = 0
// // 		else if flag == 0
// // 			answer -= resourceB[resourceSum[i].second]
// // 			flag = 1
// // 	print answer

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, temp1, temp2, answer, flag;
    vector<int> resourceA;
    vector<int> resourceB;
    vector<pair<int, int> > resourceSum;
    cin >> T;
    while (T > 0)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> temp1 >> temp2;
            resourceA.push_back(temp1);
            resourceB.push_back(temp2);
            resourceSum.push_back(make_pair((resourceA.back() + resourceB.back()), i));
        }
        sort(resourceSum.begin(), resourceSum.end());
        answer = 0;
        flag = 1;
        for (int i = 0; i < N; i++)
        {
            if (flag == 1)
            {
                answer += resourceA[resourceSum[i].second];
                flag = 0;
            }
            else if (flag == 0)
            {
                answer -= resourceB[resourceSum[i].second];
                flag = 1;
            }
        }
        cout << answer << "\n";
        resourceA.clear();
        resourceB.clear();
        resourceSum.clear();
        T--;
    }

    return 0;
}
