#include "../headers/vigenere.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

char *vigenere_encrypt(char *plaintext, char *key) {
  bool loopstate = true;
  char letterinstring;
  char keystring;
  int keylength = strlen(key);
  int keycounter = 0;
  char *encryptedstringpointer = (char *)malloc(strlen(plaintext) + 1);
  memset(encryptedstringpointer, 0, strlen(plaintext) + 1);
  for (int i = 0; i < strlen(plaintext); i++) {
    loopstate = true;
    letterinstring = plaintext[i];
    if (keycounter >= keylength) {
      keycounter = 0;
    }
    keystring = key[keycounter];

    // char brother = ALPHABET[3];
    for (int j = 0; j < strlen(ALPHABET); j++) {
      if (!loopstate)
        break;

      if (letterinstring == ALPHABET[j]) {
        for (int k = 0; k < strlen(ALPHABET); k++) {
          if (keystring == ALPHABET[k]) {
            encryptedstringpointer[i] = ALPHABET[(j + k) % strlen(ALPHABET)];
            loopstate = false;
            break;
          }
        }
      }
    }
    keycounter++;
  }
  puts(encryptedstringpointer);
  return encryptedstringpointer;
}

char *vigenere_decrypt(char *ciphertext, char *key) {
  bool loopstate = true;
  char letterinstring;
  char keystring;
  int keylength = strlen(key);
  int keycounter = 0;
  char *decryptedstringpointer = (char *)malloc(strlen(ciphertext) + 1);
  memset(decryptedstringpointer, 0, strlen(ciphertext) + 1);
  for (int i = 0; i < strlen(ciphertext); i++) {
    loopstate = true;
    letterinstring = ciphertext[i];
    if (keycounter >= keylength) {
      keycounter = 0;
    }
    keystring = key[keycounter];

    // char brother = ALPHABET[3];
    for (int j = 0; j < strlen(ALPHABET); j++) {
      if (!loopstate)
        break;

      if (letterinstring == ALPHABET[j]) {
        for (int k = 0; k < strlen(ALPHABET); k++) {
          if (keystring == ALPHABET[k]) {
            decryptedstringpointer[i] =
                ALPHABET[(j - k + strlen(ALPHABET)) % strlen(ALPHABET)];
            loopstate = false;
            break;
          }
        }
      }
    }
    keycounter++;
  }
  puts(decryptedstringpointer);
  return decryptedstringpointer;
}