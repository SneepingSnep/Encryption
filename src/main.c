#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"
char *caesar_encrypt(char *plaintext);
char *caesar_decrypt(char *ciphertext);
int main(int argc, char *argv[]) {

  char initialmsgg[100];
  char DecryptorEncrypt[5];
  strcpy(DecryptorEncrypt, argv[2]);
  strcpy(initialmsgg, argv[1]);
  for (int i = 0; i < strlen(initialmsgg); i++) {
    initialmsgg[i] = tolower(initialmsgg[i]);
  }
  for (int i = 0; i < strlen(initialmsgg); i++) {
    DecryptorEncrypt[i] = tolower(DecryptorEncrypt[i]);
  }
  if (strcmp(DecryptorEncrypt, "d") == 0) {
    char *decryptedmsg = caesar_decrypt(initialmsgg);
    puts(decryptedmsg);
  } else if (strcmp(DecryptorEncrypt, "e") == 0) {
    char *encryptedmsg = caesar_encrypt(initialmsgg);
    puts(encryptedmsg);
  }
}

char *caesar_encrypt(char *plaintext) {
  printf("%s\n", plaintext);
  char letterinstring;
  char *encryptedstringpointer = (char *)malloc(strlen(plaintext) + 1);
  memset(encryptedstringpointer, 0, strlen(plaintext) + 1);
#if 0


 printf("(%s)", encryptedstringpointer);
  for (int i = 0; i < strlen(plaintext); i++) {
    printf("%c\n", plaintext[i]);

    encryptedstringpointer[i] = ALPHABET[i + 3];
  }
  encryptedstringpointer[strlen(plaintext)] = '\0';
  printf("%s\n", encryptedstringpointer);
#endif
  for (int i = 0; i < strlen(plaintext); i++) {
    letterinstring = plaintext[i];

    for (int j = 0; j < strlen(ALPHABET); j++) {

      if (letterinstring == ALPHABET[j]) {
        // char brother = ALPHABET[(j + 3) % strlen(ALPHABET)];
        // int brother3 = (j + 3) % strlen(ALPHABET);
        // char brother2 = ALPHABET[1];
        // int brother4 = strlen(ALPHABET);
        encryptedstringpointer[i] = ALPHABET[(j + 3) % strlen(ALPHABET)];
      }
    }
  }
  return encryptedstringpointer;
}
char *caesar_decrypt(char *ciphertext) {
  printf("%s\n", ciphertext);
  char letterinstring;
  char *decryptedstringpointer = (char *)malloc(strlen(ciphertext) + 1);
  memset(decryptedstringpointer, 0, strlen(ciphertext) + 1);

  for (int i = 0; i < strlen(ciphertext); i++) {
    letterinstring = ciphertext[i];
    // char brother = ALPHABET[3];
    for (int j = 0; j < strlen(ALPHABET); j++) {

      if (letterinstring == ALPHABET[j]) {
        // char brother = ALPHABET[(j + 3) % sizeof(ALPHABET)];
        char brother = ALPHABET[(j - 3 + strlen(ALPHABET)) % strlen(ALPHABET)];
        int strlength = strlen(ALPHABET);
        int borther = (j - 3) % (int)strlen(ALPHABET);
        int brother3 = (0 - 3) % (size_t)26;
        decryptedstringpointer[i] = brother;
      }
    }
  }
  return decryptedstringpointer;
}

void makestringlower(char *string) {
  for (int i = 0; i < strlen(string); i++) {
    string[i] = tolower(string[i]);
  }
}