#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char category[20];
    float amount;
};

float budget = 0;

void setBudget() {
    printf("Hey! What's your budget for this month? ");
    scanf("%f", &budget);
    printf("Cool, your budget is set to %.2f\n", budget);
}

void addExpense(FILE *fp) {
    struct expense e;
    printf("Tell me the category (like Food, Travel): ");
    scanf("%s", e.category);
    printf("How much did you spend? ");
    scanf("%f", &e.amount);

    fwrite(&e, sizeof(e), 1, fp);
    printf("Expense saved!\n");
}

void showAllExpenses(FILE *fp) {
    struct expense e;
    rewind(fp);

    printf("\nHere's what you spent so far:\n");
    printf("---------------------------\n");
    while (fread(&e, sizeof(e), 1, fp)) {
        printf("Category: %-10s | Amount: %.2f\n", e.category, e.amount);
    }
    printf("---------------------------\n");
}

float getTotal(FILE *fp) {
    struct expense e;
    float total = 0;
    rewind(fp);

    while (fread(&e, sizeof(e), 1, fp)) {
        total += e.amount;
    }
    return total;
}

void showTotalByCategory(FILE *fp) {
    struct expense e;
    rewind(fp);

    char cats[100][20];
    float sums[100] = {0};
    int count = 0, found, i;

    while (fread(&e, sizeof(e), 1, fp)) {
        found = 0;
        for (i = 0; i < count; i++) {
            if (strcmp(cats[i], e.category) == 0) {
                sums[i] += e.amount;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(cats[count], e.category);
            sums[count] = e.amount;
            count++;
        }
    }

    printf("\nTotal expenses by category:\n");
    printf("---------------------------\n");
    float overall = 0;
    for (i = 0; i < count; i++) {
        printf("%-10s : %.2f\n", cats[i], sums[i]);
        overall += sums[i];
    }
    printf("---------------------------\n");
    printf("Overall total: %.2f\n", overall);
}

void showBudgetStatus(FILE *fp) {
    if (budget == 0) {
        printf("Hey, you didn't set your budget yet!\n");
        return;
    }

    float spent = getTotal(fp);
    printf("\nYour budget is %.2f\n", budget);
    printf("You've spent %.2f so far\n", spent);

    if (spent < budget) {
        printf("Good job! You have %.2f left to spend this month.\n", budget - spent);
    } else if (spent == budget) {
        printf("Wow, you spent exactly your budget!\n");
    } else {
        printf("Oops! You went over by %.2f\n", spent - budget);
    }
}

int main() {
    FILE *fp = fopen("expenses.dat", "ab+");
    if (!fp) {
        printf("Can't open the expense file!\n");
        return 1;
    }

    int choice;

    do {
        printf("\nWhat do you wanna do?\n");
        printf("1. Set monthly budget\n");
        printf("2. Add an expense\n");
        printf("3. Show all expenses\n");
        printf("4. Show totals by category\n");
        printf("5. Check budget status\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                setBudget();
                break;
            case 2:
                addExpense(fp);
                break;
            case 3:
                showAllExpenses(fp);
                break;
            case 4:
                showTotalByCategory(fp);
                break;
            case 5:
                showBudgetStatus(fp);
                break;
            case 6:
                printf("Bye Take care.\n");
                break;
            default:
                printf("That's not a choice. Try again.\n");
        }
    } while(choice != 6);

    fclose(fp);
    return 0;
}
