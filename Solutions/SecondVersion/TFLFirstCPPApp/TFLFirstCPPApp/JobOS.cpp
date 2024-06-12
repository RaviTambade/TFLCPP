/*
Title:Job Creation using Queue In operating system.

	If the operating system does not use priorities,
	then the jobs are processed in the order they enter the system.
	Write C++ program for simulating job queue.
	Write functions to add job and delete job from queue.
*/

#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;

class jobos
{
public:
	string name[2];
	int front, rear = -1;
	void add_job();
	void delete_job();
	void read();
	int empty();
	int full();

};

void jobos::add_job()
{
	string x;
	if (full() == 0)
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
void jobos::delete_job()
{
	string x;
	if (empty() == 0)
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
void jobos::read()
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
			cout << "\n " <<name[i];
		}
	}

}
int jobos::empty()
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

int jobos::full()
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
	jobos os;
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