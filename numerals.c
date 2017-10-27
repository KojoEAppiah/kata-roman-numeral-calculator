
#include <string.h>
#include <stdlib.h>
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


char* IntegerToNumeral(int integer){

	char *numeral = malloc(sizeof(char)*100);
	int cursor = 0;

	while(integer > 0){

		if(integer >= 900){
			if(integer >= 1000){
				numeral[cursor++] = 'M';
				integer -= 1000;
			}
			else{
				numeral[cursor++] = 'C';
				numeral[cursor++] = 'M';
				integer -= 900;
			}
		}
		else if(integer >= 400){
			if(integer >= 500){
				numeral[cursor++] = 'D';
				integer -= 500;
			}
			else{
				numeral[cursor++] = 'C';
				numeral[cursor++] = 'D';
				integer -= 400;
			}
		}
		else if(integer >= 90){
			if(integer >= 100){
				numeral[cursor++] = 'C';
				integer -= 100;
			}
			else{
				numeral[cursor++] = 'X';
				numeral[cursor++] = 'C';
				integer -= 90;
			}
		}
		else if(integer >= 40){
			if(integer >= 50){
				numeral[cursor++] = 'L';
				integer -= 50;
			}
			else{
				numeral[cursor++] = 'X';
				numeral[cursor++] = 'L';
				integer -= 40;
			}
		}
		else if(integer >= 9){
			if(integer >= 10){
				numeral[cursor++] = 'X';
				integer -= 10;
			}
			else{
				numeral[cursor++] = 'I';
				numeral[cursor++] = 'X';
				integer -= 90;
			}
		}
		else if(integer >= 4){
			if(integer >= 5){
				numeral[cursor++] = 'V';
				integer -= 5;
			}
			else{
				numeral[cursor++] = 'I';
				numeral[cursor++] = 'V';
				integer -= 4;
			}
		}
		else{
		
			numeral[cursor++] = 'I';
			integer--;
		}
	}

	numeral[cursor] = '\0';

	return numeral;
}