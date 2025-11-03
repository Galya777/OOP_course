#include <iostream>
using namespace std;
/*Prints "n, (a,b)" where(a, b) is the n - th ordered pair of
natural numbers under the following
enumeration of the ordered pairs of nat.numbers:
int main(int argument, char* ar[])
{
    int n, n1, a, b, c;
    if (argument != 2) {
        cout << "Not enough arguments.";
        return 1;
    } 
    n = atoi(ar[1]);
    if (n < 0) {
        cout << "Natural number expected!";
        return 2;
    }
    n1 = n;
    if (n == 0) {
        a = 0;
        b = 0;
    } else {
        c = 1;
        while (c <= n) {
            n = n - c;
            c++;
        }
        a = c - 1 - n;
        b = n;

    }
    cout << "n = " << n1 << "  (a ,b ) = " << a << " " << b;

    
    return 0;
} */


/*  Input is "a b" for some natural numbers a,b.
      The output is "n" where n is the number of the ordered
      pair (a,b) under the following
      enumeration of the ordered pairs of nat. numbers:

      <x,y> before <w,z>  iff  (x+y < w+z) or (x+y==w+z and x<w) */
int main(int argument, char* ar[]) {
    int n, a, b;
    if (argument != 3) {
        printf("\n Two arguments expected!  Exit.\n");
        return 1;
    }

    a = atoi(ar[1]);
    b = atoi(ar[2]);

    if (a < 0 || b < 0) {
        printf("\n Two natural numbers expected!  Exit.\n");
        return 2;
    }

    if (a == 0 && b == 0) {
        n = 0;
    }
    else {
        n = (a + b) * (a + b + 1) / 2 + b;
    }

    printf(" n = %d\n", n);


    return 0;
}

