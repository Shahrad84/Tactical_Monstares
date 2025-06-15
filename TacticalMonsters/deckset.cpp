#include "deckset.h"
#include "ui_deckset.h"
#include "QFile"
#include "play_page.h"
#include "QMessageBox"

#include "QLayout"

DeckSet::DeckSet(QString player_1_name, QString player_2_name, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DeckSet)
{
    ui->setupUi(this);

    QLayout* layout_1 = ui->groupBox_p1->layout();
    if (!layout_1) {
        qDebug() << "groupBox_2 has no layout!";
    }

    QList<QLabel*> labels_1 = ui->groupBox_p1->findChildren<QLabel*>();
    qDebug() << "Found" << labels_1.size() << "QLabels in groupBox_2";

    for (QLabel* label : labels_1) {
        if (label) {
            cart* c = new cart(label, '1', this);
            player_1_allCarts.push_back(c);
            qDebug() << "Created cart for label:" << label->objectName();
        }
    }

    //=============================================

    QLayout* layout_2 = ui->groupBox_p2->layout();
    if (!layout_2) {
        qDebug() << "groupBox_2 has no layout!";
    }

    QList<QLabel*> labels_2 = ui->groupBox_p2->findChildren<QLabel*>();
    qDebug() << "Found" << labels_2.size() << "QLabels in groupBox_2";

    for (QLabel* label : labels_2) {
        if (label) {
            cart* c = new cart(label, '2', this);
            player_2_allCarts.push_back(c);
            qDebug() << "Created cart for label:" << label->objectName();
        }
    }

    on_playerSwitch_1_pushBtn_clicked();
}

DeckSet::~DeckSet()
{
    delete ui;
}

void DeckSet::parse(){

    QFile file(":/new/prefix1/agents.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    int row = 0;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        // Accessing (row, column) data:
        //qDebug() << "Row" << row << ":";
        //qDebug() << "  (0,0) =" << fields[0];   // First column of current row
        //qDebug() << "  (0,1) =" << fields[1];   // Second column of current row

        qDebug() << fields[0];   // First column of current row

        row++;
    }
    file.close();
}

void DeckSet::on_Play_pushBtn_clicked()
{
    for(int i = 0; i < 24; i++){
        if(player_1_allCarts[i]->get_isSelected()){
            player_1_selectedAgents.push_back(player_1_allCarts[i]);
        }
        if(player_2_allCarts[i]->get_isSelected()){
            player_2_selectedAgents.push_back(player_2_allCarts[i]);
        }
    }

    if(player_1_selectedAgents.size() == 3 && player_2_selectedAgents.size() == 3){
        play_page * w5 = new play_page(player_1_name, player_2_name);
        w5->setWindowTitle("play page");
        w5->show();
        this->close();
    }
    else{
        vector <cart *>().swap(player_1_selectedAgents);
        QMessageBox::warning(this, "error", "players have select only 3 agents");
    }
}


void DeckSet::on_playerSwitch_1_pushBtn_clicked()
{
    ui->playerSwitch_1_pushBtn->hide();
    ui->playerSwitch_2_pushBtn->show();

    ui->groupBox_p1->show();
    ui->groupBox_p2->hide();
}


void DeckSet::on_playerSwitch_2_pushBtn_clicked()
{
    ui->playerSwitch_2_pushBtn->hide();
    ui->playerSwitch_1_pushBtn->show();

    ui->groupBox_p2->show();
    ui->groupBox_p1->hide();
}

