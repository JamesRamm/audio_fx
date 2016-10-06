
#include "exports.h"
#include <vector>

// ramshackle recording namespace. Just because...
namespace ramshackle {

    /*
     * Basic delay implementation. 
     * 
     * Will delay a signal by N samples. Sample rate can be set (samples per second) and delay specified in milliseconds
     */
    class AFX_DLL Delay {

        public:
            Delay();
            ~Delay();
            void process(std::vector<double> &input, std::vector<double> &output);
            void setDelayMs(double ms);
            void setSampleRate(int samplesPerSecond);

        private:
            int delayInSamples;
            double samplesPerMs;
            std::vector<double> buffer;
            int bufferPos;
	};

}