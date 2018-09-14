/**
*  Course: CMPS 2143-OOP-Griffin
*  Assignment: P01
*  Purpose: Create a Vector like class using a
*	dynamic array
*
*  @author Joseph Williamson
*  @version 1.0 09/13/18
*/

#include<iostream>
#include"myvector.h"

using namespace std;

int main()
{
	myvector V(10);

	V.pop_back(1);

	V.push_back(13);
	V.push_back(31);
	V.push_back(73);

	V.print();

	for (int i = 0; i < 1000; i++)
	{
		V.push_back(i);
	}

	cout << "The size of the vector is " << V.size() << endl;

	V.pop_back(998);
	V.print();
	cout << "The size of the vector is " << V.size() << endl;

	system("pause");
	return 0;
}