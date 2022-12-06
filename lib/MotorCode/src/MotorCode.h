#ifndef MOTORCODE
#define MOTORCODE
#define UP 1350
#define DOWN 1309
#define START 160
#include <stdint.h>
#include <Arduino.h>

enum direction_t { back = LOW, front = HIGH };

class MOTOR
{
    public:
    MOTOR() = default;
    MOTOR(const uint8_t &speedpin, const uint8_t &directpin, const uint8_t &signalpin, const uint8_t &ch1pin, const uint8_t &ch2pin);

    void init();                //To initialise motor
    bool moveForward();         //Move motor forward
    bool moveBackward();        //Move motor backwards
    void stopMOTOR();           //Stop motor

    // Methods for the remote control
   int64_t ch1Data();           //Get channel1 data
   int64_t ch2Data();           //Get channel2 data
   int64_t _ch2Data, _ch1Data;      //Variables to store channel inputs

    private:
    const uint8_t& speedCal(int64_t& ch2data, const direction_t& dir);
    uint8_t  _speedpin, _directpin, _signalpin;
    uint8_t _ch1pin, _ch2pin;       //pin for channels 1 and 2
    int64_t ch2Last;                 //Stores last value of channel 2 data
    int8_t lastSpeed;
};


#endif
