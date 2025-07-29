#include <stdio.h>
#include <stdlib.h>
void displayMenu();
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
int main() {
    char choice;
    float num1, num2, result;
    printf("Basic Arithmetic Calculator\n");
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        if (choice == '5') {
            printf("Exiting calculator. Goodbye!\n");
            break;
        }
        if (choice < '1' || choice > '5') {
            printf("Invalid choice! Please try again.\n");
            continue;
        }
        printf("Enter first number: ");
        scanf("%f", &num1);
        printf("Enter second number: ");
        scanf("%f", &num2);       
        switch(choice) {
            case '1':
                result = add(num1, num2);
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case '2':
                result = subtract(num1, num2);
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case '3':
                result = multiply(num1, num2);
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case '4':
                if (num2 != 0) {
                    result = divide(num1, num2);
                    printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                } else {
                    printf("Error: Division by zero is not allowed!\n");
                }
                break;
        }
        
        printf("\n");
    } while (choice != '5');
    
    return 0;
}
void displayMenu() {
    printf("Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
}
float add(float a, float b) {
    return a + b;
}
float subtract(float a, float b) {
    return a - b;
}
float multiply(float a, float b) {
    return a * b;
}
float divide(float a, float b) {
    return a / b;
}