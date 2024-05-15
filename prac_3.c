#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    char num[20];
    int decimal = 0;
    printf("Enter an integer constant (in decimal, octal, or hexadecimal format): ");
    scanf("%s", num);

    int is_negative = 0;
    if (num[0] == '-') {
        is_negative = 1;
        memmove(num, num+1, strlen(num)+1); // Include null terminator
    }

    int base = 10;
    if (num[0] == '0') {
        if (num[1] == 'x' || num[1] == 'X') {
            base = 16;
            memmove(num, num+2, strlen(num)+1); // Include null terminator
        } else {
            base = 8;
            memmove(num, num+1, strlen(num)+1); // Include null terminator
        }
    }

    int i = 0;
    while (num[i] != '\0') {
        int digit;
        if (isdigit(num[i])) {
            digit = num[i] - '0';
        } else if (isalpha(num[i])) {
            digit = toupper(num[i]) - 'A' + 10;
        } else {
            printf("Invalid character: %c\n", num[i]);
            return 1;
        }
        if (digit >= base) {
            printf("Invalid digit for base %d: %c\n", base, num[i]);
            return 1;
        }
        decimal = decimal * base + digit;
        i++;
    }

    if (is_negative) {
        decimal = -decimal;
    }
    printf("The decimal equivalent of %s is %d\n", num, decimal);

    return 0;
}
