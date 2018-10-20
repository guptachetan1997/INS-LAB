// Hill Cipher
#include <iostream>
#define block_size 2
using namespace std;

class HillCipher
{
	int key[block_size][block_size];
	int key_inverse[block_size][block_size];
	
	int modInverse(int a, int m)
	{
		a = a%m;
		for (int x=1; x<m; x++)
		   if ((a*x) % m == 1)
		      return x;
	}
	
	void find_key_inverse()
	{
		int adjoint = modInverse((key[1][1]*key[0][0] - key[1][0]*key[0][1]), 26);
		key_inverse[0][0] = (adjoint * key[1][1])%26;
		key_inverse[0][1] = (-adjoint * key[0][1])%26 + 26;
		key_inverse[1][0] = (-adjoint * key[1][0])%26 + 26;
		key_inverse[1][1] = (adjoint * key[0][0])%26;
	}
	
	void mat_multiply(int matA[block_size][block_size], int matB[block_size], int result[block_size])
	{
		for(int i=0 ; i<block_size ; i++)
		{
			result[i]=0;
			for(int j=0; j<block_size ; j++)
			{
				result[i] += matA[i][j]*matB[j];
			}
			result[i] = result[i]%26;
		}
	}
	string stuff(string text)
	{
		string newText = text;
		int stuff_length = text.length()%block_size;
		for(int i=0 ; i<stuff_length ; i++)
		{
			newText.push_back('x');
		}
		return newText;
	}
	
public:
	HillCipher(int KEY[block_size][block_size])
	{
		for(int i=0 ; i<block_size ; i++)
		{
			for(int j=0 ; j<block_size; j++)
			{
				key[i][j] = KEY[i][j];
			}
		}
		find_key_inverse();
	}
	string encrypt(string plain_text)
	{
		plain_text = stuff(plain_text);
		string cipher_text = plain_text;
		for(int i=0 ; i<plain_text.length() ; i+=block_size)
		{
			int block[block_size], new_block[block_size];
			for(int j=0 ; j<block_size ; j++)
			{
				block[j] = plain_text[i+j]-'a';
			}
			mat_multiply(key, block, new_block);
			for(int j=0 ; j<block_size ; j++)
			{
				cipher_text[i+j] = new_block[j]+'a';
			}
		}
		return cipher_text;
	}
	string decrypt(string cipher_text)
	{
		cipher_text = stuff(cipher_text);
		string plain_text = cipher_text;
		for(int i=0 ; i<cipher_text.length() ; i+=block_size)
		{
			int block[block_size], new_block[block_size];
			for(int j=0 ; j<block_size ; j++)
			{
				block[j] = cipher_text[i+j]-'a';
			}
			mat_multiply(key_inverse, block, new_block);
			for(int j=0 ; j<block_size ; j++)
			{
				plain_text[i+j] = new_block[j]+'a';
			}
		}
		return plain_text;
	}

};

int main()
{
	int key[block_size][block_size];
	string plain_text;
	cout << "Enter key : ";
	for(int i=0 ; i<block_size ; i++)
	{
		for(int j=0 ; j<block_size; j++)
		{
			cin >> key[i][j];
		}
	}
	cout << "Enter plain text : ";
	cin >> plain_text;
	HillCipher hc(key);
	cout << "Cipher Text : " << hc.encrypt(plain_text) << endl;
	cout << "Decrypted Cipher Text : " << hc.decrypt(hc.encrypt(plain_text)) << endl;
}
