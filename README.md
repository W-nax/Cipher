# Cipher

I developed two differents cipher algorithms in C language : Xor and Cbc.

# Xor 

The simple XOR cipher is a type of additive cipher, an encryption algorithm. This operation is sometimes called modulus 2 addition (or subtraction, which is identical). With this logic, a string of text can be encrypted by applying the bitwise XOR operator to every character using a given key. To decrypt the output, merely reapplying the XOR function with the key will remove the cipher. 

# Cbc

Ehrsam, Meyer, Smith and Tuchman invented the cipher block chaining (CBC) mode of operation in 1976. In CBC mode, each block of plaintext is XORed with the previous ciphertext block before being encrypted. This way, each ciphertext block depends on all plaintext blocks processed up to that point. To make each message unique, an initialization vector must be used in the first block.

# How to use it?

You have two solutions to know it : read the README file, or just type the "dh_crypt -h" beacon on program parameters, a message will be printed to explain.

# Credits

Thank you to considered my work and just have fun with it! :)
