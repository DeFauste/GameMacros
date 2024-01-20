/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 6.5
import QtQuick.Controls 6.5
import UIGameMacros

Rectangle {
    id: mainMenu
    width: 1000
    height: 500

    color: Constants.backgroundColor

    Button {
        id: button
        x: 136
        y: 438
        text: qsTr("Delete")
    }

    Button {
        id: addButton
        x: 21
        y: 438
        text: qsTr("Add Macros")
    }

    ListView {
        id: listMacros
        x: 21
        y: 8
        width: 300
        height: 400
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: row1
                spacing: 10
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                }

                Text {
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
            }
        }
    }
    states: [
        State {
            name: "clicked"
        }
    ]
}
