#include<iostream>
// Dynamic Lists bitches

template<typename T>
class Vector
{
public:
	Vector()
	{
		// allocate 2 elements
		ReAlloc(2);
	}

	~Vector()
	{
		delete[] m_Data;
	}

	void PushBack(const T& value)
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);
		m_Data[m_Size++] = std::move(value);
	}

	void PushBack(T&& value)
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);
		m_Data[m_Size++] = std::move(value);
	}

	template<typename... Args>
	T& EmplaceBack(Args&&... args)
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);
		new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
		return m_Data[m_Size++];
	}

	void PopBack()
	{
		if (m_Size > 0)
		{
			m_Size--;
			m_Data[m_Size].~T();
		}
	}

	void Clear()
	{
		for (size_t i = 0; i < m_Size; i++)
			m_Data[i].~T();
		m_Size = 0;
	}

	T& operator[](size_t index)
	{
		// check if index is out of bounds (assert during debug mode)
		return m_Data[index];
	}

	const T& operator[](size_t index) const
	{
		return m_Data[index];
	}

	size_t Size() const
	{
		return m_Size;
	}

private:
	void ReAlloc(size_t newCapacity)
	{
		// 1. allocate a new block of memory
		// 2. copy (move) old elements into new block
		// 3. delete

		T* newBlock = new T[newCapacity];

		size_t size = m_Size;

		if (newCapacity < size) // checking if the user chooses to shrink the vector for some dumbass reason
			size = newCapacity;

		for (size_t i = 0; i < size; i++)
			newBlock[i] = std::move(m_Data[i]);

		delete[] m_Data;
		m_Data = newBlock;
		m_Capacity = newCapacity;

	}

private:
	T* m_Data = nullptr;

	size_t m_Size = 0;
	size_t m_Capacity = 0;
};

struct Vector3
{
	float x = 0.0f, y = 0.0f, z = 0.0f;
	int* m_MemoryBlock;

	Vector3()
	{
		m_MemoryBlock = new int[5];
	}

	Vector3(float scalar) : x(scalar), y(scalar), z(scalar)
	{
		m_MemoryBlock = new int[5];
	}

	Vector3(float x, float y, float z) :x(x), y(y), z(z)
	{
		m_MemoryBlock = new int[5];
	}

	Vector3(const Vector3& other) = delete;

	Vector3(Vector3&& other) :x(other.x), y(other.y), z(other.z)
	{
		m_MemoryBlock = other.m_MemoryBlock;
		other.m_MemoryBlock = nullptr;
		std::cout << "Move" << std::endl;
	}

	~Vector3()
	{
		std::cout << "Destory" << std::endl;
	}

	Vector3& operator=(const Vector3& other) = delete;


	Vector3& operator=(Vector3&& other)
	{
		m_MemoryBlock = other.m_MemoryBlock;
		other.m_MemoryBlock = nullptr;
		std::cout << "Move" << std::endl;
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
};

template<typename T>
void PrintVector(const Vector<T>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
		std::cout << vector[i] << std::endl;
	std::cout << "\n" << std::endl;
}

template<>
void PrintVector(const Vector<Vector3>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
		std::cout << vector[i].x << " " << vector[i].y << " " << vector[i].z << " " << std::endl;
	std::cout << "\n" << std::endl;
}

int main()
{
	Vector<Vector3> vector;
	vector.EmplaceBack(1.0f);
	vector.EmplaceBack(2, 3, 4);
	vector.EmplaceBack();
	PrintVector(vector);
}