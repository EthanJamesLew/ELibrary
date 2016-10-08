#ifndef EHASH_H
#define EHASH_H
#include "estring.h"
#include <iostream>
#include <cstdint>

namespace e
{
	template <class T>
	class EHash
	{
	public:
		EHash(): _seed(1) {};
		EHash(int x) : _seed(x){}
		~EHash(){};
		unsigned int operator()(T y) { e::EString arg = _conv(y); return _hash(arg); }

		void setSeed(unsigned seed){ _seed = seed; }
	protected:
		unsigned int _seed;
	private:
		 virtual unsigned int _hash(e::EString arg)
		{
			return 0;
		}

		e::EString _conv(char* arg)
		{
			return e::EString(arg);
		}
		e::EString _conv(int arg)
		{
			char* a=new char(30);
			return e::EString(itoa(arg, a,10));
		}
		e::EString _conv(float arg)
		{
			char* a=new char(30);
			return e::EString(itoa(int(arg * 77), a,10));
		}
		e::EString _conv(e::EString arg)
		{
			return arg;
		}

	};

	template <class T>
	class EHash_adler_32 : public EHash<T>
	{
	private:
		virtual unsigned int _hash(e::EString arg)
		{
			uint32_t s1 = 1;
			uint32_t s2 = 0;

			for (int i = 0; i < arg.size(); i++)
			{
				s1 = (_seed*s1 + arg[i]) % 65521;
				s2 = (s2 + s1) % 65521;
			}

			return (s2 << 16) | s1;
		}
	};

	template <class T>
	class EHash_sdbm : public EHash<T>
	{
	private:
		virtual unsigned int _hash(e::EString arg)
		{
			hashAddress = 0;
			for (int i =0; i<arg.size(); i++){
				hashAddress = arg[i] + _seed + (hashAddress << 6) + (hashAddress << 16) - hashAddress;
			}
			return hashAddress;
		}
	};

	template <class T>
	class EHash_djb2 : public EHash<T>
	{
	private:
		virtual unsigned int _hash(e::EString arg)
		{
			hashAddress = 5381;
			for (int i = 0; i<arg.size(); i++)
			{
				hashAddress = ((hashAddress << 5) + hashAddress) + arg[i];
			}
			return hashAddress;
		}
	};

	template <class T>
	class EHash_larson : public EHash<T>
	{
	private:
		virtual unsigned int _hash(e::EString arg)
		{
			unsigned h = _seed;
			for (int i = 0; i<arg.size(); i++)
				h = h * 101 + (unsigned)*arg[i];
			return h;
		}
	};


	template <class T>
	class EHash_fnv1a : public EHash<T>
	{
	private:
		virtual unsigned int _hash(e::EString arg)
		{
			unsigned h = 0x811c9dc5;

			for (int i = 0; i<arg.size(); i++)
				h = (h ^ arg[i]) * 0x01000193;

			return h;
		}
	};

}
#endif
