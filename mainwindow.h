#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class LEDWidget;

class QPushButton;
class QVBoxLayout;
class QHBoxLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onActionButtonClicked(int buttonNr);

private:
    LEDWidget* ledWidget_;
    QPushButton* buttons_[8];
    QVBoxLayout* mainLayout_;
    QHBoxLayout* buttonLayout_;
};
#endif // MAINWINDOW_H
