#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* used these for decimal to binary conversion:
 * https://mathmonks.com/number-system/decimal-to-binary
 * https://www.eventbrite.com/cc/upskill-series-4507973
 *
 * this helped me better understand enc():
 * https://www.geeksforgeeks.org/c/c-program-for-int-to-char-conversion/
 */

/*
 * d2b  | Convert decimal to binary. See the section II-B.
 * b2d  | Convert binary to decimal. See the section II-B.
 * enc  | Encrypt user’s input based on Caesar’s cipher. See the section II-C.
 * dec  | Decrypt user’s input based on Caesar’s cipher. See the section II-C.
 * gcd  | Encode a number into a gamma code. See the section II-D. (extra)
 * exit | Exit the program
 */

char command[4];
char *token;
char loginID[8];
char encrypted[100];
char decrypted[100];

// Convert decimal to binary. See the section II-B.
int d2b(const int dec) {
    int quotient = dec, binary = 0, count = 0;

    while (quotient > 0) {
        int remainder = quotient%2;
        if (remainder==1) {
            binary += (int)pow(10,count);
        }
        quotient /= 2;
        ++count;
    }
    return binary;
}

// Convert binary to decimal. See the section II-B.
int b2d(const char binArr[]) {
    int power = strlen(binArr), decimal = 0;

    for (int i = 0; binArr[i] != '\0'; i++) {
        decimal += binArr*pow(2,power);
        power = power - 1;
    }

    return decimal;
}

// Encrypt user’s input based on Caesar’s cipher. See the section II-C.
void enc(char str[]) {
    for (int i = 0; i < strlen(str) - 1; i++) {
        encrypted[i] = (str[i]+5)%26;
    }
    printf(encrypted);
}

// Decrypt user’s input based on Caesar’s cipher. See the section II-C.
void dec(char str[]) {
    for (int i = 0; i < strlen(str) - 1; i++) {
        decrypted[i] = (str[i]-5)%26;
    }
    printf(decrypted);
}

// Encode a number into a gamma code. See the section II-D. (extra)
int gcd(int gamma) {
    return 0;
}

int main(void) {
    scanf("%s", loginID);
    printf(loginID, " $ ");

    fgets(command, sizeof(command), stdin);
    token = strtok(command, NULL);

    if (strcmp(token,"d2b")==0) {
        d2b();
    } else if (strcmp(token,"b2d")==0) {
        b2d();
    } else if (strcmp(token,"enc")==0) {
        enc();
    } else if (strcmp(token,"dec")==0) {
        dec();
    } else if (strcmp(token,"gcd")==0) {
        gcd();
    } else if (strcmp(token,"exit")==0) {
        exit(0);
    } else {
        printf("Please enter the command correctly.");
    }


}