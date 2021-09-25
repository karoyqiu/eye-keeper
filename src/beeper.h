﻿/*! ***********************************************************************************************
 *
 * \file        beeper.h
 * \brief       Beeper 类头文件。
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


// YX55675
class Beeper : public BasicUnit
{
public:
    Beeper(int vcc, int io);

    void beep();
};
