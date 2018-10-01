// Implement the caesar cipher
#include <bits/stdc++.h>

using namespace std;

string encode(string user_text, int key)
{
	if(key > 26)
	{
		key = key%26;
	}
	string cipher_text;
	for(int i=0 ; i<user_text.length() ; i++)
	{
		char encoded_char;
		if( (user_text[i]-'a') + key >= 26)
		{
			encoded_char = key - 26 + user_text[i];
		}
		else
		{
			encoded_char = char((user_text[i] + key));
		}
		cipher_text.push_back(encoded_char);
	}
	return cipher_text;
}

string decode(string cipher_text, int key)
{
	if(key > 26)
	{
		key = key%26;
	}
	string user_text;
	for(int i=0 ; i<cipher_text.length() ; i++)
	{
		char decoded_char;
		if( (cipher_text[i]-'a') - key < 0)
		{
			decoded_char = 'z' + ((cipher_text[i]-'a') - key) + 1;
		}
		else
		{
			decoded_char = char((cipher_text[i] - key));
		}
		user_text.push_back(decoded_char);
	}
	return user_text;

}

int main()
{
	string user_text;
	cout << "Enter user text : ";
	cin >> user_text;
	int key;
	cout << "Enter key : ";
	cin >> key;
	cout << "CipherText : " << encode(user_text, key) << endl;
	cout << "UserText: " << decode(encode(user_text, key), key) << endl;
}
