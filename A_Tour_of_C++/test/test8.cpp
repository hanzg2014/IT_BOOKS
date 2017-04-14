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

istream& operator >> (istream& is, Entry& e){
	char c;
	char c1;
	if (is>>c && c=='{' && is>>c1 && c1 =='\"'){
		string name;
		while(is.get(c) && c!='\"'){
			name += c;
		}
		if(is>>c && c==','){
			int number;
			if(is>>number && is>>c && c=='}'){
				e = {name, number};
				return is;
			}
		}

	} 
	cout<<"error"<<endl;
	return is>>e.name>>e.number;
}

int main(){
//	vector<int> v{1,2,3,4};
	Entry test{"hanzg", 4679};
	cin>>test;
	cout<<test;
	return 0;
}

