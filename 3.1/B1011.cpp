#include <cstdio>

int main(){
  int n;//测试用例
  scanf("%d",&n);
  
  long long array[10][3];
  for (int i = 0; i < n; i++){
    scanf("%lld",&array[i][0]);
    scanf("%lld",&array[i][1]);
    scanf("%lld",&array[i][2]);
  }
  for (int i = 0; i < n; i++){
    ((array[i][0]+array[i][1])>array[i][2])?printf("Case #%d: true\n",i)
      :printf("Case #%d: false\n",i);
  }
  return 0;
}
