/*
========================================================================================================================
 Name:		assign1.c
 Author:	Khalid Dahir.
 Description:	 Demonstrates:
 		How to write C programs that collect input from the user, and display output on the terminal.
 		How to use bitwise operations to minimize memory footprint.
========================================================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define max_length 4
#define nthbit_index 2

void display_charcter(char results);
void display_decimal(char results);
void display_binary(char results);
int main(){
	char answer[max_length];//declaring char array of length 4. this graps the three letters that the user enter and null character
	printf("Can you please input a the 3 sequence character? ");
	scanf("%s", answer);//anwer stores the user input
	
	char binChar = 0b00000000; //The ACD variable that stores permissions.	
	int n = 0;//declaring the nth bit to the set and initializing it at the zero index position
	//we need to store the data in an efficient way, we can do this by using zero and ones
 	//where y represents 1 and n represents 0. we use bit shifting models to set the nth bits.
 	for (int i = nthbit_index; i >= 0; i--){
		if(answer[i] == 'y'){
			//printf("i am here \n");
			binChar = binChar | (1 << n);//setting the nth bit to 1
			n++;
			
		}else if(answer[i] == 'n'){
			binChar = binChar | (0 << n);//setting nth bit to zero
			n++;
		}else{
			printf("Invalid input \n");
			exit(0);
		}	 
  	 }
	//function call while passing the answer array type char.
	display_character(binChar);
	display_decimal(binChar);
	display_binary(binChar);
		
	return EXIT_SUCCESS;;
}
/*
 *Function: display_character.
 *Description: Demonstrates printing the parameter passed as a character using %c.
 *parameter: 
 *	results: A char variable that contains the user input in the most efficient memory usage.
 
*/
void display_character(char results){
	printf("-------Displaying it in charcter format ----------- \n");
	printf("%c \n", results);
	return;
}

/*
 *Function: display_decimal.
 *Description: Demonstrates printing the parameter passed as a decimal form. 
 *parameter: 
 *	results:  A char variable that contains the user input in the most efficient memory usage.
 
*/
void display_decimal(char results){
	
  	 printf("-------Displaying it in decimal format ----------- \n");
  	 printf("%u \n", results); 	
  	 return;
}

/*
 *Function: display_binary.
 *Description: Demonstrates printing the parameter passed as a binary form by using zero and one. 
 *		where y represents 1 and n represents 0..
 *parameter: 
 *	results:  A char variable that contains the user input in the most efficient memory usage.
 */

void display_binary(char results){
	
	 printf("-------Displaying it in binary format ----------- \n");
	//this loop runs from 2th index to 0th index to seth the bits in binary form. A set of operation is performed 
	//on the results variable passed and it finally prints either 0  or 1.
	for (int i=nthbit_index; i>=0; i--) {
		if ((int)(results/pow(2,i)) > 0) { 
			printf("1");
			results = results - pow(2,i);
		}
		else
			printf("0"); 
	}
	printf("\n");
	return;
	
}

