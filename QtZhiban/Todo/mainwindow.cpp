#include "mainwindow.h"
#include "newtaskdialog.h"
#include <QHeaderView>
#include <QAction>
#include <QMenuBar>

#include "Database/ConnectionPool.h"
#include "Ui/CheckBoxHeaderView.h"

MainWindow::MainWindow()
{
    connection = ConnectionPool::openConnection();
    memoryDataService = MemoryDataService::instance();
    settingService = SettingService::instance();
    messageTipService = MessageTipService::instance();


    // Filters
    QHBoxLayout *filtersLayout = new QHBoxLayout;
    createFilters(filtersLayout);
    //filtersLayout->setContentsMargins();

    //Table
    table = new QTableWidget(this);
    initializeTable();

    QVBoxLayout *layout = new QVBoxLayout;
    layout -> setMargin(8);
    layout -> addLayout(filtersLayout);
    layout -> addWidget(table);
    layout -> setStretch(0, 0);
    layout -> setStretch(1, 0);
    layout -> setStretch(2, 1);

    this->setLayout(layout);

    // setWindowTitle("ToDo List QT");
    // setMinimumSize(480, 320);
    // resize(580, 480);

    this->filter();
}

void MainWindow::createFilters(QHBoxLayout *layout)
{
    addtask = new QPushButton(QString::fromLocal8Bit("添加待办"));
    rb_all = new QRadioButton;
    rb_all->setFixedWidth(80);
    rb_overdue = new QRadioButton;
    rb_overdue->setFixedWidth(80);
    rb_today = new QRadioButton;
    rb_today->setFixedWidth(80);
    rb_thisweek = new QRadioButton;
    rb_thisweek->setFixedWidth(80);
    cb_completed = new QCheckBox;

    rb_all->setText(QString::fromLocal8Bit("全部"));
    rb_all->setChecked(true);
    rb_overdue->setText(QString::fromLocal8Bit("过期"));
    rb_today->setText(QString::fromLocal8Bit("今天"));
    rb_thisweek->setText(QString::fromLocal8Bit("本周"));
    cb_completed->setText(QString::fromLocal8Bit("未完成"));

    connect(addtask,SIGNAL(clicked()),this,SLOT(addTask()));
    connect(rb_all,SIGNAL(clicked()),this,SLOT(filter()));
    connect(rb_overdue,SIGNAL(clicked()),this,SLOT(filter()));
    connect(rb_today,SIGNAL(clicked()),this,SLOT(filter()));
    connect(rb_thisweek,SIGNAL(clicked()),this,SLOT(filter()));
    connect(cb_completed,SIGNAL(clicked()),this,SLOT(filter()));

    QHBoxLayout *cbLayout = new QHBoxLayout;
    cbLayout -> setAlignment(Qt::AlignRight);
    cbLayout -> addWidget(cb_completed);
    cbLayout->addWidget(addtask);

    layout->addWidget(rb_all);
    layout->addWidget(rb_overdue);
    layout->addWidget(rb_today);
    layout->addWidget(rb_thisweek);
    layout->addLayout(cbLayout);

    layout -> setStretch(0, 0);
    layout -> setStretch(1, 0);
    layout -> setStretch(2, 0);
    layout -> setStretch(3, 0);
    layout -> setStretch(4, 1);
}

void MainWindow::initializeTable()
{
    table -> setColumnCount(6);
    tableHeader << QString::fromLocal8Bit("完成状态") << QString::fromLocal8Bit("日期") << QString::fromLocal8Bit("标题") << QString::fromLocal8Bit("百分比") << QString::fromLocal8Bit("描述") << "id";
    table->hideColumn(5);
    table -> setHorizontalHeaderLabels(tableHeader);
    table -> horizontalHeader()->setStretchLastSection(true);
    table -> verticalHeader() -> setVisible(false);
    table -> setEditTriggers(QAbstractItemView::NoEditTriggers);
    table -> setSelectionBehavior(QAbstractItemView::SelectRows);
    table -> setSelectionMode(QAbstractItemView::SingleSelection);
    // table -> setStyleSheet("QTableView {selection-background-color: #E0F7FA; selection-color: #000000;}");

    //inserting data

    QVector<todoStruct> data;

	// 查询数据库
    if (!connection.isOpen())
    {
        messageTipService->showTip(QString::fromLocal8Bit("数据库连接失败！"), TT_FAILED);
        return;
    }

    // 执行查询操作
    QSqlQuery query(connection);
    // QString sql = "SELECT id, xiwei, riqi, title, percent, miaoshu FROM todo where xiwei ='" + QString::number(memoryDataService->GetSeatName()) + "';";
    QString sql = "SELECT id, xiwei, riqi, title, percent, miaoshu FROM todo where xiwei ='" + QString::number(memoryDataService->GetSeatName()) + "' order by riqi;";
    bool success = query.exec(sql);
    if (!success)
    {
        QString err = query.lastError().databaseText();
        LOG_ERROR(QString::fromLocal8Bit("数据库查询失败：%s"), err.toStdString());
        messageTipService->showTip(QString::fromLocal8Bit("数据库查询待办事项失败！"), TT_FAILED);
        return;
    }
    else
    {
        while (query.next())
        {
            QSqlRecord dataline = query.record();

            todoStruct todo;
            todo.idGenerate = dataline.value("id").toInt();
            todo.xiwei = dataline.value("xiwei").toInt();
            todo.date = dataline.value("riqi").toDate();
            todo.title = dataline.value("title").toString();
            todo.percent = dataline.value("percent").toInt();
            todo.miaoshu = dataline.value("miaoshu").toString();
            data.push_back(todo);
        }
    }

    updateTable(data);

    connect( table, SIGNAL(cellDoubleClicked (int, int) ),this, SLOT(cellSelected( int, int ) ) );
}

void MainWindow::addTask()
{
    NewTaskDialog dlg;
    dlg.setModal(true);
    dlg.setOrigin(this);
    dlg.exec();
}

void MainWindow::cellSelected(int nRow, int nCol)
{
    NewTaskDialog dlg;
    dlg.idGenerate = table->item(nRow, 5)->text().toDouble();
    dlg.setModal(true);
    dlg.setData(table->item(nRow, 1)->text().toUtf8().constData(), table->item(nRow, 2)->text().toUtf8().constData(), table->item(nRow, 3)->text().toUtf8().constData(), table->item(nRow, 4)->text().toUtf8().constData());
    dlg.setOrigin(this);
    dlg.exec();
}

// int MainWindow::cmp_struct_char(const todoStruct* p1, const todoStruct* p2)
// {
//     if ((*(todoStruct*)p1).date < (*(struct todoStruct*)p2).date)
//     {
//         return -1;
//     }
//     else if ((*(struct todoStruct*)p1).date == (*(struct todoStruct*)p2).date)
//     {
//         return 0;
//     }
//     else
//     {
//         return 1;
//     }
//     // return strcmp(((struct todoStruct*)p1)->date, ((struct todoStruct*)p2)->date);
// }

void MainWindow::updateTable(QVector<todoStruct> data)
{
    // qSort(data, data.size(), sizeof(todoStruct), cmp_struct_char);
    qSort(data.begin(), data.end(), [&](const todoStruct& a, const todoStruct& b) {return a.date == b.date ? a.idGenerate < b.idGenerate : a.date < b.date; });
    table->clearContents();
    table->setRowCount(data.size());

    auto row = 0;
    for (auto todo :data)
    {
        QCheckBox* qcb = new QCheckBox;
        qcb->setStyleSheet(QStringLiteral("QCheckBox::indicator {subcontrol-position: center;}"));
        // Set the checkbox as not editable and check it if necessary
        // qcb->setAttribute(Qt::WA_TransparentForMouseEvents, true);
        // qcb->setFocusPolicy(Qt::NoFocus);
        qcb->setChecked(todo.percent == 100);
        connect(qcb, &QCheckBox::stateChanged, this, [this, row](int state) {checkboxChecked(state, row); });

        table->setAlternatingRowColors(true);
        table->setCellWidget(row, 0, qcb);
        QTableWidgetItem* qdd = new QTableWidgetItem(todo.date.toString("yyyy-MM-dd"));
        qdd->setTextAlignment(Qt::AlignCenter);
        table->setItem(row, 1, qdd);
        table->setItem(row, 2, new QTableWidgetItem(todo.title));
        QTableWidgetItem* qtwi = new QTableWidgetItem(QString::number(todo.percent));
        qtwi->setTextAlignment(Qt::AlignCenter);
        table->setItem(row, 3, qtwi);
        table->setItem(row, 4, new QTableWidgetItem(todo.miaoshu));
        table->setItem(row, 5, new QTableWidgetItem(QString::number(todo.idGenerate)));
        row++;
    }
}

void MainWindow::filter()
{
    QVector<todoStruct> data;

    // 查询数据库
    if (!connection.isOpen())
    {
        messageTipService->showTip(QString::fromLocal8Bit("数据库连接失败！"), TT_FAILED);
        return;
    }

    // 执行查询操作
    QSqlQuery query(connection);
    QString sql = "SELECT id, xiwei, riqi, title, percent, miaoshu FROM todo where xiwei ='" + QString::number(memoryDataService->GetSeatName()) + "';";
    bool success = query.exec(sql);
    if (!success)
    {
        QString err = query.lastError().databaseText();
        LOG_ERROR(QString::fromLocal8Bit("数据库查询失败：%s"), err.toStdString());
        messageTipService->showTip(QString::fromLocal8Bit("数据库查询待办事项失败！"), TT_FAILED);
        return;
    }
    else
    {
        while (query.next())
        {
            QSqlRecord dataline = query.record();

            todoStruct todo;
            todo.idGenerate = dataline.value("id").toInt();
            todo.xiwei = dataline.value("xiwei").toInt();
            todo.date = dataline.value("riqi").toDate();
            todo.title = dataline.value("title").toString();
            todo.percent = dataline.value("percent").toInt();
            todo.miaoshu = dataline.value("miaoshu").toString();
            data.push_back(todo);
        }
    }


    bool completed = cb_completed->isChecked();

    for (auto i = 0; i < data.size(); i++)
    {
        if (completed)
        {
            if (data[i].percent == 100)
            {
                data.erase(data.begin() + i);
                i--;
                continue;
            }
        }
    
        if (rb_today->isChecked())
        {
	        if (data[i].date != QDate::currentDate())
	        {
                data.erase(data.begin() + i);
                i--;
            }
        }
        else if (rb_thisweek->isChecked())
        {
	        if (data[i].date.weekNumber() != QDate::currentDate().weekNumber())
	        {
                data.erase(data.begin() + i);
                i--;
            }
        }
        else if (rb_overdue->isChecked())
        {
	        if (data[i].date >= QDate::currentDate())
	        {
                data.erase(data.begin()+i);
                i--;
	        }
        }
    }

    updateTable(data);
}

void MainWindow::checkboxChecked(int checked, int row )
{
	if (checked)
	{
        table->item(row, 3)->setText("100");
	}
	else
	{
        table->item(row, 3)->setText("0");
	}

    NewTaskDialog dlg;
    dlg.idGenerate = table->item(row, 5)->text().toDouble();
    dlg.setModal(true);
    dlg.setData(table->item(row, 1)->text().toUtf8().constData(), table->item(row, 2)->text().toUtf8().constData(), table->item(row, 3)->text().toUtf8().constData(), table->item(row, 4)->text().toUtf8().constData());
    dlg.setOrigin(this);
    dlg.on_savebtn_clicked();
    // dlg.exec();
}

MainWindow::~MainWindow()
{
    delete rb_all;
    delete rb_overdue;
    delete rb_today;
    delete rb_thisweek;
    delete cb_completed;
    delete table;
    delete addTaskAct;
    delete fileMenu;
}

void MainWindow::notCompletefiter()
{
    // 查询数据库
    if (!connection.isOpen()) 
    {
        messageTipService->showTip(QString::fromLocal8Bit("数据库连接失败！"), TT_FAILED);
        return;
    }

    // 执行查询操作
    QSqlQuery query(connection);
	QString sql = "SELECT id, xiwei, riqi, title, percent, miaoshu FROM todo where xiwei ='" + QString::number(memoryDataService->GetSeatName()) + "' and (riqi < '" + memoryDataService->GetcurrDate().toString("yyyy-MM-dd")+"' and percent != '" + QString::number(100)+ "');";
    bool success = query.exec(sql);
    if (!success)
    {
        QString err = query.lastError().databaseText();
        LOG_ERROR(QString::fromLocal8Bit("数据库查询失败：%s"), err.toStdString());
        messageTipService->showTip(QString::fromLocal8Bit("数据库查询未完成待办事项失败！"), TT_FAILED);
        return;
    }
    else
    {
        if (query.size() != 0)
        {
            emit shake();
        }
    }
}
