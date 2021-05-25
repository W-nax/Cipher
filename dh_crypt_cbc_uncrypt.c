/// \file dh_crypt_cbc_uncrypt.c
/// \author Axel Delas
/// \date December 2020
/// \brief Decipher Cbc algorithm

#include "dh_crypt.h"

void ciphertext_recover(FILE *cipher_filemsg, block_t ciphertext) {
/// \brief Recover cipher text block
/// \param[in] cipher_filemsg Source file containing the cipher text
/// \param[in] plaintext Table which will containing the recovered ciper text block
  int c, i=0;

  while (i<BLOCK_SIZE && (c=fgetc(cipher_filemsg))!=EOF) {
    ciphertext[i]=c;
    i++;
  }
}

void decryption_block(block_t ciphertext, block_t init_vec, char key[], int key_size) {
/// \brief Cbc decipher algorithm on a block
/// \param[in] plaintext Table containing the cipher block
/// \param[in] init_vec Table containing the precedent decipher block
/// \param[in] key Encryption key
/// \param[in] key_size Key size
  byte c;

  for (int i=0; i<BLOCK_SIZE; i++) {
    c=ciphertext[i];
    ciphertext[i]=ciphertext[i]^key[i%key_size]^init_vec[i];
    init_vec[i]=c;
  }
}

int last_byte_ind(block_t ciphertext) {
/// \brief Last index before padding caracters
/// \param[in] ciphertext Table containing the last decipher block
/// \returns Entire representing the number of bytes before the first padding caracter
  int i=BLOCK_SIZE-1;

  while (i>=0 && ciphertext[i]==' ')
    i--;

  return i;
}

void last_block_add(block_t ciphertext, FILE *decipher_filemsg) {
/// \brief Append the last decipher block without padding caracters
/// \param[in] ciphertext Table containing the last cipher block
/// \param[in] decipher_filemsg File to append the block
  int i_max=last_byte_ind(ciphertext);

  for (int i=0; i<=i_max; i++)
    fwrite(&ciphertext[i], 1, 1, decipher_filemsg);
}

void cbc_uncrypt(char cipher_filename[], char decipher_filename[], char key[], char init_vec[]) {
/// \brief Cbc decipher algorithm on a file
/// \param[in] cipher_filename Source file containing the cipher text
/// \param[in] decipher_filename Destination file which will containing the decipher text
/// \param[in] key Encryption key
/// \param[in] init_vec Initialisation vector
  FILE *cipher_filemsg=fopen(cipher_filename, "r"), *decipher_filemsg=fopen(decipher_filename, "w");
  int blocks=blocks_nb(cipher_filemsg), key_size=strlen(key);
  block_t ciphertext, vec;

  strcpy((char*)vec, init_vec);

  // 16 bytes recover block
  ciphertext_recover(cipher_filemsg, ciphertext);
  // Cbc decipher algorithm on the recovered block
  decryption_block(ciphertext, vec, key, key_size);
  // Append the decipher recovered block in the destination file
  block_add(ciphertext, decipher_filemsg);
  // Loop in comparison to the number of blocks containing in the source file
  for (int i=1; i<blocks; i++) {
    ciphertext_recover(cipher_filemsg, ciphertext);
    decryption_block(ciphertext, vec, key, key_size);
    // If is the last block, padding caracters treatment
    if (i+1==blocks)
      last_block_add(ciphertext, decipher_filemsg);
    else
      block_add(ciphertext, decipher_filemsg);
  }
  fclose(cipher_filemsg); fclose(decipher_filemsg);
}
