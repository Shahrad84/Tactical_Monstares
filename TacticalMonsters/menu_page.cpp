#include "menu_page.h"
#include "ui_menu_page.h"

menu_page::menu_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu_page)
{
    ui->setupUi(this);
    setMaximumSize(800, 600);
    setMinimumSize(800, 600);
}

menu_page::~menu_page()
{
    delete ui;
}
