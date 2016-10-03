/*
 * Playing around with audio filters
 */

#include <math.h>
#include "fftw3.h"

namespace ramshackle {
    const double twoPi = 2 * (double)M_PI;
    /*
     * sinc function
     */
    double sinc(x){
        return sin(M_PI * x) / (M_PI * x) 
    }

    /*
     * N-element impulse response of a sinc function, up to a given cutoff frequency
     */
    void sincIR(double cutoffFreq, double sampleRate, std::vector<double> &output){
        // Cutoff freq must be expressed as a fraction of the sample rate
        double doubleF = 2 * (cutoffFreq / sampleRate);
        for (int i = 0; i < output.size; ++i){
            output[i] = doubleF * sinc(doubleF * i); 
        }
    }


    /*
     * Compute a blackman window. Can be used to truncate 'infinite' functions (e.g. sinc function)
     */
    void blackmanWindow(std::vector<double> &output){
        int lessOne = output.size - 1;
        for (int i = 0; i < output.size; ++i){
            output[i] = 0.42 - 0.5 * cos(twoPi * i / lessOne) + 0.08 * cos(4 * M_PI * i / lessOne);
        }
    }

    /*
     * Simple FIR implementation. This the convolution of the input data with 
     * an impulse response expressed as a set of coefficients
     */
    void fir(std::vector<double> &output, std::vector<double> &input, std::vector<double> &coeffs){

        // In psuedo-code:
        // for each n 
        // for each k
        // temp += h[k] ** x[n - k] // ** denotes the convolution
        // y[n] is the sum of temp
        // h are the filter coefficients
        std::vector<double> temp(coeffs.size, 0.0);
        int n, k;
        for (n = 0; n < input.size; ++n){
            
            for (k = 0; k < coeffs.size; ++n){
                // shift data to left by 1
                temp[coeffs.size - k - 1] = temp[coeffs.size - k - 2];
            }
            // copy sample to buffer
            temp[0] = input[n];
            output[n] = 0;

            for (k = 0; k < input.size; ++n){
                output[n] += h[k] *temp[k]
            }
        }

    }


}