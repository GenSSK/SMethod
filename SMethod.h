/*!
 * @file    SMethodを計算するクラスを利用するためのヘッダ
 * @brief   https://doi.org/10.1109/TIE.2008.2003208
 * @author  G.Sasaki
 * @data    2021/10/4
 * @details SMethodによる計算ライブラリです．辻先生の論文を参考にしています．
 * */

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
    //計算した速度
    std::vector<double> wm {0.0};
    //一周のパルス数
    int P;
    //サンプリング時間
    double Ts;
    //カットオフ周波数
    double Gv;
    //LPF前の速度
    double wm_ = 0.0;
    //パルスバッファ
    int PulseBuf = 0;
    //パルス数バッファ
    std::vector<int> Me;
    //2つの連続したパルス変動間のサンプル数
    int Ms = 0;
    //速度計算をリセットするフラグ
    bool ResetFlag = false;
    //初回実行時のフラグ
    bool FirstFlag = true;
};


#endif //ARCS_SMETHOD_H
