#ifndef TERMINALINFOTAB_H
#define TERMINALINFOTAB_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QVBoxLayout;
QT_END_NAMESPACE

//! [0]
class TerminalInfoTab : public QWidget
{
    Q_OBJECT

public:
    TerminalInfoTab(QWidget *parent = 0);

public slots:
    void addEntry();
		// void addProduct();

signals:
    void sendDetails(QString name, QString address);

private:
    QLabel *descriptionLabel;
    QPushButton *addButton;
    QVBoxLayout *mainLayout;

};

#endif // TERMINALINFOTAB_H
