#include<iostream>

#define log(x) std::cout << x << std::endl;
#define input(x) std::cin >> x; 


// Array based stack
template<typename T, size_t MAX_SIZE>
class Stack
{
private:
	T m_Data[MAX_SIZE];
	size_t top = -1;

public:

	bool IsEmpty()
	{
		return top == -1;
	}

	bool IsFull()
	{
		return top == MAX_SIZE;
	}

	void Push(T x)
	{
		if (IsFull())
		{
			log("Error: Stack Overflow");
			return;
		}
		top++;
		m_Data[top] = x;

		// you could also use pre increment via A[++top] = x;
	}

	void Pop()
	{
		if (IsEmpty())
		{
			log("Error: No element to pop");
			return;
		}
		top--;
	}

	T Peek()
	{
		return m_Data[top];
	}

	void Print()
	{
		log("Stack: ");
		for (int i = 0; i <= top; i++)
			log(m_Data[i]);
		log("\n");
	}
	
	size_t currentSize()
	{
		return top;
	}
};


/* Linked List based stack

int main()
{
	Stack<int, 101> stack;
	stack.Push(2); stack.Print();
	stack.Push(5); stack.Print();
	stack.Push(10); stack.Print();
	stack.Pop(); stack.Print();
	stack.Push(12); stack.Print();
}

// linked list implementation
struct Node
{
	int data;
	Node* link;
};

Node* topNode = NULL;

void Push(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->link = topNode;
	topNode = temp;
}

void Pop()
{
	Node* temp;
	if (!top)return;
	temp = topNode;
	topNode = topNode->link;
	delete temp;
}
 // extra things you can do with stacks (reversing, checking balanced parenthesis for compilers, evaluating any mathematical operation)
void ReverseStringUsingStack(char* str, unsigned int length)
{
	Stack<char, 101> stack;
	for (int i = 0; i < length; i++)
		stack.Push(str[i]);

	for (int i = 0; i < length; i++)
	{
		str[i] = stack.Peek();
		stack.Pop();
	}
}

bool checkBalancedParenthesis(const char* code, unsigned int length)
{
	char openingSymbols[] = { '(', '{', '[' };
	char closingSymbols[] = { ')', '}', ']' };
	Stack<char, 1024> stack;

	for (int i = 0; i < length; i++)
	{
		if (code[i] == '(' || code[i] == '{' || code[i] == '[')
			stack.Push(code[i]);
		else if (code[i] == ')' || code[i] == '}' || code[i] == ']')
		{
			if (stack.IsEmpty() ||
				(stack.Peek() == '(' && code[i] != ')') ||
				(stack.Peek() == '{' && code[i] != '}') ||
				(stack.Peek() == '[' && code[i] != ']'))
				return false;
			else stack.Pop();
		}
	}
	return stack.IsEmpty();
}

/* Evaluation of mathematical operations using a stack
* procedure EvaluatePostfix(exp)
*	stack = new Stack
*	for i = 0 to len(exp)-1
*		if exp[i] is operand then
*			stack.push(exp[i])
*		else if exp[i] is operator then
*			op1 = stack.pop()
*			op2 = stack.pop()
*			res = perform(exp[i], op1, op2)
*			push(res)
*		endif
*	next i
* endprocedure
*
* function InfixToPostfix(exp)
*	stack = new Stack
*	res = ""
*	for i = 0 to len(exp)-1
*		if exp[i] is operand then
*			res = res + exp[i]
*		else if exp[i] is operator then
*			while !stack.isEmpty() && !isOpeningParenthesis(stack.top()) && hasHigherPrec(stack.top(), exp[i])
*				res = res + stack.top()
*				stack.pop()
*			endwhile
*			stack.push(exp[i])
*		else if isOpeningParenthesis(exp[i])
*			stack.push(exp[i])
*		else if isClosingParenthesis(exp[i])
*			while !stack.isEmpty() && !isOpeningParenthesis(stack.top())
*				res = res + stack.top()
*				stack.pop()
*			endwhile
*			stack.pop()
*		endif
*	next i
*	while !stack.isEmpty()
*		res = res + stack.top()
*		stack.pop()
*	endwhile
*	return res
* endfunction


int main()
{
	char string[] = "You are a dumb fuck";
	log(string);
	ReverseStringUsingStack(string, strlen(string));
	log(string);

	const char* code = "void ReverseStringUsingStack(char* str, unsigned int length) {	Stack<char, 101> stack;for (int i = 0; i < length; i++)stack.Push(str[i]);for (int i = 0; i < length; i++){str[i] = stack.Peek();stack.Pop();}}";
	log(checkBalancedParenthesis(code, strlen(code)));
}*/
