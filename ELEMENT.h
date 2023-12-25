
#define ECKEN_ANZAHL 6    //SHOULD NOT BE CHANGED SINCE SPECIAL CASE (ECKEN_ANZAHL(number of corners) = NUMBER OF POSSIBLE ALIGNING NEIGHBOUR ELEMENT_OBJECT


#include <stdlib.h>


// IMPLEMENTATION OF A COMPLEX KOORDINATE SYSTEM
typedef struct hexfeld {						//DEFINITION OF AN ELEMENT OBJECT OF A HEX ARRAY
	
	unsigned int wert_ID,abs;					//ELEMENT OBJECT ABSOLUTE(-VALUE) IN COMPLEX COORDINATE SYSTEM
	float cplx_exp;
	struct hexfeld* node[ECKEN_ANZAHL];				//DEFINING N-POINTER AT SURROUNDING AND ALIGNING ELEMENTS, DEPENDING ON NUMBER OF CORNERS OF ELEMENT OBJECT   
  	}ELEMENT;

inline ELEMENT* alloc_hex_arr(unsigned int endwert) {			//ALLOCATION OF ELEMENT OBJECTS

	return (ELEMENT*)malloc(sizeof ELEMENT * endwert);
}
inline void init_hex_arr(ELEMENT* hex_arr, unsigned int endwert){	//ITERATIV INITIALIZATION AND CALCULATION OF EACH STRUCT MEMBERS

	int i=1;
	
	hex_arr->wert_ID = i;
	hex_arr->cplx_exp = 0;
	(hex_arr++)->abs = 0;						 //SPECIAL CASE FOR FIRST ELEMENT =i =1 (Point of Origin)
	
	for (unsigned int n = 1, j =0 ; i <= endwert; ++i,j++, hex_arr++) {		//
		(hex_arr)->wert_ID = i;
		
		(hex_arr)->abs = n;		
		(hex_arr)->cplx_exp =(float)(360/(ECKEN_ANZAHL*n)*j);			//CALCULATING COMPLEX EXPONENTIAL VALUE MULTIPLIED BY ANGLE FACTOR j
		if(i==eor(n)){								//TESTING THE CONDITION IF ITERATIV INITIALIZATION HAS REACHED END OF CURRENT RING 			
			j=0;								//THUS SETTING ANGLE FACTOR BACK TO ZERO
			n++;								//AND INCREMENTING THE ABS VALUE WHICH INDICATES THE NEXT RING
			}	
		}

	/*STILL IN WORK...	


inline void link_hex_arr(ELEMENT* hex_arr, unsigned int endwert){	//ITERATIV FILLING AND LINKING ALLOCATED ELEMENT OBJECTS NODES WITH EACH CORRESPONDING ALIGNING NEIGHBOUR ACCORDING TO GRAPHIC  
	for(int i =0 ; i<ECKEN_ANZAHL; i++)
 		hex_arr->node[i] = hex_arr+i;
   
 		hex_arr->wert_ID = 1;
   		hex_arr++;
 	for ( i = 2; i <= endwert; i++) {
		(hex_arr++)->wert_ID = i;
		for (int j = 0; j < ECKEN_ANZAHL; j++) 
			 //hex_arr->node[j] = hex_arr + ((sizeof ELEMENT) / sizeof(char)) * (j + 1) + (hex_arr->ring)*ECKEN_ANZAHL; //hex_arr+1
			
				switch(j){
				 case 0:	 hex_arr->node[j] = hex_arr + (hex_arr->abs)*ECKEN_ANZAHL;  
					break;
				 case 1:	 hex_arr->node[j] = hex_arr + vector(hex_arr,hex_arr->abs+1, hex_arr->cplx_exp)- hex_arr->wert_ID ;
					break;
				 case 2:	 hex_arr->node[j] = hex_arr + 1;
					break;
				 case 3:	 hex_arr->node[j] = hex_arr - 1; 
					break;
				 case 4:	 hex_arr->node[j] = hex_arr + (hex_arr->abs)*ECKEN_ANZAHL-1; 
					break;
				 case 5:	 hex_arr->node[j] = hex_arr + eor((hex_arr->abs)+1)-(hex_arr->wert_ID) ;
					 break;
				}
			*/

inline unsigned int prodBYnode(unsigned int anzahl_nodes, ELEMENT* hex_element) {	//ITERATIV CALCULATION OF PRODUCT OF SURROUNDING ELEMENT OBJECT VALUES 
	int produkt = 1;
	for (unsigned int i = 0; i < anzahl_nodes; i++)
		produkt *= hex_element->node[i]->wert_ID;
	return produkt;
}


/*unsigned int prodBYvector(unsigned int ref, ELEMENT* hex_element){
	unsigned int produkt = 1;
	
	for(;hex_arr->wert_ID != ref ; hex_arr++){}
	vector(hex_arr, hex_arr->abs+1, hex_arr->)

	
	return produkt;
}*/



unsigned int eor(unsigned int n){				
	unsigned int eor = 1;					//ITERATIV CALCULATION OF END OF RING 
	for(int lv =1  ; lv<=n; lv++)				// EOR = SIG(upper limit = n|lower limit=n=1) n*ECKEN_ANZAHL
	eor+=lv*ECKEN_ANZAHL;
	return eor;

}


ELEMENT* vector(ELEMENT* hex_arr, int abs, int cplx_exp){			//COMPUTATION OF COMPLEX OFFSET VEKTOR
	for(;hex_arr->abs != abs && hex_arr->cplx_exp != cplx_exp; hex_arr++){}	//ITERATE THROUGH COORDINATE SYSTEM ARRAY UNTIL COMPLEX VEKTOR IS FOUND, ACCORDING TO PARAMETERS 
	return hex_arr;
}
