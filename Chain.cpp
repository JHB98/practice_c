#include<iostream>
using namespace std;
template <class T> class Chain;

template <class T>
class ChainNode {
	friend class Chain<T>;
private:
	T data;
	ChainNode<T> *link;

public:
	ChainNode(int element = 0, ChainNode *next = 0)
	{
		data = element;
		link = next;
	}
};

template <class T>
class Chain {
public:
	class ChainIterator {
		friend class Chain<T>;
	public:
		ChainIterator(ChainNode<T>* startNode = 0)
		{
			current = startNode;
		}
		T& operator*() const { return current->data; }
		T* operator->() const { return &current->data; }

		ChainIterator& operator++() 
		{
			current = current->link; return *this;
		}
		ChainIterator operator++(int) 
		{
			ChainIterator old = *this;
			current = current->link;
			return old;
		}

		bool operator!=(const ChainIterator right) const
		{
			return current != right.current;
		}
		bool operator==(const ChainIterator right) const
		{
			return current == right.current;
		}
	private:
		ChainNode<T>* current;
	};

	Chain() { first = 0; };
	~Chain() 
		{
			ChainNode<T> *temp;
			while (1)
	        {
				temp = first;
				first = first->link;
		        delete temp;
	            if (first == NULL)
		           {
					break;
		           }
	        }
	    }
	ChainIterator begin() { return ChainIterator(first); }
	ChainIterator end() { return ChainIterator(0); }

	void InsertFront(const T& e);
	void InsertBack(const T& e);
	T Front();
	T Back();
	T Get(int i);
	void DeleteFront();
	void DeleteBack();
	void InsertIBack(const T& e, int i);
	void RemoveI(int i);


private:
	ChainNode<T> *first;
};

template <class T>
void Chain<T>::InsertFront(const T& e)
{
	ChainNode<T> *NewNode = new ChainNode<T>(e,first);
	first = NewNode;
}

template <class T>
void Chain<T>::InsertBack(const T& e)
{
	Chain<T>::ChainIterator Ci(first);
	ChainNode<T> *NewNode = new ChainNode<T>(e);
	while (Ci.current->link!=0)
	{
		Ci++;
	}
	
	Ci.current->link = NewNode;

}

template <class T>
T Chain<T>::Front()
{
	return first->data;
}

template <class T>
T Chain<T>::Back()
{
	Chain<T>::ChainIterator Ci(first);

	while (Ci.current->link != 0)
	{
		Ci++;
	}
	return Ci.current->data;
}

template <class T>
T Chain<T>::Get(int i)
{
	Chain<T>::ChainIterator Ci(first);
	
	for (int j = 0;j < i;j++)
	{
		Ci++;
	}

	return Ci.current->data;
}

template <class T>
void Chain<T>::DeleteFront()
{
	ChainNode<T> *temp;
	temp = first->link;
	delete first;
	first = temp;
}

template <class T>
void Chain<T>::DeleteBack()
{
	Chain<T>::ChainIterator Ci(first);
	ChainNode<T> *temp;
	while (Ci.current->link->link!=NULL)
	{
		Ci++;
	}
	
	temp = Ci.current->link;
	delete temp;
	Ci.current->link = NULL;
}

template <class T>
void Chain<T>::InsertIBack(const T& e, int i)
{
	Chain<T>::ChainIterator Ci(first);
	ChainNode<T> *NewNode = new ChainNode<T>(e);
	for (int j = 0;j < i;j++)
	{
		Ci++;
	}

	NewNode->link = Ci.current->link;
	Ci.current->link = NewNode;
}

template <class T>
void Chain<T>::RemoveI(int i)
{
	Chain<T>::ChainIterator Ci(first);
	ChainNode<T> *temp;
	for (int j = 0;j < i-1;j++)
	{
		Ci++;
	}
	
	temp = Ci.current;
	Ci++;

	temp->link = Ci.current->link;
	delete Ci.current;
}

int main()
{
	Chain <int> chain;
	cout <<"1���� 9������ ������ ���� ��带 �߰��մϴ�." << endl;
	for (int i = 8;i >= 0;i--)
	{
		chain.InsertFront(i+1);
	}
	cout << "ü���� �� ������ ����Ͽ� 1���� 9���� ���������� ��µǴ��� Ȯ���Ѵ�." << endl;
	for (int i = 0;i < 9;i++)
	{
		cout << chain.Get(i)<<" ";
	}
	cout << endl;
	cout <<"0�� �� �տ� �����Ѵ�." << endl;
	chain.InsertFront(0);
	
	cout << "��ü ��带 ����Ѵ�." << endl;
	for (int i = 0;i < 10;i++)
	{
		cout << chain.Get(i) <<" ";
	}
	cout << endl;

	cout <<"10�� �� �ڿ� �����Ѵ�." << endl;
	chain.InsertBack(10);

	
	cout <<"��ü ��带 ����Ѵ�." << endl;
	for (int i = 0;i < 11;i++)
	{
		cout << chain.Get(i) <<" ";
	}
	cout << endl;

	cout<<"Front�� ȣ���Ͽ� 0�� �������� Ȯ���Ѵ�." << endl;
	cout << chain.Front() << endl;
	
	cout<<"Back�� ȣ���Ͽ� 10�� �������� Ȯ���Ѵ�." << endl;
	cout << chain.Back() << endl;

	cout<<"Get(2)�� ȣ���Ͽ� 2�� �������� Ȯ���Ѵ�." << endl;
	cout << chain.Get(2) << endl;
	
	cout<<"�� �տ� �ִ� 0�� �����Ѵ�." << endl;
	chain.DeleteFront();

	cout<<"��ü ��带 ����Ѵ�." << endl;
	for (int i = 0;i < 10;i++)
	{
		cout << chain.Get(i) << " ";
	}
	cout << endl;

	cout<<"�� �ڿ� �ִ� 10�� �����Ѵ�." << endl;
	chain.DeleteBack();
	
	cout<<"��ü ��带 ����Ѵ�." << endl;
	for (int i = 0;i < 9;i++)
	{
		cout << chain.Get(i) << " ";
	}
	cout << endl;

	cout<<"3�� 4 ��� ���̿� 100�� �����Ѵ�.(2��° ���� �ڿ� ����)" << endl;
	chain.InsertIBack(100, 2);
	
	cout<<"��ü ��带 ����Ѵ�." << endl;
	for (int i = 0;i < 10;i++)
	{
		cout << chain.Get(i) << " ";
	}
	cout << endl;

	cout<<"6�� �����Ѵ�.(6��° ���� ����)" << endl;
	chain.RemoveI(6);
	
	cout<<"��ü ��带 ����Ѵ�." << endl;
	for (int i = 0;i < 9;i++)
	{
		cout << chain.Get(i) << " ";
	}
	cout << endl;

	return 0;
}