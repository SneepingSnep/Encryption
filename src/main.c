#include "../headers/caesar.h"
#include "../headers/vigenere.h"
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET "abcdefghijklmnopqrstuvwxyz"
#define Vigenere "vigenere"
#define Caesar "caesar"

int encryptionstate(char *encryptionmode);

int startprocess(int mode, char **argv);
void makestringlower(char *string);

char EncryptionMode[16];
int main(int argc, char *argv[]) {

  strcpy(EncryptionMode, argv[1]);
  int state = encryptionstate(EncryptionMode);
  switch (state) {
  case 1:
    startprocess(state, argv);
    break;
  case 2:
    startprocess(state, argv);
    break;
  }
}

int startprocess(int mode, char **argv) {
  char initialmsgg[100];
  char DecryptorEncrypt[5];
  strcpy(DecryptorEncrypt, argv[3]);
  strcpy(initialmsgg, argv[2]);

  makestringlower(DecryptorEncrypt);
  makestringlower(initialmsgg);

  if (mode == 1) {
    if (strcmp(DecryptorEncrypt, "d") == 0) {
      char *decryptedmsg = caesar_decrypt(initialmsgg);
      printf("Decrypted msg: %s", decryptedmsg);
      free(decryptedmsg);
    } else if (strcmp(DecryptorEncrypt, "e") == 0) {
      char *encryptedmsg = caesar_encrypt(initialmsgg);
      printf("Encrypted msg: %s", encryptedmsg);
      free(encryptedmsg);
    }
  } else if (mode == 2) {
    char *keystring = argv[4];
    makestringlower(keystring);
    if (strcmp(DecryptorEncrypt, "d") == 0) {
      char *decryptedmsg = vigenere_decrypt(initialmsgg, keystring);
      printf("Decrypted msg: %s", decryptedmsg);
      free(decryptedmsg);
    } else if (strcmp(DecryptorEncrypt, "e") == 0) {
      char *encryptedmsg = vigenere_encrypt(initialmsgg, argv[4]);
      printf("Encrypted msg: %s", encryptedmsg);
      free(encryptedmsg);
    }
  }
  return 0;
}

void makestringlower(char *string) {
  for (size_t i = 0; i < strlen(string); i++) {
    string[i] = tolower(string[i]);
  }
}

int encryptionstate(char *encryptionmode) {
  makestringlower(encryptionmode);
  if (strcmp(encryptionmode, Caesar) == 0 || encryptionmode[0] == 'c') {
    return 1;
  } else if (strcmp(encryptionmode, Vigenere) == 0 ||
             encryptionmode[0] == 'v') {
    return 2;
  }
  return 0;
}