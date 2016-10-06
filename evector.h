#ifndef EVECTOR_H
#define EVECTOR_H
namespace e
{
template <class T>
class  EVector {
public:

	typedef T* Iterator;

	EVector();
	EVector(unsigned int size);
	EVector(unsigned int size, const T & initial);
	EVector(const EVector<T>& v);
	~EVector();

	unsigned int capacity() const;
	unsigned int size() const;
	bool empty() const;
	Iterator begin();
	Iterator end();
	T& front();
	T& back();
	void push_back(const T& value);
	void pop_back();

	void reserve(unsigned int capacity);
	void resize(unsigned int size);

	T & operator[](unsigned int index);
	EVector<T> & operator = (const EVector<T> &);
	void clear();
private:
	unsigned int _size;
	unsigned int _cap;
	unsigned int Log;
	T* buffer;
};
}

#include "evector.cpp"
#endif