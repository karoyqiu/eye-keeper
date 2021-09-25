/*! ***********************************************************************************************
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


class Beeper
{
public:
    Beeper(int vcc, int io);
    ~Beeper();

    void beep();

private:
    int vcc_;
    int io_;
};
