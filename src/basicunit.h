/*! ***********************************************************************************************
 *
 * \file        BasicUnit.h
 * \brief       BasicUnit 类头文件。
 *
 * \version     1.0
 * \date        2021-09-25
 *
 * \author      Roy QIU <karoyqiu@gmail.com>
 * \copyright   © 2021 karoyqiu。
 *
 **************************************************************************************************/
#pragma once
#include <boost/noncopyable.hpp>
#include <boost/signals2.hpp>


// 基础元件
class BasicUnit : private boost::noncopyable
{
public:
    using OnEvent = boost::signals2::signal<void()>;
    using OnEventSlot = OnEvent::slot_type;

    BasicUnit(int power, int io, bool input = false);
    virtual ~BasicUnit();

protected:
    static void exportPin(int pin, bool input);

protected:
    int power_;
    int io_;
};

