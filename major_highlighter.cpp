#include "major_highlighter.h"
//#include "qhtextedit.h"
major_highlighter::major_highlighter(Qhtextedit *parent)    //构造函数，主要是对词语的高亮
    : QSyntaxHighlighter(parent==0?0:parent->document())
{
     if(parent!=0)parent->P_m=this;  //用于析构 这里如果不写和上边构造形参如果不判断parent==0 程序就会crash
    HighlightingRule rule;                            //高亮规则

    keywordFormat.setForeground(Qt::darkBlue);    //设定关键词的高亮样式
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;                    //关键词集合,关键都以正则表达式表示
  
    foreach (const QString &pattern, keywordPatterns) {    //添加各个关键词到高亮规则中
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    classFormat.setFontWeight(QFont::Bold);        //添加Qt的类到高亮规则中
    classFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
    rule.format = classFormat;
    highlightingRules.append(rule);

    singleLineCommentFormat.setForeground(Qt::red);    //单行注释
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::red);    //多行注释，只设定了样式，具体匹配在highlightBlock中设置


    quotationFormat.setForeground(Qt::darkGreen);    //字符串
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);


    functionFormat.setFontItalic(true);        //函数
    functionFormat.setForeground(Qt::blue);
    rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);


    commentStartExpression = QRegExp("/\\*");        //多行注释的匹配正则表达式
    commentEndExpression = QRegExp("\\*/");
}


void major_highlighter::highlightBlock(const QString &text)    //应用高亮规则，也用于区块的高亮，比如多行注释
{
    foreach (const HighlightingRule &rule, highlightingRules) {    //文本采用高亮规则
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }

    setCurrentBlockState(0);        //以下是多行注释的匹配

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

    while (startIndex >= 0) {
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}
