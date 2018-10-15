#include <iostream>

using namespace std;

class VignereCipher
{
	string key;
	string alphabet;
	
public:
	VignereCipher(string KEY)
	{
		key = KEY;
		alphabet = "abcdefghijklmnopqrstuvwxyz";
	}
	char encrypt_char(char a, char b)
	{
		int offset = b-'a';
		return (a-'a'+offset)%26 + 'a';
	}
	char decrypt_char(char a, char b)
	{
		return 'a' + ((b-a<0) ? (26+b-a):(b-a)%26);
	}
	string encrypt(string plain_text)
	{
		string cipher_text = plain_text;
		for(int i=0 ; i<plain_text.length() ; i++)
		{
			char a=key[i%key.length()];
			char b=plain_text[i];
			cipher_text[i] = encrypt_char(a,b);
		}
		return cipher_text;
	}
	string decrypt(string cipher_text)
	{
		string plain_text = cipher_text;
		for(int i=0 ; i<cipher_text.length() ; i++)
		{
			char a = key[i%key.length()];
			char b = cipher_text[i];
			plain_text[i] = decrypt_char(a,b);
		}
		return plain_text;
	}
};

int main()
{
	string key, plain_text;
	cout << "Enter key : ";
	cin >> key;
	cout << "Enter plain text : ";
	cin >> plain_text;
	VignereCipher vc(key);
	cout << "Cipher Text : " << vc.encrypt(plain_text) << endl;
	cout << "Decrypted Cipher Text : " << vc.decrypt(vc.encrypt(plain_text)) << endl;
	
}
