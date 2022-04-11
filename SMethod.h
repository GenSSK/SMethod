/*!
 * @file    SMethod.h
 * @brief   .h file for using the class that calculates S method
 * @author  G.Sasaki
 * @data    2021/10/4
 * @details Measurement velocity by S method. This program refers to Dr. Tsuji's paper.
 * @remark  https://doi.org/10.1109/TIE.2008.2003208
 * */

#ifndef SMETHOD_H
#define SMETHOD_H

#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>

/*! @brief The class that measures velocity with S method
 *  @param Pulse per revolution[Pulses]
 *  @param  Sampling time[sec]
 *  @param  Cutoff Frequency[rad/s]
 * */
class SMethod {
 public:
	SMethod(int PulsePerRevolution, double SamplingTime, double CutOffFrequency);
	~SMethod();
	double GetSpeed(int Pulse);
	void SetCPR(int PulsePerRevolution);
	void SetSamplTime(double SamplingTime);
	void SetCutOffFreq(double CutOffFrequency);

 private:
	std::vector<double> wm {0.0};  //!<measured velocity
	int P;					//!<PPR
	double Ts; 				//!<Sampling time
	double Gv;				//!<Cutoff frequency
	double wm_ = 0.0;       //!<Velocity before applying lpf
	int PulseBuf = 0; 		//!<buffer of pulse
	std::vector<int> Me;    //!<diff of pulse
	int Ms = 0; 			//!<Number of samples between two consecutive pulse alternations
	bool ResetFlag = false; //!<Reset flag of measurement velocity
	bool FirstFlag = true;  //!<First time flag
};

#endif //SMETHOD_H

//Copyright (c) 2021, Genki Sasaki
//All rights reserved.