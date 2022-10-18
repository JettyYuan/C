// emp.h
// Created by Jetty on 2022/10/16.
//

#ifndef C_EMP_H
#define C_EMP_H
#include <iostream>
#include <string>
using std::string;

class abString_emp {
private:
    string fName;
    string lName;
    string job;
public:
    abString_emp() = default;
    __attribute__((unused)) abString_emp(const string & fn, const string & ln, const string & j);

    virtual void Data() const;
    virtual void ShowAll() const;
    virtual void SetAll();
    friend std::ostream & operator<<(std::ostream & os, const abString_emp & e);
    virtual ~abString_emp() = default;
};

class employee : public abString_emp {
public:
    employee() = default;
    employee(const string & fn, const string & ln, const string & j);
    void ShowAll() const override;
    void SetAll() override;
    ~employee() override = default;
};

class manager : virtual public abString_emp {
private:
    int inChargeOf = 0;
protected:
    __attribute__((unused)) int InChargeOf() const {return inChargeOf;}
    __attribute__((unused)) int & InChargeOf() {return inChargeOf;}
public:
    manager() = default;
    manager(const string & fn, const string & ln, const string & j, int ico = 0);
    __attribute__((unused)) manager(const abString_emp & e, int ico);
    manager(const manager & m);
    void Data() const override;
    void ShowAll() const override;
    void SetAll() override;
    ~manager() override = default;
};

class fink : virtual public abString_emp {
private:
    string reportStr;
protected:
    __attribute__((unused)) string ReportsTo() const {return reportStr;}
    __attribute__((unused)) string & ReportsTo() {return reportStr;}
public:
    fink() = default;
    fink(const string & fn, const string & ln, const string & j, const string & rpo);
    __attribute__((unused)) fink(const abString_emp & e, const string & rpo);
    fink(const fink & e);
    void Data() const override;
    void ShowAll() const override;
    void SetAll() override;
    ~fink() override = default;
};

class highFink : public manager, public fink {
public:
    highFink() = default;
    __attribute__((unused)) highFink(const string & fn, const string & ln, const string & j, const string & rpo, int ico);
    __attribute__((unused)) highFink(const abString_emp & e, const string & rpo, int ico);
    __attribute__((unused)) highFink(const fink & f, int ico);
    highFink(const manager & m, const string & rpo);
    __attribute__((unused)) highFink(const highFink & h);
    void Data() const override;
    void ShowAll() const override;
    void SetAll() override;
    ~highFink() override = default;
};

#endif //C_EMP_H
