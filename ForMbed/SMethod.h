/*!
 * @file    SMethod.h
 * @brief   SMethodを計算するクラスを利用するためのヘッダ
 * @author  G.Sasaki
 * @data    2021/10/4
 * @details SMethodによる計算ライブラリです．辻先生の論文を参考にしています.
 * @remark  https://doi.org/10.1109/TIE.2008.2003208
 * */

#ifndef ARCS_SMETHOD_H
#define ARCS_SMETHOD_H

#include <vector>
#include <math.h>
#include <cstdio>
#include <iostream>
#include <complex>

/*! @brief S Methodで速度を計算するクラス
 *  @param 一回転のエンコーダのパルス数[Pulses]
 *  @param  サンプリング時間[sec]
 *  @param  カットオフ周波数[rad/s]
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
	std::vector<double> wm;
	int P;					//!<一周のパルス数
	double Ts; 				//!<サンプリング時間
	double Gv;				//!<カットオフ周波数
	double wm_;       //!<LPFする前の速度
	int PulseBuf; 		//!<パルスバッファ
	std::vector<int> Me;    //!<パルス数バッファ
	int Ms; 			//!<2つの連続したパルス変動間のサンプル数
	bool ResetFlag; //!<速度計算をリセットするフラグ
	bool FirstFlag;  //!<初回実行時のフラグ
};


#endif //ARCS_SMETHOD_H

