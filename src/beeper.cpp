/*! ***********************************************************************************************
 *
 * \file        beeper.cpp
 * \brief       Beeper 类源文件。
 *
 * \version     1.0
 * \date        2021-09-25
 *
 * \author      Roy QIU <karoyqiu@gmail.com>
 * \copyright   © 2021 karoyqiu。
 *
 **************************************************************************************************/
#include "beeper.h"

#include <wiringPi.h>
#include <softTone.h>


Beeper::Beeper(int vcc, int io)
    : BasicUnit(vcc, io)
{
    digitalWrite(io_, HIGH);
    softToneCreate(io_);
}


void Beeper::beep()
{
    softToneWrite(io_, 4000);
    delay(200);
    softToneWrite(io_, 0);
}
