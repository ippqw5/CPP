#include <iostream>
#include <string>
class Base {
public:
    virtual void show() {
        std::cout << "Base show" << std::endl;
    }

    void display() {
		this->show();  // this调用的是实际对象的show()方法，可能是Base类的，也可能是Derived类的
    }

	Base* setName(const std::string& name) { // 返回this，可以链式调用
		m_name = name;
		return this;
	}
protected:
    std::string m_name;
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived show" << std::endl;
		std::cout << "Name: " << m_name << std::endl;
    }
};

int main() {
    Derived d;
    Base* b = &d;
    b->setName("Hello")->display();  // 尽管指针是Base类的，但调用的是Derived的show()方法
    return 0;
}
