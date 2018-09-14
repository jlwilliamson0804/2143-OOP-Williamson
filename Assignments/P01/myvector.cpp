#include "myvector.h"
#include<iostream>

using namespace std;

//default constructor
myvector::myvector()
{
	vSize = 0;
}

/**
  *  vector constructor for size of param
  *
  *  @param {int} size to allocate vector
  *  @return {} a created object includes vector
  */
myvector::myvector(int size)
{
	original_Size = size;
	vSize = size;
	theVector = new int[vSize];
	index = 0;
}

//default destructor
myvector::~myvector()
{

}

/**
  *  Print the items in the vector
  *
  *  @param {} 
  *  @return {void} only prints, no return
  */
void myvector::print()
{
	for (int i = 0; i < index; i++) 
	{
		cout << theVector[i] << " ";
	}

	cout << "\n";
}

/**
  *  gives the vector size to user
  *
  *  @param {} none
  *  @return {int} return vSize
  */
int myvector::size()
{
	return vSize;
}

/**
  *  removes last item from the vector, and resizes if needed
  *
  *  @param {int} number of how many times to remove
  *  @return {void} removes/resizes accordingly. no return
  */
void myvector::pop_back(int number)
{
	// initial check if vector is empty
	if (index == 0)
		cout << "Error! vector is empty \n";

	else
	{
		//check everytime what to do ie. move and/or resize
		for (int i = 0; i < number; i++)
		{
			//values to check for resize
			double percent = (double)index / vSize;
			double sentinal = 0.4;

			//if it needs to resize
			if (percent < sentinal)
			{
				if (vSize < original_Size)
				{
					index--;
				}
				else
				{
					int* tempV = new int[(vSize / 2)];
					for (int j = 0; j < index; j++)
					{
						tempV[j] = theVector[j];
					}
					if (vSize / 2 > original_Size)
					{
						vSize = (vSize / 2);
					}
					else vSize = original_Size;
					int* temp = theVector;
					theVector = tempV;
					delete[] temp;
					index--;
				}
			}
			else
				index--;
		}
	
	}
}

/**
  *  Push/add an item to the end of vector
  *
  *  @param {int} item to be added
  *  @return {bool} true/false
  */
bool myvector::push_back(int item)
{
	//message that array is growing
	if (index >= vSize) {
		cout << "Resizing the array!!" << endl;

		// 1. Create new array 1.5 times bigger than myVector.
		int *tempVector = new int[vSize*1.5];

		// 2. Copy each item from myVector to new vector.
		for (int i = 0; i < vSize; i++)
		{
			tempVector[i] = theVector[i];
		}
		
		//update vSize
		vSize = vSize * 1.5;

		// 3. Point temp pointer to old array
		int *tempPTR = theVector;
		
		// 4. Point myVector to new array
		theVector = tempVector;
		
		// 5. Delete old array
		delete [] tempPTR;
		
	}

	//update index and add item to correct spot
	theVector[index++] = item;
	
	return true;
}