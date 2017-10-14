#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#endif // MAINWINDOW_H
#include "ui_mainwindow.h"
#include "major_highlighter.h"
#include "titlelist.h"
#include <QMainWindow>
#include <QDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QTextCodec>
#include<QLineEdit>
#include<QDialog>
class QLineEdit;
class QDialog;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void InitEditor(QTextEdit *newtextedit);
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
    void showFindText_N();
    void showFindText_P();
    void on_action_Open_triggered();

    void on_action_Find_triggered();

    void on_action_Cut_triggered();

    void on_action_Undo_triggered();

    void on_action_Copy_triggered();

    void on_action_Paste_triggered();

    void on_actiontianjiabutton_triggered();

    void on_actiontest_triggered();

    void on_titletabWidget_tabBarClicked(int index);

    void on_titletabWidget_tabCloseRequested(int index);

private:
    TitleList *titlelist;
    Qhtextedit *CurEdit;

    QLineEdit *findLineEdit;
    QDialog   *findDlg;     //Find聊天窗口
    bool IsUnTitle;       //文件是否命名
    QString CurFile;      //文件名字
    Ui::MainWindow *ui;
    major_highlighter highlighter;

};


