#ifndef EMAP_H
#define EMAP_H

#include "eptr.h"
#include "estring.h"
#include "ehash.h"
#include <utility>

namespace e
{
	template <typename K, typename V>
	class EMap
	{
	public:
		EMap(int x) :_size(x){ table = e::EPtr<e::EVector<e::EVector<std::pair<K, V>>>>(new e::EVector<e::EVector<std::pair<K, V>>>(x)); }
		~EMap(){ table = nullptr; }

		void addEntry(K key, V val)
		{
			unsigned idx = _hash(key) % _size;
			this->table->at(idx).push_back(std::make_pair(key, val));
		}

		void reserve(int x)
		{
			_size = x;
			table = nullptr;
			table = e::EPtr<e::EVector<Node<std::pair<K, V>>>>(x);
		}

		V& lookup(K key)
		{
			unsigned idx = _hash(key) % _size;
			for (int i = 0; i < this->table->at(idx).size(); i++)
			{
				if (this->table->at(idx).at(i).first == key)
				{
					return this->table->at(idx).at(i).second;
				}
			}

		}

		V& operator[](K idx){return lookup(idx);}

	private:
		int _size;
		e::EPtr<e::EVector<e::EVector<std::pair<K, V>>>> table;
		e::EHash_adler_32<K> _hash;


	};
}
#endif