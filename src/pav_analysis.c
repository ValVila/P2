#include <math.h>
#include "pav_analysis.h"



float compute_power(const float *x, unsigned int N) {
    float pow = 0;    
    for (unsigned int i = 0; i < N; i++){
        pow = pow + (x[i]*x[i]);
    }
    pow = 10*log10(pow/N);
   return pow;
}

float compute_am(const float *x, unsigned int N) {
    float am = 0;  
    for(unsigned int i = 0; i < N; i++){
        am = am + fabs(x[i]);
    }
    
    am = am / N;
   
    return am;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    float zcr = 0;  
    for (unsigned int i = 1; i < N; i++) {
        if( (x[i]>0 && x[i-1]<0) || (x[i]<0 && x[i-1]>0)){
            zcr++;
        }
    }

    zcr = fm*zcr/(2*(N-1));
    
    return zcr;
  
}
