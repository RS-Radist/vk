#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QKeyEvent>
#include <QTime>
#include <QTimer>
#include <QtWebEngineWidgets>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QDateTime>

#include <QPointer>
#include <QFile>
#include "vkconnect.h"
#include <crypt.h>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    Form(QWidget *parent = 0, QSharedPointer<vkConnect> _vk = QSharedPointer<vkConnect>());
    ~Form();

    //методы нужны для получения родных размеров окна, а не присвоенных после инициализации
    int getW();
    int getH();


public slots:
    void ready();
private slots:

    void on_l_contacts_itemActivated(QListWidgetItem *item);

    void on_b_sent_clicked();

    void on_progressBar_valueChanged(int value);

    void checkNewMsg();

private:
    //QListWidgetItem * serchById(const QString & id);

    Ui::Form *ui;
    //QPointer<MessageArea> mArea;
    QSharedPointer<vkConnect> vk;

    int w;
    int h;
    QJsonObject friends;
    QJsonObject lastMessages;
    QString currentDiaolg;
    QString lastMsgID;
    QString basicHTML;
    QString CSS;
    QString chatMenu;
    QString chatOther;
    QString chatSelf;
    QString chatHTML;
    QString chatMiddle;
    QPointer<QTimer> timer;

    QString photoOther;

    QListWidgetItem * currentItem;
    crypt * cr;


};

#endif // FORM_H
