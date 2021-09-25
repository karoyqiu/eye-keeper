/*! ***********************************************************************************************
 *
 * \file        basicunit.cpp
 * \brief       BasicUnit 类源文件。
 *
 * \version     1.0
 * \date        2021-09-25
 *
 * \author      Roy QIU <karoyqiu@gmail.com>
 * \copyright   © 2021 karoyqiu。
 *
 **************************************************************************************************/
#include "basicunit.h"

#include <string>
#include <boost/process.hpp>
#include <wiringPi.h>

namespace bp = boost::process;


BasicUnit::BasicUnit(int power, int io, bool input)
    : power_(power)
    , io_(io)
{
    exportPin(power, false);
    exportPin(io, input);

    pinMode(power, OUTPUT);
    pinMode(io, input ? INPUT : OUTPUT);

    digitalWrite(power, HIGH);
}


BasicUnit::~BasicUnit()
{
    digitalWrite(power_, LOW);
}


void BasicUnit::exportPin(int pin, bool input)
{
    static const auto gpio = bp::search_path("gpio");
    auto bcm = wpiPinToGpio(pin);
    bp::system(gpio, "export", std::to_string(bcm), (input ? "in" : "out"));
}
