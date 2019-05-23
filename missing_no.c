#include<stdio.h>
#include<stdlib.h>

int sum_total(int a) {
    return (a * (a + 1))/2;
}

int sum_element(int *p, int l) {
    int i, sum=0;
    for(i = 0; i < l ; i++) {
        sum += p[i];
        // printf("%d\n", sum);
    }
    return sum;
}

void main() {
    int i, n, Esum, Tsum, k=0, j=0;
    scanf("%d", &n);
    int *q = (int *)malloc(n * sizeof(int));
    while(n>0) {
        j = 0;
        scanf("%d", &i);
        printf("INPUT SIZE %d\n", i);
        Tsum = sum_total(i);
        
        // printf("%d\n", Tsum); //DEBUG
        
        int *p = (int *)malloc((i-1) * sizeof(int));
        while( j!= i && scanf("%d", &p[j++]) == 1);
        Esum = sum_element(p, i-1);
        
        // printf("%d\n", Esum); //DEBUG
        
        q[k++] = Tsum - Esum; //ANSWER
        // printf("%d\n", q[k-1]);  //DEBUG
        n --;
        free(p);
    }
    for(i = 0; i < k; i++) {
        printf("%d\n", q[i]);
    }
}
