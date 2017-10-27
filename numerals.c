
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
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
	}

	return 0;
}


int NumeralToInteger(char* numeral){

	int numeral_length = strlen(numeral);
	int cursor = numeral_length - 1;
	int value = 0;
	int subtract = 0;

	while(cursor >= 0){
		if(cursor == numeral_length-1){
			value += IntValueOf(numeral[cursor]);
		}
		else{
			if(IntValueOf(numeral[cursor]) < IntValueOf(numeral[cursor+1])){
				subtract = 1;
			}
			if(IntValueOf(numeral[cursor]) > IntValueOf(numeral[cursor+1])){
				subtract = 0;
			}

			value += (subtract==1)?-IntValueOf(numeral[cursor]):IntValueOf(numeral[cursor]);
		}

		cursor--;
	}

	return value;
}