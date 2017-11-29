#include <stdio.h>

#define MAX 200000

int naoEhPrimo(int numero) {

	if (numero <= 1) return 1;

	for(int i=2; i*i <= numero; i++){
		if (numero % i == 0) return 1;
	}
	
	return 0;
}

int main() {

	int n, naoPrimos[MAX], nNaoPrimos = 0;
	
	do {
		scanf("%d", &n);
		if ((n>0) && naoEhPrimo(n)) {
			naoPrimos[nNaoPrimos] = n;
			nNaoPrimos++;
		}
	} while (n > 0);
	

	for(int i=0; i < nNaoPrimos; i++) {
       for(int j=1; j < nNaoPrimos-i; j++) {
           if (naoPrimos[j - 1] < naoPrimos[j]) {
               int tmp = naoPrimos[j];
               naoPrimos[j] = naoPrimos[j - 1];
               naoPrimos[j - 1] = tmp;
           }
        }
 	}
	
	for(int i=0; i < nNaoPrimos; i++) {
		printf("%d\n", naoPrimos[i]);
	}

    return 0;
}