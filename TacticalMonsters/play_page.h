#ifndef PLAY_PAGE_H
#define PLAY_PAGE_H

#pragma once

// #include <hexa.h>
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QString>

using std::vector;

class Hexa;
class InRangeSystem;

namespace Ui {
class play_page;
}

class play_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit play_page(QString player_1_name, QString player_2_name, QWidget * parent = nullptr);
    void parse(const QString &);
    ~play_page();

    static char turn;
    void change_turn();
    Hexa * hexa_array[9][9];

    InRangeSystem * in_range_system;

private:

    Ui::play_page *ui;
    QChar extracted_datas_from_txtFile[9][9];
    const int HEX_COLS = 9;
    const int HEX_ROWS = 9;
};

#endif
