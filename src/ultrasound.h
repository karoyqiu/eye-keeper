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

#include <boost/signals2.hpp>


class Ultrasound : public BasicUnit
{
    using OnTooClose= boost::signals2::signal<void()>;

public:
    using OnTooCloseSlot = OnTooClose::slot_type;

    Ultrasound(int vcc, int trig, int echo);

    boost::signals2::connection onTooClose(const OnTooCloseSlot &slot)
    {
        return onTooClose_.connect(slot);
    }

    void trigger();

private:
    static void onEcho();

private:
    using Clock = boost::chrono::steady_clock;

    static Ultrasound *instance_;

    OnTooClose onTooClose_;
    Clock::time_point lastHigh_;
    int echo_;
    int threshold_;
};

