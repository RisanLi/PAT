#include <cstdio>

int convertToKnut(int Galleon, int Sickle, int Knut){
	return Galleon*17*29+Sickle*29+Knut;
}

int main(){
	//p代表应付 a代表实付
	int pGalleon, aGalleon;		
	int pSickle, aSickle;
	int pKnut, aKnut;

	scanf("%d.%d.%d %d.%d.%d",&pGalleon, &pSickle, &pKnut,
			&aGalleon, &aSickle, &aKnut);
	int p = convertToKnut(pGalleon,pSickle,pKnut);
	int a = convertToKnut(aGalleon,aSickle,aKnut);

	int difference = a - p;

	if (difference < 0){
		printf("-");
		difference *= -1;
	}
	int Galleon = difference / (29*17);
	int Sickle = (difference - Galleon * 29 * 17) / 29;
	int Knut = difference - Galleon * 29 * 17 -Sickle * 29;

	printf("%d.%d.%d",Galleon,Sickle,Knut);


}
