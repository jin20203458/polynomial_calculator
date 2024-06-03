
#include"Poly.h"

    void poly::read() // ���带 �Ҷ����� �����Ͱ� �̵�(s) �ش��� ���׽ĸ� ��갡��
    {
        cout << "�ְ������� ����� �Է� �Ͻÿ� : ";
        cin >> n;
        s = GetM()->GetCount();    // ���������� �ʱ�ȭ
        for (int i = 0; i <= n; i++)
        {
            cout << n - i << "�� ���� ����� �Է��Ͻÿ� : ";
            GetM()->insert(s + i, n); // �� ������ ��� �Է�
        }
        GetM()->SetCount(n + 1); // ���� ����� ���� ���������� �̵�
    };

    void poly::write(int head,int tail)
    {
        for (int i = 0; i <= tail; ++i)
        {
            if (GetM()->GetMemory(head + i) == 0)continue;           // ����� 0�ϰ�� ������� ����
            if (i != 0)cout << '+';                    // �ְ������� �ƴϸ� + ���
            cout << GetM()->GetMemory(head + i);       // ��� ���
            if (i < tail - 1)cout << "x^" << tail - i; // ������ 1���� ũ�� ���� �߰� ���
            if (i == tail - 1)cout << 'x';             // ������ 1�̸� x�� ��� (1���� ������ x��� ��������)
        }
      cout << '\n';
    }

    int poly::eval(int x,int head,int tail)   // ȣ�ʽ� ���� �̿��� ���׽� ���
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
