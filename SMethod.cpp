/*!
 * @file    SMethod.cpp
 * @brief   .cpp file for using the class that calculates S method
 * @author  G.Sasaki
 * @date    2021/10/4
 * @details Measurement velocity by S method. This program refers to Dr. Tsuji's paper.
 * @remark  https://doi.org/10.1109/TIE.2008.2003208
 * */


#include "SMethod.h"

/*!
 * @brief  Constructor
 * */
SMethod::SMethod(int PulsePerRevolution, double SamplingTime, double CutOffFrequency):
	P(PulsePerRevolution),
	Ts(SamplingTime),
	Gv(CutOffFrequency)
{
}

/*!
 * @brief  Destructor
 * */
SMethod::~SMethod() = default;

/*! @brief  function of measurement velocity
 *  @param  Pulses [Pulses]
 *  @return velocity [rad/s]
 * */
double SMethod::GetSpeed(int Pulse) {
	if (FirstFlag){
		Me.push_back(0);
		wm.push_back(0.0);
		FirstFlag = false;
		Ms = 2;
	}

	Me.push_back(Pulse - PulseBuf);  //insert the diff pulse
	PulseBuf = Pulse;

	if (!ResetFlag){
		/* Compare with the previous number of pulses */
		if (Me.back() != Me.at(Me.size() - 2)) {
			double first = (double)Me.at(Me.size() - Ms) / 2.0;

			double second = 0.0;
			for (int j = 1; j < Ms - 1; ++j) {
				second += (double)Me.at(Me.size() - 1 - j);
			}

			double third = (double)Me.back() / 2.0;

			wm_ = 2.0 * M_PI / ((double)P * (double)Ms * Ts) * (first + second + third);
			wm.push_back(((1 - exp(-Gv*(double)Ms*Ts)) * (wm_ - wm.at(wm.size() - Ms))) + wm.at(wm.size() - Ms));

			Ms = 1;

		} else {
			wm.push_back(wm.back());
			if (Ms > 10000){
				ResetFlag = true;
			}
			Ms++;
		}
	} else {
		wm.erase(wm.begin(), wm.begin() + 5000);
		wm.push_back(wm.back());
		Me.erase(Me.begin(), Me.begin() + 5000);
		ResetFlag = false;
		Ms = 1;
	}

	return wm.back();
}

/*! @brief  function that sets the pulse per revolution
 *  @param  Pulse per revolution [Pulses]
 * */
void SMethod::SetCPR(int PulsePerRevolution) {
	P = PulsePerRevolution;
}

/*! @brief  function that sets the sampling time
 *  @param  Sampling time [sec]
 * */
void SMethod::SetSamplTime(double SamplingTime) {
	Ts = SamplingTime;
}

/*! @brief  function that sets the cutoff frequency
 *  @param  Cutoff frequency [rad/s]
 * */
void SMethod::SetCutOffFreq(double CutOffFrequency) {
	Gv = CutOffFrequency;
}


//Copyright (c) 2021, Genki Sasaki
//All rights reserved.