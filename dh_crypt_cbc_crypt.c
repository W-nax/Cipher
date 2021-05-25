/// \file dh_crypt_cbc_crypt.c
/// \author Axel Delas
/// \date December 2020
/// \brief Cipher Cbc algorithm

#include "dh_crypt.h"

int blocks_nb(FILE *filemsg) {
/// \brief Number of blocks containing in the file
/// \param[in] filemsg Source file
/// \returns Entire representing the number of blocks
  int bytes_nb=0;

  while (!(fgetc(filemsg)==EOF))
    bytes_nb++;
  rewind(filemsg);

  if (bytes_nb%BLOCK_SIZE==0)
    return bytes_nb/BLOCK_SIZE;
  else
    return (bytes_nb/BLOCK_SIZE)+1;
}

void block_add(block_t block, FILE *filemsg) {
/// \brief Append in the file the block given
/// \param[in] block Table containing the block
/// \param[in] filemsg File to append the block
  for (int i=0; i<BLOCK_SIZE; i++)
    fwrite(&block[i], 1, 1, filemsg);
}

void plaintext_recover(FILE *plaintext_filename, block_t plaintext) {
/// \brief Recover a plaintext block from the file
/// \details Append padding caracters if the plaintext block is not full
/// \param[in] plaintext_filename File to recover the plaintext block
/// \param[in] plaintext Table which will containing the block
  int c, i=0;

  while (i<BLOCK_SIZE && (c=fgetc(plaintext_filename))!=EOF) {
    plaintext[i]=c;
    i++;
  }

  while (i<BLOCK_SIZE) {
    plaintext[i]=' ';
    i++;
  }
}

void encryption_block(block_t plaintext, block_t init_vec, char key[], int key_size) {
/// \brief Cbc algorithm on a file
/// \param[in] plaintext Table containing the decipher block
/// \param[in] init_vec Table containing the precedent cipher block
/// \param[in] key Encryption key
/// \param[in] key_size Key size
  for (int i=0; i<BLOCK_SIZE; i++) {
    plaintext[i]=plaintext[i]^init_vec[i]^key[i%key_size];
    init_vec[i]=plaintext[i];
  }
}

void cbc_crypt(char plaintext_filename[], char cipher_filename[], char key[], char init_vec[]) {
/// \brief Cbc algorithm on a source file to destination file
/// \param[in] plaintext_filename Source file containing the decipher text
/// \param[in] cipher_filename Destination file which will containing the cipher text
/// \param[in] key Encryption key
/// \param[in] init_vec Initialisation vector
  FILE *plaintext_f_msg=fopen(plaintext_filename, "r"), *cipher_f_msg=fopen(cipher_filename, "w");
  int blocks=blocks_nb(plaintext_f_msg), key_size=strlen(key);
  block_t plaintext, vec;

  strcpy((char*)vec, init_vec);

  // 16 bytes recover block
  plaintext_recover(plaintext_f_msg, plaintext);
  // Cbc cipher algorithm on the recovered block
  encryption_block(plaintext, vec, key, key_size);
  // Append the cipher recovered block in the destination file
  block_add(plaintext, cipher_f_msg);
  // Loop in comparison to the number of blocks containing in the source file
  for (int i=1; i<blocks; i++) {
    plaintext_recover(plaintext_f_msg, plaintext);
    encryption_block(plaintext, vec, key, key_size);
    block_add(plaintext, cipher_f_msg);
  }
  fclose(plaintext_f_msg); fclose(cipher_f_msg);
}
