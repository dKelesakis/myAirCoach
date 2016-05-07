#ifndef PAGES_H
#define PAGES_H

#include <QWidget>

class PersonalProfilePage : public QWidget
{
public:
    PersonalProfilePage(QWidget *parent = 0);
};

class PersonalDoctorPage : public QWidget
{
public:
    PersonalDoctorPage(QWidget *parent = 0);
};

class MicrophoneBreathMonitoringPage : public QWidget
{
public:
    MicrophoneBreathMonitoringPage(QWidget *parent = 0);
};

class SensorsBreathMonitoringPage : public QWidget
{
public:
   SensorsBreathMonitoringPage(QWidget *parent = 0);
};

class HelpPage : public QWidget
{
public:
    HelpPage(QWidget *parent = 0);
};

#endif
