# 🔐 Cipher project

This project features two different cipher algorithms implemented in C: XOR and CBC.

# ✖️ XOR Cipher

The XOR cipher is a simple type of additive cipher, based on the bitwise XOR (exclusive OR) operation. This operation is sometimes called "modulo 2 addition." Using this method, a string of text can be encrypted by applying the XOR operator to each character with a given key.\
To decrypt the message, you simply apply the XOR operation again using the same key, effectively reversing the encryption.

# 🔗 CBC (Cipher Block Chaining)

Cipher Block Chaining (CBC) mode was introduced in 1976 by Ehrsam, Meyer, Smith, and Tuchman. In CBC mode, each plaintext block is XORed with the previous ciphertext block before being encrypted. This chaining mechanism ensures that each ciphertext block depends on all previous plaintext blocks, improving security.\
An initialization vector (IV) is required for the first block to ensure uniqueness across messages.

# 🚀 How to use it

You can find usage instructions in the README file, or by running the following command:\
`./dh_crypt -h`\
This will print a help message explaining available options and parameters.

# 🙌 Credits

Thank you for checking out my project!\
Feel free to use it, explore it, and have fun experimenting with encryption! 😊
