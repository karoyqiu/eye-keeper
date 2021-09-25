/*! ***********************************************************************************************
 *
 * \file        humaninfraredsensor.cpp
 * \brief       HumanInfraredSensor 类源文件。
 *
 * \version     1.0
 * \date        2021-09-25
 *
 * \author      Roy QIU <karoyqiu@gmail.com>
 * \copyright   © 2021 karoyqiu。
 *
 **************************************************************************************************/
#include "humaninfraredsensor.h"

#include <iostream>
#include <boost/chrono/chrono_io.hpp>

HumanInfraredSensor *HumanInfraredSensor::instance_ = nullptr;


HumanInfraredSensor::HumanInfraredSensor(int power, int out)
    : BasicUnit(power, out, true)
    , entered_(false)
    , threshold_(boost::chrono::seconds(5))
{
    BOOST_ASSERT(instance_ == nullptr);
    instance_ = this;
    wiringPiISR(out, INT_EDGE_RISING, onRising);
}


void HumanInfraredSensor::check()
{
    if (entered_)
    {
        auto diff = Clock::now() - lastRising_;

        if (diff >= threshold_)
        {
            entered_ = false;
            onLeave_();
        }
    }
}


void HumanInfraredSensor::onRising()
{
    auto now = Clock::now();
    std::cout << now << "Rising" << std::endl;

    auto diff = now - instance_->lastRising_;
    instance_->lastRising_ = now;

    if (!instance_->entered_ && diff >= instance_->threshold_)
    {
        instance_->entered_ = true;
        instance_->onEnter_();
    }
}
