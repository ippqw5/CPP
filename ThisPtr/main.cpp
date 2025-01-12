#include <iostream>
#include <string>
class Base {
public:
    virtual void show() {
        std::cout << "Base show" << std::endl;
    }

    void display() {
		this->show();  // this���õ���ʵ�ʶ����show()������������Base��ģ�Ҳ������Derived���
    }

	Base* setName(const std::string& name) { // ����this��������ʽ����
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
    b->setName("Hello")->display();  // ����ָ����Base��ģ������õ���Derived��show()����
    return 0;
}
