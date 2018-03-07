#include <cstdio>

int  main (){
	
	int n;
	scanf ("%d",&n);
	bool judge[10];

	long long A, B, C;
	long long temp;
	for (int i = 0; i < n; i++){
		scanf("%lld%lld%lld", &A, &B, &C);
		temp = A + B;
		if ( A > 0 && B > 0 && temp < 0)
			judge[i] = true;
		else if (A < 0 && B < 0 && temp >= 0){
			judge[i] = false;
		}
		else if (A + B > C)
			judge[i] = true;
		else 
			judge[i] = false;
	}
	for (int i = 0; i <n ; i++){
		printf("Case #%d: ", i+1);
		if (judge[i] ) printf("true\n");
		else printf ("false\n");
	}

	return 0;
}
