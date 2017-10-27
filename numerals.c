
#include <string.h>
#include <stdio.h>
#include "numerals.h"


int IntValueOf(char numeral){

	switch(numeral){

		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
	}

	return 0;
}
