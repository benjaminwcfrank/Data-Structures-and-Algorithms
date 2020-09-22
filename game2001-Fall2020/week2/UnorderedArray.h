#pragma once
#include <cassert>
#include <cstring>	//NEEDED FOR memset and memcpy!!!!!!!!!

template<class T>
class UnorderedArray
{
public:
	//constructor
	UnorderedArray(int size, int growBy = 1) :					//init variables in constructor via colon
		arrayPtr(NULL), maxSize(0), growSize(0), numElements(0)
	{
		if (size)												//is size given?
		{
			//if so, give new maxsize
			maxSize = size;
			arrayPtr = new T[maxSize];							//dynamically allocating an array 
			memset(arrayPtr, 0, sizeof(T) * maxSize);			//tells compiler to set aside a bunch of memory. Useful for template functions. Allocation begins at arrayPtr's location in memory (at position 0) and end at (size of T times the number of elements)
			growSize = ((growBy > 0) ? growBy : 0);				//growBy > 0? If so then return growBy. If not, return 0

		}
	}


	//destructor
	~UnorderedArray()
	{
		if (arrayPtr != NULL)
		{
			delete[] arrayPtr;					//delete memory pointed at by arrayPtr
			arrayPtr = NULL;					//set to nullptr
		}
	}

	//Fast Insertion for UNORDERED array (add to end of array)
	void push(T valToInsert)
	{
		assert(arrayPtr != NULL);				//for debugging. if true, program will stop here

		if (numElements >= maxSize)
		{
			//if needed, expand
			Expand();
		}


		arrayPtr[numElements] = valToInsert;	//place valToInsert at end of array
		numElements++;
	}

	//Deletion
		//remove last item in array
	void pop()
	{
		if (numElements > 0)				//top element may as well not exsist
		{
			numElements--;
		}
	}

	//remove at certain index (kinda brute force execution, skips over everything UP TO the index. Brute force would start and check everything)
	void remove(int indexToDelete)
	{
		assert(arrayPtr != NULL);

		if (indexToDelete >= numElements)	//is index legit?
		{
			return;			//not legit. boots you out
		}

		for (int i = indexToDelete; i < numElements; i++)
		{
			if (i + 1 < numElements)
			{
				arrayPtr[i] = arrayPtr[i + 1]; //shifting stuff down
			}
		}

		numElements--;		//dont forget to shrink the elements size!
	}

	//searching (linear)
	int search(T val)
	{
		assert(arrayPtr != NULL);

		//brute force search

		for (int i = 0; i < numElements; i++)
		{
			if (arrayPtr[i] == val)
			{
				return i; //found!		:)
			}
		}
		return -1; //not found			:(
	}

	//overload [] operators
	T& operator[](int index)
	{
		assert(arrayPtr != NULL && index < numElements);	//index mustt be valid

		return arrayPtr[index];
	}

	//clear
	void clear()
	{
		arrayPtr = 0;
	}

	//gets and sets
	int GetSize()
	{
		return numElements;
	}

	int GetMaxSize()
	{
		return maxSize;
	}

	int GetGrowSize()
	{
		return growSize;
	}

	void SetGrowSize(int value) //HINT HINT FOR ASSIGNMENT <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	{
		assert(value >= 0);
		growSize = value;
	}

private:
	//expand
	bool Expand()
	{
		if (growSize <= 0)
		{
			return false; //grow by negative or zero? Get outta here.
		}

		//create new array of new size
		T* tempArray = new T[maxSize + growSize];
		assert(tempArray != NULL);

		//copy array contents
		memcpy(tempArray, arrayPtr, sizeof(T) * maxSize);	//copy from arrayPtr to tempArray. Literally take the bytes from one to another.

		//delete contents of old array
		delete[] arrayPtr;

		//cleanup variable assignments
		arrayPtr = tempArray; //pointer now points to the address where tempArray is
		tempArray = NULL;	//temp is now nulled
		maxSize += growSize;	//set new max size
		return true;

	}

private: //double private, one for functions and one for variables. Common but not required.
	T* arrayPtr;			//pointer to start of array

	int maxSize;			//max size of the array
	int growSize;			//amount to expand the array via expansion
	int numElements;			//number of items in array
};