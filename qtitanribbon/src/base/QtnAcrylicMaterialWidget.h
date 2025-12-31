/****************************************************************************
**
** Qtitan Library by Developer Machines (Navigation UI for Qt.C++)
**
** Copyright (c) 2009-2018 Developer Machines (http://www.devmachines.com)
**           ALL RIGHTS RESERVED
**
**  The entire contents of this file is protected by copyright law and
**  international treaties. Unauthorized reproduction, reverse-engineering
**  and distribution of all or any portion of the code contained in this
**  file is strictly prohibited and may result in severe civil and
**  criminal penalties and will be prosecuted to the maximum extent
**  possible under the law.
**
**  RESTRICTIONS
**
**  THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED
**  FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE
**  COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE
**  AVAILABLE TO OTHER INDIVIDUALS WITHOUT WRITTEN CONSENT
**  AND PERMISSION FROM DEVELOPER MACHINES
**
**  CONSULT THE END USER LICENSE AGREEMENT FOR INFORMATION ON
**  ADDITIONAL RESTRICTIONS.
**
****************************************************************************/
#ifndef QTN_ACRYLICWIDGET_H
#define QTN_ACRYLICWIDGET_H

#include <QWidget>
#include <QGraphicsEffect>
#include "QtitanDef.h"
#ifdef QTN_OPENGL_ENABLED
#include "QtnOpenGLEffect.h"
#endif

QTITAN_BEGIN_NAMESPACE

class QTITAN_BASE_EXPORT AcrylicMaterialWidget : public QWidget
{
    Q_OBJECT
    Q_ENUMS(AcrylicBlend)
    Q_PROPERTY(AcrylicBlend blend READ acrylicBlend WRITE setAcrylicBlend)
    Q_PROPERTY(QColor tintColor READ tintColor WRITE setTintColor)
    Q_PROPERTY(double tintOpacity READ tintOpacity WRITE setTintOpacity)
    Q_PROPERTY(double noiseOpacity READ noiseOpacity WRITE setNoiseOpacity)
public:
    enum AcrylicBlend
    {
        DisabledBlend,
        InAppBlend,
        BackgroundBlend
    };
    explicit AcrylicMaterialWidget(QWidget* parent = Q_NULL, Qt::WindowFlags f = Qt::WindowFlags());
    virtual ~AcrylicMaterialWidget();
    AcrylicBlend acrylicBlend() const;
    void setAcrylicBlend(AcrylicBlend acrylicBlend);
    const QColor& tintColor() const;
    void setTintColor(const QColor& color);
    double tintOpacity() const;
    void setTintOpacity(double opacity);
    double noiseOpacity() const;
    void setNoiseOpacity(double opacity);
protected:
    QBrush createAcrylicBrush() const;
    void paintBackground(QPainter* painter, const QRegion& clip);
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual void showEvent(QShowEvent *event);
    virtual void hideEvent(QHideEvent *event);
    virtual void changeEvent(QEvent * event);
    const QImage& grabBackstageToBuffer(const QRegion& clip, bool& hasChanges);
    void setBackstageToWindow(const QImage& newBackstage, const QRegion& clip);
    QRect clipRect() const;
private:
    friend class AcrylicWidgetEffect;
    AcrylicBlend m_blend;
    double m_tintOpacity;
    double m_noiseOpacity;
    QBrush m_acrylicBrush;
    QImage m_buffer;
};

class AcrylicWidgetEffect : public QGraphicsEffect
{
    Q_OBJECT
public:
    AcrylicWidgetEffect(AcrylicMaterialWidget* widget);
    virtual ~AcrylicWidgetEffect();
    virtual QRectF boundingRectFor(const QRectF &sourceRect) const;
protected:
    virtual void draw(QPainter *painter);
    virtual void sourceChanged(ChangeFlags flags);
private:
    void forceRenderSiblings(QWidget* widget, QPainter* painter, const QRegion& clip);
    AcrylicMaterialWidget* m_widget;
#ifdef QTN_OPENGL_ENABLED
    OpenGLEffect* m_openglEffect;
#endif
    QImage m_blurredBuffer;
};

QTITAN_END_NAMESPACE

#endif// QTN_ACRYLICWIDGET_H



