YinYang-Puzzle-Verifier-C This C program serves as a verifier for Yin Yang puzzles, specifically designed for 4x4 matrices. The process involves converting a decimal input to its binary representation, segmenting the binary string into sets representing emptiness and color, constructing a matrix based on a predetermined order, and subsequently checking the matrix against predefined rules.

Usage Input: Obtain a decimal number from the user. Conversion: Convert the decimal number to its binary representation. Segmentation: Split the binary string into sets representing emptiness and color. Matrix Construction: Create a 4x4 matrix following a specific order based on the binary sets. Rule Verification: Check the matrix against predefined rules to determine if it qualifies as a Yin Yang puzzle solution. How It Works Decimal to Binary Conversion: The program utilizes a function to convert a decimal number to a 32-bit binary string.

Matrix Construction: A 4x4 matrix is created by following a predefined order and considering the binary sets for emptiness and color.

Rule Verification: The program checks the constructed matrix against two rules:

Rule 1: Ensures that each 2x2 cell in the matrix does not consist of just one character. Rule 2: Validates that black and white cells are connected by horizontal or vertical neighbors.

test example : 
Enter a decimal number: 123 
Binary representation: 00000000000000000000000001111011 
Emptyness: 01111011 
Color: 00000000

4x4 Matrix: 
e e e e
e b e e
b e e e
e e e e

Result: Not Yin Yang
