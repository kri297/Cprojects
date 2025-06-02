#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, hasUpper=0, hasLower=0, hasDigit=0, hasSpecial=0, score=0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for(int i=0; i<length; i++) {
        if(isupper(password[i])) hasUpper = 1;
        else if(islower(password[i])) hasLower = 1;
        else if(isdigit(password[i])) hasDigit = 1;
        else hasSpecial = 1;
    }

    if(length >= 8) score++;
    if(length >= 12) score++;      
    if(hasUpper) score++;
    if(hasLower) score++;
    if(hasDigit) score++;
    if(hasSpecial) score++;

    printf("\nYour password analysis:\n");

    if(score <= 2)
        printf("Oops! That password is weak like a soggy noodle.\n");
    else if(score <= 4)
        printf("Hmm, not bad! But it could be stronger, like a sandwich without cheese.\n");
    else if(score <= 5)
        printf("Nice! Your password is solid, like a good cup of coffee.\n");
    else
        printf("Wowza! Your password is a fortress, no hacker stands a chance!\n");

    int suggestions = 0;

    printf("\nSuggestions to be a password ninja:\n");

    if(length < 8) {
        printf("- Make it longer than 8 characters.\n");
        suggestions = 1;
    }
    if(!hasUpper) {
        printf("- Throw in some UPPERCASE letters.\n");
        suggestions = 1;
    }
    if(!hasLower) {
        printf("- Don’t forget lowercase letters.\n");
        suggestions = 1;
    }
    if(!hasDigit) {
        printf("- Add some numbers (digits).\n");
        suggestions = 1;
    }
    if(!hasSpecial) {
        printf("- Spice it up with special characters (!@#$ etc).\n");
        suggestions = 1;
    }

    if(suggestions == 0) {
        printf("- No suggestions, your password rocks!\n");
    }

    return 0;
}
