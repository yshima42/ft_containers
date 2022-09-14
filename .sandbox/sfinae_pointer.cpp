#include <iostream>

using namespace std;

template<class T>
typename remove_reference<T>::type&& move(T&& t)
{
	typedef typename remove_reference<T>::type U;
	return static_cast<U&&>(t);
}
