#pragma once
#include"MemoryManager.h"
class poly
{
private:
    int s; // ����������
    int n; // size (�ְ�����)
    static MemoryMenager* MM; // �̱��� �޸𸮸޴���
public:
    poly() 
    {
        cout << "�޸𸮰� �����ϴ�. ���׽��� �Է��Ͻÿ�\n\n";
        read();
    }
    static MemoryMenager* GetM()
    {
        if (MM == nullptr)
            MM = new MemoryMenager;
        return MM;
    }
    void read();       // ���带 �Ҷ����� �����Ͱ� �̵�(s) �ش��� ���׽ĸ� ��갡��
    void write(int,int);
    int eval(int ,int,int);   // ȣ�ʽ� ���� �̿��� ���׽� ���
   

};

