/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 2.15
import QtQuick.Controls 2.15
import FlowView 1.0

FlowItem {
    width: 280
    height: 50

    TextInput {
        id: txtNameMacr
        x: 8
        y: 8
        width: 178
        height: 35
        text: qsTr("Text Input")
        font.pixelSize: 12

        Button {
            id: btnStartMacr
            x: 184
            y: 0
            width: 90
            height: 35
            text: qsTr("Start")
        }
    }
}
