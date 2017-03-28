#include <stack>
#include <cstdio>
using namespace std;


//stack
int main(){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	printf("%d\n",s.top());
	s.pop();
	printf("%d\n",s.top());
	s.pop();
	printf("%d\n",s.top());
	s.pop();
	//s.pop();	//segmentatoin fault 11
	//printf("%d\n",s.top());	//segmentatoin fault 11
	return 0;
}