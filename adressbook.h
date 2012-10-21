#ifndef ADRESSBOOK_H
#define ADRESSBOOK_H


#include <QWidget>
#include <QMap>

 class QLabel;
 class QLineEdit;
 class QTextEdit;
 class QPushButton;



class AddressBook : public QWidget
{
    Q_OBJECT

public:
    AddressBook(QWidget *parent = 0);

    //Добавили 2 для реакции
public slots:
    void addContact();
    void submitContact();
    void cancel();

private:
    QLineEdit *nameLine;
    QTextEdit *addressText;

    //Добавили 2
    QPushButton *addButton;
    QPushButton *submitButton;
    QPushButton *cancelButton;



    //Контейнер в котором будут храниться адреса
    //парами ключ - значение имя контакта - ключ, сам контакт - значение

    QMap<QString, QString> contacts;

    //Строки для хранения предыдущего контакта
    QString oldName;
    QString oldAddress;
};


#endif // ADRESSBOOK_H
