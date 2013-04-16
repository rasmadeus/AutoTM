#ifndef MENU_H
#define MENU_H

#include <QObject>
class Model;

class Menu : public QObject
{
    Q_OBJECT
public:
    explicit Menu(QObject *parent = 0);
    ~Menu();
public slots:
    void clickedFiles();
    void clickedReport();
    void clickedStart();
    void clickedExit();
private:
    Model* model;
};

#endif // MENU_H
