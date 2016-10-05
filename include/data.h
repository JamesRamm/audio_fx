

namespace ramshackle {

    /*
     * Hold information for N channels of audio data
     * Provides input and output buffers for processing data._Alias
     *
     *  TODO: Just experimental - not actually used yet... 
     *
     */
    class AudioData {
        public:
            setNumChannels(int N);
            int getNumChannels() const;
            float **inputData;
            float **outputData;
        
        private:
            int nChannels;        
    }


}
