#ifndef GALLERY_PAGE_H
#define GALLERY_PAGE_H

#include <QMainWindow>

namespace Ui {
class gallery_page;
}

class gallery_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit gallery_page(QWidget *parent = nullptr);
    ~gallery_page();

private:
    Ui::gallery_page *ui;
};

#endif // GALLERY_PAGE_H
