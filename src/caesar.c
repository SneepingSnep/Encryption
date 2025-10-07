#include "../headers/caesar.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET "abcdefghijklmnopqrstuvwxyz"
char *caesar_encrypt(char *plaintext) {
  printf("Provided plaintext: %s\n", plaintext);
  char letterinstring;
  char *encryptedstringpointer = (char *)malloc(strlen(plaintext) + 1);
  memset(encryptedstringpointer, 0, strlen(plaintext) + 1);
  for (size_t i = 0; i < strlen(plaintext); i++) {
    letterinstring = plaintext[i];

    for (size_t j = 0; j < strlen(ALPHABET); j++) {

      if (letterinstring == ALPHABET[j]) {
        encryptedstringpointer[i] = ALPHABET[(j + 3) % strlen(ALPHABET)];
      }
    }
  }
  return encryptedstringpointer;
}

char *caesar_decrypt(char *ciphertext) {
  printf("Provide ciphertext: %s\n", ciphertext);
  char letterinstring;
  char *decryptedstringpointer = (char *)malloc(strlen(ciphertext) + 1);
  memset(decryptedstringpointer, 0, strlen(ciphertext) + 1);

  for (size_t i = 0; i < strlen(ciphertext); i++) {
    letterinstring = ciphertext[i];

    for (size_t j = 0; j < strlen(ALPHABET); j++) {

      if (letterinstring == ALPHABET[j]) {
        decryptedstringpointer[i] =
            ALPHABET[(j - 3 + strlen(ALPHABET)) % strlen(ALPHABET)];
      }
    }
  }
  return decryptedstringpointer;
}