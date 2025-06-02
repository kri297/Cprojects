#include <stdio.h>

int main() {
    float totalBill, serviceCharge = 0, totalAmount, perPerson;
    int people, addServiceCharge;

    printf("===== BILL SPLITTER =====\n");

    printf("Enter total bill amount: ");
    scanf("%f", &totalBill);

    printf("Enter number of people: ");
    scanf("%d", &people);

    printf("Add service charge? (1 = Yes, 0 = No): ");
    scanf("%d", &addServiceCharge);

    if (addServiceCharge == 1) {
        printf("Enter service charge amount: ");
        scanf("%f", &serviceCharge);
    }

    totalAmount = totalBill + serviceCharge;
    perPerson = totalAmount / people;

    
    printf("\n====== FINAL BILL ======\n");
    printf("Bill Amount        : %.2f\n", totalBill);
    printf("Service Charge     : %.2f\n", serviceCharge);
    printf("Total Amount       : %.2f\n", totalAmount);
    printf("Each Person Pays   : %.2f\n", perPerson);

    return 0;
}
