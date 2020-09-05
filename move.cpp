// define move function
#include <iostream>
#include <string>
#include <vector>

using namespace std;
	vector <double> move(vector <double> p, int U, float pExact, float pOvershoot, float pUndershoot){

/* updates probability based on movement

*/

vector <double> q (p.size());
double s;

for (int i = 0; i < p.size(); i++)
{// Calculate new probabilities
  
        // The modulo operator behaves a bit different in C++ with negatives
        // If we took it as -1 % p.size(), we'd get zero instead of four
        // -1 + p.size() will give us what we would get from -1 % p.size in Python
        
        if (i-U < 0) {
            s = pExact * p[(i-U) + p.size()];
        }
        else {
            s = pExact * p[(i-U) % p.size()];
        }
        if (i-U-1 < 0) {
            s = s + pOvershoot * p[(i-U-1) + p.size()];
        }
        else {
            s = s + pOvershoot * p[(i-U-1) % p.size()];
        }
        if (i-U+1 < 0) {
            s = s + pUndershoot * p[(i-U+1) + p.size()];
        }
        else {
            s = s + pUndershoot * p[(i-U+1) % p.size()];
        }

        q[i] = s;
    }

    return q;
}
	


/* attempt but python modulus differs 
      Updates probability based on movement.
     
s = pExact * p[i-U] % p.size()];
	s = s + pOvershoot * p[i-U-1 % size.p()];
	s = s + pUndershoot * p[i-U+1 % size.p()];
	q = s;
*/
    
