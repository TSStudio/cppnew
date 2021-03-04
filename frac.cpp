#include<cstdio>
#include<cstring>
#include"frac.h"
int main(){
    fraction a(1,3),b(-1,2);
    a=a+b;//-1 6
    fraction c=a*fraction(1,5);//-1 30
    printf("%s%llu/%llu,%llu/%llu\n",a.getsig(),a.numerator,a.denominator,c.numerator,c.denominator);
    printf("%d",c>a);//1
    getchar();
}