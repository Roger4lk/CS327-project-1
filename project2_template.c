#include <stdio.h>
#include <stdlib.h>

int gcd(int inE, int inZ)
{
    // TO BE FINISHED
	// Must implement Euclid's algorithm
	// NO brute-forcing; violation will lead to zero points
	// NO recursion; violation will lead to zero points
}


void testGcd() 
{
    int result1 = gcd (29, 288);
    int result2 = gcd (30, 288);
    int result3 = gcd (149, 288);
    int result4 = gcd (2, 4);
    
    printf("GCD (29, 288) = %#X \n", result1 );
    printf("GCD (30, 288) = %#X \n", result2 );
    printf("GCD (149, 288) = %#X \n", result3 );
    printf("GCD (2, 4) = %#X \n", result4 );
}

//
// We assume that inE < inZ
// This implementation follows our slides
// Return:
//	-1: no inverse
//	inverse of inE mod inZ
//
int xgcd(int inE, int inZ)
{
    // TO BE FINISHED
	// Must implement the extended Euclidean algorithm
	// NO brute-forcing; violation will lead to zero points
	// NO recursion; violation will lead to zero points
} 


int testXgcd()
{
    int result1 = xgcd (29, 288);
    int result2 = xgcd (30, 288);
    int result3 = xgcd (149, 288);
    int result4 = xgcd (2, 4);
    
    printf("29^-1 mod 288  = %#X \n", result1 );
    printf("30^-1 mod 288 = %#X \n", result2 );
    printf("149^-1 mod 288  = %#X \n", result3 );
    printf("2^-1 mod 4 = %#X \n", result4 );
}


int * keygen (int inP, int inQ, int inE)
{

    // TO BE FINISHED

}


//
// The following method will return an integer array, with [e, N, d] in this order
//
void testKeygen ()
{
    int * keypair;

    keypair = keygen (17, 19, 29);
    printf("e = %#X \n", *keypair );
    printf("N = %#X \n", *( keypair + 1 ) );
    printf("d = %#X \n", *( keypair + 2 ) );
}


//
// Calculate c = a^b mod n, with the square-and-multiply algorithm
//
// The following method implements the square-and-multiply algorithm, 
//     with Java primitive types
//
// Note that even with primitive types, a^b may well exceed the range of Java int
// For example, 5^20 is too big to be held by a Java primitive integer
//
int modExp (int message, int inE, int inN) 	 
{
    int x = 1;
	int w = message;
	int y = inE;

	while (y > 0) {
		int t = y%2;
		y = y/2;
		if (t == 1) {
			long xLong = x * w;
			x = (int) (xLong % inN);
		}

		long wLong = w * w;
		w = (int) (wLong % inN);
	}

	return x;
}

int encrypt (int message, int inE, int inN)
{
    // TO BE FINISHED
}


int decrypt (int ciphertext, int inD, int inN)
{
    // TO BE FINISHED
}


void testRSA ()
{
    int * keypair;

    keypair = keygen (17, 19, 29);

    int m1 = 131;
    int c1 = modExp (m1, *keypair, *( keypair + 1 ) );
    printf("The encryption of (m1=%#X ) is %#X \n", m1, c1 );
    int cleartext1 = modExp (c1, *( keypair + 2), *( keypair + 1 ) );
    printf("The decryption of (c=%#X ) is %#X \n", c1, cleartext1 );

    int m2 = 254;
    int c2 = modExp (m2, *keypair, *( keypair + 1 ) );
    printf ("The encryption of (m2=%#X ) is %#X \n", m2, c2 );
    int cleartext2 = modExp (c2, *( keypair + 2 ), *( keypair + 1 ) );
    printf ("The decryption of (c2=%#X ) is %#X \n", c2, cleartext2 );
}


int main()  
{
    printf("********** Project 1 output begins **********\n");
    
    testGcd ();
    testXgcd ();
    testKeygen ();
    testRSA (); 

    return 0;
} 
