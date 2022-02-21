#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>

template<typename T, size_t S>
class Array
{

private:
	T m_Data[S];

public:

	/*
	Array()
	{
		nullData();
	}
	*/
	template<typename... Args>
	Array(Args... args)
	{
		//std::cout << sizeof(args) << std::endl;
		int count = 0;
		for (auto elem : { args... })
		{
			if (count >= Size())
			{
				std::cout << "ERROR::ARRAY::OVERFLOW_WARNING::TOO MANY VALUES COMPARED TO ARRAY SIZE (LEARN TO COUNT)" << std::endl;
				break;
			}
			m_Data[count++] = (T)elem;
		}
		//nullData();
	}

	~Array()
	{
		delete[] m_Data;
	}

	constexpr size_t Size() const
	{
		return S;
	}

	T& operator[](int index)
	{
		if (!(index < S) || (index < 0)) return m_Data[0];
		return m_Data[index];
	}

	const T& operator[](int index) const
	{
		if (!(index < S) || (index < 0)) return -1;
		return m_Data[index];
	}

	T* Data()
	{
		return m_Data;
	}

	const T* Data() const
	{
		return m_Data;
	}

	void nullData()
	{
		memset(Data(), 0, Size() * sizeof(T));
	}
};

#endif