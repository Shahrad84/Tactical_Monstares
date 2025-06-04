#ifndef DECKSET_H
#define DECKSET_H

#include <QMainWindow>

namespace Ui {
class DeckSet;
}

class DeckSet : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeckSet(QWidget *parent = nullptr);
    ~DeckSet();

private:
    Ui::DeckSet *ui;
};

#endif // DECKSET_H
