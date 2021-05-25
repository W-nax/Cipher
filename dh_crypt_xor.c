/// \file dh_crypt_xor.c
/// \author Axel Delas
/// \date octobre 2020
/// \brief Cipher and decipher xor algorithm

#include "dh_crypt.h"

void xor(char source_filename[], char destination_filename[], char key[]) {
/// \brief Xor cipher and decipher algorithm on a content file
/// \param[in] source_filename Source file
/// \param[in] destination_filename Destination file
/// \param[in] key Encryption key
  FILE *plaintext_filemsg=fopen(source_filename, "r"), *cipher_filemsg=fopen(destination_filename, "w");
  int i=0, key_size=strlen(key), c, res;

  while (!((c=fgetc(plaintext_filemsg))==EOF)) {
    res=c^key[i%key_size];
    fwrite(&res, 1, 1, cipher_filemsg);
    i++;
  }
  fclose(plaintext_filemsg); fclose(cipher_filemsg);
}
