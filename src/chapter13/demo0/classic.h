// classic.h
// Created by Jetty on 2022/10/11.
//

#ifndef C_CLASSIC_H
#define C_CLASSIC_H

// 基类Cd
class Cd {
private:
    /*
     * performers: 表演者
     * label: 标签
     * selections: 选择的人数
     * playtime: 演奏的时间
     */
    char * performers = nullptr;
    char * label = nullptr;
    int selections = 0;
    double playtime = 0;
public:
    // 有参构造函数
    Cd(const char * s1, const char * s2, int n, double x);
    // 复制构造函数
    Cd(const Cd & d);
    // 无参构造函数
    Cd() = default;
    // 显式析构函数
    virtual ~Cd();
    // 显示信息
    virtual void Report() const;
    // 重载的赋值运算符
    Cd & operator=(const Cd & d);
};

// 继承于Cd的派生类Classic
class Classic : public Cd {
private:
    // 演奏的曲目
    char * track = nullptr;
public:
    // 有参构造函数
    Classic(const char * track, const char * s1, const char * s2, int n, double x);
    // 复制构造函数
    Classic(const Classic & c);
    // 无参构造函数
    Classic() = default;
    // 显式析构函数
    ~Classic() override;
    // 显示信息
    void Report() const override;
    // 重载的赋值运算符
    Classic & operator=(const Classic & c);
};

#endif //C_CLASSIC_H
