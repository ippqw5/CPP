#include <iostream>
#include <string>
class String {
public:
	String() = default;

	String(const char* name) {
		m_Size = strlen(name) + 1;
		m_Data = new char[m_Size];
		memcpy(m_Data, name, m_Size);
		printf("Create: %s\n", m_Data);
	}

	String(const String& other) {
		printf("Copy\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	String(String&& other)  noexcept {
		printf("MoveCopy\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	String& operator= (String&& other)  noexcept {
		printf("MoveAssign\n");
		delete[] m_Data;

		m_Size = other.m_Size;
		m_Data = other.m_Data;
		
		other.m_Size = 0;
		other.m_Data = nullptr;

		return *this;
	}

	~String()
	{
		printf("Destroy: %s\n", m_Data);
		delete[] m_Data;
	}

	void Print() {
		for (int i = 0; i < m_Size; i++)
		{
			printf("%c", m_Data[i]);
		}
		printf("\n");
	}

private:
	char* m_Data;
	unsigned int m_Size;
};


String CreateString() {
	return String("test");
}

int main() {
	String test;
	test = CreateString(); // Return value optimization

	//String&& s0("s0"); // String&& is lvalue

	//String s1(s0); // Copy Constructor
	//String s2 = s0; // Copy Constructor

	//String s3 = std::move(s0); // Move Constructor
	//String s4(s0); // wrong! because s0 is moved

	return 0;
}