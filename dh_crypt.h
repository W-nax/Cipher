#ifndef DH_CRYPT_H
#define DH_CRYPT_H

#define BLOCK_SIZE 16                   // Block size for Cbc algorithm

typedef unsigned char byte;             // Byte
typedef byte block_t[BLOCK_SIZE];       // Cbc block

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

// Xor program
void xor(char plaintext_filename[], char cipher_filename[], char key[]);
// Functions used for cipher and decipher Cbc algorithm
int blocks_nb(FILE *filemsg);
void block_add(block_t block, FILE *filemsg);
// Cipher Cbc program
void plaintext_recover(FILE *plaintext_filename, block_t plaintext);
void encryption_block(block_t plaintext, block_t init_vec, char key[], int key_size);
void cbc_crypt(char plaintext_filename[], char cipher_filename[], char key[], char init_vec[]);
// Decipher Cbc program
void ciphertext_recover(FILE *cipher_filemsg, block_t ciphertext);
void decryption_block(block_t ciphertext, block_t init_vec, char key[], int key_size);
int last_byte_ind(block_t ciphertext);
void last_block_add(block_t ciphertext, FILE *decipher_filemsg);
void cbc_uncrypt(char cipher_filename[], char decipher_filename[], char key[], char init_vec[]);

#endif
