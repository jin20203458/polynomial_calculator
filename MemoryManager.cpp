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
            cout << "������ ���׽��� �����ϴ�\n";
            return;
        }

        int io; cout << "������ ���׽��� ���ÿ�. :";
        cin >> io; io--; // �ε����� 0���� �����ϱ⿡

        int RP = remindP[io];
        int RB = remindB[io];
      
        int dSize = RB - RP + 1;// ������ ����� ������

        // 1. �޸𸮻��� ���� ����� ����
        for (int i =RB+1; i < count; ++i)
            memory[RP++] = memory[i]; // �޸𸮸� ��ܿ�(������ ���� �޸�)
        
        // 2. ī��Ʈ�� ���ҽ�Ŵ (���� ���׽��� �� ����)
        count -= dSize;

        // 3. ���Ͱ� �����ϴ� ������ ��� ���� ����
       remindP.erase(remindP.begin() + io);
       remindB.erase(remindB.begin() + io);

       // 4. ������ ��� ������ ���������� ����
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
            cout << "���׽��� �����ϴ�\n";
            return -1;
        }
        int io1, io2,sum;
        cout << "����� ���׽��� ���ÿ�\n";
        cin >> io1; io1--;
        cout << "�������� �Է��Ͻÿ�\n";
        cin >> io2;
        sum = p.eval(io2, remindP[io1], remindB[io1] - remindP[io1]);
        cout << "��� ��� :" << sum << '\n';
        return sum;
    }
 
    void MemoryMenager::interface(poly p)
    {
        int io;
        while (true)
        {
            cout << "���� ����� ���׽��� ���� :" << remindP.size() << "\n\n";


            for (int i = 0; i < remindP.size(); ++i)
            {
                cout << i + 1 << "��° ���� ���׽� :";
                p.write(remindP[i], remindB[i] - remindP[i]);

            }
            cout << "������ ������ �Է��Ͻÿ�. ����:1, ����:2, ����:3, ����:4  :";
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
                cout << "���� ����\n";
                return;
            }
        }
    }

 



