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
    explicit play_page(QWidget *parent = nullptr);
    void parse(const QString &);
    ~play_page();

    void chagne_turn();
    char turn;

private:
    Ui::play_page *ui;
    std::vector<std::vector<QChar>> fgrid;
    const int HEX_COLS = 9;
    const int HEX_ROWS = 5;
};

#endif // PLAY_PAGE_H
