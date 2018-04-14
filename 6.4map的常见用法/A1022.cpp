#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct Pub{
	string keywords;
	int id;
};
bool cmpByPub(Pub a, Pub b){
	return a.id < b.id;
}

int main(){
	map<string, vector<int> > title;
	map<string, vector<int> > author;
	vector<Pub> keyW;
	map<string, vector<int> > publisher;
	map<string, vector<int> > year;

	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++){
		int id;
		string bookName, personName, keywords, publish ,y;
		cin >> id;
		getchar();
		getline(cin, bookName);
		getline(cin, personName);
		getline(cin, keywords);
		getline(cin,publish);
		cin >> y;
		getchar();

		title[bookName].push_back(id);
		author[personName].push_back(id);
		Pub b;
		b.keywords = keywords;
		b.id = id;
		keyW.push_back(b);
		publisher[publish].push_back(id);
		year[y].push_back(id);
	}

	int m;
	cin >> m;
	getchar();
	for (int i = 0; i < m; i++){
		string query;
		getline(cin,query);
		char type = query[0];
		string str = query.substr(3,99999);
		cout << query << endl;
		switch(type){
			case '1':{
				sort(title[str].begin(),title[str].end());
				for (int j : title[str]){
					printf("%07d\n",j);
				}
				if (title[str].size() == 0)
					cout << "Not Found\n";
				break;
			}
			case '2':{
				sort(author[str].begin(),author[str].end());
				for (int j : author[str]){
					printf("%07d\n",j);
				}	
				if (author[str].size() == 0)
					cout << "Not Found\n";
				break;
			}
			case '3':{
				sort(keyW.begin(),keyW.end(),cmpByPub);
				vector<Pub>::iterator it = keyW.begin();
				int cnt = 0;
				for(it; it != keyW.end(); it++){
					if (it->keywords.find(str) != string::npos){
						printf("%07d\n",it->id);
						cnt++;
					}
				}
				if (cnt == 0){
					cout << "Not Found\n";
				}
				break;
			}
			case '4':{
				sort(publisher[str].begin(),publisher[str].end());
				for (int j : publisher[str]){
					printf("%07d\n",j);
				}
				if (publisher[str].size() == 0)
					cout << "Not Found\n";
				break;
			}
			case '5':{
				sort(year[str].begin(),year[str].end());
				for (int j : year[str]){
					printf("%07d\n",j);
				}
				if (year[str].size() == 0)
					cout << "Not Found\n";
				break;
			}
		}
	}

	return 0;
}
