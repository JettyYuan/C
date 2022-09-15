/* Time class after operator overloading
 * @Author: Jetty 
 * @Date: 2022-09-15 20:07:28 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-15 20:15:12
 */
#ifndef MYTIME2_H_
#define MYTIME2_H_

class Time
{
    private:
        int hours;
        int minutes;
    public:
        Time();
        Time(int h, int m = 0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0, int m = 0);
        Time operator+(const Time & t) const;
        Time operator-(const Time & t) const;
        Time operator*(double mult) const;
        void Show() const;
};

#endif