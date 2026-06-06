/* xor.c */

#define KEY 'X';
#define CLEARTEXT 'A';

#include <stdio.h>

void printchar (char c, char *text) {
    printf("%s = '%c' (0x%x)\n", text, c, c);
    return;
}

int main () {
    char clearText, key, cipherText, newClearText;

    clearText = CLEARTEXT;
    printchar(clearText, "clearText");

    key = KEY;
    printchar(key, "key");

    cipherText = clearText ^ key;
    printchar(cipherText, "cipherText");

    newClearText = cipherText ^ key;
    printchar(newClearText, "newClearText");
}