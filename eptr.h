#ifndef EPTR_H
#define EPTR_H
#include <iostream>
namespace e
{
	template <class T>
	class EPtr
	{
	public:
		explicit EPtr(T *p = nullptr) : _ptr(p), _refs(new std::size_t(1))
		{
			_ptr = p;
		}

		explicit EPtr(const EPtr<T>& other)
			: _ptr(other._ptr), _refs(other._refs)
		{
			++*_refs;
		} 

		~EPtr() { _clear(); }
		EPtr<T>& operator=(const EPtr<T>& other);
		EPtr<T>& operator=(T* p);
		T& operator*();
		const T& operator*() const;
		T* operator->();
		const T* operator->() const;
		std::size_t instances();

	private:
		T *_ptr;
		std::size_t *_refs;
		void _clear();
	};
}
#include "eptr.cpp"
#endif