# set的使用方法
	set的优点:set内部根据红黑树自动排序，同时只保留一个相同元素
## 1.定义set
	set的定义与其他 STL容器定义相同
	引入头文件 #include <set> 名字域的使用
	set<基本类型/定义类/结构体> myset
## 2.set的访问
	set访问只能够通过迭代器，同时迭代器只能进行 it++ 或it-- 不允许it+数字
	it+数字的形式只有string和vector可以使用
## 3.set常用函数
### 3.1 insert()	
	insert(x) x是set类型的实例
### 3.2 find()
	find(x) x是set类型的实例
	找到的话返回 x所在的迭代器，找不到返回 set::end()
### 3.3 erase()
	3.3.1 erase(it) 删除迭代器所在的元素
	3.3.2 erase(x) 删除x元素 不安全如果x不存在会出现错误
		最好用find找到x 不为 end()的时候再用3.3.1方式删除
	3.3.3 erase(it_start,it_end) 删除范围
		删除从[it_start,it_end)范围的元素
### 3.4 size()
	其他的STL size()同样的使用方法
### 3.5 clear()
	同其他的STL 的clear
## 4.set中结构体判断重复和排序方法
	假设set<Node> myset;
	我们需要对Node结构体进行<运算符的重载
	struct Node {	//我们决定对Node按照id去重，按hot排序，hot相同的按id排序
		int id;
		int hot;
		bool operator<(const Node &temp){
			if (temp.id == this.id) return false;	//id相同的不加入set
			else{
				if (temp.hot != this.hot) return temp.hot < this.hot;
				else	//hot相同按id降序排列
					return temp.id > this.id;

			}
		}
	};

