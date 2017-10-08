#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
      ui->setupUi(this);
      IsUnTitle=true;
      CurFile=tr("未命名.txt");
      setWindowTitle(CurFile);
}
bool MainWindow::OpenFile(const QString &fname)
{
    QFile file(fname);
    file.open(QFile::ReadOnly|QFile::Text);
    QTextStream in(&file);
    ui->textEdit->setPlainText(in.readAll());
    CurFile = QFileInfo(fname).canonicalFilePath();
    IsUnTitle=false;
    setWindowTitle(CurFile);
    return true;
}

void MainWindow::NewFile()
{
   if(NeedSave())   //如果我们要新建文档，就要提醒是否保存当前文档，取消返回F
    {
       CurFile=tr("未命名.txt");
        IsUnTitle=true;
       setWindowTitle(CurFile);
       ui->textEdit->clear();
       ui->textEdit->setVisible(true);
    }
}
bool MainWindow::Save()
{
    if(IsUnTitle)  //如果是需要被创建新文件
    {
        if(SaveAs()) //如果我们另存为，且存取成功，那么这就是一个相当于open的文件
             return IsUnTitle=false;
    }
    else
    {
        return SaveFile(CurFile);}//save保存修改
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
    out << ui->textEdit->toPlainText();  //写入文件
       CurFile = QFileInfo(fname).canonicalFilePath(); //获得文件路径
       setWindowTitle(CurFile);       //重置标题
       file.close();
       return true;

}

bool MainWindow::NeedSave()  //保存提示
{
    if(ui->textEdit->document()->isModified())  //改变了文本内容
    {
        QMessageBox warnbox;
        warnbox.setWindowTitle(tr("warning"));
        warnbox.setIcon(QMessageBox::Warning);
        warnbox.setText(CurFile+tr("是否需要保存"));
        QPushButton *YButton = warnbox.addButton(tr("是(&Y)"),QMessageBox::YesRole);
        warnbox.addButton(tr("否(&N)"), QMessageBox::NoRole);

         QPushButton *CButton=warnbox.addButton(tr("取消"),QMessageBox::RejectRole);
        warnbox.exec();
         if(warnbox.clickedButton()==YButton)
         {
          return  Save();
         }
         else if(warnbox.clickedButton()==CButton)
             return false;
    }
    return true;             //文档没有更改返回true
}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::on_pushButton_clicked()
//{
//    QDialog *dlg=new QDialog(this);
//    dlg->show();
//}

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
