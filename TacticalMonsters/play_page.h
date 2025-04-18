#ifndef PLAY_PAGE_H
#define PLAY_PAGE_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QString>

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

private:
    Ui::play_page *ui;
    QChar fgrid[5][9];
    const int HEX_COLS = 9;
    const int HEX_ROWS = 5;
};

#endif
