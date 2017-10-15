#include "titlelist.h"
#include<QDialog>
#include<QMessageBox>
#include "qhtextedit.h"
 TitleList:: TitleList(QTabWidget *titletabwidget_,QString *CurFile_,Qhtextedit **CurEdit_)
{
titletabwidget=titletabwidget_;
CurFile=CurFile_;
CurEdit=CurEdit_;
}
void TitleList::UpdateCurInfo(int &index)
{

    *CurFile=titletabwidget->tabText(index);
//    QMessageBox m;
//    m.setText(CurFile);
//    m.exec();
    *CurEdit=titletabwidget->widget(index)->findChild<Qhtextedit*>();   //找到对应tag的textedit控件
}

Qhtextedit* TitleList::addTitle(const QString &fname)
{
Qhtextedit *htextedit =new Qhtextedit();
QWidget *widget = new QWidget();
QVBoxLayout *vlayout = new QVBoxLayout();
vlayout->addWidget(htextedit);
widget->setLayout(vlayout);
titletabwidget->addTab(widget,fname);   //QTtab消失后孩子控件自动释放，major_highlighter需要手写释放
//connect(this,signal(tabBarClicked(id)),this,UpdateCurInfo());
major_highlighter *highter = new major_highlighter(htextedit);
return htextedit;
}

