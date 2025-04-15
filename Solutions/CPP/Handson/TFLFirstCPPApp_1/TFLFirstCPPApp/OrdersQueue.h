#pragma once
//Orders Processing using Queue
class OrdersQueue
{
	private:
		int list[2];
		int front, rear = -1;

	public:
		void PlaceOrder(int orderId);
		void ProcessOrder();
		bool IsEmpty();
		bool IsFull();
};