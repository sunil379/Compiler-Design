#include <stdio.h> 

#include <stdbool.h> 

#include <stdlib.h> 

#include <string.h> 

#define MAX_CODE_LINES 100 

#define MAX_CODE_LENGTH 50 

// Structure to represent a three-address code line 

typedef struct { 

 char op; // OperaƟon: '+', '-', '*', '/' 

 int result; // Result variable index 

 int arg1; // Argument 1 variable index or constant value 

 int arg2; // Argument 2 variable index or constant value 

} ThreeAddressCode; 

ThreeAddressCode code[MAX_CODE_LINES]; // Array to store three-address code lines 

int codeCount = 0; // Current count of code lines 

// FuncƟon to add a three-address code line to the array 

void addCodeLine(char op, int result, int arg1, int arg2) { 

 code[codeCount].op = op; 

 code[codeCount].result = result; 

 code[codeCount].arg1 = arg1; 

 code[codeCount].arg2 = arg2; 

 codeCount++; 

} 

// FuncƟon to perform basic opƟmizaƟons on three-address code 

void opƟmizeCode() {

 for (int i = 0; i < codeCount; i++) { 

 // Check if both arguments are constants 

 if (code[i].arg1 >= 0 && code[i].arg2 >= 0) { 

 // Perform constant folding 

 int value; 

 switch (code[i].op) { 

 case '+': 

 value = code[i].arg1 + code[i].arg2; 

 break; 

 case '-': 

 value = code[i].arg1 - code[i].arg2; 

 break; 

 case '*': 

 value = code[i].arg1 * code[i].arg2; 

 break; 

 case '/': 

 value = code[i].arg1 / code[i].arg2; 

 break; 

 } 

 // Replace the current line with a simplified assignment if applicable 

 code[i].op = '='; 

 code[i].arg1 = value;
code[i].arg2 = -1; // No need for a second argument in an assignment

 }

 }

}

// FuncƟon to print the opƟmized three-address code

void printOpƟmizedCode() {

 for (int i = 0; i < codeCount; i++) {

 if (code[i].op == '=') {

 prinƞ("t%d = %d\n", code[i].result, code[i].arg1);

 } else {

 prinƞ("t%d = t%d %c t%d\n", code[i].result, code[i].arg1, code[i].op, code[i].arg2);

 }

 }

}

int main() {

 // Example three-address code

 addCodeLine('+', 1, 2, 3);

 addCodeLine('*', 4, 1, 2);

 addCodeLine('-', 5, 4, 3);

 addCodeLine('*', 6, 5, 6);

 prinƞ("Original three-address code:\n");

 printOpƟmizedCode();

 prinƞ("\nOpƟmized three-address code:\n");

 opƟmizeCode();

 printOpƟmizedCode();

 return 0;

}
