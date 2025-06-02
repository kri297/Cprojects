#include <stdio.h>

void lengthConverter() {
    int choice;
    float cm, inch;
    printf("\nLength Converter:\n");
    printf("1. Centimeters to Inches\n");
    printf("2. Inches to Centimeters\n");
    printf("Choose option: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter length in centimeters: ");
        scanf("%f", &cm);
        inch = cm / 2.54;
        printf("%.2f cm = %.2f inches\n", cm, inch);
    } else if(choice == 2) {
        printf("Enter length in inches: ");
        scanf("%f", &inch);
        cm = inch * 2.54;
        printf("%.2f inches = %.2f cm\n", inch, cm);
    } else {
        printf("Invalid option!\n");
    }
}

void weightConverter() {
    int choice;
    float kg, lb;
    printf("\nWeight Converter:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("Choose option: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter weight in kilograms: ");
        scanf("%f", &kg);
        lb = kg * 2.20462;
        printf("%.2f kg = %.2f lbs\n", kg, lb);
    } else if(choice == 2) {
        printf("Enter weight in pounds: ");
        scanf("%f", &lb);
        kg = lb / 2.20462;
        printf("%.2f lbs = %.2f kg\n", lb, kg);
    } else {
        printf("Invalid option!\n");
    }
}

void tempConverter() {
    int choice;
    float celsius, fahrenheit;
    printf("\nTemperature Converter:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Choose option: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9/5) + 32;
        printf("%.2f C = %.2f F\n", celsius, fahrenheit);
    } else if(choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32) * 5/9;
        printf("%.2f F = %.2f C\n", fahrenheit, celsius);
    } else {
        printf("Invalid option!\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n*** Unit Converter ***\n");
        printf("1. Length Converter\n");
        printf("2. Weight Converter\n");
        printf("3. Temperature Converter\n");
        printf("4. Exit\n");
        printf("Pick your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                lengthConverter();
                break;
            case 2:
                weightConverter();
                break;
            case 3:
                tempConverter();
                break;
            case 4:
                printf("Bye Stay curious.\n");
                break;
            default:
                printf("Oops! Invalid choice.\n");
        }
    } while(choice != 4);

    return 0;
}
