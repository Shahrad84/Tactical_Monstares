#include "deckset.h"
#include "ui_deckset.h"

DeckSet::DeckSet(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DeckSet)
{
    ui->setupUi(this);
}

DeckSet::~DeckSet()
{
    delete ui;
}
