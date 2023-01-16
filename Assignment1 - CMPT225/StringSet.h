#include <string> 
using std::string; 

class StringSet
{
public: 
	//Constructors and Destructor 
	StringSet(); 
	StringSet(const StringSet& str);
	~StringSet(); 

	//Overloaded Assignment Operator 
	StringSet& operator = (const StringSet& str); 

	//Behaviours (Functions) 
	bool insert(string value);
	void remove(string value); 
	int find(string value); 

	int size() const; //getters 

	StringSet ssUnion(const StringSet& str);
	StringSet intersection(const StringSet& str);
	StringSet difference(const StringSet& str); 

private: 
	//Attributes 
	string* arrStr;
	int currentSize; 
	int maxSize; 
};