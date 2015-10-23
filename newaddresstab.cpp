#include "adddialog.h"
#include "newaddresstab.h"

#include <QtWidgets>

//! [0]
NewAddressTab::NewAddressTab(QWidget *parent)
{
    Q_UNUSED(parent);

    descriptionLabel = new QLabel(tr("There are currently no order in your log. "
                                      "\nClick Add to add new order."));

    addButton = new QPushButton(tr("Add an Order"));

    connect(addButton, SIGNAL(clicked()), this, SLOT(addEntry()));

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel);
    mainLayout->addWidget(addButton, 0, Qt::AlignCenter);

    setLayout(mainLayout);
}
//! [0]

//! [1]
void NewAddressTab::addEntry()
{
    AddDialog aDialog;

    if (aDialog.exec()) {
        QString name = aDialog.nameText->text();
        QString address = aDialog.addressText->toPlainText();

        emit sendDetails(name, address);
    }
}
//! [1]
