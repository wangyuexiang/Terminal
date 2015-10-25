#include "adddialog.h"
#include "terminalinfotab.h"

#include <QtWidgets>

TerminalInfoTab::TerminalInfoTab(QWidget *parent)
{
    Q_UNUSED(parent);

    descriptionLabel = new QLabel(tr("This tab is used to display Termnial & Operator Information. "
                                      "\nClick Add to add new Product."));

    addButton = new QPushButton(tr("Add a Product"));

    connect(addButton, SIGNAL(clicked()), this, SLOT(addProduct()));

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel);
    mainLayout->addWidget(addButton, 0, Qt::AlignCenter);

    setLayout(mainLayout);
}

void TerminalInfoTab::addEntry()
{
    AddDialog aDialog;

    if (aDialog.exec()) {
        QString name = aDialog.nameText->text();
        QString address = aDialog.addressText->toPlainText();

        emit sendDetails(name, address);
    }
}
