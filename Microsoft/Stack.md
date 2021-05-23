# Stack
- A stack uses LIFO (last-in first-out) ordering
- A stack does not offer constant-time access to the ith item
- Constant-time adds and removes from stack, as it doesn't require shifting elements around
- It uses the following operations:
  - **pop():** Remove the top item from the stack.
  - **push(item):** Add an item to the top of the stack.
  - **peek():** Return the top of the stack.
  - **isEmpty():** Return true if and only if the stack is empty.



## Stack using Linked list
- The time complexity for all push(), pop(), and peek() operations is O(1)


```cpp
// Stack using linked-list
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* link;
};

struct Node* top;

void push(int data) {
  struct Node* temp;
  temp = new Node();

  if (!temp) {
    cout << "\nHeap Overflow";
    exit(1);
  }

  temp->data = data;
  temp->link = top;
  top = temp;
}

int isEmpty() { return top == NULL; }

int peek() {
  if (!isEmpty())
    return top->data;
  else
    exit(1);
}

void pop() {
  struct Node* temp;

  if (top == NULL) {
    cout << "\nStack Underflow" << endl;
    exit(1);
  } else {
    temp = top;
    top = top->link;
    temp->link = NULL;
    free(temp);
  }
}

void display() {
  struct Node* temp;
  if (top == NULL) {
    cout << "\nStack Underflow";
    exit(1);
  } else {
    temp = top;
    while (temp != NULL) {
      cout << temp->data << "-> ";
      temp = temp->link;
    }
  }
}

int main() {
  push(11);
  push(22);
  push(33);
  push(44);

  display();
  cout << "\nTop element is " << peek() << endl;

  pop();
  pop();
  display();

  cout << "\nTop element is " << peek() << endl;
  return 0;
}
```

## Stack using Arrays
- Pros: Easy to implement. Memory is saved as pointers are not involved. 
- Cons: It is not dynamic. It doesn’t grow and shrink depending on needs at runtime.

```cpp
// Stack using arrays
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack {
	int top;

public:
	int a[MAX]; // Maximum size of Stack

	Stack() { top = -1; }
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
};

bool Stack::push(int x)
{
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
		a[++top] = x;
		cout << x << " pushed into stack\n";
		return true;
	}
}

int Stack::pop()
{
	if (top < 0) {
		cout << "Stack Underflow";
		return 0;
	}
	else {
		int x = a[top--];
		return x;
	}
}
int Stack::peek()
{
	if (top < 0) {
		cout << "Stack is Empty";
		return 0;
	}
	else {
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty()
{
	return (top < 0);
}

// Driver program to test above functions
int main()
{
	class Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.pop() << " Popped from stack\n";
	//print all elements in stack :
	cout<<"Elements present in stack : ";
	while(!s.isEmpty())
	{
		// print top element in stack
		cout<<s.peek()<<" ";
		// remove top element in stack
		s.pop();
	}

	return 0;
}
```
