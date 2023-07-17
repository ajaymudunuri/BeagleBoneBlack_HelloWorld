/**
 * @file hello_beagle_bone.cpp
 * @author Ajay Mudunuri (ajay.mudunuri@yahoo.com)
 * @brief Hello world in beagle bone
 * @version 0.1
 * @date 2023-07-11
 * 
 * @copyright Copyright (c) 2023
 * 
 * @details Print Hello statement and blink LED for 20 seconds
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

/**
 * @brief Main function for hello world program in beagle bone black
 * 
 * @details This function prints string to the console and flashes an LED every 1 second
 *          for 20 seconds
 * 
 * @return int 
 */
int main(void)
{
    cout << "Hello Beagle Bone from Host PC" << endl;

    ofstream LEDHandle; /**< Output file stream handle for LED */
    string LEDBrightness = "/sys/devices/platform/leds/leds/beaglebone:green:usr3/brightness"; /**< String for LED brightness command */

    /**
     * Print date and time stamp with message showing the start of LED flashing
     */
    addDate();
    addTimeStamp();
    cout << "LED Flash start..." << endl;

    /**
     * For 10 times
     */
    for(int i=0; i < 10; i++)
    {
        /**
         * -# Add only time stamp each time the LED is turned ON
         */
        addTimeStamp();
        cout << "Turning LED On..." << endl;
        /**
         * -# Open the handler for LEDBrightness folder in linux
         * -# Write '1' to the brightness handler to turn ON the LED
         * -# Close the handler for LEDBrightness folder
         * -# Sleep for 1 second
         */
        LEDHandle.open(LEDBrightness);
        if(LEDHandle)
        {
            LEDHandle << "1" << endl;
            LEDHandle.close();
        }
        sleep(1);

        /**
         * -# Add only time stamp each time the LED is turned OFF
         */
        addTimeStamp();
        cout << "Turning LED Off..." << endl;
        /**
         * -# Open the handler for LEDBrightness folder in linux
         * -# Write '0' to the brightness handler to turn OFF the LED
         * -# Close the handler for LEDBrightness folder
         * -# Sleep for 1 second
         */
        LEDHandle.open(LEDBrightness);
        if(LEDHandle)
        {
            LEDHandle << "0" << endl;
            LEDHandle.close();
        }
        sleep(1);
    }

    /**
     * Print date and time stamp with message showing the end of LED flashing
     */
    addDate();
    addTimeStamp();
    cout << "LED Flash end" << endl;

    return 0;
}

/**
 * @brief Function used to add date stamp to the console output
 * 
 * @details This function adds a date stamp to the console log/output
 *          in the YYYY-MM-DD_ format.
 * 
 * @attention This function adds an underscore "_" at the end of the date.
 *            This is meant to be used with the addTimeStamp() function which
 *            adds the time stamp after the underscore
 * 
 */
void addDate(void)
{
    auto now = system_clock::now(); /** Read the system clock */
    time_t now_time = (system_clock::to_time_t(now)); /** Convert to time format */
    auto currentTime = gmtime(&now_time); /** Convert to GM/UTC Time */
    auto datestamp = put_time(currentTime, "%Y-%m-%d_"); /** Format the datestamp string to "YYYY-MM-DD_" format */
    cout << datestamp ;
}

/**
 * @brief Function used to add time stamp to the console output
 * 
 * @details This function adds a time stamp to the console log/output
 *          in the HH:MM:SS.xxx format, where xxx is in milli-seconds
 * 
 */
void addTimeStamp(void)
{
    auto now = system_clock::now(); /** Read the system clock */
    auto milliSec = duration_cast<milliseconds>(now.time_since_epoch()) % 1000; /** Calculate millisecond time */
    time_t now_time = (system_clock::to_time_t(now)); /** Convert to time format */
    auto currentTime = gmtime(&now_time); /** Convert to GM/UTC Time */
    auto timestamp = put_time(currentTime, "%H:%M:%S"); /** Format the timestamp string to "HH-MM-SS" format */
    cout << timestamp <<  '.' << setfill('0') << setw(3) << milliSec.count() << " : "; /** Add milli-second data to the output string */
}
