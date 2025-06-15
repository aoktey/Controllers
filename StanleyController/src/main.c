/*
 * main.c
 *
 *  Created on: Apr 21, 2025
 *      Author: ashishoktey
 */

#include <stdio.h>
#include "app/atan.h"

//Controller Declaration
typedef struct{
	float K;
}StanleyC;

//initializing controller
void StanleyC_init(StanleyC *SCP, float K){
	SCP->K = K;
}

//write an update definition to calculate control signal
float StanleyC_update(StanleyC *SCP, float thet_e, float lat_e, float vel){
	float thet = SCP->K * lat_e / vel;
	float output = thet_e + tan_inv(thet);

	return output;
}

int main(){
	StanleyC SCP;
	StanleyC_init(&SCP, 10.0);

	float thet_e = 0.5f;	//rad
	float lat_e = 0.1f;		//meters
	float vel = 15.0f;		//m/s

	float U = StanleyC_update(&SCP, thet_e, lat_e, vel);
	printf("controller output is %0.2f", U);
}
