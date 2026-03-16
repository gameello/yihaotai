#include "newtaskdialog.h"
#include "ui_newtaskdialog.h"
#include "Common/global.h"
#include "Common/IdGenerateHelper.h"
#include "Database/ConnectionPool.h"

NewTaskDialog::NewTaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTaskDialog)
{
    ui->setupUi(this);
    connection = ConnectionPool::openConnection();
    memoryDataService = MemoryDataService::instance();
    settingService = SettingService::instance();
    messageTipService = MessageTipService::instance();

    ui->datepicker->setDisplayFormat("yyyy-MM-dd");

    QDate date = QDate::currentDate();
    ui->datepicker->setDate(date);

    ui->slider->setRange(0, 100);
    ui->slider->setSingleStep(5);

    ui->savebtn->setEnabled(false);
    ui->deletebtn->setVisible(false);

    ui->datepicker->setCalendarPopup(true);

    this->newTask = true;
}

void NewTaskDialog::setData(string duedate, string title, string percent, string description)
{
    this->oldDuedate = duedate;
    this->oldTitle = title;
    this->oldPercent = percent;
    this->oldDescription = description;
    string *sdate = IOManager::split(duedate, '-');
    QDate *sd = new QDate(stoi(sdate[0]), stoi(sdate[1]), stoi(sdate[2]));
    ui->datepicker->setDate(*sd);
    ui->title_et->setText(QString::fromStdString(title));
    ui->slider->setValue(stoi(percent));
    ui->description_ed->setPlainText(QString::fromStdString(description));
    this->newTask = false;
    ui->deletebtn->setVisible(true);
}


NewTaskDialog::~NewTaskDialog()
{
    delete ui;
}


void NewTaskDialog::on_slider_valueChanged(int value)
{
    ui->percent_lbl->setText(QString::fromStdString(to_string(value)) + QString::fromLocal8Bit("% 完成率"));
    checkFields();
}


void NewTaskDialog::checkFields()
{
    string sdatepicker(ui->datepicker->text().toUtf8().constData());
    string stitle(ui->title_et->text().toUtf8().constData());
    string spercent(ui->percent_lbl->text().toUtf8().constData());
    spercent = spercent.substr(0, spercent.find('%'));
    string sdescr(ui->description_ed->toPlainText().toUtf8().constData());

    //We check all fields are completed
    if(sdatepicker.length()!=10 || stitle.length()==0 || spercent.length()==0 || sdescr.length()==0)
    {
        ui->savebtn->setEnabled(false);
    }
	else
    {
        ui->savebtn->setEnabled(true);
    }
}
void NewTaskDialog::on_description_ed_textChanged()
{
    checkFields();
}

void NewTaskDialog::on_title_et_textChanged(const QString &arg1)
{
    checkFields();
}

void NewTaskDialog::on_datepicker_userDateChanged(const QDate &date)
{
    checkFields();
}

void NewTaskDialog::on_savebtn_clicked()
{
    QString sdatepicker(ui->datepicker->text().toLocal8Bit());
    QString stitle(ui->title_et->text().toUtf8());
    QString spercent(ui->percent_lbl->text().toUtf8().constData());
    spercent = spercent.split("%")[0];
    if (ui->slider->value() == 0) //解决完成度为0时，spercent为“完成率”，因为在setdata时，设置slider为0，不触发slider槽函数，导致文字错误 
    {
        spercent = "0";
    }
    // spercent = spercent.substr(0, spercent.find('%'));
    QString sdescr(ui->description_ed->toPlainText().toUtf8().constData());
    QString s = sdatepicker+";"+stitle+";"+spercent+";"+sdescr;

    // 保存至数据库
    if (!connection.isOpen())
    {
        messageTipService->showTip(QString::fromLocal8Bit("数据库连接失败！"), TT_FAILED);
        return;
    }
    QSqlQuery query(connection);
    if (newTask)
    {
        query.prepare("INSERT INTO todo (id, xiwei, riqi, title, percent, miaoshu) VALUES (:id, :xiwei, :riqi, :title, :percent, :miaoshu)");
        QStringList ss = s.split(";");
        QString id = QString::number(IdGenerateHelper::instance()->generate());
        query.bindValue(":id", id);
        query.bindValue(":xiwei", QString::number(memoryDataService->GetSeatName()));
        query.bindValue(":riqi", ss[0]);
        query.bindValue(":title", ss[1]);
        query.bindValue(":percent", ss[2]);
        query.bindValue(":miaoshu", ss[3]);
    }
    else
    {
        query.prepare("UPDATE todo SET xiwei =:xiwei, riqi =:riqi, title=:title, percent=:percent, miaoshu=:miaoshu WHERE id = :id");
        QStringList ss = s.split(";");
        QString id = QString::number(idGenerate);
        query.bindValue(":id", id);
        query.bindValue(":xiwei", QString::number(memoryDataService->GetSeatName()));
        query.bindValue(":riqi", ss[0]);
        query.bindValue(":title", ss[1]);
        query.bindValue(":percent", ss[2]);
        query.bindValue(":miaoshu", ss[3]);
    }
     
    bool success = query.exec();
    if (!success)
    {
        QString err = query.lastError().databaseText();
    	messageTipService->showTip(QString::fromLocal8Bit("数据库更新待办失败！"), TT_FAILED);
    }
    ConnectionPool::closeConnection(connection);

    // IOManager::writeFile(path, s);
    origin->filter();
    this->close();
}

void NewTaskDialog::on_cancelbtn_clicked()
{
    this->close();
}

void NewTaskDialog::on_deletebtn_clicked()
{
    QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, QString::fromLocal8Bit("删除任务"), QString::fromLocal8Bit("确定删除本任务？"),
	                            QMessageBox::Yes|QMessageBox::No);
	if (reply == QMessageBox::No) 
	{
	  return;
	}

	// 保存至数据库
    if (!connection.isOpen())
    {
        messageTipService->showTip(QString::fromLocal8Bit("数据库连接失败！"), TT_FAILED);
        return;
    }
    QSqlQuery query(connection);
    query.prepare("DELETE from todo WHERE id = :id");
    query.bindValue(":id", idGenerate);
    bool success = query.exec();
    if (!success)
    {
        QString err = query.lastError().databaseText();
        messageTipService->showTip(QString::fromLocal8Bit("数据库删除待办失败！"), TT_FAILED);
    }
    ConnectionPool::closeConnection(connection);

    origin->filter();
    this->close();
}
