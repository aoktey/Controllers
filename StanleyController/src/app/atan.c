/*
 * atan.c
 *
 *  Created on: Apr 21, 2025
 *      Author: ashishoktey
 */


float tan_inv(float x){
	// maclaurin's series
	// atan(x) = x - x^3/3 + x^5/5 - x^7/7 .....
	return (x - (x*x*x/3) + (x*x*x*x*x/5) - (x*x*x*x*x*x*x/7)); //approximated till power 7
}
