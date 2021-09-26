/*! ***********************************************************************************************
 *
 * \file        ultrasound.cpp
 * \brief       Ultrasound 类源文件。
 *
 * \version     1.0
 * \date        2021-09-25
 *
 * \author      Roy QIU <karoyqiu@gmail.com>
 * \copyright   © 2021 karoyqiu。
 *
 **************************************************************************************************/
#include "ultrasound.h"

#include <iostream>
#include <boost/chrono/chrono_io.hpp>

Ultrasound *Ultrasound::instance_ = nullptr;


Ultrasound::Ultrasound(int vcc, int trig, int echo)
    : BasicUnit(vcc, trig)
    , echo_(echo)
    , threshold_(180)
{
    BOOST_ASSERT(instance_ == nullptr);
    instance_ = this;
    wiringPiISR(echo, INT_EDGE_BOTH, onEcho);
}


void Ultrasound::trigger()
{
    digitalWrite(io_, HIGH);
    delayMicroseconds(100);
    digitalWrite(io_, LOW);
}


void Ultrasound::onEcho()
{
    auto now = Clock::now();
    auto level = digitalRead(instance_->echo_);

    if (level == LOW)
    {
        static const double speedOfSound = 34029.0 / INT64_C(1000000000);      // cm/ns
        auto diff = now - instance_->lastHigh_;
        auto dist = speedOfSound * diff.count() / 2;

        if (dist < instance_->threshold_)
        {
            std::cout << "Diff: " << diff << ", distance: " << dist << "cm" << std::endl;
            instance_->onTooClose_();
        }
        else
        {
            instance_->onFarEnough_();
        }
    }
    else
    {
        instance_->lastHigh_ = now;
    }
}
