#ifndef PLAY_PAGE_H
#define PLAY_PAGE_H

#include <QMainWindow>

namespace Ui {
class play_page;
}

class play_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit play_page(QWidget *parent = nullptr);
    ~play_page();

private:
    Ui::play_page *ui;
};

#endif // PLAY_PAGE_H
