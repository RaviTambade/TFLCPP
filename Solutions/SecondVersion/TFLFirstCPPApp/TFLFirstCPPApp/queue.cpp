
#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;

class item
{
public:
	int name[2];
	int front, rear = -1;
	void add_job();
	void delete_job();
	void read();
	int empty_queue();
	int full_queue();

};

void item::add_job()
{
	int x;
	if (full_queue() == 0)
	{
		cout << "\nenter element:";
		cout << "\n";

		cin >> x;

		if (rear == -1)
		{
			rear = front = 0;
			name[rear] = x;
		}
		else
		{
			rear = rear + 1;
			name[rear] = x;
		}
		printf("\ndata enter successfully");
	}
	else
	{
		printf("\nqueue is full");
	}
}
void item::delete_job()
{
	int x;
	if (empty_queue() == 0)
	{
		x = name[front];
		if (front == rear)
		{
			rear = front = -1;
		}
		else
		{
			front = front + 1;
		}
		cout << "\ndata delete successfully";
	}
	else
	{
		cout << "\nqueue is empty";
	}
}
void item::read()
{
	int i;
	if (front == -1)
	{
		cout << "queue is empty";
	}
	else
	{
		cout << "\n \nqueue data: ";
		for (i = front; i <= rear; i++)
		{
			cout << "\n " << name[i];
		}
	}
}

int item::empty_queue()
{
	if (rear == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int item::full_queue()
{
	if (rear == 5 - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



/*
int main()
{
	cout << "welcome to job in operating system data";
	int ch = 1;
	item os;
	do
	{
		cout << "\n\n\n choose option:";
		cout << "\n 1.insert new job";
		cout << "\n 2.delte old job";
		cout << "\n 3.display jab data";
		cout << "\n 4.exit";
		cout << "\n";
		cin >> ch;

		switch (ch)
		{
		case 1:
		{
			os.add_job();
		}
		break;
		case 2:
		{
			os.delete_job();
		}
		break;
		case 3:
		{
			os.read();
		}
		break;
		case 4:
		{
			cout << "thank you..";
		}
		break;
		}

	} while (ch != 4);
}

*/
