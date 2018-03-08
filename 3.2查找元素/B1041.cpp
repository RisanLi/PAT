#include <iostream>
#include <string>
#include <cstdio>

struct info{
	long long studentNumber;
	int testSeatNumber;
};

int main(){
	info pat[1001];
	long long stuNum;
	int trySeat;
	int testSeat;

	int n;
	std::cin >> n;	
	for (int i = 0; i < n; i++){
		scanf("%lld%d%d",&stuNum,&trySeat,&testSeat);
		pat[trySeat].studentNumber = stuNum;
		pat[trySeat].testSeatNumber = testSeat;
	}

	int m;
	std::cin >> m;
	int findTrySeat;
	for (int i = 0; i < m; i++){
		std::cin >> findTrySeat;
		std::cout << pat[findTrySeat].studentNumber << " " 
			<< pat[findTrySeat].testSeatNumber << std::endl;
	}



	return 0;
}
