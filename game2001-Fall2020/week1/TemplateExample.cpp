//woohoo I'm a template

//compare 2 numbers and return the smallest, largest, and do that for objects too.


#include <iostream>
using namespace std;

//check 2 things and return smallest------------
//non-template example with ints for referance
int minNum(int num1, int num2)
{
	if (num1 > num2)
	{
		return num1;
	}

	return num2;
}


template <class T>
T minFunc(T lVal, T rVal)
{
	if (lVal > rVal)
	{
		return lVal;
	}

	return rVal;
}


//check 2 things and return largest----------
template <class T>
T maxFunc(T lVal, T rVal)
{
	if (lVal < rVal)
	{
		return rVal;
	}

	return lVal;
}


// implement a template here
template <class T>
class TemplateClass
{
public:
	TemplateClass(T val)
	{
		mVal = val;
	}

	//overloading operators to allow comparisons
	bool operator<(TemplateClass& rVal)
	{
		return mVal < rVal.GetVal();
	}
	bool operator>(TemplateClass& rVal)
	{
		return mVal > rVal.GetVal();
	}



	T GetVal()
	{
		return mVal;
	}

private:
	T mVal;
};


/*

//main here
int main()
{
	cout << "Template Example" << endl << endl;
	cout << "Min = " << minFunc(10, 20) << endl;
	cout << "Max = " << maxFunc(56.1, 43.6) << endl;


	//make 2 TemplateClass objects and compare them
	cout << "Max (objects)" << maxFunc(TemplateClass<int>(7), TemplateClass<int>(4)).GetVal();






	return 0;
}

*/