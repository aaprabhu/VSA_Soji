#ifndef PQUEUE_IS_INCLUDED
#define PQUEUE_IS_INCLUDED

template <class T> 
class PriorityQueue
{
private:
	T *elem;
	int queueSize;

public:	
	T top();
	PriorityQueue(){
		elem = nullptr;
		queueSize = 0;
	}
	void push_back(T add);
	void pop_back();
	bool isEmpty();
	void resize();
	void print();
};

template <class T> 
T PriorityQueue<T>::top()
{
	if (elem != nullptr && !isEmpty())
		return elem[0];
	else
	{
		printf("Queue Empty!\n");
	}
}
template <class T> 
void PriorityQueue<T>::push_back(T add)
{
		resize();
		if (queueSize > 1)
		{
			for (int i = 0; i < queueSize; i++)
			{
				if (add <= elem[i])
				{
					for (int j = queueSize - 1; j >= i; j--)
					{
						elem[j] = elem[j - 1];
					}
					elem[i] = add;
					break;
				}
			}
			if (add>=elem[queueSize-1])
				elem[queueSize - 1] = add;
		}
		else
		{
			elem[queueSize - 1] = add;
		}
}
template <class T> 
void PriorityQueue<T>::pop_back()
{
	if (queueSize > 0 && elem != nullptr)
	{
		T *temp;
		temp = elem;
		queueSize = queueSize - 1;
		if (queueSize > 0)
		{
			elem = new T[queueSize];
			elem = temp + 1;
		}
		else
			elem = nullptr;
	}
}
template <class T> 
bool PriorityQueue<T>::isEmpty()
{
	if (queueSize == 0)
		return true;
	else
		return false;
}
template <class T> 
void PriorityQueue<T>::print()
{
	if (!isEmpty())
	{
		for (int i = 0; i < queueSize; i++)
		{
			printf("%lf ", elem[i]);
		}
		printf("\n");
	}
	else
		printf("Queue is Empty!\n");
}
template <class T> 
void PriorityQueue<T>::resize()
	{
		T *temp;
		temp = elem;
		queueSize = queueSize + 1;
		elem = new T[queueSize];
		for (int i = 0; i < queueSize-1; i++)
		{
			elem[i] = temp[i];
		}
		if (queueSize>1)
			elem[queueSize - 1] = temp[queueSize - 2];
		temp = nullptr;
	}

#endif
