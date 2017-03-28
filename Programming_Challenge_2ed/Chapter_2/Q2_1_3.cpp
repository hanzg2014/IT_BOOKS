#include <queue>
#include <cstdio>
using namespace std;

//queue
int main(){
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	printf("%d\n",q.front());
	q.pop();
	printf("%d\n",q.front());
	q.pop();
	printf("%d\n",q.front());
	q.pop();
	printf("%d\n",q.front());
	//q.pop();	//0
	//s.pop();	//segmentatoin fault 11
	return 0;
}