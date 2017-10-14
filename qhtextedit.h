#ifndef QHTEXTEDIT_H
#define QHTEXTEDIT_H
#include<QTextEdit>
#include<QMessageBox>
class major_highlighter;
class Qhtextedit : public QTextEdit
{
public:
    Qhtextedit();
    major_highlighter *P_m;
    ~Qhtextedit()
    {
        delete P_m;
//      QMessageBox m;
//      m.setText("mh 已经被析构");
//      m.exec();
    }
};

#endif // QHTEXTEDIT_H
