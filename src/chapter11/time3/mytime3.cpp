// implementing Time methods
// Created by Jetty on 2022/9/16.
//
#include "mytime3.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time &t) const {
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time &t) const {
    Time diff;
    int tol1;
    int tol2;
    tol1 = t.minutes + 60 * t.hours;
    tol2 = minutes + 60 * hours;
    diff.minutes = (tol2 - tol1) % 60;
    diff.hours = (tol2 - tol1) / 60;
    return diff;
}

Time Time::operator*(double multi) const {
    Time result;
    long totalminutes = hours * multi * 60 + minutes * multi;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t) {
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}