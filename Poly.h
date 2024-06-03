#pragma once
#include"MemoryManager.h"
class poly
{
private:
    int s; // 시작포인터
    int n; // size (최고차항)
    static MemoryMenager* MM; // 싱글톤 메모리메니저
public:
    poly() 
    {
        cout << "메모리가 비어습니다. 다항식을 입력하시오\n\n";
        read();
    }
    static MemoryMenager* GetM()
    {
        if (MM == nullptr)
            MM = new MemoryMenager;
        return MM;
    }
    void read();       // 리드를 할때마다 포인터가 이동(s) 해당한 다항식만 계산가능
    void write(int,int);
    int eval(int ,int,int);   // 호너스 룰을 이용한 다항식 계산
   

};

