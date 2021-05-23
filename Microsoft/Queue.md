# Queue
- A queue implements FIFO (first-in first-out) ordering
- Items are removed from the data structure in the same order that they are added.
- It uses the operations:
  - add(item): Add an item to the end of the list.
  - remove(): Remove the first item in the list.
  - peek(): Return the top of the queue.
  - isEmpty(): Return true if and only ifthe queue is empty.

## Queue using arrays
- Time Complexity of Enqueue : O(1) 
- Time Complexity of Dequeue : O(n)


```cpp
#include <bits/stdc++.h>
using namespace std;

struct Queue {
	int front, tail, capacity;
	int* queue;

	Queue(int c)
	{
		front = tail = 0;
		capacity = c;
		queue = new int;
	}

	~Queue() { delete[] queue; }

	void queueEnqueue(int data)
	{
		if (capacity == tail) {
			printf("\nQueue is full\n");
			return;
		}

		else {
			queue[tail] = data;
			tail++;
		}
		return;
	}

	void queueDequeue()
	{
		// if queue is empty
		if (front == tail) {
			printf("\nQueue is empty\n");
			return;
		}
		else {
			for (int i = 0; i < tail - 1; i++) {
				queue[i] = queue[i + 1];
			}

			tail--;
		}
		return;
	}

	void queueDisplay()
	{
		int i;
		if (front == tail) {
			printf("\nQueue is Empty\n");
			return;
		}

		for (i = front; i < tail; i++) {
			printf(" %d <-- ", queue[i]);
		}
		return;
	}

	void queueFront()
	{
		if (front == tail) {
			printf("\nQueue is Empty\n");
			return;
		}
		printf("\nFront Element is: %d", queue[front]);
		return;
	}
};

int main(void)
{
	Queue q(4);

	q.queueDisplay();

	q.queueEnqueue(20);
	q.queueEnqueue(30);
	q.queueEnqueue(40);
	q.queueEnqueue(50);

	q.queueDisplay();

	q.queueEnqueue(60);

	q.queueDisplay();

	q.queueDequeue();
	q.queueDequeue();

	printf("\n\nafter two node deletion\n\n");

	q.queueDisplay();

	q.queueFront();

	return 0;
}
```

## Queue using linked-list
- Time complexity of both operations enqueue() and dequeue() is O(1) as we only change few pointers in both operations

```cpp
#include <bits/stdc++.h>
using namespace std;

struct QNode {
	int data;
	QNode* next;
	
  QNode(int d)
	{
		data = d;
		next = NULL;
	}
};

struct Queue {
	QNode *front, *tail;

	Queue()
	{
		front = tail = NULL;
	}

	void enQueue(int x)
	{

		QNode* temp = new QNode(x);

		if (tail == NULL) {
			front = tail = temp;
			return;
		}

		tail->next = temp;
		tail = temp;
	}


	void deQueue()
	{
		if (front == NULL)
			return;

		QNode* temp = front;
		front = front->next;

		if (front == NULL)
			tail = NULL;

		delete (temp);
	}
};

int main()
{
	Queue q;
	q.enQueue(10);
	q.enQueue(20);
	q.deQueue();
	q.deQueue();
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	q.deQueue();
	cout << "Queue Front : " << (q.front)->data << endl;
	cout << "Queue tail : " << (q.tail)->data;
}
```
