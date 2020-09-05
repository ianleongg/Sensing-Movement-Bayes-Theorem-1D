// define sense function
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <double> sense (vector <double> p, string Z, vector<string> world, float pHit, float pMiss){

/* updates probability based on a sensor reading

*/

vector <double> q (p.size());
bool hit;
double s;

//calculate new probabilities
for (int i =0; i < p.size(); i++){
	hit = (Z == world[i]);
	q[i] = p[i] * (hit * pHit + (1-hit) * pMiss);
	s += q[i]; 
}

//normalize the probabilities
for (int i = 0; i < q.size(); i++){
	q[i] = q[i] / s ;		
}

return q;

}