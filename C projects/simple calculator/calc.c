#include <stdio.h>

void displayMenu() {
    printf("\n=============================\n");
    printf("       SIMPLE CALCULATOR\n");
    printf("=============================\n");
    printf("Select Operation:\n");
    printf(" 1. Addition (+)\n");
    printf(" 2. Subtraction (-)\n");
    printf(" 3. Multiplication (*)\n");
    printf(" 4. Division (/)\n");
    printf(" 5. Exit\n");
    printf("=============================\n");
    printf("Enter your choice (1-5): ");
}

int main() {
    int choice;
    float num1, num2, result;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting calculator. Thank you!\n");
            break;
        }

        if (choice >= 1 && choice <= 4) {
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);

            switch (choice) {
                case 1:
                    result = num1 + num2;
                    printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                    break;
                case 2:
                    result = num1 - num2;
                    printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                    break;
                case 3:
                    result = num1 * num2;
                    printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                    break;
                case 4:
                    if (num2 != 0) {
                        result = num1 / num2;
                        printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                    } else {
                        printf("Error: Cannot divide by zero!\n");
                    }
                    break;
            }
        } else {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}
