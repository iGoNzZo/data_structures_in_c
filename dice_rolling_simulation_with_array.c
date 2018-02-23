/* Author:Steven Gonzalez SSID: 009387092
 *
 * C program to simulate the rolling of dice 
 * 49C Test2 Problem 6.19.c
 */

#include <stdio.h>
#include <stdlib.h>

//double array declaration to hold frequancy count
double frequancies[11] = {0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0};

//function declarations
void printFrequancies();

//main function 
void main()	{
	//variable declarations
	int diceA;
	int diceB;
	
	//variablle to represent # of rolls
	int rolls;
	for(rolls = 1; rolls <= 36000; rolls++)	{
		diceA = (rand() % 6) + 1;	//diceA roll
		diceB = (rand() % 6) + 1;	//diceB roll
		++frequancies[diceA + diceB - 2];	//increment freaquancy of sums 
	}//end for loop
	
	//print the frequancies of the rolls
	printFrequancies();
} // end main 

//print frequancies function
void printFrequancies()	{
	//loop to print the frequancies table
	printf("\n-Sum Frequancies-\n");	
	int i;
	for(i = 0; i < 11; i++)	{
		if(i < 8)	{ //if statement to control spacing of table
			printf("Sum: %d  | freq: %.2f\n", i + 2, (frequancies[i]/360000)*36);
		}
		else	{	//if statement to controll spacing of table
			printf("Sum: %d | freq: %.2f\n", i + 2, (frequancies[i]/360000)*36);
		} // end if statement
	}
	printf("\n");
}// end printFrequancies function 
