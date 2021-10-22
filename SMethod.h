//
// Created by genki on 2021/10/04.
//

#ifndef ARCS_SMETHOD_H
#define ARCS_SMETHOD_H

#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>

//! @brief S Methodで速度を計算するクラス
class SMethod {
public:
    SMethod(int PulsePerRevolution, double SamplingTime, double CutOffFrequency);
    ~SMethod();
    double GetSpeed(int Pulse);
    void SetCPR(int PulsePerRevolution);
    void SetSamplTime(double SamplingTime);
    void SetCutOffFreq(double CutOffFrequency);

private:
    std::vector<double> wm {0.0};  //計算した速度
    int P;    //一周のパルス数
    double Ts;  //サンプリング時間
    double Gv; //カットオフ周波数
    double wm_ = 0.0;
    int PulseBuf = 0; //パルスバッファ
    std::vector<int> Me;    //パルス数バッファ
    int Ms = 0; //2つの連続したパルス変動間のサンプル数
    bool ResetFlag = false; //速度計算をリセットするフラグ
    bool FirstFlag = true;
};


#endif //ARCS_SMETHOD_H
