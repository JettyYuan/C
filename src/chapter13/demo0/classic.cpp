// classic.cpp
// Created by Jetty on 2022/10/11.
//

#include <iostream>
#include "classic.h"
#include "cstring"
using std::strlen;
using std::strcpy;
using std::cout;
using std::endl;

Cd::Cd(const char * s1, const char * s2, int n, double x) {
    performers = new char[strlen(s1) + 1];
    strcpy(performers, s1);
    label = new char[strlen(s2) + 1];
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d) {
    this -> performers = new char[strlen(d.performers) + 1];
    strcpy(this -> performers, d.performers);
    this -> label = new char[strlen(d.label) + 1];
    strcpy(this -> label, d.label);
    this -> selections = d.selections;
    this -> playtime = d.playtime;
}

Cd::~Cd() {
    delete [] performers;
    delete [] label;
}

void Cd::Report() const {
    cout << "Performers: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "selections: " << selections << endl;
    cout << "playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d) {
    if (this == &d) return *this;
    delete[] this -> performers;
    this -> performers = new char[strlen(d.performers) + 1];
    strcpy(this -> performers, d.performers);
    delete [] this -> label;
    this -> label = new char[strlen(d.label) + 1];
    strcpy(this -> label, d.label);
    this -> selections = d.selections;
    this -> playtime = d.playtime;
    return *this;
}

Classic::Classic(const char * track, const char * s1, const char * s2, int n, double x) : Cd(s1, s2, n, x) {
    this -> track = new char[strlen(track) + 1];
    strcpy(this -> track, track);
}

Classic::Classic(const Classic & c) : Cd(c) {
    this -> track = new char[strlen(c.track) + 1];
    strcpy(this -> track, c.track);
}

Classic::~Classic() {
    delete [] track;
}

void Classic::Report() const {
    cout << "Track: " << track << endl;
    Cd::Report();
}

Classic & Classic::operator=(const Classic & c) {
    if (this == &c) return *this;
    Cd::operator=(c);
    delete [] this -> track;
    this -> track = new char[strlen(c.track) + 1];
    strcpy(this -> track, c.track);
    return *this;
}
