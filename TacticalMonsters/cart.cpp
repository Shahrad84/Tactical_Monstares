#include "cart.h"

cart::cart(QLabel *inputQLabel, char inputOwnership, QWidget *parent)
    : QLabel(parent), ownership(inputOwnership)
{
    qlabel = inputQLabel;

    qlabel->setMouseTracking(true);
    qlabel->installEventFilter(this);
    qlabel->setMouseTracking(true);

    isSelected = false;

    parseText();
}

bool cart::eventFilter(QObject* watched, QEvent* event)
{
    if (watched == qlabel && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {

            if(isSelected){
                qlabel->resize(50, 60);
                isSelected = false;
            }
            else{
                qlabel->resize(60, 70);
                isSelected = true;
            }

            emit clicked();
            return true; // Event handled
        }
    }
    return QWidget::eventFilter(watched, event);
}

bool cart::get_isSelected(){
    return isSelected;
}

void cart::parseText(){
    string rawText = qlabel->text().toStdString();

    int i;
    for(i = 0; i < rawText.length(); i++){
        if(rawText[i] == ':'){
            break;
        }
    }

    if(i == 0){
        return;
    }

    for(int j = 0; j < i; j++){
        subAgentType += rawText[j];
    }
    for(int j = i + 1; j < rawText.length(); j++){
        subAgentName += rawText[j];
    }

    //qDebug() << "this cart is " << subAgentType << "with name " << subAgentName;
}


string cart::get_subAgentType(){
    return subAgentType;
}
string cart::get_subAgentName(){
    return subAgentName;
}
