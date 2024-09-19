import java.math.BigInteger;

/**
 * @author Xunhua Wang. All rights reserved
 * @date 02/09/2012
 */
public class SmallIntModExp {

	//
	// Calculate c = a^b mod n
	//
	public int modExpOne (int a, int b, int n) 	 {

		int x = 1;
		int w = a; 
		int y = b;
		
		while (y > 0) {
			int t = y%2; 
			y = y/2;
			if (t == 1) { 
				long xLong = x * w; 
				x = (int) (xLong % n);
			}
			
			long wLong = w * w;
			w = (int) (wLong % n);
		}

		return x;
	}

	//
	// A different implementation to calculate a^b mod n for small integers a, b, n (functionality same as modExpOne)
	// The following implementation uses BigInteger, which is not recommended
	//
	public int modExpTwo (int a, int b, int n) {
                        BigInteger aBigInt = BigInteger.valueOf ((long) a);
                        BigInteger bBigInt = BigInteger.valueOf ((long) b);
                        BigInteger nBigInt = BigInteger.valueOf ((long) n);

                        BigInteger resBigInt = aBigInt.modPow (bBigInt, nBigInt);
                        int res = resBigInt.intValue ();
                        return res;
	}

	public static void main (String[] args) {
		SmallIntModExp sime = new SmallIntModExp ();
		int a = 10;
		int b = 20;
		int n = 29;

		int res1 = sime.modExpOne (a, b, n);
		int res2 = sime.modExpTwo (a, b, n);

		System.out.println ("" + a + "^" + b + " mod " + n + " = " + res1);
		System.out.println ("" + a + "^" + b + " mod " + n + " = " + res2);
	}
}





