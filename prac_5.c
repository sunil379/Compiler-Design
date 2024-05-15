#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

bool parse_E(char *input, int *index);
bool parse_EE(char *input, int *index);

bool parse_E(char *input, int *index) {
    if (input[*index] == 'a' || input[*index] == 'b') {
        (*index)++;
        return true;
    }
    else if (input[*index] == '+' || input[*index] == '-') {
        (*index)++;
        return parse_E(input, index) && parse_EE(input, index);
    }
    else if (input[*index] == '\0') {
        return true; // End of input string reached
    }
    else {
        return false;
    }
}


bool parse_EE(char *input, int *index) {
    if (input[*index] == '+' || input[*index] == '-') {
        (*index)++;
        return parse_E(input, index);
    }
    else if (input[*index] == '\0') {
        return true; // End of input string reached
    }
    else {
        return false;
    }
}


int main() {
    char input[100];
    int index = 0;
    
    printf("Enter an input string:\n");
    scanf("%99s", input);
    
    bool success = parse_E(input, &index);
    
    if (success && input[index] == '\0') {
        printf("The input string can be accepted using the grammar.\n");
    } else {
        printf("The input string cannot be accepted by the grammar.\n");
    }
    
    return 0;
}
