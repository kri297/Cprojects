#include <stdio.h>

int main() {
    int happy = 50, health = 50, iq = 50;
    int choice;

    printf("Hello! Welcome to your life game!\n");
    printf("You start with 50 points in Happiness, Health, and IQ.\n\n");

    printf("1) Morning time! What do you do?\n");
    printf("1) Go for a run\n2) Sleep more\n3) Scroll social media\nChoose 1-3: ");
    scanf("%d", &choice);
    if(choice == 1) { health += 10; happy += 5; printf("Good job! Fresh air rocks.\n"); }
    else if(choice == 2) { happy += 5; iq -= 5; printf("More sleep, nice!\n"); }
    else { happy += 2; iq -= 10; health -= 5; printf("Phone time again...\n"); }

    printf("\n2) Lunch! Whats on your plate?\n");
    printf("1) Salad\n2) Burger\n3) Skip meal\nChoose 1-3: ");
    scanf("%d", &choice);
    if(choice == 1) { health += 10; printf("Healthy choice!\n"); }
    else if(choice == 2) { happy += 5; health -= 10; printf("Yummy but not so healthy.\n"); }
    else { health -= 15; happy -= 5; printf("Skipping meals is bad!\n"); }

    printf("\n3) Free time, what now?\n");
    printf("1) Read a book\n2) Watch TV\n3) Hang out with friends\nChoose 1-3: ");
    scanf("%d", &choice);
    if(choice == 1) { iq += 10; happy += 5; printf("Smart move!\n"); }
    else if(choice == 2) { happy += 5; iq -= 5; printf("Relaxing time.\n"); }
    else { happy += 10; health -= 5; printf("Fun but don’t overdo it!\n"); }

    printf("\n4) Exam tomorrow! Your plan?\n");
    printf("1) Study all night\n2) Study a bit\n3) Dont study\nChoose 1-3: ");
    scanf("%d", &choice);
    if(choice == 1) { iq += 15; health -= 10; happy -= 5; printf("Burning the midnight oil!\n"); }
    else if(choice == 2) { iq += 7; happy += 5; printf("Balanced plan.\n"); }
    else { iq -= 10; happy += 5; printf("Risky business!\n"); }

    printf("\n5) Exercise frequency?\n");
    printf("1) Daily\n2) Sometimes\n3) Never\nChoose 1-3: ");
    scanf("%d", &choice);
    if(choice == 1) { health += 15; happy += 5; printf("Great discipline!\n"); }
    else if(choice == 2) { health += 5; printf("Better than nothing.\n"); }
    else { health -= 10; printf("Need to move more!\n"); }

    if(happy > 100) happy = 100;
    if(health > 100) health = 100;
    if(iq > 100) iq = 100;

    if(happy < 0) happy = 0;
    if(health < 0) health = 0;
    if(iq < 0) iq = 0;

    printf("\nYour final scores:\n");
    printf("Happiness: %d\nHealth: %d\nIQ: %d\n", happy, health, iq);

    if(happy > 70 && health > 70 && iq > 70) {
        printf("You're a rockstar! Keep it up!\n");
    } else if(iq >= happy && iq >= health) {
        printf("Brainiac alert! Keep learning!\n");
    } else if(health >= happy && health >= iq) {
        printf("Fit and fine! Stay healthy!\n");
    } else if(happy >= health && happy >= iq) {
        printf("Happy vibes only! Enjoy life!\n");
    } else {
        printf("Keep pushing forward!\n");
    }

    return 0;
}
