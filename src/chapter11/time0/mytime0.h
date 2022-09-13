/* Time class before operator overloading
 * @Author: Jetty 
 * @Date: 2022-09-13 10:09:35 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-13 10:28:35
 */
#ifndef MYTIME0_H_
#define MYTIME0_H_

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
        Time Sum(const Time & t) const;
        void Show() const;
};

#endif