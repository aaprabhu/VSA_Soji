#ifndef HASHSET_IS_INCLUDED
#define HASHSET_IS_INCLUDED
/* { */

#include <vector>
#include <stdio.h>


////////////////////////////////////////////////////////////

template <class KeyType, class ValueType>
class HashSet
{

private:

	enum 
	{
		MINIMUM_TABLE_SIZE=7
	};
	std::vector <std::vector <ValueType> > table;
	long long int nElem;

public:

	HashSet();
	~HashSet();
	void CleanUp(void);

	void Add(const KeyType &key, const ValueType &value);
	int GetSize(void);
	void Resize(long long int tableSize);
	void Delete(const KeyType &key);
	int GetRowSize(const KeyType &key);
	ValueType GetElem(const KeyType &key, const int &pos);

};

template <class KeyType, class ValueType>
HashSet<KeyType,ValueType>::HashSet()
{
	table.resize(MINIMUM_TABLE_SIZE);
	nElem=0;
}
template <class KeyType, class ValueType>
HashSet<KeyType,ValueType>::~HashSet()
{
}
template <class KeyType, class ValueType>
void HashSet<KeyType,ValueType>::CleanUp(void)
{
	table.resize(MINIMUM_HASH_SIZE);
	for(auto &t : table)
	{
		t.clear();
	}
	nElem=0;
}
template <class KeyType, class ValueType>
void HashSet<KeyType,ValueType>::Add(const KeyType &key,const ValueType &value)
{
	for(int i=0;i< table.size();i++)
	{
		if(i==key)
		{
			table[key].push_back(value);
			nElem++;
			return;
		}
	}
	Resize(table.size()+1);
	table[key].push_back(value);
	nElem++;
}
template <class KeyType, class ValueType>
int HashSet<KeyType,ValueType>::GetSize(void)
{
	return table.size();
}
template <class KeyType, class ValueType>
int HashSet<KeyType,ValueType>::GetRowSize(const KeyType &key)
{
	return table[key].size();
}

template <class KeyType, class ValueType>
ValueType HashSet<KeyType,ValueType>::GetElem(const KeyType &key, const int &pos)
{
	return table[key][pos];
}

template <class KeyType, class ValueType>
void HashSet<KeyType,ValueType>::Resize(long long int tableSize)
{
	std::vector <ValueType> buffer;
	for(auto &t : table)
	{
		for(auto e : t)
		{
			buffer.push_back(e);
		}
		t.clear();
	}
	table.resize(tableSize);
	for(auto b : buffer)
	{
		Add(b);
	}
}
template <class KeyType, class ValueType>
void HashSet<KeyType,ValueType>::Delete(const KeyType &key)
{
	auto hashCode=HashCode(key);
	auto idx=hashCode%table.size();
	for(auto &e : table[idx])
	{
		if(e.hashCode==hashCode && e.hashKey==key)
		{
			e=table[idx].back();
			table[idx].pop_back();
			break;
		}
	}
}

/* } */
#endif
