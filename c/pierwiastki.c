#include<stdio.h>
int main(){
float a,b,c;
while(3==scanf("%f %f %f",&a,&b,&c)){
float delta= b*b-(4*c*a);
printf("%d\n", delta>0?2:delta==0?1:0);
}
}
