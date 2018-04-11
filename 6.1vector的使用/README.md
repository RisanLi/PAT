# 在vector中存放char型数组 char[]
	方法：将char[]封装在结构体内
	如：
	```C++
	struct Cstring{
		char str[100];	
	};
	```
	这样每次就可以scanf读入数组到vector中
# 将vector的string 用printf打印
	vector<string> myVector;
	直接调用c_str()函数
	printf("%s",myVector[1].c_str());
