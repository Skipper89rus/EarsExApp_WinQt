/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QCheckBox>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QVBoxLayout>

#include "SettingsDialog.h"

// Macro which connects a signal to a slot, and which causes application to
// abort if the connection fails.  This is intended to catch programming errors
// such as mis-typing a signal or slot name.  It is necessary to write our own
// macro to do this - the following idiom
//     Q_ASSERT(connect(source, signal, receiver, slot));
// will not work because Q_ASSERT compiles to a no-op in release builds.
#define CHECKED_CONNECT(source, signal, receiver, slot) \
    if (!connect(source, signal, receiver, slot)) \
        qt_assert_x(Q_FUNC_INFO, "CHECKED_CONNECT failed", __FILE__, __LINE__);

SettingsDialog::SettingsDialog(
            const QList<QAudioDeviceInfo> &availableInputDevices,
            const QList<QAudioDeviceInfo> &availableOutputDevices,
            QWidget *parent)
    :   QDialog(parent)
    ,   _inputDeviceComboBox(new QComboBox(this))
    ,   _outputDeviceComboBox(new QComboBox(this))
{
    QVBoxLayout *dialogLayout = new QVBoxLayout(this);

    // Populate combo boxes

    QAudioDeviceInfo device;
    foreach (device, availableInputDevices)
        _inputDeviceComboBox->addItem(device.deviceName(),
                                       QVariant::fromValue(device));
    foreach (device, availableOutputDevices)
        _outputDeviceComboBox->addItem(device.deviceName(),
                                       QVariant::fromValue(device));

    // Initialize default devices
    if (!availableInputDevices.empty())
        _inputDevice = availableInputDevices.front();
    if (!availableOutputDevices.empty())
        _outputDevice = availableOutputDevices.front();

    // Add widgets to layout

    QScopedPointer<QHBoxLayout> inputDeviceLayout(new QHBoxLayout);
    QLabel *inputDeviceLabel = new QLabel(tr("Input device"), this);
    inputDeviceLayout->addWidget(inputDeviceLabel);
    inputDeviceLayout->addWidget(_inputDeviceComboBox);
    dialogLayout->addLayout(inputDeviceLayout.data());
    inputDeviceLayout.take(); // ownership transferred to dialogLayout

    QScopedPointer<QHBoxLayout> outputDeviceLayout(new QHBoxLayout);
    QLabel *outputDeviceLabel = new QLabel(tr("Output device"), this);
    outputDeviceLayout->addWidget(outputDeviceLabel);
    outputDeviceLayout->addWidget(_outputDeviceComboBox);
    dialogLayout->addLayout(outputDeviceLayout.data());
    outputDeviceLayout.take(); // ownership transferred to dialogLayout

    // Connect
    CHECKED_CONNECT(_inputDeviceComboBox, SIGNAL(activated(int)),
                    this, SLOT(inputDeviceChanged(int)));
    CHECKED_CONNECT(_outputDeviceComboBox, SIGNAL(activated(int)),
                    this, SLOT(outputDeviceChanged(int)));

    // Add standard buttons to layout
    QDialogButtonBox *buttonBox = new QDialogButtonBox(this);
    buttonBox->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    dialogLayout->addWidget(buttonBox);

    // Connect standard buttons
    CHECKED_CONNECT(buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()),
                    this, SLOT(accept()));
    CHECKED_CONNECT(buttonBox->button(QDialogButtonBox::Cancel), SIGNAL(clicked()),
                    this, SLOT(reject()));

    setLayout(dialogLayout);
}

SettingsDialog::~SettingsDialog()
{

}

void SettingsDialog::inputDeviceChanged(int index)
{
    _inputDevice = _inputDeviceComboBox->itemData(index).value<QAudioDeviceInfo>();
}

void SettingsDialog::outputDeviceChanged(int index)
{
    _outputDevice = _outputDeviceComboBox->itemData(index).value<QAudioDeviceInfo>();
}

