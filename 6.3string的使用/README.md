# string 的使用说明

## 1.string的输入输出
	string 类型只能用cin cou 进行标准输入输出
	如果有时间要求 使用scanf 和printf 时用如下方法：
	```C++
		string str;
		str.resize(100);	//类似生命char str[100]
		scanf("%s",&str[0]);//	输入str第一个字符的首地址
	
		printf("%s",str.c_str());//可以使用printf输出
	```

## 2.string的迭代器访问
	string::iterator it;
	可以对string的迭代器进行 it = it±数字

## 3.string的常用函数
### 3.1 运算符的重载
	string 可以使用 + 进行两个string的连接 于strcat类似
	string 可以使用 == != <= >= 等比较运算符进行字典序比较
### 3.2 length函数和size函数
	length 与 size 函数都是返回 string的长度
### 3.3 insert()
#### str1.insert(pos,str2) 
	在str1 的 pos 处插入 str2
#### str1.insert(it1,it2,it3)
	在str1的it1 处 插入 str2的[it2,it3)
### 3.4 erase()
	erase(it)	删除it处的元素
	erase(it_first,it_last) 删除[it_first,it_last)处的元素
	erase(pos,n) 删除从pos开始一共n个元素
### 3.5 clear();
### 3.6 substr()
	substr(pos,len)	返回从pos开始len长度的子穿，若len大于剩余长度，则返回到字符串最后一个字符
### 3.7 string::npos
	npos == -1 或 == 4294967295
	对于返回int型的函数 若不存在则返回 npos,比如find函数
### 3.8 find()
	str1.find(str2) 返回str1中 str2 * 第一次 * 出现的位置
	str1.find(str2,pos) 返回从pos以后查找到第一个 str2的位置
### 3.9 replace()
	str1.replace(pos,len,str2)	返回从pos开始len长度的子串替换为str2的新的字符串
	str1.replace(it1,it2,str2)  返回从[it1,it2)子串替换为str2的新字符串

	
