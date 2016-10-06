#ifndef EPTR_CPP
#define EPTR_CPP
#include "eptr.h"
namespace e
{
	template <class T>
	EPtr<T>& EPtr<T>::operator=(const EPtr<T>& other){
		if (this != &other){
			_clear();

			_ptr = other._ptr;
			_refs = other._refs;
			++*_refs;
		}
		return *this;
	}

	template <class T>
	EPtr<T>& EPtr<T>::operator=(T* p){
		if (_ptr != p){
			_ptr = p;
			*_refs = 1;
		}
		return *this;
	}

	template <class T>
	T& EPtr<T>::operator*(){
		return *_ptr;
	}

	template <class T>
	const T& EPtr<T>::operator*() const{
		return *_ptr;
	}

	template <class T>
	T* EPtr<T>::operator->(){
		return _ptr;
	}

	template <class T>
	const T* EPtr<T>::operator->() const{
		return _ptr;
	}

	template <class T>
	std::size_t EPtr<T>::instances(){
		return *_refs;
	}

	template <class T>
	void EPtr<T>::_clear(){
		if (!--*_refs){
			delete _ptr;
			delete _refs;
		}
	}

}
#endif
