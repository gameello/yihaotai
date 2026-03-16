#ifndef CUSTOMLINEEDIT_H
#define CUSTOMLINEEDIT_H

#include <QLineEdit>
#include <QWidget>
#include <QLabel>
class CustomLineEdit : public QLineEdit
{
	Q_OBJECT
public:
	explicit CustomLineEdit(QWidget *parent = nullptr);

protected:
	void enterEvent(QEvent * event) override;
	void leaveEvent(QEvent * event) override;

private:

	QWidget * toolTipWidget;
	QLabel * tipLabel;

};

#endif // CUSTOMLINEEDIT_H
