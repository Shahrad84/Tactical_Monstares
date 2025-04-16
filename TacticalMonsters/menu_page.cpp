#include "menu_page.h"
#include "ui_menu_page.h"
#include "QMessageBox"
#include "play_page.h"
#include "gallery_page.h"

menu_page::menu_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu_page)
{
    ui->setupUi(this);
    setMaximumSize(800, 600);
    setMinimumSize(800, 600);
    ui->playerUsernames_groupBox->hide();
    ui->title_label->setAlignment(Qt::AlignCenter);
}

menu_page::~menu_page()
{
    delete ui;
}

void menu_page::on_play_pushButton_clicked()
{
    ui->playerUsernames_groupBox->show();
    ui->play_pushButton->setEnabled(false);
}


void menu_page::on_cancel_pushButton_clicked()
{
    ui->playerUsernames_groupBox->hide();
    ui->play_pushButton->setEnabled(true);
}


void menu_page::on_join_pushButton_clicked()
{
    QString p1_username = ui->player1usernamelineEdit->text();
    QString p2_username = ui->player2usernamelineEdit->text();

    if(p1_username == "" || p2_username == ""){
        QMessageBox::warning(this, "error", "every 2 fields must be completed");
    }
    else{
        play_page * w3 = new play_page;
        w3->setWindowTitle("main page");
        w3->show();
        this->close();
    }
}


void menu_page::on_gallery_pushButton_clicked()
{
    gallery_page * w4 = new gallery_page;
    w4->setWindowTitle("gallery");
    w4->show();
}

