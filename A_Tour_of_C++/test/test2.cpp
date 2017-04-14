#include <iostream>
#include <vector>
using namespace std;

struct Entry{
	string name;
	int number;
};

ostream& operator << (ostream& os, const Entry& e){
	return os<<"{\""<<e.name<<"\","<<e.number<<"}"<<endl;
}

int main(){
//	vector<int> v{1,2,3,4};
	Entry test{"Han", 4679};
	cout<<test;
	return 0;
}