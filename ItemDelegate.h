#ifndef MUITEMDELEGATE_H
#define MUITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QCheckBox>

class ItemDelegate : public QStyledItemDelegate
{
public:
    ItemDelegate(QObject *parent = nullptr);

    // painting
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
};

#endif // MUITEMDELEGATE_H
