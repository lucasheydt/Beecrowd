#include <stdio.h>

int main() {
    int n=1;

    while (n) {
        scanf("%d", &n);
        if (n == 0) break;

        int cartas[51];
        int  base = 1;
        for (int i = 1; i <= n; i++) {
            cartas[i] = i;
        }
        int dpsprimeira =0;
        printf("Discarded cards:");
        while(base!=n&&n!=1){
            if (dpsprimeira) {
                printf(", %d", cartas[base]);
            }else{
                dpsprimeira = 1;
                printf(" %d", cartas[base]);
            }
            base++;
            int temp = cartas[base];
            for (int i = base; i < n; i++)
            {
                cartas[i]=cartas[i+1];
            }
            cartas[n]= temp;
        }
        printf("\nRemaining card: %d\n", cartas[base]);
        
    }
    
    return 0;
}
