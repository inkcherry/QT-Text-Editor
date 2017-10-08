#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QTextCodec>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void NewFile();
    bool NeedSave();   //如果文档被更改后设置为true，文档未被更改设置为false
    bool Save();
    bool SaveAs();     //另存为
    bool SaveFile(const QString &fname);  //保存
    bool OpenFile(const QString &fname);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
//    void on_pushButton_clicked();

    void on_action_New_triggered();

    void on_action_Save_triggered();

    void on_action_SaveAs_triggered();

    void on_action_Open_triggered();

private:
    bool IsUnTitle;       //文件是否命名
    QString CurFile;   //文件名字
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
