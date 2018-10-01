//Monoalphabetic Encryption and Decryption

#include <iostream>

using namespace std;

string encipher(string plainText, string key)
{
    string cipherText = plainText;
    for(int i=0 ; i<plainText.length() ; i++)
    {
        cipherText[i] = key[(plainText[i] - 'a')];
    }
    return cipherText;
}

string decipher(string cipherText, string keyInverse)
{
    string plainText = cipherText;
    for(int i=0 ; i<cipherText.length() ; i++)
    {
        plainText[i] = keyInverse[(cipherText[i] - 'a')];
    }
    return plainText;
}

int main()
{
    string key = "qazwsxedcrfvtgbyhnujmikolp";
    string keyInverse = "boihgknqvtwyurxzajemsldfpc";
    string plainText;
    cout << "Enter the plaintext : ";
    cin >> plainText;
    cout << "CipherText : " << encipher(plainText, key) << endl;
    cout << "Deciphered PlainText : " << decipher(encipher(plainText, key), keyInverse) << endl;
}
