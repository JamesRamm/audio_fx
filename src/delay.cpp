/*
 * Implementation of a simple delay
 */
#include "delay.h"

ramshackle::Delay::Delay()
: samplesPerMs (44100*10E-3)
, delayInSamples (0)
, bufferPos (0)
{
    this->buffer.resize(44100, 0.0);
}

ramshackle::Delay::~Delay(){};

void ramshackle::Delay::setSampleRate(int samplesPerSecond){
    this->samplesPerMs = samplesPerSecond * 10E-3;
}

void ramshackle::Delay::setDelayMs(double ms){
    this->delayInSamples = (int)(ms * this->samplesPerMs);
    this->buffer.resize(this->delayInSamples, 0.0);
}

void ramshackle::Delay::process(std::vector<double> &input, std::vector<double> &output){

    int i, tmpBufferPos;
    int input_tail = input.size() - delayInSamples;

    tmpBufferPos = this->bufferPos;
    for (i = 0; i < input.size(); ++i){
        output[i] = this->buffer[tmpBufferPos];
        this->buffer[tmpBufferPos] = input[i];
        tmpBufferPos++;
        if (tmpBufferPos >= this->delayInSamples){
            tmpBufferPos = 0;
        }
    }
    this->bufferPos += input.size();
    while (this->bufferPos >= this->delayInSamples){
        this->bufferPos -= this->delayInSamples;
    }

}
