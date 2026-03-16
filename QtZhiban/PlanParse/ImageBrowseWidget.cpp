#include "ImageBrowseWidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QMouseEvent>

ImageBrowseWidget::ImageBrowseWidget(QString & path, QWidget *parent)
	: QWidget(parent), m_ImagePath(path),ui(new Ui::ImageBrowseWidget)
{
	ui->setupUi(this);
	InitWidget();
}

ImageBrowseWidget::~ImageBrowseWidget()
{
}

void ImageBrowseWidget::InitWidget()
{
	/*QWidget * subWid = new QWidget();
	QVBoxLayout* layout = new QVBoxLayout(subWid);*/
	QImage image(m_ImagePath);
	image = image.scaled(68, 50, Qt::KeepAspectRatio);
	QLabel *imageLabel = new QLabel();
	imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	imageLabel->setFixedSize(68, 50);
	imageLabel->setPixmap(QPixmap::fromImage((image)));
	QString name = m_ImagePath.split("/").last();
	QLabel * nameLabel = new QLabel(name);
	//nameLabel->setFixedHeight(28);
	nameLabel->setAlignment(Qt::AlignHCenter);
	nameLabel->setStyleSheet("border:none;font-size:12px;max-width:68px;");
	ui->gridLayout->addWidget(imageLabel);
	ui->gridLayout->addWidget(nameLabel);
	ui->gridLayout->setContentsMargins(0,0,0,0);
	ui->gridLayout->setSpacing(0);
	//subWid->setLayout(layout);
	//ui->gridLayout->addWidget(subWid);
}

void ImageBrowseWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		// 发射自定义的双击信号
		emit doubleClicked(m_ImagePath);
	}
}