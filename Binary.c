//Mustafa Ali Mohammed 1002214199
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define BITS 8

void PrintOutput(int numf, char operator[], int nums, int result);
void ConvertDecimalToBinary(int decimal, char binary[]);


int main() 
{
            
    long int upperLimit = (long int)pow(2, BITS) - 1;
    printf("Bitwise Calculator\n");
    printf("\n");
    printf("Enter two base 10 values with a bitwise operator to see the decimal result\n");
    printf("and the binary result. The format is\n");
    printf("\n");
    printf("FirstNumber BitwiseOperator SecondNumber\n");
    printf("\n");
    printf("For example, enter the expression\n");
    printf("\n");
    printf("2 | 3\n");
    printf("\n");
    printf("This calculator can used with &, |, ^, << and >>\n");
    printf("\n");
    printf("Please note that the spaces between numbers and operator is essential\n");
    printf("and the two entered values must be between 0 and %ld.\n", upperLimit);
    printf("\n");
    int numf, nums;
    int result = 0;
    char operator[3] = {};
    
    printf("Enter expression ");
    scanf("%d %s %d", &numf, operator, &nums);
    printf("\n");
    
    while (numf < 0 || numf > upperLimit || nums < 0 || nums > upperLimit) 
    {
        printf("The entered expression contains out of range values.\n");
        printf("Please enter values between 0 and %ld only.\n", upperLimit);
        printf("\n");
        printf("Enter expression ");   
        scanf("%d %s %d", &numf, operator, &nums);
        printf("\n");
        
    }
    
    
    
    
    switch (operator[0]) 
    {
        case '&':
            result = numf & nums;
            PrintOutput(numf, operator, nums, result);
            break;
        case '|':
            result = numf | nums;
            PrintOutput(numf, operator, nums, result);
            break;
        case '^':
            result =  numf ^ nums;
            PrintOutput(numf, operator, nums, result);
            break;
        case '<':
            result = numf << nums;
            PrintOutput(numf, operator, nums, result);
            break;
        case '>':
            result = numf >>  nums;
            PrintOutput(numf, operator, nums, result);
            break;
        default:
            printf("Operator %s is not supported by this calculator.\n", operator);
            break;
            
    }
    
    
}

void PrintOutput(int numf, char operator[], int nums, int result) 
{
    char base1[BITS + 1] = {};
    char base2[BITS + 1] = {};
    char baseresult[BITS + 1] = {};
    
    ConvertDecimalToBinary(numf, base1);
    ConvertDecimalToBinary(nums, base2);
    ConvertDecimalToBinary(result, baseresult);
    printf("\nIn base 10...\n");
    printf("\n");
    printf("%d %s %d = %d\n", numf, operator, nums, result);
    printf("\n");
    printf("\nIn %d-bit base 2...\n", BITS);
    printf("\n");
    printf("    %s\n", base1);
    printf("%s\n", operator);
    printf("    %s\n", base2);
    printf("    ========\n");
    printf("    %s\n", baseresult);
}

void ConvertDecimalToBinary(int decimal, char binary[]) 
{
	
    int temp[BITS] = {};
    int placeH = decimal;
    
    for (int i = BITS - 1; i >= 0; i--) 
    {
        temp[i] = placeH & 1;  
        placeH = placeH >>  1;    
    }
    
    for (int i = 0; i < BITS; i++) 
    {
        binary[i] = temp[i] + '0'; 
    }
    binary[BITS] = '\0';  
}
	
