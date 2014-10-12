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

// bug occure
class cB : public cA
{
public:
	cB() {m_b = 0;}
	cB(int b) : m_b(b) {}
	void print() { 
		cout << "print" << m_b << endl;
	}

	int m_b;
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

	// bug occure
	cA *pp5 = new cB(1000);
	pp5->print();
	delete pp5;

}
