#include <stdio.h>
#include "OrdersQueue.h"
#include <iostream>
using  namespace std;

void OrdersQueue::PlaceOrder(int order) {
	if (!IsFull()) {
		if (rear == -1)
		{
			rear = front = 0;
			list[rear] = order;
		}
		else
		{
			rear = rear + 1;
			list[rear] = order;
		}
	}
	else {
		cout << "All Order Tray is Full";
	}
}

void OrdersQueue::ProcessOrder()
{
	int x;
	if (! IsEmpty())
	{
		x = list[front];
		if (front == rear)
		{
			rear = front = -1;
		}
		else
		{
			front = front + 1;
		}
		cout << "\n Order is processed and dispatched";
	}
	else
	{
		cout << "\nqueue is empty";
	}
}
 
bool OrdersQueue::IsEmpty() {
	bool status = false;
	if (rear == -1)
	{
		status = true;
	}
	return status;
}

bool OrdersQueue::IsFull() {
	bool status = false;
	if (rear == 5 - 1)
	{
		status = true;
	}
	return status;
}