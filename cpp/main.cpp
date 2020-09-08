#include "main.h"

int loopInts(int size)
{
	int xs[size];
	for (int i = 0; i < size; i++)
	{
		cout << "add i: " << i << "\n";
		xs[i] = i;
	}
	return size;
}

int loopObjects(int size)
{
	vector<int> xs;
	for (int i = 0; i < size; i++)
	{
		cout << "add i: " << i << "\n";
		xs.push_back(i);
	}

	return size;
}

class IntHolder
{
	int _x;

public:
	IntHolder();
	IntHolder(int);
	void set_x(int x)
	{
		this->_x = x;
	}

	int get_x()
	{
		return this->_x;
	}

	void *operator new(size_t size)
	{
		void *p = malloc(size);
		return p;
	}

	void operator delete(void *ptr)
	{
		free(ptr);
	}
};

IntHolder::IntHolder()
{
	_x = 0;
}
IntHolder::IntHolder(int x)
{
	_x = x;
}

int loopObjectsWithReferences(int size)
{
	vector<IntHolder> xs;
	for (int i = 0; i < size; i++)
	{
		cout << "add i: " << i << "\n";
		IntHolder int_holder(i);
		xs.push_back(int_holder);
	}

	return size;
}

int main()
{
	/*
	Stack operations below
	*/
	cout << "*** loopInts(5)\n";
	int xs1 = loopInts(5);

	cout << "\n";
	cout << "*** loopObjects(5)\n";
	int xs2 = loopObjects(5);

	cout << "\n";
	cout << "*** loopObjectsWithReferences(5)\n";
	int xs3 = loopObjectsWithReferences(5);

	IntHolder x = IntHolder(123);
	cout << "\n";
	cout << "x.get_x(): " << x.get_x() << "\n";

	/*
	Heap operations below
	*/
	IntHolder *xp = new IntHolder(345);
	cout << "\n";
	cout << "xp->get_x(): " << xp->get_x() << "\n";
	delete xp;
}
