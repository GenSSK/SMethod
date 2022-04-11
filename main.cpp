/*!
 * @file    main.cpp
 * @brief   for test
 * @author  Genki Sasaki of Tokyo Denki University
 * @date    2021/12/23
 */

#include "SMethod.h"


int main(){
	double pulse = 0.0; //Encoder Pulses [pulses]
	double wm = 0.0;    //Angular velocity[rad/s]
	SMethod sm{1000, 0.001, 300};

	/* loop */
	while(true){
		wm = sm.GetSpeed(pulse); //measurement velocity
	}

	return 0;
}

//Copyright (c) 2021, Genki Sasaki
//All rights reserved.