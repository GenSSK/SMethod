# C++ Class for measurement motor velocity with high precision 
This C++ class makes measurement motor velocity based on the S Method.
S Method is proposed by Dr. Tsuji realizes measurement velocity with high precision using encoder pulse alteration.  

If you need more technical information, you can get following article:
    
> T. Tsuji, T. Hashimoto, H. Kobayashi, M. Mizuochi and K. Ohnishi, "A Wide-Range Velocity Measurement Method for Motion Control," in IEEE Transactions on Industrial Electronics, vol. 56, no. 2, pp. 510-519, Feb. 2009, doi: 10.1109/TIE.2008.2003208.

## Using Class

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
