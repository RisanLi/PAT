#include <cstdio>
#include <cstring>
class BigNumber{
	public :int bit[1010];
	public :int length;
	public :BigNumber(){
		memset(bit,0,sizeof(bit));
		this->length = 0;
	}
};

int main(){
	char str[1010];
	int division;
	scanf("%s%d",str,&division);
	BigNumber *t = new BigNumber();
	BigNumber *c = new BigNumber();

	t->length = strlen(str);
	for (int i = 0; i < t->length; i++){
		t->bit[i] = str[i] - '0';
	}
//	printf ("存储结果为 ");
//	for (int i = 0; i < t->length; i++){
//		printf ("%d",t->bit[i]);
//	}
//	printf ("\n");
	int rest = 0, quotient = 0;
	for (int i = 0; i < t->length; i++){
		quotient = (rest * 10 + t->bit[i]) / division;
		rest = (rest * 10 + t->bit[i]) % division;
		c->bit[c->length++] = quotient;
	}
	if (c->length == 0){
		printf ("0 %d\n",division);
		return 0;
	}
	if (c->length == 1){
		printf("%d %d\n",t->bit[0] / division, t->bit[0] % division);
		return 0;
	}
	for (int i = 0; i < c->length; i++){
		if (c->bit[i] == 0 && i == 0) continue; 
		printf("%d",c->bit[i]);
	}
	printf (" %d",rest);
	return 0;
}
