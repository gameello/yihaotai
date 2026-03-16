#include "MyQTreeWidgetItem.h"
#include <QMessageBox>
namespace Ui
{
	MyQTreeWidgetItem::MyQTreeWidgetItem(QTreeWidget* parent) :QTreeWidgetItem(parent)
	{
		baseElement = nullptr;
	}

	MyQTreeWidgetItem::~MyQTreeWidgetItem()
	{

	}

	BaseElement * MyQTreeWidgetItem::getBaseElement() const
	{
		return baseElement;
	}

	void MyQTreeWidgetItem::setBaseElement(BaseElement * value)
	{
		baseElement = value;
	}

}