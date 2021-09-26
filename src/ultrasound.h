/*! ***********************************************************************************************
 *
 * \file        ultrasound.h
 * \brief       Ultrasound 类头文件。
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


class Ultrasound : public BasicUnit
{
public:
    Ultrasound(int vcc, int trig, int echo);

    boost::signals2::connection onTooClose(const OnEventSlot &slot)
    {
        return onTooClose_.connect(slot);
    }

    boost::signals2::connection onFarEnough(const OnEventSlot &slot)
    {
        return onFarEnough_.connect(slot);
    }

    void trigger();

private:
    static void onEcho();

private:
    using Clock = boost::chrono::steady_clock;
    static Ultrasound *instance_;

    OnEvent onTooClose_;
    OnEvent onFarEnough_;
    Clock::time_point lastHigh_;
    int echo_;
    int threshold_;
};
