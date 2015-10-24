#include "adddialog.h"
#include "addresswidget.h"

#include <QtWidgets>
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

void AddressWidget::addEntry()
{
    AddDialog aDialog;

    if (aDialog.exec()) {
        QString name = aDialog.nameText->text();
        QString address = aDialog.addressText->toPlainText();

        addEntry(name, address);
    }
}

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

void AddressWidget::addProduct()
{
    AddProductDialog aDialog;

    if (aDialog.exec()) {
        int item = aDialog.itemText->text().toInt();
        int category = aDialog.categoryText->text().toInt();
        double weight = aDialog.weightText->text().toDouble();
        int number1 = aDialog.number1Text->text().toInt();
        int number2 = aDialog.number2Text->text().toInt();
        int number3 = aDialog.number3Text->text().toInt();

        addProduct(item, category, weight, number1, number2, number3);
    }
}

void AddressWidget::addProduct(int i, int c, double w, int number1, int number2, int number3)
{
    QList<Product> list = producttable->getList();
    Product p(i,c, w, number1, number2, number3);

    // if (!list.contains(p)) {
        producttable->insertRows(0, 1, QModelIndex());

        QModelIndex index = producttable->index(0, 0, QModelIndex());
        producttable->setData(index, i, Qt::EditRole);
        index = producttable->index(0, 1, QModelIndex());
        producttable->setData(index, c, Qt::EditRole);
        index = producttable->index(0, 2, QModelIndex());
        producttable->setData(index, w, Qt::EditRole);				
        index = producttable->index(0, 3, QModelIndex());
        producttable->setData(index, number1, Qt::EditRole);
        index = producttable->index(0, 4, QModelIndex());
        producttable->setData(index, number2, Qt::EditRole);	
        index = producttable->index(0, 5, QModelIndex());
        producttable->setData(index, number3, Qt::EditRole);					
        // removeTab(indexOf(newAddressTab));
    // } else {
        // QMessageBox::information(this, tr("Duplicate Product"),
            // tr("The product \"%1\" already exists.").arg(i));
    // }
}

void AddressWidget::editProduct()
{
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    QModelIndexList indexes = selectionModel->selectedRows();
		QString item;     // which kind of product,  not the id;
		QString category; // optional now;
		QString weight;   // 
		QString number1;
		QString number2;
		QString number3;		
    int row = -1;

    foreach (QModelIndex index, indexes) {
        row = proxy->mapToSource(index).row();
        QModelIndex itemIndex = producttable->index(row, 0, QModelIndex());
        QVariant varItem = producttable->data(itemIndex, Qt::DisplayRole);
        item = varItem.toString();

        QModelIndex categoryIndex = producttable->index(row, 1, QModelIndex());
        QVariant varCategory = producttable->data(categoryIndex, Qt::DisplayRole);
        category = varCategory.toString();
				
				QModelIndex weightIndex = producttable->index(row, 2, QModelIndex());
        QVariant varWeight = producttable->data(weightIndex, Qt::DisplayRole);
        weight = varWeight.toString();

				QModelIndex number1Index = producttable->index(row, 3, QModelIndex());
        QVariant varNumber1 = producttable->data(number1Index, Qt::DisplayRole);
        number1 = varNumber1.toString();
				
				QModelIndex number2Index = producttable->index(row, 4, QModelIndex());
        QVariant varNumber2 = producttable->data(number2Index, Qt::DisplayRole);
        number2 = varNumber2.toString();
				
				QModelIndex number3Index = producttable->index(row, 5, QModelIndex());
        QVariant varNumber3 = producttable->data(number3Index, Qt::DisplayRole);
        number3 = varNumber3.toString();
    }

    AddProductDialog aDialog;
    aDialog.setWindowTitle(tr("Edit a Product"));

		//consider item as ID, not modifiable
    aDialog.itemText->setReadOnly(true);
    aDialog.itemText->setText(item);
    aDialog.categoryText->setText(category);
		aDialog.weightText->setText(weight);
    aDialog.number1Text->setText(number1);
    aDialog.number2Text->setText(number2);
    aDialog.number3Text->setText(number3);


    if (aDialog.exec()) {
        QString newCategory = aDialog.categoryText->text();
        QString newWeight = aDialog.weightText->text();
        QString newNumber1 = aDialog.number1Text->text();
        QString newNumber2 = aDialog.number2Text->text();
        QString newNumber3 = aDialog.number3Text->text();	

        if (newCategory != category) {
            QModelIndex index = producttable->index(row, 1, QModelIndex());
            producttable->setData(index, newCategory, Qt::EditRole);
        }

        if (newWeight != weight) {
            QModelIndex index = producttable->index(row, 2, QModelIndex());
            producttable->setData(index, newWeight, Qt::EditRole);
        }

        if (newNumber1 != number1) {
            QModelIndex index = producttable->index(row, 3, QModelIndex());
            producttable->setData(index, newNumber1, Qt::EditRole);
        }				
			
        if (newNumber2 != number2) {
            QModelIndex index = producttable->index(row, 4, QModelIndex());
            producttable->setData(index, newNumber2, Qt::EditRole);
        }				

        if (newNumber3 != number3) {
            QModelIndex index = producttable->index(row, 5, QModelIndex());
            producttable->setData(index, newNumber3, Qt::EditRole);
        }				
    }
}

void AddressWidget::removeProduct()
{
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    QModelIndexList indexes = selectionModel->selectedRows();

    foreach (QModelIndex index, indexes) {
        int row = proxy->mapToSource(index).row();
        producttable->removeRows(row, 1, QModelIndex());
    }
}

