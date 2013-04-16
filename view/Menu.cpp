#include "Menu.h"

#include "../model/Model.h"
Menu::Menu(QObject *parent) :
    QObject(parent)
{
    model = new Model();
}

Menu::~Menu()
{
    delete model;
}

#include <QFileDialog>
void Menu::clickedFiles()
{
    model->setFilesDir(QFileDialog::getExistingDirectory(0, tr("������� ���������� � ���������������� ������."), model->getFilesDir()));
}

void Menu::clickedReport()
{
    model->setReportDir(QFileDialog::getExistingDirectory(0, tr("������� ����������, ���� ����� �������� ����������."), model->getReportDir()));
}

void Menu::clickedStart()
{
    model->save();
}

#include <QApplication>
void Menu::clickedExit()
{
    QApplication::exit();
}
