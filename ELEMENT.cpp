#include "ELEMENT.h"
#include <stdio.h>
#include <stdlib.h>


#define ENDWERT 37		//ELEMENT ALLOCATION LIMITERS
#define STARTWERT 1		
#define REF 2			//ELEMENT'S OBJECT VALUE the calculation of surrounding ELEMENTS is meant for 


int main() {
	ELEMENT* hex_arr;					//DEFINITION OF AN ELEMENT_OBJECT (CONSTRUCTOR IN C++)
	int ergebnis;
	hex_arr = alloc_hex_arr(ENDWERT);			//ALLOCATION 
	init_hex_arr(hex_arr,ENDWERT);				//INITIALATION

	ergebnis = prodBYnode((unsigned int)ECKEN_ANZAHL, (&hex_arr[REF]->node));	//OUTPUT SOLUTION EITHER BY prodBYnode() or prodBYvector() func
	printf("Produkt_Umkreis von Element %d = %d\n",REF, ergebnis);
	
	return 0;
}
