# include <cstdio>

struct Item{
	int exp;
	double coe;
};

int main(){
	int n;	//第一行多项式项数
	Item poly[1001];
	double result[2002] = {0};

	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		scanf("%d%lf", &poly[i].exp, &poly[i].coe);
	}

	int m;
	int exp;
	double coe;
	scanf ("%d",&m);
	for (int i = 0; i < m; i++){
		scanf("%d%lf",&exp, &coe);
		for(int j = 0; j < n; j++){
			result[exp + poly[j].exp] += coe * poly[j].coe;
		}
	}
	int count = 0;
	for (int i = 0;i < 2002; i++){
		if (result[i]  != 0) count++;
	}
	printf ("%d",count);

	for (int i = 2001; i >= 0; i--){
		if (result[i] != 0)
			printf(" %d %.1lf",i,result[i]);
	}
	return 	0;
}
