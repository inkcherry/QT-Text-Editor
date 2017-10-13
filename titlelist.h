#ifndef TITLELIST_H
#define TITLELIST_H
//#include"mainwindow.h"
#include<QPushButton>
#include<QLayout>
#include<vector>
#include<QTabWidget>
#include<QLayout>
#include<major_highlighter.h>
using namespace std;

class TitleList
{
public:
    TitleList(QTabWidget *titletabwidget_,QString &CurFile_,QTextEdit *CurEdit_);
    QTextEdit* addTitle(const QString &fname);    //添加标题块UpdateCurInfo()
    void UpdateCurInfo(int &index);
    major_highlighter *p_m;         //用于析构；
private:
    QTextEdit *CurEdit;
    QString CurFile;
    QTabWidget *titletabwidget;

};

#endif // TITLELIST_H
