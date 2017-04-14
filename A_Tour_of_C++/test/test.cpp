#include <iostream>
#include <vector>
using namespace std;

string::size_type find_char(const string &s, char c, string::size_type &occurs){
	auto ret = s.size();
	occurs = 0;
	for (decltype(ret) i = 0; i != s.size(); ++i){
		if(s[i] == c){
			ret = i;
			++occurs;
		}
	}
	return ret;
}

int* reset(int *ip){  //
	*ip = 0;
	ip = 0;
}

void reset2(int &i){
	i = 0;
}

int tran(char c){
	if (c == 'a')
		return 0;
	else 
		return 1;
}

void hello_line()
{
cout << "Please enter your name\n";
string str;
getline(cin,str);
cout << "Hello, " << str << "!\n";
}


int main(){
	hello_line();

	int i1;
	double d1;
	cin>>d1>>i1;
	cout<<"i1:"<<i1<<endl<<"d1:"<<d1<<endl;


	string s1("Hello, world");
	string::size_type occurs;
	auto index = find_char(s1, 'l', occurs);
	cout<<"index: "<<index<<" occurs: "<<occurs<<endl;

	int i = 42;
	int *ptr = &i;
	reset2(i);
//	cout<<"ptr="<<ptr<<endl;

//	ptr = reset(ptr);
	cout<<"i = "<<i<<endl;
//	cout<<"ptr="<<ptr<<endl;

	bool flag;
//	int & refval2;
	constexpr size_t sz = 5;
	int a[] = {1,2,3,4,5};
	string s("Hello world!");
//	char *s1 = "0123456789012345678901234567890";

	bool boo = -1;
	cout<<"boo:";
	if(boo){
		cout<<boo;
	}
	cout<<endl;

//	const int ci = 42;
//	int *const p1 = &ci;

	int *test = a + 10;

    int (*fp)(char);
    fp = tran;
	vector<string> svec2 = {"a", "an", "the"};
	vector<char> cvec(3,'c');
	vector<int> v1{1, 2, 3, 4};

	for (auto c : cvec)
		cout << c << " ";
	cout << endl;

	cout<<(*fp)('a')<<fp('b')<<endl;

	int *beg = begin(a);
	int *last = end(a);
	while(beg != last && *beg >= 0){
		++beg;
	}
	int b = *beg;
	cout<<"b: "<<b<<endl;

	cout<<"test: "<< *test <<endl;


//	vector<int> v;
//	v[0] = 0;


//	for(int i = 0; i < 100; i++)
//		v.push_back(i);

//  segmentation fault:11 になる
//	for(decltype(v.size()) i = 0; i < 100; i++)
//		v[i] = i;


//	for(decltype(v.size()) i = 0; i < 100; i++)
//		cout<<v[i]<<endl;


	/*
	for(auto &c:s){
		c = toupper(c);
	}
	*/

	/*
	for(decltype(s.size()) i = 0; index != s.size();i++){
		s[i] = toupper(s[i]);
	}
	*/


	/*
	char *p = index(s1,'l');

	cout << s << endl;
	cout << *p << endl;
	*/
//	int i = 42;
	//int j = reset(&i);
	return 0;
}