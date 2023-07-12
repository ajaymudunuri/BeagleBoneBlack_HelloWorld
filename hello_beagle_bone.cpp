/**
 * @file hello_beagle_bone.cpp
 * @author Ajay Mudunuri (ajay.mudunuri@yahoo.com)
 * @brief Hello world in beagle bone
 * @version 0.1
 * @date 2023-07-11
 * 
 * @copyright Copyright (c) 2023
 * 
 * @details Print Hello statement and blink LED for 10 seconds
 */

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <chrono>
#include <iomanip>
#include <ctime>

using namespace std;
using namespace chrono;

void addDate(void);
void addTimeStamp(void);

int main(void)
{
    cout << "Hello Beagle Bone from Host PC" << endl;

    ofstream LEDHandle;
    string LEDBrightness = "/sys/devices/platform/leds/leds/beaglebone:green:usr3/brightness";

    addDate();
    addTimeStamp();
    cout << "LED Flash start..." << endl;

    for(int i=0; i < 10; i++)
    {
        addTimeStamp();
        cout << "Turning LED On..." << endl;
        LEDHandle.open(LEDBrightness);
        if(LEDHandle)
        {
            LEDHandle << "1" << endl;
            LEDHandle.close();
        }
        sleep(1);

        addTimeStamp();
        cout << "Turning LED Off..." << endl;
        LEDHandle.open(LEDBrightness);
        if(LEDHandle)
        {
            LEDHandle << "0" << endl;
            LEDHandle.close();
        }
        sleep(1);
    }

    addDate();
    addTimeStamp();
    cout << "LED Flash end" << endl;

    return 0;
}

void addDate(void)
{
    auto now = system_clock::now();
    time_t now_time = (system_clock::to_time_t(now));
    auto currentTime = gmtime(&now_time);
    auto datestamp = put_time(currentTime, "%Y-%m-%d_");
    cout << datestamp ;
}

void addTimeStamp(void)
{
    auto now = system_clock::now();
    auto milliSec = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;
    time_t now_time = (system_clock::to_time_t(now));
    auto currentTime = gmtime(&now_time);
    auto timestamp = put_time(currentTime, "%H:%M:%S");
    cout << timestamp <<  '.' << setfill('0') << setw(3) << milliSec.count() << " : ";
}
