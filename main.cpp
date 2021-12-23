/*!
 * @file    main.cpp
 * @brief   テスト用
 * @author  Genki Sasaki of Tokyo Denki University
 * @date    2021/12/23
 */

#include "SMethod.h"


int main(){
	double pulse = 0.0; //エンコーダのパルス数[pulses]
	double wm = 0.0;    //角速度[rad/s]
	SMethod sm{1000, 0.001, 300};   //初期化する

	/* 制御ループ */
	while(true){
		wm = sm.GetSpeed(pulse); //パルス取得後に速度を計算
	}

	return 0;
}