GCD(int A, int B)       A와 B의 최대공약수 계산

int C
While B!=0
    C = A % B
    A = B
    B = C
return A

Main()

Read T                  테스트케이스의 수
While T--
    Read A, B, x, y

    gcd = GCD(A, B)
    cost = 0
    cnt = 0             훈련 강제/억제 횟수를 셈
    a = A               
    b = B               A 와 B의 값을 변경시킬 것이므로 임시저장

    While A != 1 or B != 1
        A--
        B--
        cnt++
        temp = GCD(A, B)

        if temp > gcd   현재 값으로 구한 gcd가 기존 gcd보다 크다면 최신화
            gcd = temp
            cost = y * cnt      드는 비용에 횟수만큼 곱하면 총 소모비용

    A = a
    B = b               A와 B의 값을 원래대로 돌려줌
    cnt = 0            

    While cnt < 10000
        A++
        B++
        cnt++
        temp = GCD(A, B)

        if temp > gcd
            gcd = temp
            cost = x * cnt

    print gcd and cost
