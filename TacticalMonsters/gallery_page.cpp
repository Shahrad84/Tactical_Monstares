#include "gallery_page.h"
#include "ui_gallery_page.h"

gallery_page::gallery_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gallery_page)
{
    ui->setupUi(this);
    setMaximumSize(840, 640);
    setMinimumSize(840, 640);
}

gallery_page::~gallery_page()
{
    delete ui;
}
