//
// Created by genki on 2021/10/04.
//

#include "SMethod.h"

/*! @brief コンストラクタ
 *  @param 一回転のエンコーダのパルス数[Pulses]
 *  @param  サンプリング時間[sec]
 *  @param  カットオフ周波数[rad/s]
 * */
SMethod::SMethod(int PulsePerRevolution, double SamplingTime, double CutOffFrequency):
    P(PulsePerRevolution),
    Ts(SamplingTime),
    Gv(CutOffFrequency)
    {
}


/*! @brief  デストラクタ
 * */
SMethod::~SMethod() = default;

/*! @brief  速度を計算する関数
 *  @param  Pulse パルス数[Pulses]
 *  @return 速度[rad/s]
 * */
double SMethod::GetSpeed(int Pulse) {
    if (FirstFlag){
        Me.push_back(0);
        wm.push_back(0.0);
        FirstFlag = false;
        Ms = 2;
    }

    Me.push_back(Pulse - PulseBuf);  //パルスの偏差を挿入
    PulseBuf = Pulse;

//    Me.push_back(Pulse);  //パルスの偏差を挿入

    if (!ResetFlag){
        /* 前回のパルス数と比較 */
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

/*! @brief  一回転のエンコーダのパルス数をセットする関数
 *  @param  一回転のエンコーダのパルス数[Pulses]
 * */
void SMethod::SetCPR(int PulsePerRevolution) {
    P = PulsePerRevolution;
}

/*! @brief  サンプリング時間をセットする関数
 *  @param  サンプリング時間[sec]
 * */
void SMethod::SetSamplTime(double SamplingTime) {
    Ts = SamplingTime;
}

/*! @brief  カットオフ周波数をセットする関数
 *  @param  カットオフ周波数[rad/s]
 * */
void SMethod::SetCutOffFreq(double CutOffFrequency) {
    Gv = CutOffFrequency;
}

