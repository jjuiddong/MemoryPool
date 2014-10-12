// 부스트 pool 을 쓰기로 함.
// http://postgame.tistory.com/32

#include <iostream>
#include "memorypool.h"
using namespace std;


class cA : public common::cMemoryPool<cA>
{
public:
	cA() {m_a = 0;}
	cA(int a) : m_a(a) {}
	void print() { 
		cout << "print" << m_a << endl;
	}

	int m_a;
};


void main()
{
	cA *pp3 = new cA(100);
	pp3->print();
	delete pp3;

	cA *pp4 = new cA(1000);
	pp4->print();
	delete pp4;

	cA *pa = new cA[ 10];
	pa[ 0].print();
	delete[] pa;
}
