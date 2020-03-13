#include<iostream>

struct A{
	int a;
	void func();
};

void A:: func(){}

int main()
{
	struct A a1;
	a1.func();
	return 0;
}
