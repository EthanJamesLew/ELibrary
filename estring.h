#ifndef E_STRING_H
#define E_STRING_H
#include <ostream>
namespace e
{
	class EString
	{
	public:
		EString(char* cstr);
		EString();

		~EString();

		void cat(char* cat);
		void cat(EString cat);

		bool cmp(char* cstr);
		bool cmp(EString estr);

		char* cstr();

		EString slice(int a, int b);
		EString slice(int b);

		EString& operator+(EString& rhs);
		EString& operator+(char* rhs);

		bool operator==(EString rhs);
		bool operator==(char* rhs);

		char& operator[] (const int idx);

		int size(){ return _size; }

	private:
		char* _cstr;
		int _size;

		friend std::ostream& operator << (std::ostream &os, EString &v)
		{
			os << v.cstr();
			return os;
		}
	};
}

#endif