# priority\_queue的常见用法
	priority_queue采用堆排列的方法 时间复杂度为logN
	将 队列中的元素排序，默认从大到小 可修改
	只对优先队列中的 头元素 操作
## 头文件仍然是 \<queue>
## 常用函数
### top()
	获取头元素
### push() 
	把某个元素加入队列，重新堆排列
### pop()
	把队首元素弹出
### size()

## 设置优先级
### 对于基本元素
	设置优先级可采用
	```C++
	priority_queue<int> q  		//默认int从大到小
	priority_queue<int, vector<int>, less<int> >	
				//第一个参数 代表队列类型为int 第二个参数代表底层排列采用vector承担， 第三个参数代表 小的int 优先级高
	priority_queue<int, vector<int>, greater<int> > 这和默认是一样的效果
	```
### 对于结构体/类
	1、设置优先级可直接在结构体/类定义的时候 重载<
	```C++
	struct Fruit{
		string name;
		double price;
		bool operator < (const Fruit &a,const Fruit &b) const{
			 return a.price < b.price;	
		}
	};
	```
	   这样直接priority_queue<Fruit> f;
	2、采用cmp结构体法
	```C++
		struct Fruit{
			string name;
			double price;
		}
		struct cmp{
			bool operator() (const Fruit &a, const Fruit &b)
				return  a.price < b.price;
			}
	```
		要priority_queue<Fruit, vector<Fruit>, cmp> f;
