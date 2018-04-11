#include <iostream>
#include <set>
using namespace std;


struct Node {
	int id;
	int hot;
	bool operator<(const struct Node &temp) const {
		if (temp.id == this->id) return false;
		else{
			if (temp.hot == this->hot){
				return temp.id > this->id; //temp 类似于cmp函数中第二个参数
			}
			else {
				return temp.id > this->id;
			}
		}
		//或者else后面可直接跟 return temp.id > this->id
	}
};

int main(){
	set<Node> myset;
	Node a, b, c, d, e, f;
	b.id = 2;b.hot = 8;
	c.id = 2;c.hot = 1;
	e.id = 4;e.hot = 2;
	d.id = 5;d.hot = 2;
	f.id = 3;f.hot = 2;
	a.id = 1;a.hot = 10;
	myset.insert(a);
	myset.insert(b);
	myset.insert(c);
	myset.insert(d);
	myset.insert(e);
	myset.insert(f);

	for (Node i : myset){
		cout << i.id << " " << i.hot << endl;
	}
}
