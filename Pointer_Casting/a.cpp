#include<bits/stdc++.h>

using namespace std;

class base{
	virtual void func();
};

class derived : public base{
	public:
		void func(){cout<<"Inside Derived Class \n";}
};

int main()
{
	try{
		base *pbb=new base;
		base *pbd=new derived;
		derived *pd;
		pd=dynamic_cast<derived*> (pbb);
		if(pd==0)
			cout<<"Handler failed at 1:\n";
		pd=dynamic_cast<derived*> (pbd);
		if(pd==0)
			cout<<"Handler failed at 2:\n";
	}
	catch(exception& e){
		cout<<"Exception"<<e.what()<<endl;
	}
	return 0;
}
