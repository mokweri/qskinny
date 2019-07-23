/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the 3-clause BSD License
 *****************************************************************************/

#ifndef TEST_BOX_H
#define TEST_BOX_H

#include "GridAccessor.h"
#include <QWidget>

class TestBox : public QWidget, public GridAccessor
{
  public:
    TestBox( QWidget* parent = nullptr );
    ~TestBox() override;

    void setColumns( int );

    void insert( const QByteArray& colorName,
        int row, int column, int rowSpan, int columnSpan ) override;

    void setSpacing( Qt::Orientations, int spacing ) override;

    void setStretchFactor( int pos, Qt::Orientation, int stretch ) override;
    void setSizeHint( int pos, Qt::Orientation, Qt::SizeHint, int hint ) override;

    void setSizeHintAt( int index, Qt::Orientation, Qt::SizeHint, int hint ) override;
    void setSizePolicyAt( int index, Qt::Orientation, int policy ) override;

    void setAlignmentAt( int index, Qt::Alignment ) override;
    void setRetainSizeWhenHiddenAt( int index, bool on ) override;

  protected:
    void resizeEvent( QResizeEvent* ) override;

  private:
    void layoutGrids();

    enum
    {
        Skinny,
        Widgets,
        Graphics,
        Quick,

        GridCount
    };

    QWidget* grids[ GridCount ];
    int m_columnCount = 2;
};

#endif
