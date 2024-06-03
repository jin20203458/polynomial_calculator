
#include"Poly.h"

    void poly::read() // 리드를 할때마다 포인터가 이동(s) 해당한 다항식만 계산가능
    {
        cout << "최고차항의 계수를 입력 하시오 : ";
        cin >> n;
        s = GetM()->GetCount();    // 시작포인터 초기화
        for (int i = 0; i <= n; i++)
        {
            cout << n - i << "차 항의 계수를 입력하시오 : ";
            GetM()->insert(s + i, n); // 각 차수의 계수 입력
        }
        GetM()->SetCount(n + 1); // 다음 계산을 위해 시작포인터 이동
    };

    void poly::write(int head,int tail)
    {
        for (int i = 0; i <= tail; ++i)
        {
            if (GetM()->GetMemory(head + i) == 0)continue;           // 계수가 0일경우 출력하지 않음
            if (i != 0)cout << '+';                    // 최고차항이 아니면 + 출력
            cout << GetM()->GetMemory(head + i);       // 계수 출력
            if (i < tail - 1)cout << "x^" << tail - i; // 차수가 1보다 크면 차수 추가 출력
            if (i == tail - 1)cout << 'x';             // 차수가 1이면 x만 출력 (1보다 작으면 x출력 하지않음)
        }
      cout << '\n';
    }

    int poly::eval(int x,int head,int tail)   // 호너스 룰을 이용한 다항식 계산
    {
        int y = 0;
        for (int i = 0; i <= tail; i++)
        {
            y += GetM()->GetMemory(head + i);
            if (i < tail)
                y *= x;
        }
        return y;
    };


MemoryMenager* poly::MM = nullptr;
