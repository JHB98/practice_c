#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;
class Bizcard
{
private:
	char *name;
	char *phone;
public:
	Bizcard()
	{
		name = NULL;
		phone = NULL;
	}

	Bizcard(const char *n, const char *p)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		phone = new char[strlen(p) + 1];
		strcpy(phone, p);
	}

	Bizcard(const Bizcard& copy)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
		phone = new char[strlen(copy.phone) + 1];
		strcpy(phone, copy.phone);
	}

	Bizcard& operator=(const Bizcard& ref)
	{
		if (this != &ref)
		{
			name = new char[strlen(ref.name) + 1];
			strcpy(name, ref.name);
			phone = new char[strlen(ref.phone) + 1];
			strcpy(phone, ref.phone);
		}
		return *this;
	}

	void setter(char * RefName, char * RefPhone)
	{
		name = RefName;
		phone = RefPhone;
	}

	void ShowInfo()
	{
		cout << "이름 : " << name << "전화번호 : " << phone;
	}

	~Bizcard()
	{
		delete[] name;
		delete[] phone;
	}
};

template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize)
{
	if (newSize < 0) throw "New length must be >= 0";

	T* temp = new T[newSize];
	int number = __min(oldSize, newSize);
	copy(a, a + number, temp);
	delete[] a;
	a = temp;
}

template <class T>
class Bag
{
public:
	Bag(int bagCapacity = 3);
	~Bag();

	int Size() const;
	bool IsEmpty() const;
	T& Element() const;

	void Push(const T&);
	void Pop();

private:
	T * array;
	int capacity;
	int top;
};

template <class T>
Bag<T>::Bag(int bagCapacity) : capacity(bagCapacity)
{
	if (capacity < 1) throw "Capacity must be > 0";
	array = new T[capacity];
	top = -1;
}

template <class T>
Bag<T>::~Bag()
{
	delete[] array;
}

template <class T>
void Bag<T>::Push(const T& x)
{
	if (capacity == top + 1)
	{
		try {
			ChangeSize1D(array, capacity, 2 * capacity);
		}
		catch (const char* msg) {
			cout << msg << endl;
		}
		capacity *= 2;
	}
	array[++top] = x;
}

template <class T>
void Bag<T>::Pop()
{
	if (IsEmpty() == 1)throw"Bag is empty,cannot delete!";
	int deletepos = 0;
	if (top != 0)deletepos = rand() % top;
	if (deletepos != 0)
		copy(array + deletepos + 1, array + top + 1, array + deletepos);
	array[top--].~T();
}

template <class T>
int Bag<T>::Size() const
{
	return top + 1;
}

template <class T>
bool Bag<T>::IsEmpty() const
{
	return Size() == 0;
}

template <class T>
T& Bag<T>::Element() const
{	
	int RandomNum;
	if (IsEmpty())throw"Bag is empty";
	int num = Size();
	srand((unsigned int)time(NULL));
	RandomNum = rand() % num;
	return array[RandomNum];
}

int main()
{
	int choice, i = 0;
	char *RefName, *RefPhone;
	char buffer1[20], buffer2[20];
	Bag<Bizcard> bag;
	Bizcard *card = new Bizcard[100];
	while (1)
	{
		cout << endl << endl;
		cout << "메뉴를 선택하세요." << endl;
		cout << "1. Push 2. Pop 3. Size 4. IsEmpty 5. Element 6. finish" << endl;
		cin >> choice;
		cout << "---------------------------------------------" << endl;

		if (choice < 1 || choice>6)
		{
			continue;
		}

		if (choice == 6)
		{
			break;
		}

		switch (choice)
		{
		case 1:
			cout << "이름 입력 : ";
			RefName = buffer1;
			cin >> RefName;
			cout << "전화번호 입력 : ";
			RefPhone = buffer2;
			cin >> RefPhone;
			card[i].setter(RefName, RefPhone);
			bag.Push(card[i]);
			i++;
			break;

		case 2:
			try {
				bag.Pop();
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
			break;

		case 3:
			cout << "size : " << bag.Size();
			break;

		case 4:
			if (bag.IsEmpty())
			{
				cout << "비어있습니다." << endl;
			}

			else
			{
				cout << "비어있지 않습니다." << endl;
			}
			break;

		case 5:
			try {
				bag.Element().ShowInfo();
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
			
			break;

		}
	}
	return 0;
}