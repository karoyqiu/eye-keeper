/*! ***********************************************************************************************
 *
 * \file        main.cpp
 * \brief       eyekeeper 主源文件。
 *
 * \version     1.0
 * \date        2021-09-17
 *
 * \author      John Doe <johndoe@gmail.com>
 * \copyright   © 2021 A Company。
 *
 **************************************************************************************************/
#include <wiringPi.h>

#include <iostream>


static void onBodyTriggered()
{
    time_t now = 0;
    time(&now);
    std::cout << ctime(&now) << " Signal " << digitalRead(4) << std::endl;
}


int main(int argc, char *argv[])
{
    wiringPiSetup();
    pinMode(1, OUTPUT);
    digitalWrite(1, HIGH);

    wiringPiISR(4, INT_EDGE_BOTH, onBodyTriggered);

    std::cout << "Input something to exit." << std::endl;
    std::getchar();

    return 0;
}
