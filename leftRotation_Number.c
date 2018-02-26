#include<stdio.h>
int main(){
  char a[100];
  int r;
  scanf("%s%d",a,&r);
  for(int i=r;a[i]!='\0';i++){
      printf("%c",a[i]);
  }
  for(int i=0;i<r;i++){
      printf("%c",a[i]);
  }
  return 0;
}

