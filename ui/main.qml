import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Triangle 1.0

ApplicationWindow {
    visible: true
    width: 480
    height: 640
    title: qsTr("Triangle Calculator")

    Triangle {
        id: triangle
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 10

        TextField {
            id: sideA
            placeholderText: qsTr("Enter Side A")
            onTextChanged: triangle.SideA = parseFloat(text)
            inputMethodHints: Qt.ImhFormattedNumbersOnly
        }

        TextField {
            id: sideB
            placeholderText: qsTr("Enter Side B")
            onTextChanged: triangle.SideB = parseFloat(text)
            inputMethodHints: Qt.ImhFormattedNumbersOnly
        }

        TextField {
            id: sideC
            placeholderText: qsTr("Enter Side C")
            onTextChanged: triangle.SideC = parseFloat(text)
            inputMethodHints: Qt.ImhFormattedNumbersOnly
        }

        TextField {
            id: alpha
            placeholderText: qsTr("Enter Alpha")
            onTextChanged: triangle.Alpha = parseFloat(text)
            inputMethodHints: Qt.ImhFormattedNumbersOnly
        }

        TextField {
            id: beta
            placeholderText: qsTr("Enter Beta")
            onTextChanged: triangle.Beta = parseFloat(text)
            inputMethodHints: Qt.ImhFormattedNumbersOnly
        }

        TextField {
            id: gamma
            placeholderText: qsTr("Enter Gamma")
            onTextChanged: triangle.Gamma = parseFloat(text)
            inputMethodHints: Qt.ImhFormattedNumbersOnly
        }

        Button {
            text: qsTr("Calculate")
            onClicked: {
                triangle.Calculate()
                sideA.text = triangle.SideA.toFixed(2)
                sideB.text = triangle.SideB.toFixed(2)
                sideC.text = triangle.SideC.toFixed(2)
                alpha.text = triangle.Alpha.toFixed(2)
                beta.text = triangle.Beta.toFixed(2)
                gamma.text = triangle.Gamma.toFixed(2)
                area.text = qsTr("Area: ") + triangle.Area.toFixed(2)
                perimeter.text = qsTr("Perimeter: ") + triangle.Perimeter.toFixed(2)
            }
        }

        Label {
            id: area
            text: qsTr("Area: ") + triangle.Area
        }

        Label {
            id: perimeter
            text: qsTr("Perimeter: ") + triangle.Perimeter
        }
    }
}
