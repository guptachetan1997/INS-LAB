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
	
	int* mat_multiply(int matA[block_size][block_size], int matB[block_size])
	{
		int result[block_size];
		for(int i=0 ; i<block_size ; i++)
		{
			result[i][j]=0;
			for(int j=0; j<block_size ; j++)
			{
				result[i][j] += matA[i][j]*matB[j];
			}
		}
		return result;
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
		string cipher_text = plain_text;
		for(int i=0 ; i<plain_text.length() ; i+=block_size)
		{
			int block[block_size], new_block[block_size];
			for(int j=0 ; j<block_size ; j++)
			{
				block[j] = plain_text[i+j]-'a';
			}
			new_block = mat_multiply(key, block);
			for(int j=0 ; j<block_size ; j++)
			{
				cipher_text[i+j] = block[j]+'a';
			}
		}
		return cipher_text;
	}
	string decrypt(string cipher_text)
	{
		string plain_text = cipher_text;
		return plain_text;
	}

};

int main()
{
	int key[block_size][block_size];
	string plain_text;
	cout << "Enter key : " << endl;
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
