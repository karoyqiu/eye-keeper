﻿/*! ***********************************************************************************************
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


// 基础元件
class BasicUnit : private boost::noncopyable
{
public:
    BasicUnit(int power, int io, bool input = false);
    virtual ~BasicUnit();

private:
    void exportPin(int pin, bool input);

protected:
    int power_;
    int io_;
};

