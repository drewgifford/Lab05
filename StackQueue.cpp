#include <iostream>
#include <string>
#include <array>
using namespace std;

#include "StackQueue.h"

template <class ItemType> ArrayBasedStack<ItemType>::ArrayBasedStack()
{
	int size = 1000; // Configurable size

	m_size = size;
	m_values = new int[size];
	m_count = 0;
}

template <class ItemType> int ArrayBasedStack<ItemType>::peek() const
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		return m_values[m_count - 1];
	}
}

template <class ItemType> bool ArrayBasedStack<ItemType>::isEmpty() const
{
	return (m_count == 0);
}

template <class ItemType> bool ArrayBasedStack<ItemType>::push(const ItemType &val)
{

	if (m_count >= m_size)
	{
		return false;
	}

	m_values[m_count] = val;
	m_count += 1;
	return true;
}

template <class ItemType> bool ArrayBasedStack<ItemType>::pop()
{

	if (m_count == 0)
	{
		return false;
	}

	m_values[m_count] = 0;
	m_count -= 1;
	return true;
}

template <class ItemType> std::string ArrayBasedStack<ItemType>::toString() const
{
	std::string str = "";

	for (int i = 0; i < m_count; i++)
	{
		str += std::to_string(m_values[i]);

		if (i != m_count - 1)
		{
			str += " ";
		}
	}
	return str;
}

template <class ItemType> int * ArrayBasedStack<ItemType>::getArray() const{
	return m_values;
}

template <class ItemType> int ArrayBasedStack<ItemType>::getCount() const {
	return m_count;
}


template <class ItemType> ArrayBasedStack<ItemType>::~ArrayBasedStack()
{
	m_values = NULL;
	delete m_values;
}




// QUEUE

template <class ItemType> ArrayBasedQueue<ItemType>::ArrayBasedQueue()
{
	int size = 1000;

	m_size = size;
	m_values = new std::string[size];
	m_count = 0;
}

template <class ItemType> std::string ArrayBasedQueue<ItemType>::peekFront() const
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		return m_values[0];
	}
}

template <class ItemType> bool ArrayBasedQueue<ItemType>::isEmpty() const
{
	return (m_count == 0);
}

template <class ItemType> bool ArrayBasedQueue<ItemType>::deQueue()
{

	if (m_count == 0){
		return false;
	}

	for (int i = 0; i < m_count - 1; i++)
	{
		m_values[i] = m_values[i+1];
	}
	for (int i = m_count; i < m_size; i++){
		m_values[i] = "";
	}

	m_count--;
	return true;
}

template <class ItemType> bool ArrayBasedQueue<ItemType>::enQueue(const ItemType &val)
{

	if (m_count == m_size)
	{
		return false;
	}

	m_values[m_count++] = val;
	return true;
}

template <class ItemType> std::string ArrayBasedQueue<ItemType>::toString() const
{
	std::string str = "";

	for (int i = 0; i < m_count; i++)
	{
		str += m_values[i];

		if (i != m_count - 1)
		{
			str += " ";
		}
	}
	return str;
}

template <class ItemType> ArrayBasedQueue<ItemType>::~ArrayBasedQueue()
{
	m_values = NULL;
	delete m_values;
}

template <class ItemType> std::string * ArrayBasedQueue<ItemType>::getArray() const{
	return m_values;
}

template <class ItemType> int ArrayBasedQueue<ItemType>::getCount() const {
	return m_count;
}
