#include <cstdio>


int main (){
	int aGalleon,aSickle,aKnut;
	int bGalleon,bSickle,bKnut;
	
	scanf("%d.%d.%d",&aGalleon,&aSickle,&aKnut);
	scanf("%d.%d.%d",&bGalleon,&bSickle,&bKnut);
	
	int Knut = aKnut + bKnut;
	int Sickle = aSickle + bSickle + Knut / 29;
	int Galleon = aGalleon + bGalleon + Sickle / 17;
	Knut %= 29;
	Sickle %= 17;

	printf("%d.%d.%d",Galleon,Sickle,Knut);

	return 0;
}
