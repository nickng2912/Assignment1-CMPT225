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