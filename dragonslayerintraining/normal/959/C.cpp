#include <cstdio>

int main(){
  int N;
  scanf("%d",&N);
  if(N<6){
    printf("-1\n");
  }else{
    printf("1 2\n");
    printf("1 3\n");
    printf("1 4\n");
    for(int i=5;i<=N;i++){
      printf("2 %d\n",i);
    }
  }
  for(int i=1;i<N;i++){
    printf("%d %d\n",i,i+1);
  }
  return 0;
}