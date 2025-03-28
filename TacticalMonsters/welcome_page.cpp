#include "welcome_page.h"
#include "ui_welcome_page.h"
#include "menu_page.h"

welcome_page::welcome_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::welcome_page)
{
    ui->setupUi(this);
    setMaximumSize(800, 600);
    setMinimumSize(800, 600);
}

welcome_page::~welcome_page()
{
    delete ui;
}


void welcome_page::on_play_pushButton_clicked()
{
    menu_page * w2 = new menu_page;
    w2->setWindowTitle("menu");
    w2->show();

    this->close();
}

