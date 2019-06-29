#include <stdio.h>
#include <stdlib.h>

int *calculaMaiorMenor(int *vetor, int n, int inicio, int fim)
{
    int *temp;
    if(n==2){

        temp = (int *) malloc (2 * sizeof(int));
        if(vetor[inicio]>vetor[fim]){
            temp[0] = vetor[inicio];
            temp[1] = vetor[fim];
        }else{
            temp[0] = vetor[fim];
            temp[1] = vetor[inicio];
        }
    }else{
        temp = (int *) malloc (2 * sizeof(int));
        int meio = (inicio+fim)/2;
        int*esq,*dir;
        int qtd;
    
        if(n%2==0){
            qtd = ((fim-inicio)+1)/2;
            esq = calculaMaiorMenor(vetor, qtd,inicio,meio);
            dir = calculaMaiorMenor(vetor, qtd, meio+1,fim);
        }else{
            qtd = (((fim-inicio)+1)/2)+1;
            esq = calculaMaiorMenor(vetor, qtd,inicio,meio);
            dir = calculaMaiorMenor(vetor, qtd, meio,fim);
        }
                
        if(esq[0]>dir[0]) temp[0] = esq[0];
        else temp[0] = dir[0];
        if(esq[1]<dir[1]) temp[1] = esq[1];
        else temp[1] = dir[1];
       free(esq);
       free(dir);  
        
    }
    
    return temp;
}


int main(){
    int out;
    int inicio = 0;
    int qtd;
    int min,max,aleatorio;
    printf("Digite o tamanho do vetor:");
    scanf("%d", &qtd);
    printf("\n");
    int vetor[qtd];
    for(int i=0; i<qtd; i++){
        printf("Digite um numero: ");
        scanf("%d", &vetor[i]);
    }
    int fim = qtd-1;
    int *res = calculaMaiorMenor(vetor,qtd,inicio,fim);
    printf("Maior(%d)\nMenor(%d)", res[0],res[1]);
    scanf("\n%d", &out);
    return 0;
}