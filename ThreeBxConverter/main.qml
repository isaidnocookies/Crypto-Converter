import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.3

import com.threeb.ThreeBxConverter.PlatformInformation 1.0
import com.threeb.ThreeBxConverter.UserAccount 1.0
import com.threeb.ThreeBxConverter.ThreshodlTools 1.0

ApplicationWindow {
    visible: true
    width: 375
    height: 900
    title: qsTr("ThreeBx Converter")

    flags: Qt.MaximizeUsingFullscreenGeometryHint

    PlatformInformation { id: platformInformation }
    UserAccount { id: userAccount }
    ThreshodlTools { id: threshodlTools }

    property real topAreaCorrectionHeight: (platformInformation.getTopAreaCorrection())
    property real bottomAreaCorrectionHeight: (platformInformation.getBottomAreaCorrection())
    property string titleName: "ThreeBxConverter"

    property int cellHeight: 160
    property int cellWidth: 160

    property int buttonFontSize: 13

    DashboardPage {
        id: dashboard
        visible: false
    }

    StackView {
        id: ourStackView
        initialItem: dashboard
        anchors.fill: parent
    }
}
