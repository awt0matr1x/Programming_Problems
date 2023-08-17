#include "ELEMENT.h"
#include <stdio.h>
#include <stdlib.h>
#include "ELEMENT.h"


#define ENDWERT 37
#define STARTWERT 1
#define REF 2


int main() {
	ELEMENT* hex_arr;
	int ergebnis;
	hex_arr = alloc_hex_arr(ENDWERT);
	init_hex_arr(hex_arr,ENDWERT);

	ergebnis = prod(ECKEN_ANZAHL, *(hex_arr+REF)->node);
	printf("Produkt_Umkreis von Element %d = %d\n",REF, ergebnis);
	
	return 0;
}
