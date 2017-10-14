#ifndef MAJOR_HIGHLIGHTER_H
#define MAJOR_HIGHLIGHTER_H
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include<QTextEdit>
#include "qhtextedit.h"
//语法高亮---QSyntaxHighlighter
class TitleList;
 class major_highlighter : public QSyntaxHighlighter    //定义一个类继承自QSyntaxHightliaghter
 {
     Q_OBJECT                                         //Qt宏定义，使用Qt元编程

 public:
     major_highlighter( Qhtextedit *parent = 0);      //构造函数，传递一个QTextDocument对象给其父类

 protected:
     void highlightBlock(const QString &text) Q_DECL_OVERRIDE;    //块高亮使用的函数，自动调用

 private:
     struct HighlightingRule                    //语法规则结构体，包含正则表达式模式串和匹配的样式
     {
         QRegExp pattern;
         QTextCharFormat format;
     };
     QVector<HighlightingRule> highlightingRules;    //规则的集合，可以定义多个高亮规则

     QRegExp commentStartExpression;                //注释的高亮，使用highliangBlock()匹配，下文提到
     QRegExp commentEndExpression;

     QTextCharFormat keywordFormat;                //高亮样式，关键词，一下顾名思义
     QTextCharFormat classFormat;
     QTextCharFormat singleLineCommentFormat;
     QTextCharFormat multiLineCommentFormat;
     QTextCharFormat quotationFormat;
     QTextCharFormat functionFormat;
 };

#endif
