#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"
#define Vigenere "vigenere"
#define Caesar "caesar"
char *caesar_encrypt(char *plaintext);
char *caesar_decrypt(char *ciphertext);
int encryptionstate(char *encryptionmode);
char *vigenere_encrypt(char *plaintext, char *key);
char *vigenere_decrypt(char *ciphertext, char *key);
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
      puts(decryptedmsg);
      free(decryptedmsg);
    } else if (strcmp(DecryptorEncrypt, "e") == 0) {
      char *encryptedmsg = caesar_encrypt(initialmsgg);
      puts(encryptedmsg);
      free(encryptedmsg);
    }
  } else if (mode == 2) {
    char *keystring = argv[4];
    makestringlower(keystring);
    if (strcmp(DecryptorEncrypt, "d") == 0) {
      char *decryptedmsg = vigenere_decrypt(initialmsgg, keystring);
      puts(decryptedmsg);
      free(decryptedmsg);
    } else if (strcmp(DecryptorEncrypt, "e") == 0) {
      char *encryptedmsg = vigenere_encrypt(initialmsgg, argv[4]);
      puts(encryptedmsg);
      free(encryptedmsg);
    }
  }
}
char *caesar_encrypt(char *plaintext) {
  printf("%s\n", plaintext);
  char letterinstring;
  char *encryptedstringpointer = (char *)malloc(strlen(plaintext) + 1);
  memset(encryptedstringpointer, 0, strlen(plaintext) + 1);
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
        int brother2 = (0 - 3) % (size_t)26;
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

int encryptionstate(char *encryptionmode) {
  makestringlower(encryptionmode);
  if (strcmp(encryptionmode, Caesar) == 0 || encryptionmode[0] == 'c') {
    return 1;
  } else if (strcmp(encryptionmode, Vigenere) == 0 ||
             encryptionmode[0] == 'v') {
    return 2;
  }
}
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