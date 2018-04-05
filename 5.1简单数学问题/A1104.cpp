#include <cstdio>
int main(){
	int n;
	double arr[100010];
	scanf ("%d",&n);
	for (int i = 0; i < n; i++){
		scanf ("%lf",&arr[i]);
	}
	double tot = 0;
	for (int i = 0; i < n; i++){
		tot += arr[i] * (n - i) * (i + 1);
	}
	printf ("%.2lf",tot);
	return 0;
}
