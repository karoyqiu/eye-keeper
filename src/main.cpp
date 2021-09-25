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
#include <boost/bind.hpp>
#include <boost/chrono/chrono.hpp>
#include <boost/thread/thread.hpp>

#include "beeper.h"
#include "humaninfraredsensor.h"


int main(int argc, char *argv[])
{
    wiringPiSetup();

    Beeper beeper(5, 6);
    HumanInfraredSensor humanSensor(1, 4);
    humanSensor.onEnter([&beeper]() { beeper.beep(); });
    humanSensor.onLeave([&beeper]() { beeper.beep(); delay(200); beeper.beep(); });

    boost::signals2::signal<void()> onTimeout;
    onTimeout.connect(boost::bind(&HumanInfraredSensor::check, &humanSensor));

    for (;;)
    {
        boost::this_thread::sleep_for(boost::chrono::seconds(1));
        onTimeout();
    }

    return 0;
}
