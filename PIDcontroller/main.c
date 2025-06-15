/*
 * main.c
 *
 *  Created on: Apr 20, 2025
 *      Author: ashishoktey
 */

#include <stdio.h>
#include <stdint.h>


typedef struct{
	float Kp;
	float Ki;
	float Kd;

	float integral;
	float errorprev;
}PIDcontroller;

void PID_init(PIDcontroller *pid, float Kp, float Ki, float Kd){
	pid->Kp = Kp;
	pid->Ki = Ki;
	pid->Kd = Kd;

	pid->integral = 0.0f;
	pid->errorprev = 0.0f;
}

float PID_update(PIDcontroller *pid, float setpoint,float measured, float dt, float upper_limit, float lower_limit){
	//compute error
	float error = setpoint - measured;

	//integral part
	pid->integral += error * dt;

	//derivative part
	float derivative = (error - pid->errorprev) / dt;
	pid->errorprev = error;

	//controller gain
	float output = pid->Kp * error + pid->Ki * pid->integral + pid->Kd * derivative;

	if(output > upper_limit){
		output = upper_limit;
	}
	if(output < lower_limit){
		output = lower_limit;
	}

	return output;
}

float Plant_update(float y, float u, float a, float b, float dt){
	float dydt = -a * y + b * u;
	return y + dydt * dt;
}

int main(){
	FILE *file = fopen("output.csv", "w");

	if (file == NULL){
		printf("File not found\n");
		return 0;
	}

	// initialize PID controller
	PIDcontroller pid;
	PID_init(&pid, 20, 0.1, 0.01);

	//initialize plant model
	float y = 0.0f;
	float a = 1.2f;
	float b = 2.0f;
	float upper_limit = 21.0f;
	float lower_limit = 0.0f;

	float setpoint = 10.0f;
	float dt = 0.01f;
	uint16_t steps = 500;
	float time = 0.0f;


	fprintf(file, "Time,Output,Control\n");
	for(uint16_t i = 0; i < steps; i++){
		time += dt;
		float u = PID_update(&pid, setpoint, y, dt, upper_limit, lower_limit);
		y = Plant_update(y, u, a, b, dt);
		fprintf(file, "%.2f,%.5f,%.5f\n", time, y, u);
	}
	fclose(file);
	printf("Simulation complete. Data saved to output.csv\n");

	return 0;
}

