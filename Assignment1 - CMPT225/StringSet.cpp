#include "StringSet.h"
#include <iostream> 
#include <string> 

using std::cout;
using std::endl;
using std::string;

StringSet::StringSet()
{
	maxSize = 2;
	currentSize = 0;

	arrStr = new string[maxSize];
}

StringSet::StringSet(const StringSet& str)
{
	maxSize = str.maxSize;
	currentSize = str.currentSize; 

	arrStr = new string[maxSize];

	for (int i = 0; i < currentSize; i++)
	{
		arrStr[i] = str.arrStr[i];
	}
}

StringSet::~StringSet()
{
	delete[] arrStr;
}

StringSet& StringSet::operator= (const StringSet& str)
{
	if (this != &str)
	{
		delete[] arrStr; 
		maxSize = str.maxSize;
		currentSize = str.currentSize; 

		arrStr = new string[maxSize];
		for (int i = 0; i < currentSize; i++)
		{
			this->arrStr[i] = str.arrStr[i];
		}
	}
	return *this; 
}


bool StringSet::insert(string value)
{
	// Check if the value is already in the set
	for (int i = 0; i < currentSize; i++)
	{
		if (arrStr[i] == value)
			return false; 
	}

	//Check if the array is full, if yes then we double the maximum size
	if (currentSize == maxSize)
	{
		doubleTheSize();
	}

	arrStr[currentSize] = value; 
	currentSize++;
	return true;
}

void StringSet::remove(string value)
{
	for (int i = 0; i < currentSize; i++)
	{
		if (arrStr[i] == value)
		{
			arrStr[i] = arrStr[currentSize - 1];
			currentSize--; 
		}
	}
}

int StringSet::find(string value) const
{
	for (int i = 0; i < currentSize; i++)
	{
		if (arrStr[i] == value)
			return i; 
	}
	return -1; 
}

int StringSet::size() const
{
	return currentSize; 
}


StringSet StringSet::ssUnion(const StringSet& str) const 
{
	StringSet temp; 

	for (int i = 0; i < currentSize; i++)
	{
		temp.insert(arrStr[i]);
	}
	for (int i = 0; i < str.currentSize; i++)
	{
		temp.insert(str.arrStr[i]);
	}

	return temp; 
}

StringSet StringSet::intersection(const StringSet& str) const 
{
	StringSet temp;

	for (int i = 0; i < currentSize; i++) 
	{
		if (str.find(arrStr[i]) != -1) 
		{
			temp.insert(arrStr[i]);
		}
	}
	return temp;
}

StringSet StringSet::difference(const StringSet& str) const 
{
	StringSet temp;
	for (int i = 0; i < currentSize; i++) {
		if (str.find(arrStr[i]) == -1) {
			temp.insert(arrStr[i]);
		}
	}
	return temp;
}


//Helper Function 
void StringSet::doubleTheSize()
{
	maxSize *= 2; 
	string* tempArray = new string[maxSize];
	
	for (int i = 0; i < currentSize; i++)
	{
		tempArray[i] = arrStr[i];
	}
	
	delete[] arrStr; 
	arrStr = tempArray;
}

int main()
{
	StringSet sset1;
	sset1.insert("cat");
	sset1.insert("bat");
	sset1.insert("rat");
	bool insertTest = sset1.insert("badger");
	cout << "insert success: " << insertTest << endl;

	StringSet sset2;
	sset2.insert("elephant");
	sset2.insert("bat");
	sset2.insert("hamster");
	sset2.insert("weasel");
	sset2.remove("weasel");
	int findTest = sset2.find("weasel");
	cout << "index of weasel = " << findTest << endl;

	// Use the copy constructor to build a StringSet with sset1 U sset2
	StringSet sset3(sset1.ssUnion(sset2));

	// Use overloaded assignment operator to make a StringSet with sset2 int sset1
	StringSet sset4;
	sset4 = sset2.intersection(sset1);
	// Use overloaded assignment operator to make a StringSet with sset2 - sset1
	sset4 = sset2.difference(sset1);

	cout << "end basic test" << endl;
	return 0;
}






