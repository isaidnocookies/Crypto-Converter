import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3

Item {
    id: dashboardPage

    property bool isInfoUp: false

    function updateValueIfUnfocused(iShortname) {
        if (totalCurrencyLabel.focus !== true) {
            totalCurrencyLabel.text = "$" + userAccount.getValue("USD", "USD")
            getDisplayText()
        }
    }

    function getDisplayText() {
        if (totalCurrencyLabel.text.indexOf("$") < 0) {
            totalCurrencyLabel.text = "$" + totalCurrencyLabel.text
        }

        if (totalCurrencyLabel.text === "$" || totalCurrencyLabel.text === "$0") {
            totalCurrencyLabel.placeholderText = "Enter Amount"
            totalCurrencyLabel.text = ""
        }
    }

    Connections {
        target: userAccount

        onMarketValueChanged: {
            updateValueIfUnfocused("USD")
        }

        onValueChanged: {
            updateValueIfUnfocused("USD")
        }
    }

    Rectangle {
        id: topBarSpacer
        color: "white"
        anchors.top: parent.top
        width: parent.width
        height: topAreaCorrectionHeight - 5
        z:8
    }

    Text {
        id: titleLabel
        font.bold: false
        text: "ThreeBx - Crypto Converter"
        anchors.top: topBarSpacer.bottom
        x: (parent.width / 2) - (width / 2)
        z:10
        height: 20

        verticalAlignment: TextInput.AlignTop


        color: "black"
    }

    Image {
        id: topInfoButton
        source: "/images/assets/infoIcon.png"
        height: 20
        width: 20
        z: 15

        y: totalCurrencyLabel.y + totalCurrencyLabel.height - height - 12
        x: parent.width - width - 20

        MouseArea {
            anchors.fill: parent
            z: 20

            onClicked: {
                console.log("More information")

                if (!isInfoUp) {
                    movementAnimation.running = true
                    isInfoUp = true
                } else {
                    closeAnimation.running = true
                    isInfoUp = false
                }
            }
        }
    }

    TextField {
        id: totalCurrencyLabel
        y: titleLabel.y + titleLabel.height //+ 20
        z:10

        width: parent.width * 0.85
        height: 60 //parent.height * 0.1

        inputMethodHints: (Qt.ImhNoPredictiveText | Qt.ImhPreferNumbers)

        font.pointSize: 30
        wrapMode: Text.NoWrap
        font.weight: Font.Thin

        text: ""
        placeholderText: "Enter Amount"
        color: "black"

        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: TextInput.AlignHCenter
        verticalAlignment: TextInput.AlignBottom

        background: Rectangle {
            color: "transparent"
            border.color: "transparent"
        }

        onTextEdited: {
            userAccount.setValue("USD", totalCurrencyLabel.text)
            getDisplayText()
        }
    }

    Rectangle {
        id: totalToListSpacer
        anchors.top: totalCurrencyLabel.bottom
        height: 15
        width: parent.width
        z:8
        color: Qt.rgba(1,1,1,0)
    }

    Rectangle {
        z:9
        id: colorBackgroundHeader
        width: parent.width
        anchors.top: topBarSpacer.top
        anchors.bottom: listMask.bottom

        color: "white"

        opacity: 0.8
    }

    Rectangle {
        z:8
        id: listMask
        color: "white"
        width: parent.width
        anchors.top: parent.top
        anchors.bottom: totalToListSpacer.bottom
    }

    Rectangle {
        id: topShadowEffect
        anchors.top: listMask.bottom
        height: 8
        width: parent.width
        z:9
        opacity: 0.4

        gradient: Gradient {
            GradientStop {
                position: 0
                color: Qt.rgba(0, 0, 0, 0.5)
            }
            GradientStop {
                position: 1
                color: Qt.rgba(0, 0, 0, 0)
            }
        }
    }

    Rectangle {
        id: topListSpacer
        anchors.top: topShadowEffect.bottom
        height: 5
        width: parent.width
    }

    DashboardListModel {
        id: theDashboardListModel
    }

    CryptoWalletDelegate {
        id: cryptoDelegate
    }

    Flickable {
        id: flickableView

        function getRowCount () {
            return Math.floor(parent.width / (cellWidth + flowView.spacing))
        }

        function getRowWidth() {
            return getRowCount() * cellWidth + ((getRowCount() - 1) * flowView.spacing)
        }

        function getMarginSize() {
            return ((parent.width - getRowWidth()) / 2)
        }

        anchors.top: topListSpacer.bottom
        width: parent.width * 0.95
        anchors.bottom: bottomBarCorrectionSpacer.top

        contentWidth: flickableView.width
        contentHeight: ((theDashboardListModel.count / getRowCount()) + 1) * cellHeight + 50

        flickableDirection: Flickable.VerticalFlick

        anchors.horizontalCenter: parent.horizontalCenter

        Flow {
            id: flowView
            width: parent.width
            spacing: 15

            leftPadding: parent.getMarginSize()

            Repeater {
                model: theDashboardListModel
                delegate: cryptoDelegate
            }

            onWidthChanged: {
                flowView.leftPadding = flickableView.getMarginSize() / 2
                flickableView.contentHeight = ((theDashboardListModel.count / flickableView.getRowCount()) + 1) * cellHeight + 50
            }
        }

        Component.onCompleted: console.log(contentHeight)
    }

    Rectangle {
        id: footer
//        anchors.bottom: parent.bottom
        y: 0 - height
        height: parent.height / 2 - 30
        width: parent.width
        color: "white"

        opacity: 1

        Text {
            id: bottomTitle
            text: "ThreeBx - Crypto Converter"
            topPadding: 10
            rightPadding: 5
            color: "gray"

            visible: false

            anchors.top: footer.top
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Image {
            id: infoIcon
            source: "/images/assets/infoIcon.png"
            height: bottomTitle.height - bottomTitle.topPadding
            width: height

            visible: false

            anchors.left: bottomTitle.right
            y: bottomTitle.y + bottomTitle.topPadding - 1
        }

        Text {
            id: info1
            text:  "Brought to you by ThreeBx"
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width * 0.8

            horizontalAlignment: Text.AlignHCenter

            y: bottomTitle.y + bottomTitle.height + 30

            color: "black"
        }

        Image {
            id: threebxLogo

            z: 30
            source: "/images/assets/threebxLogo.png"
            width: parent.width / 2
            fillMode: Image.PreserveAspectFit
            y: info1.y + info1.height + 10

            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: info2
            text:  "(Click image to visit threebx.com)"
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width * 0.8

            font.pointSize: 8

            horizontalAlignment: Text.AlignHCenter

            y: threebxLogo.y + threebxLogo.height + 10

            color: "black"
        }

        MouseArea {
            z: 50

            anchors {
                top: info1.top
                bottom: info2.bottom
                right: threebxLogo.right
                left: threebxLogo.left
            }

            onClicked: {
                Qt.openUrlExternally("https://www.threebx.com")
                console.log("Visit ThreeBx")
            }
        }

        Text {
            id: info3

            text: {
                "This tool was created to help with the complexities of cryptocurrency conversions. By clicking one the values, you can calculate the conversion between any of the assets. We hope this will help make trading easier to understand and give our community the tools needed to navigate the digital asset trading world! And questions or comments, please contact us at info@threebx.com"
            }

            wrapMode: Text.WordWrap

            width: parent.width * 0.8
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: Text.AlignHCenter

            y:info2.y + info2.height + 30
        }

        MouseArea {
            anchors.fill: parent
            z: 20

            onClicked: {
                console.log("More information")

                if (!isInfoUp) {
                    movementAnimation.running = true
                    isInfoUp = true
                } else {
                    closeAnimation.running = true
                    isInfoUp = false
                }
            }
        }

        NumberAnimation on y {
            id: movementAnimation
            running: false
            from: 0 - parent.height; to: listMask.y + listMask.height
        }

        NumberAnimation on y {
            id: closeAnimation
            running: false
            from: listMask.y + listMask.height; to: 0 - parent.height
        }

        Rectangle {
            id: bottomShadowEffect
            anchors.top: footer.bottom
            height: 8
            width: parent.width
            z:9
            opacity: 0.4

            gradient: Gradient {
                GradientStop {
                    position: 0
                    color: Qt.rgba(0, 0, 0, 0.5)
                }
                GradientStop {
                    position: 1
                    color: Qt.rgba(0, 0, 0, 0)
                }
            }
        }

        Image {
            id: upArrow
            source: "/images/assets/upNavArrowIcon.png"
            height: 15
            width: 25
            anchors.horizontalCenter: parent.horizontalCenter
            y: bottomShadowEffect.y - upArrow.height - 20
        }
    }



    Rectangle {
        id: bottomBarCorrectionSpacer
        color: "transparent"
        anchors.bottom: parent.bottom
        height: bottomAreaCorrectionHeight
        width: parent.width
        z:10
    }
}
