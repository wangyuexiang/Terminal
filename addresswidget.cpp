#include "adddialog.h"
#include "addresswidget.h"

#include <QtWidgets>


//! [0]
AddressWidget::AddressWidget(QWidget *parent)
    : QTabWidget(parent)
{
    table = new TableModel(this);
    producttable = new ProductModel(this);
    newAddressTab = new NewAddressTab(this);
    connect(newAddressTab, SIGNAL(sendDetails(QString, QString)),
        this, SLOT(addEntry(QString, QString)));

    addTab(newAddressTab, "Add Order");

    setupTabs();
}
//! [0]

//! [2]
void AddressWidget::addEntry()
{
    AddDialog aDialog;

    if (aDialog.exec()) {
        QString name = aDialog.nameText->text();
        QString address = aDialog.addressText->toPlainText();

        addEntry(name, address);
    }
}
//! [2]

//! [3]
void AddressWidget::addEntry(QString name, QString address)
{
    QList<QPair<QString, QString> >list = table->getList();
    QPair<QString, QString> pair(name, address);

    if (!list.contains(pair)) {
        table->insertRows(0, 1, QModelIndex());

        QModelIndex index = table->index(0, 0, QModelIndex());
        table->setData(index, name, Qt::EditRole);
        index = table->index(0, 1, QModelIndex());
        table->setData(index, address, Qt::EditRole);
        removeTab(indexOf(newAddressTab));
    } else {
        QMessageBox::information(this, tr("Duplicate Name"),
            tr("The name \"%1\" already exists.").arg(name));
    }
}
//! [3]

//! [4a]
void AddressWidget::editEntry()
{
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    QModelIndexList indexes = selectionModel->selectedRows();
    QString name;
    QString address;
    int row = -1;

    foreach (QModelIndex index, indexes) {
        row = proxy->mapToSource(index).row();
        QModelIndex nameIndex = table->index(row, 0, QModelIndex());
        QVariant varName = table->data(nameIndex, Qt::DisplayRole);
        name = varName.toString();

        QModelIndex addressIndex = table->index(row, 1, QModelIndex());
        QVariant varAddr = table->data(addressIndex, Qt::DisplayRole);
        address = varAddr.toString();
    }
//! [4a]

//! [4b]
    AddDialog aDialog;
    aDialog.setWindowTitle(tr("Edit an Order"));

    aDialog.nameText->setReadOnly(true);
    aDialog.nameText->setText(name);
    aDialog.addressText->setText(address);

    if (aDialog.exec()) {
        QString newAddress = aDialog.addressText->toPlainText();
        if (newAddress != address) {
            QModelIndex index = table->index(row, 1, QModelIndex());
            table->setData(index, newAddress, Qt::EditRole);
        }
    }
}
//! [4b]

//! [5]
void AddressWidget::removeEntry()
{
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    QModelIndexList indexes = selectionModel->selectedRows();

    foreach (QModelIndex index, indexes) {
        int row = proxy->mapToSource(index).row();
        table->removeRows(row, 1, QModelIndex());
    }

    if (table->rowCount(QModelIndex()) == 0) {
        insertTab(0, newAddressTab, "Order List");
    }
}
//! [5]

//! [1]
void AddressWidget::setupTabs()
{
	//Order List
		table_proxy = new QSortFilterProxyModel(this);
		table_proxy->setSourceModel(table);
		table_proxy->setFilterKeyColumn(0);

		QTableView *tableView = new QTableView;
        tableView->setModel(table_proxy);

		tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
		tableView->horizontalHeader()->setStretchLastSection(true);
		// tableView->verticalHeader()->hide();
		tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
		tableView->setSelectionMode(QAbstractItemView::SingleSelection);

		tableView->setSortingEnabled(true);

		connect(tableView->selectionModel(),
				SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
				this, SIGNAL(selectionChanged(QItemSelection)));

		addTab(tableView, "Order List");

		// Product List
		product_proxy = new QSortFilterProxyModel(this);
		
		// producttable.append(Product(1,2,2.5,10,20,20));
		// producttable.append(Product(2,4,25,16,20,20));
		// producttable.append(Product(1,2,2.5,10,25,20));
		// producttable.append(Product(3,2,5,0,20,20));
				
		product_proxy->setSourceModel(producttable);
		product_proxy->setFilterKeyColumn(0);

		QTableView *productView = new QTableView;
		productView->setModel(product_proxy);

		productView->setSelectionBehavior(QAbstractItemView::SelectRows);
		productView->horizontalHeader()->setStretchLastSection(true);
		productView->verticalHeader()->hide();
		productView->setEditTriggers(QAbstractItemView::NoEditTriggers);
		productView->setSelectionMode(QAbstractItemView::SingleSelection);

		productView->setSortingEnabled(true);

		connect(productView->selectionModel(),
				SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
				this, SIGNAL(selectionChanged(QItemSelection)));

		addTab(productView, "Product List");
		
}
//! [1]

//! [7]
void AddressWidget::readFromFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }

    QList<QPair<QString, QString> > pairs = table->getList();
    QDataStream in(&file);
    in >> pairs;

    if (pairs.isEmpty()) {
        QMessageBox::information(this, tr("No orders in file"),
                                 tr("The file you are attempting to open contains no orders."));
    } else {
        for (int i=0; i<pairs.size(); ++i) {
            QPair<QString, QString> p = pairs.at(i);
            addEntry(p.first, p.second);
        }
    }
}
//! [7]

//! [6]
void AddressWidget::writeToFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }

    QList<QPair<QString, QString> > pairs = table->getList();
    QDataStream out(&file);
    out << pairs;
}
//! [6]
