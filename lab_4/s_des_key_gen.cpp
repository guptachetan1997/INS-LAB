//Simplified DES Key Generation

#include <iostream>
#define KEY_BITS 10
#define BLOCK_SIZE 8
#define MAX_ROUNDS 16

using namespace std;

class DES
{
	int initial_key[KEY_BITS];
	int P1[KEY_BITS] = {2,4,1,6,3,9,0,8,7,5};
	int P2[BLOCK_SIZE] = {5,2,6,3,7,4,9,8};
	
	void p_box(int key[], int result[])
	{
		for(int i=0 ; i<KEY_BITS ; i++)
			result[i] = key[P1[i]];
	}
	
	void compression_pbox(int key[], int result[])
	{
		for(int i=0 ; i<BLOCK_SIZE ; i++)
			result[i] = key[P2[i]];
	}
	
	void split_half(int parent[], int left[], int right[])
	{
		for(int i=0 ; i<KEY_BITS/2 ; i++)
		{
			left[i] = parent[i];
			right[i] = parent[KEY_BITS/2 + i];
		}
	}
	
	void combine(int left[], int right[], int parent[])
	{
		for(int i=0 ; i<KEY_BITS/2 ; i++)
		{
			parent[i] = left[i];
			parent[KEY_BITS/2 + i] = right[i];
		}
	}
	
	void shift(int key[], int size)
	{
		int first = key[0];
		for(int i=0 ; i<size-1 ; i++)
			key[i] = key[i+1];
		key[size-1] = first;
	}
	
	void generate_round_keys(int rounds, int round_keys[MAX_ROUNDS][BLOCK_SIZE])
	{
		int round_start_key[KEY_BITS];
		p_box(initial_key, round_start_key);
		for(int i=0 ; i<rounds ; i++)
		{
			int round_left[KEY_BITS/2], round_right[KEY_BITS/2];
			split_half(round_start_key, round_left, round_right);
			shift(round_left, KEY_BITS/2);
			shift(round_right, KEY_BITS/2);			
			if(i == 1)
			{
				shift(round_left, KEY_BITS/2);
				shift(round_right, KEY_BITS/2);
			}
			combine(round_left, round_right, round_start_key);
			compression_pbox(round_start_key, round_keys[i]);
		}
	}
	
public:
	DES(int INIT_KEY[KEY_BITS])
	{
		for(int i=0 ; i<KEY_BITS ; i++)
			initial_key[i] = INIT_KEY[i];
	}
	void print_keys(int rounds)
	{
		int round_keys[MAX_ROUNDS][BLOCK_SIZE];
		generate_round_keys(rounds,round_keys);
		for(int i=0 ; i<rounds ; i++)
		{
			cout << "Round Key " << i+1 << " (8 bit): ";
			for(int j=0 ; j<BLOCK_SIZE ; j++)
			{
				cout << round_keys[i][j];
			}
			cout << endl;
		}
	}
};

int main()
{
	int INIT_KEY[KEY_BITS];
	cout << "Enter 10 bit initial key : ";
	for(int i=0 ; i<KEY_BITS ; i++)
		cin >> INIT_KEY[i];
	DES des(INIT_KEY);
	des.print_keys(2);
}
