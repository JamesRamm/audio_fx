
#include <vector>

// ramshackle recording namespace. Just because...
namespace ramshackle {

    class Delay {

        public:
            Delay();
            ~Delay();
            void process(std::vector<double> &input, std::vector<double> &output);
            void setDelayMs(double ms);
            void setSampleRate(float samplesPerSecond);

        private:
            int delayInSamples;
            int samplesPerMs;
            std::vector<double> buffer;
            int bufferPos;
    }

}