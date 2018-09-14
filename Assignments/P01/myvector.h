#pragma once


class myvector
{
public:
	myvector();
	myvector(int size);
	~myvector();

	void print();
	int size();
	bool push_back(int item);
	void pop_back(int number);
	

private:
	int *theVector;
	int vSize;
	int original_Size;
	int index;
};

