#include <memory>
#include <iostream>

using namespace std;
class B;

class A {
public:
	shared_ptr<B> ptr;
	~A() {
		cout << "A destructor" << endl;
	}
};

class B {
public:
	shared_ptr<A> ptr;
	~B() {
		cout << "B destructor" << endl;
	}

};


int main()
{
	unique_ptr<int> a = make_unique<int>(5);

	auto b = std::move(a);
	std::cout << *b << std::endl;
	
	//// crash
	//auto c = std::move(a); 
	//std::cout << *c << std::endl; 

	shared_ptr<A> a1 = make_shared<A>();
	shared_ptr<B> b1 = make_shared<B>();
	a1->ptr = b1;
	b1->ptr = a1;
	cout << a1.use_count() << endl;
	cout << b1.use_count() << endl;

	return 0;
}