#pragma once
#ifndef MYQTREEWIDGETITEM_H
#define MYQTREEWIDGETITEM_H
#include <QTreeWidget>
#include "qobjectdefs.h"
#include "Data/BaseElement.h"

namespace Ui
{
	class MyQTreeWidgetItem :public QTreeWidgetItem {
	public:
		explicit MyQTreeWidgetItem(QTreeWidget* parent=nullptr);
		~MyQTreeWidgetItem();
		BaseElement *getBaseElement()const;
		void setBaseElement(BaseElement *);
	signals:

	protected:

	private:
		BaseElement * baseElement;
	};
}
#endif