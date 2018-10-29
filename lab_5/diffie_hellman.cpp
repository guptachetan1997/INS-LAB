// Diffie Hellman Key Exchange
#include <iostream>
#include <math.h>

using namespace std;

class DHKeyExchange
{
	int p,g,a;

public:
	DHKeyExchange(int P, int G)
	{
		p = P;
		g = G;
	}
	
	int generate_key_message(int A)
	{
		a = A;
		int message = int(pow(g, a)) % p;
		return message;
		
	}
	
	int extract_key(int message)
	{
		int key = int(pow(message, a)) % p;
		return key;
	}
};

int main()
{
	int alice_secret=4, bob_secret=3, alice_msg, bob_msg;
	DHKeyExchange alice(23, 5), bob(23, 5);
	cout << "P : 23, G : 5\n";
	cout << "Secret integer for Alice : "<< alice_secret << endl;
	alice_msg = alice.generate_key_message(alice_secret);
	cout << "Message sent by Alice : " << alice_msg << endl;
	cout << endl;
	cout << "Secret integer for Bob : " << bob_secret << endl;
	bob_msg = bob.generate_key_message(bob_secret);
	cout << "Message sent by Bob : " << bob_msg << endl;
	cout << endl;
	cout << "Shared Secret Key at Alice : " << alice.extract_key(bob_msg) << endl;
	cout << "Shared Secret Key at Bob : " << bob.extract_key(alice_msg) << endl;
}
