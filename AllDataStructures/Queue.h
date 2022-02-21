template<typename T, size_t MAX_SIZE>
class Queue
{
private:
	T m_Data[S];
	int front = -1;
	int rear = -1;

public:
	bool IsEmpty()
	{
		return front == -1 && rear == -1;
	}

	bool IsFull()
	{
		return (rear + 1) % MAX_SIZE == front;
	}

	void Enqueue(T x)
	{
		if (IsFull())return;
		else if (IsEmpty())
		{
			front = 0;
			rear = 0;
			m_Data[rear] = x;
		}
		else
		{
			rear = (rear + 1) % MAX_SIZE;
			m_Data[rear] = x;
		}
	}

	void Dequeue()
	{
		if (IsEmpty())return;
		else if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else front = (front + 1) % MAX_SIZE;
	}
};

// Queue linked list implementation
/*
struct Node
{
	int data;
	Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void Enqueue(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if (!front && !rear)
	{
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void Dequeue()
{
	Node* temp = front;
	if (!front) return;
	if (front == rear)
		front = rear = NULL;
	else front = front->next;
	delete temp;
}
*/