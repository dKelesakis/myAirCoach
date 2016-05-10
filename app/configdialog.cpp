#include <QtWidgets>

#include "configdialog.h"
#include "pages.h"
#include "mainwidget.h"

ConfigDialog::ConfigDialog()
{
    contentsWidget = new QListWidget;          //to aristero menu
    contentsWidget->setViewMode(QListView::IconMode);
    contentsWidget->setIconSize(QSize(96, 84));
    contentsWidget->setMovement(QListView::Static);
    contentsWidget->setMaximumWidth(128);
    contentsWidget->setSpacing(12);

    pagesWidget = new QStackedWidget;              //ta widget deksia
    pagesWidget->addWidget(new MainMenuPage);
    pagesWidget->addWidget(new PersonalProfilePage);
    pagesWidget->addWidget(new PersonalDoctorPage);
    pagesWidget->addWidget(new MicrophoneBreathMonitoringPage);
    pagesWidget->addWidget(new SensorsBreathMonitoringPage);
    pagesWidget->addWidget(new MainWidget);

    QPushButton *closeButton = new QPushButton(tr("Close"));      //to koympi katw deksia

    createIcons();
    contentsWidget->setCurrentRow(0);

    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    //horizontalLayout->addWidget(contentsWidget);
    horizontalLayout->addWidget(pagesWidget, 1);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(closeButton);

    QComboBox *pageComboBox = new QComboBox;
        pageComboBox->addItem(tr("Page 1"));
        pageComboBox->addItem(tr("Page 2"));
        pageComboBox->addItem(tr("Page 3"));
        pageComboBox->addItem(tr("Page 4"));
        pageComboBox->addItem(tr("Page 5"));
        pageComboBox->addItem(tr("Page 6"));
        connect(pageComboBox, SIGNAL(activated(int)),
                pagesWidget, SLOT(setCurrentIndex(int)));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(horizontalLayout);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    mainLayout->addLayout(buttonsLayout);
    mainLayout->addWidget(pageComboBox);
    setLayout(mainLayout);

    setWindowTitle(tr("myAirCoach Application"));
}

void ConfigDialog::createIcons()
{
    QListWidgetItem *mainMenuButton = new QListWidgetItem(contentsWidget);
    mainMenuButton->setIcon(QIcon(":/images/update.png"));
    mainMenuButton->setText(tr("Main Menu"));
    mainMenuButton->setTextAlignment(Qt::AlignHCenter);
    mainMenuButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);


    QListWidgetItem *personalProfileButton = new QListWidgetItem(contentsWidget);
    personalProfileButton->setIcon(QIcon(":/images/update.png"));
    personalProfileButton->setText(tr("Personal Profile"));
    personalProfileButton->setTextAlignment(Qt::AlignHCenter);
    personalProfileButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *personalDoctorButton = new QListWidgetItem(contentsWidget);
    personalDoctorButton->setIcon(QIcon(":/images/update.png"));
    personalDoctorButton->setText(tr("Personal Doctor"));
    personalDoctorButton->setTextAlignment(Qt::AlignHCenter);
    personalDoctorButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *microphoneBreathMonitoringPageButton = new QListWidgetItem(contentsWidget);
    microphoneBreathMonitoringPageButton ->setIcon(QIcon(":/images/query.png"));
    microphoneBreathMonitoringPageButton ->setText(tr("Microphone Breath Monitoring"));
    microphoneBreathMonitoringPageButton ->setTextAlignment(Qt::AlignHCenter);
    microphoneBreathMonitoringPageButton ->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *sensorsBreathMonitoringButton = new QListWidgetItem(contentsWidget);
    sensorsBreathMonitoringButton->setIcon(QIcon(":/images/update.png"));
    sensorsBreathMonitoringButton->setText(tr("Sensors Breath Monitoring"));
    sensorsBreathMonitoringButton->setTextAlignment(Qt::AlignHCenter);
    sensorsBreathMonitoringButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *helpButton = new QListWidgetItem(contentsWidget);
    helpButton->setIcon(QIcon(":/images/query.png"));
    helpButton->setText(tr("Help"));
    helpButton->setTextAlignment(Qt::AlignHCenter);
    helpButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    connect(contentsWidget,
            SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));
}

void ConfigDialog::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        current = previous;


    pagesWidget->setCurrentIndex(contentsWidget->row(current));
}

