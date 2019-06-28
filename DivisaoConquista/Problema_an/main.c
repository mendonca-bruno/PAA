#include <stdio.h>
#include <stdlib.h>

int calcula(int a, int n){
    if (n==0) return 1;    
    double res;
    double calc = calcula(a,n/2);
    res = calc*calc;
    if(n%2==1){
        res = a*calc;
    }
    return res;
    
}

int main(){
    int a,n;
    scanf("%d", &a);
    scanf("%d", &n);
    printf("%d", calcula(a,n));
    
    return 0;
}