#include <iostream>
using namespace std;

int GCD(int A, int B)
{
    int C;
    while(B != 0)
    {
        C = A % B;
        A = B;
        B = C;
    }
    return A;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, A, B, x, y, gcd, cost;
    cin >> T;
    while(T > 0)
    {
        cin >> A >> B >> x >> y;
        
        gcd = GCD(A, B);
        int temp;
        cost = 0;
        int cnt = 0;
        int a, b;
        a = A;
        b = B;
        while(1)
        {
            A -= 1;
            B -= 1;
            cnt += 1;
            if(A == 0 || B == 0) break;
            else
            {
                temp = GCD(A, B);
            
                if(temp > gcd)
                {
                    gcd = temp;
                    cost = y * cnt;
                }
            }
        }
        A = a;
        B = b;
        cnt = 0;
        int flag = 10;
        while(cnt < 10000)
        {
            A += 1;
            B += 1;
            cnt += 1;
            
            temp = GCD(A, B);
            
            if(temp > gcd && x * cnt < cost * 10)
            {
                gcd = temp;
                cost = x * cnt;
            }
            
        }
        cout << gcd << " " << cost << "\n";
        T--;
    }
    
    return 0;
}


// Main()
// int T, A, B, x, y, g, answer
// Read T
// While T--
//     Read A, B, x, y
//         g = Absolute(A - B)
//         answer = min((a % g) * y, (g - (a % g)) * x)

//         print g, answer