#ifndef WELCOME_PAGE_H
#define WELCOME_PAGE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class welcome_page;
}
QT_END_NAMESPACE

class welcome_page : public QMainWindow
{
    Q_OBJECT

public:
    welcome_page(QWidget *parent = nullptr);
    ~welcome_page();

private slots:
    void on_play_pushButton_clicked();

private:
    Ui::welcome_page *ui;
};
#endif // WELCOME_PAGE_H
