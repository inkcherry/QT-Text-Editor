#include "titlelist.h"
#include<QDialog>
 TitleList:: TitleList(QTabWidget *titletabwidget_,QString &CurFile_,QTextEdit *CurEdit_)
{
titletabwidget=titletabwidget_;
CurFile=CurFile_;
CurEdit=CurEdit_;
}
void TitleList::UpdateCurInfo(int &index)
{

    CurFile=titletabwidget->tabText(index);
    CurEdit=titletabwidget->widget(index)->findChild<QTextEdit *>();   //找到对应tag的textedit控件
}

QTextEdit* TitleList::addTitle(const QString &fname)
{

QTextEdit *textedit=new QTextEdit();
QWidget *widget = new QWidget();
QVBoxLayout *vlayout = new QVBoxLayout();
vlayout->addWidget(textedit);
widget->setLayout(vlayout);
titletabwidget->addTab(widget,fname);   //QTtab消失后孩子控件自动释放，major_highlighter需要手写释放
//connect(this,signal(tabBarClicked(id)),this,UpdateCurInfo());
major_highlighter *highter = new major_highlighter(textedit);
return textedit;
}

