#include <cstdio>

int main (){
	int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char ID[19];
	char M[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
	int n;
	scanf("%d",&n);
	int pass = 0;
	for (int j = 0; j < n; j++){
		bool legal = true;
		scanf("%s",ID);
		for(int i = 0; i < 17; i++){			//检查身份证前17位合法性
			if(ID[i]-'0'< 0 || ID[i] - '0' > 9){
				printf("%s\n",ID);
				legal = false;
				break;
			}
		}
		if(legal){
			int count = 0;
			for(int i = 0; i < 17; i++){
				count += (ID[i] - '0') * weight[i];
			}
			if (M[count % 11]!=ID[17]){
				printf("%s\n",ID);
				legal = false;
			}
		}
		if (!legal)
			pass++;
	}

	if (pass == 0)
		printf("All passed");
	


	return 0;
}
