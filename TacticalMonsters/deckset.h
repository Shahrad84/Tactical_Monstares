#ifndef DECKSET_H
#define DECKSET_H

#include <QMainWindow>
#include "vector"
#include "cart.h"

using std::vector;

namespace Ui {
class DeckSet;
}

class DeckSet : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeckSet(QString player_1_name, QString player_2_name, QWidget *parent = nullptr);
    ~DeckSet();
    void parse();

private slots:
    void on_Play_pushBtn_clicked();

    void on_playerSwitch_1_pushBtn_clicked();

    void on_playerSwitch_2_pushBtn_clicked();

private:
    Ui::DeckSet *ui;

    vector <cart *> player_1_allCarts;
    vector <cart *> player_2_allCarts;

    vector <cart *> player_1_selectedAgents;
    vector <cart *> player_2_selectedAgents;

    QString player_1_name;
    QString player_2_name;
};

#endif // DECKSET_H
