#include<stdio.h>
int main(){
    int n = 5;
    int pad  = ~(-1<<4);
    int a = n & pad;
    int b = n & (pad<<4);
    int c = (a>>4)|(b<<4);
    printf("%d",c);
    return 0;

    // return ((n&~(-1<<4)<<4)|((n&~(-1<<4)<<4)>>4));
}
