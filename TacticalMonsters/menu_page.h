#ifndef MENU_PAGE_H
#define MENU_PAGE_H

#include <QMainWindow>

namespace Ui {
class menu_page;
}

class menu_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu_page(QWidget *parent = nullptr);
    ~menu_page();

private:
    Ui::menu_page *ui;
};

#endif // MENU_PAGE_H
