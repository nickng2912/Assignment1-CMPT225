/*
	PART 2 - O Notation Running Time 

1) Default Constructor : O(1) - since it just initialize the value to the class attributes
2) Copy Constructor : O(n) - it creates a deep copy of the parameter, so it needs to go through the array and copy each value to it
3) Destructor : O(1) - simply deallocates the dynamic memory 
4) Overloaded Assignment Operator : O(n) - it also creates a deep copy, so it have to go through the array and copy its value 
5) Insert : O(n^2) - it check if the array is full using loop, and if it full, it will call a helper function of O(n) to resize the array
6) Remove : O(n) - iterate through the array and swap the remove value to the end of the array and then decrement it
7) Find : O(n) - go through the array to find the index of the value 
8) Size : O(1) - return the currentSize, no input needded 
9) ssUnion: O(n) - go through the array of the current set and the parameters' which take times proportional to each other 
10) Intersection: 0(n^2) - go through a loop and then call the Find function with O(n) so it take 2 loops to go through 
11) Difference: o(n^2) - same as intersection, go through a loop and then call Find function again 
12) doubleTheSize (helper function): O(n) - double the size and then deep copy of the old array to the new array with double the size

*/

#include <string> 
using std::string; 

class StringSet
{
public: 
	//Default Constructor 
	StringSet(); 

	//Copy Constructor
	StringSet(const StringSet& str);

	//Destructor
	~StringSet(); 

	//Overloaded Assignment Operator 
	StringSet& operator = (const StringSet& str); 


	// return fales if the value is already in the string set, otherwise add the value to the set
	bool insert(string value);

	// remove the value that matches in the string set, and then decrement the current size
	void remove(string value); 

	// return index of the value that match in the string set
	int find(string value) const; 

	// return the size of the set
	int size() const; //getters 

	
	// return a StringSet object that contains the union of the calling object and the str
	StringSet ssUnion(const StringSet& str) const;

	//return a StringSet object that contains the intersection of the calling object and the str
	StringSet intersection(const StringSet& str) const;

	//return a Stringset object that contains the set difference of the calling object and the str
	StringSet difference(const StringSet& str) const; 

private: 
	//Attributes 
	string* arrStr;
	int currentSize; 
	int maxSize; 

	//Helper function 
	void doubleTheSize();
};