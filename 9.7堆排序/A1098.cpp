#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
int n;
int m;
int input[maxn];
int heap[maxn];
int result[maxn],result_h[maxn];

bool isEqualInsert(){
	for (int i = 0; i < n; i++){
		if (input[i] != result[i]){
			return false;
		}
	}
	return true;
}

int step_i = 1;
bool isInsert(){
//	printf ("step_i = %d\n",step_i);
	for (step_i; step_i < n; step_i++){
		sort(input,input+step_i+1);
		if (isEqualInsert()){
			step_i++;
			return true;
		}
	}
	return false;
}

void downAdjust(int pos){
	int father = pos;
	int child = father * 2;
	while (child <= n){
		if (child+1 <= n && heap[child] < heap[child+1]){
			child = child + 1;
		}
		if (heap[father] < heap[child]){
			swap(heap[father], heap[child]);
			father = child;
			child = father * 2;
		} else {
			break;
		}
	}
}

bool isEqualHeap(){
	//printf ("heap = \n");			
	//for (int i = 1; i <= m; i++){
	//				if ( i != 1)
	//					printf (" ");
	//				printf ("%d", heap[i]);
	//			}
	//printf ("\n");

	for (int i = 1; i <= m; i++){
		if (heap[i] != result_h[i-1]){
			return false;
		}
	}
	return true;
}
void heapsort(){
	swap(heap[1],heap[n--]);
	downAdjust(1);	
}


int main(){
	scanf ("%d", &n);
	m = n;
	for (int i = 0; i < n; i++){
		scanf ("%d",&input[i]);
		heap[i+1] = input[i];
	}
	for (int i = 0; i < n; i++){
		scanf("%d", &result[i]);
		result_h[i] = result[i];
	}
	if (isInsert()){
		printf ("Insertion Sort\n");
		sort(result,result+step_i+1);
		for (int i = 0; i < n; i++){
			if (i != 0){
				printf(" ");
			}
			printf("%d",result[i]);
		}
	} else {
		for (int i = n / 2; i >= 1; i--){
			downAdjust(i);
		}
		for (int i = 0; i < m; i++){
			if (isEqualHeap()){
				heapsort();
				printf ("Heap Sort\n");
				for (int i = 1; i <= m; i++){
					if ( i != 1)
						printf (" ");
					printf ("%d", heap[i]);
				}
				return 0;
			}
			else
				heapsort();
		}	
	}
	return 0;
}
