#ifndef PAGES_H
#define PAGES_H

#include <QWidget>

enum { NumGridRows = 3, NumButtons = 4 };



class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;

class MainMenuPage : public QWidget
{
public:
    MainMenuPage(QWidget *parent = 0);
};

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
private:
    QDeclarativeView *view;
private slots:
    void handleButton();
};

#endif
