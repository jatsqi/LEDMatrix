#include "mainwindow.h"
#include "LEDWidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* main = new QWidget(this);

    ledWidget_ = new LEDWidget(8, 8);
    ledWidget_->setMinimumSize(500, 500);
    ledWidget_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    buttonLayout_ = new QHBoxLayout;
    for(int i = 0; i < 8; ++i)
    {
        buttons_[i] = new QPushButton(QString("%1").arg(i));
        buttonLayout_->addWidget(buttons_[i]);

        QObject::connect(buttons_[i], &QPushButton::clicked, this, [=]() {
            onActionButtonClicked(i);
        });
    }

    mainLayout_ = new QVBoxLayout;
    mainLayout_->addWidget(ledWidget_);
    mainLayout_->addLayout(buttonLayout_);

    main->setLayout(mainLayout_);
    setCentralWidget(main);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onActionButtonClicked(int buttonNr)
{
    ledWidget_->showCell(buttonNr, buttonNr, Qt::red);
    ledWidget_->repaint();
}
