#include "play_page.h"
#include "ui_play_page.h"

play_page::play_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::play_page)
{
    ui->setupUi(this);
    setMaximumSize(800, 600);
    setMinimumSize(800, 600);
}

play_page::~play_page()
{
    delete ui;
}
