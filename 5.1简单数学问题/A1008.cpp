#include <cstdio>
int main(){
	int now = 0, next;
	int n;
	scanf ("%d",&n);
	int tot = 0;
	for (int i = 0; i < n; i++){
		scanf ("%d",&next);
		if (next > now){
			tot += (next - now) * 6;
		}
		else {
			tot += (now - next) * 4;
		}
		tot += 5;

		now = next;
	}
	printf ("%d",tot);

	return 0;
}
