#include <iostream>

using namespace std;

struct Test{
	typedef int Value;

	Value a;
};

template<class T>
bool hasValue(typename T::Value) {
	return true;
}

template<class T>
bool hasValue(T) {
	return false;
}

int main() {
	Test test;
	test.a = 1;

	cout<<hasValue<Test>(0)<<endl;
	cout<<hasValue<int>(0)<<endl;
}
