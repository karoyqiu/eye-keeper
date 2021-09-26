/*! ***********************************************************************************************
 *
 * \file        humaninfraredsensor.h
 * \brief       HumanInfraredSensor 类头文件。
 *
 * \version     1.0
 * \date        2021-09-25
 *
 * \author      Roy QIU <karoyqiu@gmail.com>
 * \copyright   © 2021 karoyqiu。
 *
 **************************************************************************************************/
#pragma once
#include "basicunit.h"

#include <boost/atomic/atomic.hpp>
#include <boost/chrono/system_clocks.hpp>


// HC-SR501
class HumanInfraredSensor : public BasicUnit
{
public:
    HumanInfraredSensor(int power, int out);

    boost::signals2::connection onEnter(const OnEventSlot &slot)
    {
        return onEnter_.connect(slot);
    }

    boost::signals2::connection onLeave(const OnEventSlot &slot)
    {
        return onLeave_.connect(slot);
    }

    void check();

private:
    static void onRising();

private:
    using Clock = boost::chrono::steady_clock;
    static HumanInfraredSensor *instance_;
    OnEvent onEnter_;
    OnEvent onLeave_;
    boost::atomic<bool> entered_;
    Clock::time_point lastRising_;
    Clock::duration threshold_;
};
