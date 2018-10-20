// Autokey polyalphabetic cipher
#include <iostream>

using namespace std;

class AutoKeyCipher
{
	int START;
public:
	AutoKeyCipher(int initial_key)
	{
		START = initial_key%26;
	}

	string encrypt(string plain_text)
	{
		string cipher_text = plain_text;
		cipher_text[0] = ((plain_text[0]-'a') + START >= 26 ? START - 26 + plain_text[0] : (plain_text[0] + START));
		for(int i=1 ; i<plain_text.length() ; i++)
		{
			int key = plain_text[i-1]-'a';
			cipher_text[i] = ((plain_text[i]-'a') + key >= 26 ? key - 26 + plain_text[i] : (plain_text[i] + key));
		}
		return cipher_text;
	}
	string decrypt(string cipher_text)
	{
		string plain_text = cipher_text;
		plain_text[0] = (cipher_text[0]-'a' - START < 0) ? 'z' + ((cipher_text[0]-'a') - START) + 1 : char((cipher_text[0] - START));
		for(int i=1 ; i<cipher_text.length() ; i++)
		{
			int key = plain_text[i-1]-'a';
			plain_text[i] = (cipher_text[i]-'a' - key < 0) ? 'z' + ((cipher_text[i]-'a') - key) + 1 : char((cipher_text[i] - key));
		}
		return plain_text;
	}
};


int main()
{
	int start_key;
	string plain_text;
	cout << "Enter initial key : ";
	cin >> start_key;
	cout << "Enter plain text : ";
	cin >> plain_text;
	AutoKeyCipher cipher(start_key);
	cout << "CipherText : " << cipher.encrypt(plain_text) << endl;
	cout << "Decypted CipherText : " << cipher.decrypt(cipher.encrypt(plain_text)) << endl;
}