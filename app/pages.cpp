#include <QtWidgets>
#include <QQuickView>
#include <QGroupBox>

#include "pages.h"
#include "mainwidget.h"
#include "configdialog.h"

MainMenuPage::MainMenuPage(QWidget *parent)
    : QWidget(parent)
{
    /*view = new QDeclarativeView(this);
    view->rootContext()->setContextProperty("MainMenuPage",this);    //this
    view->setSource(QUrl("main.qml"));
*/
    QQuickView *view = new QQuickView();

    /* NB: We load the QML from a .qrc file becuase the Qt build step
     * that packages the final .app on Mac forgets to add the QML
     * if you reference it directly
     */
    view->setSource(QUrl("main.qml"));

    /* Enable transparent background on the QQuickView
     * Note that this currently does not work on Windows
     */
#ifndef _WIN32
    view->setClearBeforeRendering(true);
    view->setColor(QColor(Qt::transparent));
#endif

    // Attach to the 'mouse moved' signal
    QQuickItem *root = view->rootObject();
   /* connect(
        root,
        SIGNAL(joystick_moved(double, double)),
        this,
        SLOT(joystick_moved(double, double))
    );*/
    QWidget *container = QWidget::createWindowContainer(view, this);

    container->setMinimumSize(200, 200);
    container->setMaximumSize(300, 300);
    container->setFocusPolicy(Qt::TabFocus);


    QPushButton *startUpdateButton1 = new QPushButton(tr("Personal Profile"));
    QPushButton *startUpdateButton2 = new QPushButton(tr("Personal e-Doctor"));
    QPushButton *startUpdateButton3 = new QPushButton(tr("Microphone Breath Monitoring"));
    QPushButton *startUpdateButton4 = new QPushButton(tr("Sensors Breath Monitoring"));
    QPushButton *startUpdateButton5= new QPushButton(tr("Asthma-pedia"));
    QPushButton *startUpdateButton6= new QPushButton(tr("Asthma-connect"));
    QPushButton *startUpdateButton7= new QPushButton(tr("Help"));
    int a=1;
    int b=2;
    int c=3;
    int d=4;
            int e=5;
    int f=6;
            int g=8;
    //connect(startUpdateButton1, SIGNAL (clicked()), pagesWidget, SLOT (handleButton1()));
    connect(startUpdateButton2, SIGNAL (clicked()), this, SLOT (handleButton2()));
    connect(startUpdateButton3, SIGNAL (clicked()), this, SLOT (handleButton3()));
    connect(startUpdateButton4, SIGNAL (clicked()), this, SLOT (handleButton4()));
    connect(startUpdateButton5, SIGNAL (clicked()), this, SLOT (handleButton5()));
    connect(startUpdateButton6, SIGNAL (clicked()), this, SLOT (handleButton6()));
    connect(startUpdateButton7, SIGNAL (clicked()), this, SLOT (handleButton7()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(startUpdateButton1);
    mainLayout->addWidget(startUpdateButton2);
    mainLayout->addWidget(startUpdateButton3);
    mainLayout->addWidget(startUpdateButton4);
    mainLayout->addWidget(startUpdateButton5);
    mainLayout->addWidget(startUpdateButton6);
    mainLayout->addWidget(startUpdateButton7);

    /*QComboBox *pageComboBox1 = new QComboBox;
        pageComboBox1->addItem(tr("Page 1"));
        pageComboBox1->addItem(tr("Page 2"));
        pageComboBox1->addItem(tr("Page 3"));
        pageComboBox1->addItem(tr("Page 4"));
        pageComboBox1->addItem(tr("Page 5"));
        pageComboBox1->addItem(tr("Page 6"));
        connect(pageComboBox1, SIGNAL(activated(int)),
                pagesWidget, SLOT(setCurrentIndex(int)));*/
      //connect(pageComboBox, SIGNAL(activated(int)), dialog.pagesWidget, SLOT(setCurrentIndex(int)));
    /*connect(startUpdateButton1,
            SIGNAL(clicked(bool)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));
    connect(startUpdateButton2,
            SIGNAL(clicked(bool)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));
    connect(startUpdateButton3,
            SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));
    connect(startUpdateButton4,
            SIGNAL(clicked(bool)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));
            */
    //connect(startUpdateButton5,
      //      SIGNAL(clicked(bool)),
        //    this, SLOT(changePage(QListWidgetItem*,helpButton)));
  //  connect(startUpdateButton5,
    //        SIGNAL(clicked(bool)),
      //      ConfigDialog, SLOT(changePage(helpButton, helpButton)));
   // contentsWidget,
     //           SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
       //         this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)
    mainLayout->addWidget(container);
   // mainLayout->addWidget(buttonPanelLayout);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}
void MainMenuPage::handleButton1(){
    dynamic_cast<QStackedWidget*>(parent())->setCurrentIndex(1);
}
void MainMenuPage::handleButton2(){
    dynamic_cast<QStackedWidget*>(parent())->setCurrentIndex(2);
}
void MainMenuPage::handleButton3(){
    dynamic_cast<QStackedWidget*>(parent())->setCurrentIndex(3);
}
void MainMenuPage::handleButton4(){
    dynamic_cast<QStackedWidget*>(parent())->setCurrentIndex(4);
}
void MainMenuPage::handleButton5(){
    dynamic_cast<QStackedWidget*>(parent())->setCurrentIndex(5);
}
void MainMenuPage::handleButton6(){
    dynamic_cast<QStackedWidget*>(parent())->setCurrentIndex(6);
}
void MainMenuPage::handleButton7(){
    dynamic_cast<QStackedWidget*>(parent())->setCurrentIndex(7);
}
void MainMenuPage::joystick_moved(double, double){
    dynamic_cast<QStackedWidget*>(parent())->setCurrentIndex(4);
}

void HelpPage::handlesButton(){
    dynamic_cast<QStackedWidget*>(parent())->setCurrentIndex(1);
}


PersonalProfilePage::PersonalProfilePage(QWidget *parent)
    : QWidget(parent)
{
    QGroupBox *configGroup = new QGroupBox(tr("Server configuration"));

    QLabel *serverLabel = new QLabel(tr("Server:"));
    QComboBox *serverCombo = new QComboBox;
    serverCombo->addItem(tr("Qt (Australia)"));
    serverCombo->addItem(tr("Qt (Germany)"));
    serverCombo->addItem(tr("Qt (Norway)"));
    serverCombo->addItem(tr("Qt (People's Republic of China)"));
    serverCombo->addItem(tr("Qt (USA)"));

    QHBoxLayout *serverLayout = new QHBoxLayout;
    serverLayout->addWidget(serverLabel);
    serverLayout->addWidget(serverCombo);

    QVBoxLayout *configLayout = new QVBoxLayout;
    configLayout->addLayout(serverLayout);
    configGroup->setLayout(configLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(configGroup);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

PersonalDoctorPage::PersonalDoctorPage(QWidget *parent)
    : QWidget(parent)
{
    QGroupBox *configGroup = new QGroupBox(tr("Server configuration"));

    QLabel *serverLabel = new QLabel(tr("Server:"));
    QComboBox *serverCombo = new QComboBox;
    serverCombo->addItem(tr("Qt (Australia)"));
    serverCombo->addItem(tr("Qt (Germany)"));
    serverCombo->addItem(tr("Qt (Norway)"));
    serverCombo->addItem(tr("Qt (People's Republic of China)"));
    serverCombo->addItem(tr("Qt (USA)"));

    QHBoxLayout *serverLayout = new QHBoxLayout;
    serverLayout->addWidget(serverLabel);
    serverLayout->addWidget(serverCombo);

    QVBoxLayout *configLayout = new QVBoxLayout;
    configLayout->addLayout(serverLayout);
    configGroup->setLayout(configLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(configGroup);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

MicrophoneBreathMonitoringPage::MicrophoneBreathMonitoringPage(QWidget *parent)
    : QWidget(parent)
{
    QGroupBox *updateGroup = new QGroupBox(tr("Package selection"));
    QCheckBox *systemCheckBox = new QCheckBox(tr("Update system"));
    QCheckBox *appsCheckBox = new QCheckBox(tr("Update applications"));
    QCheckBox *docsCheckBox = new QCheckBox(tr("Update documentation"));

    QGroupBox *packageGroup = new QGroupBox(tr("Existing packages"));

    QListWidget *packageList = new QListWidget;
    QListWidgetItem *qtItem = new QListWidgetItem(packageList);
    qtItem->setText(tr("Qt"));
    QListWidgetItem *qsaItem = new QListWidgetItem(packageList);
    qsaItem->setText(tr("QSA"));
    QListWidgetItem *teamBuilderItem = new QListWidgetItem(packageList);
    teamBuilderItem->setText(tr("Teambuilder"));

    QPushButton *startUpdateButton = new QPushButton(tr("Start update"));

    QVBoxLayout *updateLayout = new QVBoxLayout;
    updateLayout->addWidget(systemCheckBox);
    updateLayout->addWidget(appsCheckBox);
    updateLayout->addWidget(docsCheckBox);
    updateGroup->setLayout(updateLayout);

    QVBoxLayout *packageLayout = new QVBoxLayout;
    packageLayout->addWidget(packageList);
    packageGroup->setLayout(packageLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(updateGroup);
    mainLayout->addWidget(packageGroup);
    mainLayout->addSpacing(12);
    mainLayout->addWidget(startUpdateButton);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

SensorsBreathMonitoringPage::SensorsBreathMonitoringPage(QWidget *parent)
    : QWidget(parent)
{
    QGroupBox *updateGroup = new QGroupBox(tr("Package selection"));
    QCheckBox *systemCheckBox = new QCheckBox(tr("Update system"));
    QCheckBox *appsCheckBox = new QCheckBox(tr("Update applications"));
    QCheckBox *docsCheckBox = new QCheckBox(tr("Update documentation"));

    QGroupBox *packageGroup = new QGroupBox(tr("Existing packages"));

    QListWidget *packageList = new QListWidget;
    QListWidgetItem *qtItem = new QListWidgetItem(packageList);
    qtItem->setText(tr("Qt"));
    QListWidgetItem *qsaItem = new QListWidgetItem(packageList);
    qsaItem->setText(tr("QSA"));
    QListWidgetItem *teamBuilderItem = new QListWidgetItem(packageList);
    teamBuilderItem->setText(tr("Teambuilder"));

    QPushButton *startUpdateButton = new QPushButton(tr("Start update"));

    QVBoxLayout *updateLayout = new QVBoxLayout;
    updateLayout->addWidget(systemCheckBox);
    updateLayout->addWidget(appsCheckBox);
    updateLayout->addWidget(docsCheckBox);
    updateGroup->setLayout(updateLayout);

    QVBoxLayout *packageLayout = new QVBoxLayout;
    packageLayout->addWidget(packageList);
    packageGroup->setLayout(packageLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(updateGroup);
    mainLayout->addWidget(packageGroup);
    mainLayout->addSpacing(12);
    mainLayout->addWidget(startUpdateButton);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

HelpPage::HelpPage(QWidget *parent)
    : QWidget(parent)
{
    QGroupBox *packagesGroup = new QGroupBox(tr("Look for packages"));

    QLabel *nameLabel = new QLabel(tr("Name:"));
    QLineEdit *nameEdit = new QLineEdit;

    QLabel *dateLabel = new QLabel(tr("Released after:"));
    QDateTimeEdit *dateEdit = new QDateTimeEdit(QDate::currentDate());

    QCheckBox *releasesCheckBox = new QCheckBox(tr("Releases"));
    QCheckBox *upgradesCheckBox = new QCheckBox(tr("Upgrades"));

    QSpinBox *hitsSpinBox = new QSpinBox;
    hitsSpinBox->setPrefix(tr("Return up to "));
    hitsSpinBox->setSuffix(tr(" results"));
    hitsSpinBox->setSpecialValueText(tr("Return only the first result"));
    hitsSpinBox->setMinimum(1);
    hitsSpinBox->setMaximum(100);
    hitsSpinBox->setSingleStep(10);

  /* view = new QDeclarativeView(this);
    view->rootContext()->setContextProperty("MainMenuPage",this);    //this
    view->setSource(QUrl("main.qml"));

   // QQuickView *view = new QQuickView();
    QWidget *container = QWidget::createWindowContainer(view, this);

    container->setMinimumSize(200, 200);
    container->setMaximumSize(300, 300);
    container->setFocusPolicy(Qt::TabFocus);
*/
   // view->setSource(QUrl("qrc:/qml/main.qml"));

    QPushButton *startQueryButton = new QPushButton(tr("Start query"));
     connect(startQueryButton, SIGNAL (clicked()), this, SLOT (handlesButton()));

    QGridLayout *packagesLayout = new QGridLayout;
    packagesLayout->addWidget(nameLabel, 0, 0);
    packagesLayout->addWidget(nameEdit, 0, 1);
    packagesLayout->addWidget(dateLabel, 1, 0);
    packagesLayout->addWidget(dateEdit, 1, 1);
    packagesLayout->addWidget(releasesCheckBox, 2, 0);
    packagesLayout->addWidget(upgradesCheckBox, 3, 0);
    packagesLayout->addWidget(hitsSpinBox, 4, 0, 1, 2);
    packagesGroup->setLayout(packagesLayout);

   /// QQuickView *view = new QQuickView();

    /* NB: We load the QML from a .qrc file becuase the Qt build step
     * that packages the final .app on Mac forgets to add the QML
     * if you reference it directly
     */
  //  view->setSource(QUrl("qrc:/main.qml"));

    /* Enable transparent background on the QQuickView
     * Note that this currently does not work on Windows
     */
#ifndef _WIN32
    view->setClearBeforeRendering(true);
    view->setColor(QColor(Qt::transparent));
#endif

    // Attach to the 'mouse moved' signal
   // QQuickItem *root = view->rootObject();
   /* connect(
        root,
        SIGNAL(clicked(bool)),
        this,
        SLOT(handleButton3())
    );

    // Create a container widget for the QQuickView
    QWidget *container = QWidget::createWindowContainer(view, this);
    container->setMinimumSize(160, 160);
    container->setMaximumSize(160, 160);
    container->setFocusPolicy(Qt::TabFocus);
    mainLayout->addWidget(container);

*/
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(packagesGroup);
    //mainLayout->addWidget(container);
    mainLayout->addSpacing(12);
    mainLayout->addWidget(startQueryButton);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

