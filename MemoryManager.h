#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class poly;
class MemoryMenager
{
    int memory[1000] = {};
    vector<int> remindP; // 다항식의 시작지점
    vector<int> remindB; // 다항식의 끝지점
    int count = 0;       // 다음 다항식이 들어갈 지점
 
public:
    void insert(int data, int n)
    {
        cin >> memory[data];
    }
    int& GetCount() { return count; }
    int& GetMemory(int data) { return memory[data]; }

    vector<int>& GetRP() { return remindP; }
    vector<int>& GetRB() { return remindB; }

    int sub(poly);
    void Pdelete( );
    void SetCount(int);
    void interface(poly);
    
   
   
};


