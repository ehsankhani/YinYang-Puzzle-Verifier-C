#include <stdio.h>

void decimalToBinary(int decimal, char binaryStr[]);

int checkRules(char matrix[4][4]);

int main() {
    int decimalNumber;
    char binaryString[33];  // 32 bits for binary representation + 1 for null-termination

    // Get input from the user
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Convert decimal to binary
    decimalToBinary(decimalNumber, binaryString);

    // Display the full binary representation
    printf("Binary representation: %s\n", binaryString);

    // Split the binary number into two sets: emptyness and color
    char emptyness[17], color[17];
    for (int i = 0; i < 16; i++) {
        color[i] = binaryString[i];
        emptyness[i] = binaryString[i + 16];
    }
    emptyness[16] = color[16] = '\0';  // Null-terminate the strings

    // Display the split sets
    printf("Emptyness: %s\n", emptyness);
    printf("Color: %s\n", color);

    // Create a 4x4 matrix based on the specified order
    char matrix[4][4];

    int sequence[16] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int index = sequence[i * 4 + j];
            if (emptyness[index] == '1') {
                if(color[index] == '1'){
                    matrix[i][j] = 'w';
                } else{
                    matrix[i][j] = 'b';
                }
            } else{
                matrix[i][j] = 'e';
            }
        }
    }

    // Display the matrix
    printf("4x4 Matrix:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    // Check rules and print result
    if (checkRules(matrix)) {
        printf("Yin Yang\n");
    } else {
        printf("Not Yin Yang\n");
    }

    return 0;
}

void decimalToBinary(int decimal, char binaryStr[]) {
    for (int i = 31; i >= 0; i--) {
        binaryStr[i] = (decimal & 1) + '0';
        decimal >>= 1;
    }
    binaryStr[32] = '\0';  // Null-terminate the string
}

int checkRules(char matrix[4][4]) {
    // Rule 1: Each 2*2 cells must not have just one character
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == matrix[i + 1][j] &&
                matrix[i][j] == matrix[i][j + 1] &&
                matrix[i][j] == matrix[i + 1][j + 1]) {
                return 0; // Rule 1 violated
            }
        }
    }

    // Rule 2: Black and white must be connected by horizontal or vertical neighbors
    int bwConnected = 0;
    for (int i = 0; i < 4 && !bwConnected; i++) {
        for (int j = 0; j < 4 && !bwConnected; j++) {
            if (matrix[i][j] == 'b') {
                // Check if there's a horizontal or vertical neighbor with 'w'
                if ((i < 3 && matrix[i + 1][j] == 'w') || (j < 3 && matrix[i][j + 1] == 'w')) {
                    bwConnected = 1; // Rule 2 satisfied
                }
            } else if (matrix[i][j] == 'w') {
                // Check if there's a horizontal or vertical neighbor with 'b'
                if ((i < 3 && matrix[i + 1][j] == 'b') || (j < 3 && matrix[i][j + 1] == 'b')) {
                    bwConnected = 1; // Rule 2 satisfied
                }
            }
        }
    }

    return bwConnected; // Return the result of Rule 2 check
}
