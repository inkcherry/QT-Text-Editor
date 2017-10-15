#ifndef TITLELIST_H
#define TITLELIST_H
//#include"mainwindow.h"
#include<QPushButton>
#include<QLayout>
#include<vector>
#include<QTabWidget>
#include<QLayout>
#include<major_highlighter.h>
#include "qhtextedit.h"
class Qhtextedit;
using namespace std;

class TitleList
{
public:

    TitleList(QTabWidget *titletabwidget_,QString *CurFile_,Qhtextedit **CurEdit_);
    Qhtextedit* addTitle(const QString &fname);    //添加标题块UpdateCurInfo()
    void UpdateCurInfo(int &index);
    major_highlighter *p_m;         //用于析构；
private:
   Qhtextedit **CurEdit;
    QString *CurFile;
    QTabWidget *titletabwidget;

};

#endif // TITLELIST_H
