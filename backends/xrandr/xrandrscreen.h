/*
 *  SPDX-FileCopyrightText: 2012, 2013 Daniel Vrátil <dvratil@redhat.com>
 *
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 */
#pragma once

#include "types.h"

#include <QObject>
#include <QSize>

class XRandRConfig;
namespace KScreen
{
class Screen;
class Config;
}

class XRandRScreen : public QObject
{
    Q_OBJECT

public:
    explicit XRandRScreen(XRandRConfig *config = nullptr);
    ~XRandRScreen() override;

    KScreen::ScreenPtr toKScreenScreen() const;
    void updateKScreenScreen(KScreen::ScreenPtr &screen) const;

    void update();
    void update(const QSize &size);
    QSize currentSize();

    void setExplicitSize(const QSize &size);
    QSize explicitSize() const;

private:
    int m_id;
    QSize m_minSize;
    QSize m_maxSize;
    QSize m_currentSize;
    QSize m_explicitSize;
};
