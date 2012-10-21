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

    //�������� 2 ��� �������
public slots:
    void addContact();
    void submitContact();
    void cancel();

private:
    QLineEdit *nameLine;
    QTextEdit *addressText;

    //�������� 2
    QPushButton *addButton;
    QPushButton *submitButton;
    QPushButton *cancelButton;



    //��������� � ������� ����� ��������� ������
    //������ ���� - �������� ��� �������� - ����, ��� ������� - ��������

    QMap<QString, QString> contacts;

    //������ ��� �������� ����������� ��������
    QString oldName;
    QString oldAddress;
};


#endif // ADRESSBOOK_H
