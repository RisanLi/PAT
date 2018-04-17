#include <cstdio>
#include <queue>
using namespace std;
int M, N, L, T;
int pixel[1290][130][70];
bool inq[1290][130][70] = {};
int ans = 0;
int X[] = {0, 0, 0, 0, -1, 1};
int Y[] = {0, 0, -1, 1, 0, 0};
int Z[] = {-1, 1, 0, 0, 0, 0};

struct Node{
	int x, y, z;
};

bool available(int x, int y, int z){
	// 不能越界
	if (x >= M || x < 0 || y >=N || y < 0 || z >= L || z < 0)
		return false;
	if (inq[x][y][z] || pixel[x][y][z] == 0)
		return false;
	return true;
}

int BFS(int x, int y, int z){
	int cnt = 0;
	queue<Node> q;
	Node node;
	node.x = x;
	node.y = y;
	node.z = z;
	q.push(node);
	inq[x][y][z] = true;
	while (!q.empty()){
		Node top = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < 6; i++){
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			if (available(newX, newY, newZ)){
				Node temp;
				temp.x = newX;
				temp.y = newY;
				temp.z = newZ;
				q.push(temp);
				inq[newX][newY][newZ] = true;
			}
		}
	}
	return cnt >= T ? cnt : 0;
}

int main(){
	scanf ("%d%d%d%d", &M, &N, &L, &T);
	for (int z = 0; z < L; z++){
		for (int x = 0; x < M; x++){
			for (int y = 0; y < N; y++){
				scanf ("%d",&pixel[x][y][z]);
			}
		}
	}
	for (int z = 0; z < L; z++){
		for (int x = 0; x < M; x++){
			for (int y = 0; y < N; y++){
				if (pixel[x][y][z] == 1 && !inq[x][y][z])
					ans += BFS(x,y,z);
			}
		}	
	}
	printf ("%d\n",ans);
}
