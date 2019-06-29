#include <stdio.h>
#include <stdlib.h>

int *calculaMaiorMenor(int *s, int n){
    int *temp;
    if(n==2){
        temp = (int *) malloc (2 * sizeof(int));
        if(s[0]>s[1]){
            temp[0] = s[0];
            temp[1] = s[1];
        }else{
            temp[0] = s[1];
            temp[1] = s[0];
        }
    }else{
        temp = calculaMaiorMenor(s,n-1);
        if(s[n-1]>temp[0]) temp[0] = s[n-1];
        if(s[n-1]<temp[1]) temp[1] = s[n-1];
    }
    return temp;
}

int main(){
    int s[4] = {1,2,3,4};
    int *res = calculaMaiorMenor(s,4);
    printf("Maior(%d)\nMenor(%d)", res[0],res[1]);
    return 0;
}