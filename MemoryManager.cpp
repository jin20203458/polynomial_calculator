 #include"MemoryManager.h"
#include"Poly.h"


    void MemoryMenager::SetCount(int data)
    {
        remindP.push_back(count);
        count += data;
        remindB.push_back(count - 1);
    }

    void MemoryMenager:: Pdelete()
    {
        if (count == 0)
        {
            cout << "삭제할 다항식이 없습니다\n";
            return;
        }

        int io; cout << "삭제할 다항식을 고르시오. :";
        cin >> io; io--; // 인덱스는 0부터 시작하기에

        int RP = remindP[io];
        int RB = remindB[io];
      
        int dSize = RB - RP + 1;// 삭제할 대상의 사이즈

        // 1. 메모리상의 삭제 대상을 지움
        for (int i =RB+1; i < count; ++i)
            memory[RP++] = memory[i]; // 메모리를 당겨옴(삭제한 다음 메모리)
        
        // 2. 카운트를 감소시킴 (다음 다항식이 들어갈 지점)
        count -= dSize;

        // 3. 백터가 저장하는 삭제할 대상 정보 삭제
       remindP.erase(remindP.begin() + io);
       remindB.erase(remindB.begin() + io);

       // 4. 삭제할 대상 다음의 벡터정보들 수정
       for (int i = io; i < remindB.size(); ++i)
       {
           remindP[i] -= dSize;
           remindB[i] -= dSize;
       }

    }

    int MemoryMenager::sub(poly p)
    {
        if (count == 0)
        {
            cout << "다항식이 없습니다\n";
            return -1;
        }
        int io1, io2,sum;
        cout << "계산할 다항식을 고르시오\n";
        cin >> io1; io1--;
        cout << "미지수를 입력하시오\n";
        cin >> io2;
        sum = p.eval(io2, remindP[io1], remindB[io1] - remindP[io1]);
        cout << "계산 결과 :" << sum << '\n';
        return sum;
    }
 
    void MemoryMenager::interface(poly p)
    {
        int io;
        while (true)
        {
            cout << "현재 저장된 다항식의 개수 :" << remindP.size() << "\n\n";


            for (int i = 0; i < remindP.size(); ++i)
            {
                cout << i + 1 << "번째 저장 다항식 :";
                p.write(remindP[i], remindB[i] - remindP[i]);

            }
            cout << "수행할 연산을 입력하시오. 삽입:1, 삭제:2, 대입:3, 종료:4  :";
            cin >> io;
            switch (io) {
            case 1:
                p.read();
                break;
            case 2:
                Pdelete();
                break;
            case 3:
                sub(p);
                break;
            case 4:
                cout << "정상 종료\n";
                return;
            }
        }
    }

 



