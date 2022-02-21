#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define log(x) std::cout << x << std::endl;
#define input(x) std::cin >> x;

template<typename T>
class LinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

	Node* head = NULL;

	// this section contains any functions that are iterative instead of recursive
	void printIteratively()
	{
		Node* temp = head;
		log("List is: ");
		while (temp)
		{
			log(temp->data);
			temp = temp->next;
		}
	}

	void reverseItaritively()
	{
		Node* current = head, * prev = NULL, * next;

		while (current)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

	// store recursive functions privately with public accessors
	void printRecursively(Node* p, bool reverse = false)
	{
		if (!p) return;
		if (reverse)
		{
			printRecursively(p->next);
			log(p->data);
		}
		else
		{
			log(p->data);
			printRecursively(p->next);
		}
	}

	void reverseRecursively(Node* p)
	{
		if (!p->next)
		{
			head = p;
			return;
		}
		reverseRecursively(p->next);
		Node* q = p->next;
		q->next = p;
		p->next = NULL;
	}

	Node* createNode(T value)
	{
		Node* temp1 = new Node();
		temp1->data = value;
		temp1->next = NULL;
	}

public:

	~LinkedList()
	{
		for (int i = 0; i < size(); i++)
			deleteNode();
		log("Nodes are deleted");

	}

	void insert(T value, int index = 0)
	{
		Node* temp1 = createNode(value);
		if (index > 0)
		{
			Node* temp2 = head;
			for (int i = 0; i < index - 1; i++)
				temp2 = temp2->next;
			temp1->next = temp2->next;
			temp2->next = temp1;
		}
		else
		{
			temp1->next = head;
			head = temp1;
		}
	}

	void printList(bool reverse = false)
	{
		printRecursively(head, reverse);
	}

	void reverse()
	{
		reverseRecursively(head);
	}

	void deleteNode(int index = 0)
	{
		Node* temp1 = head;
		if (index == 0)
		{
			head = temp1->next;
			delete temp1;
		}
		else
		{
			for (int i = 0; i < index - 1; i++)
				temp1 = temp1->next;
			Node* temp2 = temp1->next;
			temp1->next = temp2->next;
			delete temp2;
		}
	}

	size_t size()
	{
		size_t count = 0;
		Node* temp = head;
		while (temp)
		{
			temp = temp->next;
			count++;
		}
		return count;
	}
};

/* Incomplete: needs print functions, and deletion before usable
template<typename T>
class DoublyLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};

	Node* head;

	Node* createNode(T value)
	{
		Node* temp = new Node;
		temp->data = x;
		temp->prev = NULL;
		temp->next = NULL;
		return temp;
	}

public:
	void insertAtHead(T value)
	{
		Node* newNode = createNode(x);
		if (!head)
		{
			head = newNode;
			return;
		}
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	/*
	void insert(T value, int index = 0)
	{
		Node* temp1 = createNode(value);
		if (index > 0)
		{
			Node* temp2 = head;
			for (int i = 0; i < index - 1; i++)
				temp2 = temp2->next;
			temp1->next = temp2->next;
			temp2->next = temp1;
		}
		else
		{
			temp1->next = head;
			head = temp1;
		}
	}

	void insertAtTail(T value)
	{
		for (int i = 0; i < size() - 1; i++)
		Node* temp1 = createNode(value), temp2 = head;
			temp2 = temp2->next;
		temp1->next = temp2->next;
		temp2->next = temp1;
	}

	size_t size()
	{
		size_t count = 0;
		Node* temp = head;
		while (temp)
		{
			temp = temp->next;
			count++;
		}
		return count;
	}
};
#endif

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* head;

Node* GetNewNode(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

void InsertAtHead(int x)
{
	Node* newNode = GetNewNode(x);
	if (!head)
	{
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

void PrintIeratively()
{
	//same code as linked list
	Node* temp = head;
	log("List is: ");
	while (temp)
	{
		log(temp->data);
		temp = temp->next;
	}
	log("\n");
}

void ReversePrint()
{
	Node* temp = head;
	if (!temp) return;
	while (temp->next)
		temp = temp->next;
	// literally normal print but temp->prev instead of temp->next
	log("Reverse");
	while (temp)
	{
		log(temp->data);
		temp = temp->prev;
	}
	log("\n");
}
*/
#endif