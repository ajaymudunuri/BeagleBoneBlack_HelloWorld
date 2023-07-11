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
#include <stdio.h>
#include <unistd.h>
using namespace std;

int main(void)
{
    cout << "Hello Beagle Bone from Host PC" << endl;

    FILE *LEDHandle = NULL;
    char *LEDBrightness = "/sys/devices/platform/leds/leds/beaglebone:green:usr3/brightness";

    cout << "LED Flash start..." << endl;

    for(int i=0; i < 10; i++)
    {
        if((LEDHandle = fopen(LEDBrightness, "r+"))!=NULL)
        {
            fwrite("1", sizeof(char), 1, LEDHandle);
            fclose(LEDHandle);
        }
        sleep(1);

        if((LEDHandle = fopen(LEDBrightness, "r+"))!=NULL)
        {
            fwrite("0", sizeof(char), 1, LEDHandle);
            fclose(LEDHandle);
        }
        sleep(1);
    }

    cout << "LED Flash end" << endl;

    return 0;
}
