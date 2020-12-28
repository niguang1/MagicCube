#ifndef COMMON_H
#define COMMON_H

#include <QMetaType>

#include <QDateTime>
#include <QString>

typedef struct {
    QString title;
    QString info;
    QDateTime deadLine;

} STTodoItem;
Q_DECLARE_METATYPE(STTodoItem)

#endif // COMMON_H
