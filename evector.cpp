#ifndef EVECTOR_CPP
#define EVECTOR_CPP

#include "evector.h"
namespace e
{
	template<class T>
	EVector<T>::EVector() {
		_cap = 0;
		_size = 0;
		buffer = 0;
		Log = 0;
	}

	template<class T>
	EVector<T>::EVector(const EVector<T> & v) {
		_size = v._size;
		Log = v.Log;
		_cap = v._cap;
		buffer = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			buffer[i] = v.buffer[i];
	}

	template<class T>
	EVector<T>::EVector(unsigned int size) {
		_size = size;
		Log = ceil(log((double)size) / log(2.0));
		_cap = 1 << Log;
		buffer = new T[_cap];
	}

	template <class T>
	bool EVector<T>::empty() const {
		return _size == 0;
	}

	template<class T>
	EVector<T>::EVector(unsigned int size, const T& initial) {
		_size = size;
		Log = ceil(log((double)size) / log(2.0));
		_cap = 1 << Log;
		buffer = new T[_cap];
		for (unsigned int i = 0; i < size; i++)
			buffer[i] = initial;
	}

	template<class T>
	EVector<T>& EVector<T>::operator = (const EVector<T> & v) {
		delete[] buffer;
		_size = v._size;
		Log = v.Log;
		_cap = v._cap;
		buffer = new T[_cap];
		for (unsigned int i = 0; i < _size; i++)
			buffer[i] = v.buffer[i];
		return *this;
	}

	template<class T>
	typename EVector<T>::Iterator EVector<T>::begin() {
		return buffer;
	}

	template<class T>
	typename EVector<T>::Iterator EVector<T>::end() {
		return buffer + size();
	}

	template<class T>
	T& EVector<T>::front() {
		return buffer[0];
	}

	template<class T>
	T& EVector<T>::back() {
		return buffer[_size - 1];
	}

	template<class T>
	void EVector<T>::push_back(const T & v) {
		if (_size >= _cap) {
			reserve(1 << Log);
			Log++;
		}
		buffer[_size++] = v;
	}

	template<class T>
	void EVector<T>::pop_back() {
		_size--;
	}

	template<class T>
	void EVector<T>::reserve(unsigned int capacity) {
		T * newBuffer = new T[capacity];

		for (unsigned int i = 0; i < _size; i++)
			newBuffer[i] = buffer[i];

		_cap = capacity;
		delete[] buffer;
		buffer = newBuffer;
	}

	template<class T>
	unsigned int EVector<T>::size() const {
		return _size;
	}

	template<class T>
	void EVector<T>::resize(unsigned int size) {
		Log = ceil(log((double)size) / log(2.0));
		reserve(1 << Log);
		_size = size;
	}

	template<class T>
	T& EVector<T>::operator[](unsigned int index) {
		return buffer[index];
	}

	template<class T>
	unsigned int EVector<T>::capacity()const {
		return _cap;
	}

	template<class T>
	EVector<T>::~EVector() {
		delete[] buffer;
	}

	template <class T>
	void EVector<T>::clear() {
		_cap = 0;
		_size = 0;
		buffer = 0;
		Log = 0;
	}
}
#endif