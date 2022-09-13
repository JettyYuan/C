/* class Plorg
 * @Author: Jetty 
 * @Date: 2022-09-12 10:46:13 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-12 11:10:53
 */
#ifndef DEMO6_H_
#define DEMO6_H_

class Plorg
{
    private:
        char name[20];
        double CI;
    public:
        Plorg(const char * n = "Plorga", double c = 50);
        void setCI();
        void show() const;
};

#endif