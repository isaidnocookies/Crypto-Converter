import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0

Component {
    id: cryptoRowDelegate

    Item {
        width: cellWidth
        height: cellHeight

        function getMarketValue(iShortname) {
            return userAccount.getMarketValue(iShortname, "USD")
        }

        function updateValueIfUnfocused(iShortname) {
            if (cryptoAmount.focus !== true) {
                cryptoAmount.text = userAccount.getValue(iShortname, "USD")
            }
        }

        Connections {
            target: userAccount

            onMarketValueChanged: {
                marketValueText.text = "$" + threshodlTools.formatMarketValueString(getMarketValue(shortName))
                updateValueIfUnfocused(shortName)
            }

            onValueChanged: {
                updateValueIfUnfocused(shortName)
            }
        }

        Rectangle {
            id: cellBorder
            height: parent.height
            width: parent.width

            Image {
                id: iconImage
                source: Qt.resolvedUrl(imageName)
                height: 50
                width: 50

                anchors.horizontalCenter: parent.horizontalCenter
                y: 10
            }

            Text {
                id: longNameText
                text: name + " (" + shortName + ")"
                font.bold: true
                font.pointSize: 16

                y: iconImage.y + iconImage.height + 10
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: marketValueText
                text: "$" + threshodlTools.formatMarketValueString(getMarketValue(shortName))
                font.pointSize: 15
                font.weight: Font.Thin

                anchors.horizontalCenter: parent.horizontalCenter
                y: longNameText.y + longNameText.height + 10
            }

            TextField {
                id: cryptoAmount
                width: parent.width * 0.9
                text: "0"
                font.pointSize: 20
                font.weight: Font.Bold

                inputMethodHints: (Qt.ImhNoPredictiveText | Qt.ImhPreferNumbers)

                anchors.horizontalCenter: parent.horizontalCenter
                y: marketValueText.y + marketValueText.height + 10

                horizontalAlignment: TextInput.AlignHCenter

                background: Rectangle {
                    border.color: "transparent"
                    color: "transparent"
                }

                onTextEdited: {
                    userAccount.setValue(shortName, cryptoAmount.text)
                }
            }

            Rectangle {
                id: bottomLine
                width: parent.width * 0.9
                height: 1
                color: "lightgray"
                anchors.horizontalCenter: parent.horizontalCenter
                y: cryptoAmount.y + cryptoAmount.height + 10
            }

//            Rectangle {
//                id: rightLine
//                width: bottomLine.height
//                height: cellHeight/4
//                anchors.right: parent.right
//                y: bottomLine.y - height - 5

//                color: "lightgray"
//            }
        }
    }
}
