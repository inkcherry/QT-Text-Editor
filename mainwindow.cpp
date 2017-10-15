#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
      ui->setupUi(this);
      /* InitEditor();  */              // 代码高亮初始化
       QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));  //utf-8编码

       ui->titletabWidget->setStyleSheet("QTabBar::tab { background:#CCCCCC;"
                                         "color:#555555;height: 15px;"
                                         " width:80px; padding: 0px;}"
                                    "QTabBar::tab:selected { background: #FFFFFF;color:#000000 } ");
       titlelist = new TitleList(ui->titletabWidget,&CurFile,&CurEdit);
//       titlelist->addTilte();




      IsUnTitle=true;
      CurFile=tr("未命名.txt");

      setWindowTitle(CurFile);
      findDlg = new QDialog(this);
      findDlg->setWindowTitle(tr("查找"));
      findLineEdit = new QLineEdit(findDlg);
      QPushButton *btn_n= new QPushButton(tr("下一个"), findDlg);
      QPushButton *btn_p= new QPushButton(tr("上一个"),findDlg);

      QVBoxLayout *layout= new QVBoxLayout(findDlg);
      layout->addWidget(findLineEdit);
      layout->addWidget(btn_n);
      layout->addWidget(btn_p);
      connect(btn_n, SIGNAL(clicked()), this, SLOT(showFindText_N()));
      connect(btn_p, SIGNAL(clicked()), this, SLOT(showFindText_P())); //默认向前查找

}
void MainWindow::InitEditor(QTextEdit *newtextedit)
{
//调用方法，新建对象并传递document
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);
    newtextedit->setFont(font);
//    Qhtextedit *hnewtextedit = newtextedit;
//    major_highlighter *highter = new major_highlighter(hnewtextedit);  //这里指针考虑怎么释放
}

bool MainWindow::OpenFile(const QString &fname)
{

    QFile file(fname);
    file.open(QFile::ReadOnly|QFile::Text);
    QTextStream in(&file);
    CurEdit=titlelist->addTitle(fname);
    CurEdit->setPlainText(in.readAll());
    CurFile =QFileInfo(fname).canonicalFilePath();

    IsUnTitle=false;
    setWindowTitle(CurFile);
    return true;

//    return false;

}

void MainWindow::NewFile()
{

       CurFile=tr("未命名.txt");
       IsUnTitle=true;
       setWindowTitle(CurFile);
       CurEdit= titlelist->addTitle(CurFile);   //保存下CurFile;

}
bool MainWindow::Save()
{
    if(IsUnTitle)  //如果是需要被创建新文件
    {
        if(SaveAs()) //如果我们另存为，且存取成功，那么这就是一个相当于open的文件
             return IsUnTitle=false;
    }
    else
    { return SaveFile(CurFile);}//save保存修改
}
bool MainWindow::SaveAs()
{
     QString fileName = QFileDialog::getSaveFileName(this,
                                           tr("另存为"),CurFile);  //获取需要保存的文件路径
     if (fileName.isEmpty()) return false;
     return SaveFile(fileName);
}
bool MainWindow::SaveFile(const QString &fname)
{
    QFile file(fname);
    file.open(QFile::WriteOnly | QFile::Text);   //打开文件
    QTextStream out(&file);
    out <<CurEdit->toPlainText();  //写入文件
       CurFile = QFileInfo(fname).canonicalFilePath(); //获得文件路径
       setWindowTitle(CurFile);       //重置标题
       file.close();
       return true;

}

bool MainWindow::NeedSave()  //保存提示
{
//QDialog m;
//m.//QDialog m;
    //m.exec();exec();
//QMessageBox kk;
//kk.setText(CurEdit->toPlainText());
//kk.exec();
    if(CurEdit->document()->isModified())  //当前编辑器改变了文本内容
        {QMessageBox warnbox;
        warnbox.setWindowTitle(tr("warning"));
        warnbox.setIcon(QMessageBox::Warning);
        warnbox.setText(CurFile+tr("是否需要保存"));
        QPushButton *YButton = warnbox.addButton(tr("是(&Y)"),QMessageBox::YesRole);
        warnbox.addButton(tr("否(&N)"), QMessageBox::NoRole);

         QPushButton *CButton=warnbox.addButton(tr("取消"),QMessageBox::RejectRole);
        warnbox.exec();
         if(warnbox.clickedButton()==YButton)         //yes
         {
          return  Save();
         }
         else if(warnbox.clickedButton()==CButton)   //cancle
             return false;
    }
    return true;             //no  文档不保存关闭返回true
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_action_New_triggered()
{
    NewFile();

}

void MainWindow::on_action_Save_triggered()
{
    Save();
}

void MainWindow::on_action_SaveAs_triggered()
{
    SaveAs();
}

void MainWindow::showFindText_N()
{
    QString findstr = findLineEdit->text();
    if (!CurEdit->find(findstr,QTextDocument::FindBackward))  //第二个参数为枚举，向后查找
    {
       QMessageBox::warning(this, tr("查找"),
                tr("找不到%1").arg(findstr));
    }
}
void MainWindow::showFindText_P()
{  /* QMessageBox j;
    j.setWindowTitle("333");
    j.exec();*/
    QString findstr = findLineEdit->text();
    if (!CurEdit->find(findstr))  //第二个参数为枚举，向后查找
    {
       QMessageBox::warning(this, tr("查找"),
                tr("找不到%1").arg(findstr));
    }
}
void MainWindow::on_action_Open_triggered()
{
    if(NeedSave())
    {
        QString fname=QFileDialog::getOpenFileName(this);
        if(!fname.isEmpty())
        {
            OpenFile(fname);

        }
    }
}

void MainWindow::on_action_Find_triggered()
{
   findDlg->show();//查找框
}

void MainWindow::on_action_Cut_triggered()
{
   CurEdit->cut();
}

void MainWindow::on_action_Undo_triggered()
{
    CurEdit->undo();
}

void MainWindow::on_action_Copy_triggered()
{
    CurEdit->copy();
}

void MainWindow::on_action_Paste_triggered()
{
    CurEdit->paste();
}



void MainWindow::on_actiontest_triggered()
{
    QString f("ff");
    titlelist->addTitle(f);
}

void MainWindow::on_titletabWidget_tabBarClicked(int index)
{
    titlelist->UpdateCurInfo(index); //点击更新当前文件
//    CurEdit->setText("hhhh");
//    QMessageBox m;
//    m.setText(CurFile);
//    m.exec();
//    setWindowTitle(CurFile);

}

void MainWindow::on_titletabWidget_tabCloseRequested(int index)
{
    if(NeedSave())
   {    /*ui->titletabWidget->setCurrentIndex(index+1);*/
//        index++;
  //      titlelist->UpdateCurInfo(2);                  //因为下面两个bug，我猜测可能是由于CurEdit内存Curedit没有指向崩掉的，在关闭之前更新活动页 也是不行
        ui->titletabWidget->removeTab(index);
//ui->titletabWidget->widget(index)->~QWidget();                       //这样析构tab的widget确实能释放掉子控件编辑器edit控件内存，但是程序崩了。
//      ui->titletabWidget->widget(index)->findChild<Qhtextedit *>()->~Qhtextedit();  //直接析构编辑器的内存也崩了）：

   }
}
