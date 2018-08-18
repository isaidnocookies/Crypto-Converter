import QZXing 2.3
import QtMultimedia 5.8
import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3

Item {
    id: qrScanner

    property string addressFromScanner

    function restartTimer () {
        myPhotoTimer.restart()
    }

    Component.onCompleted: {
        myPhotoTimer.running = false
        myPhotoTimer.stop
    }

    Image {
        z:101
        source: "images/assets/qrScannerGuides.png"
        width: parent.width * 0.6
        height: width
        fillMode: Image.PreserveAspectFit
        anchors.centerIn: parent
    }

    Rectangle {
        z:0
        color: "black"
        anchors.fill: parent
    }

    Rectangle {
        id: topBarSpacer
        color:"black"
        anchors.top: parent.top
        width: parent.width
        height: topAreaCorrectionHeight
    }

    Button {
        id: backButton
        height: 30
        width: 30
        z:100

        background: Rectangle {
            color: Qt.rgba(1,1,1,0)
            width: parent.height
            height: parent.width
            anchors.centerIn: parent
        }

        anchors.top: topBarSpacer.bottom
        x: 25

        Image {
            source: "images/assets/whiteBackButtonIcon.png"
            fillMode: Image.PreserveAspectFit
            width: parent.width
        }
        onClicked: {
            myPhotoTimer.stop()
            myPhotoTimer.running = false
            ourStackView.pop()
        }
    }

    Camera {
        id: camera

        imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash
        exposure {
            exposureCompensation: -1.0
            exposureMode: Camera.ExposurePortrait
        }
        flash.mode: Camera.FlashRedEyeReduction
        imageCapture {
            onImageCaptured: {
                photoPreview.source = preview  // Show the preview in an Image
                console.log("Image captured")
                decode(preview)
            }
        }
    }

    VideoOutput {
        source: camera

        fillMode: VideoOutput.PreserveAspectCrop

        width: parent.width

        anchors.top:topBarSpacer.top
        anchors.bottom: parent.bottom

        focus : visible
        autoOrientation: true
    }

    Image {
        visible: false
        id: photoPreview
    }

    function decode(preview) {
        decoder.decodeImageQML(photoPreview);
    }

    QZXing{
        id: decoder
        enabledDecoders: QZXing.DecoderFormat_QR_CODE
        onDecodingStarted: console.log("Decoding of image started...")
        onTagFound: {
            console.log("Barcode data: " + tag)
            addressFromScanner = tag
        }

        onDecodingFinished: {
            if (succeeded==true) {
                console.log("Decoding successful!")
                myPhotoTimer.stop
                myPhotoTimer.running = false
                ourStackView.pop()
            } else {
                console.log("Continuing to look....")
            }
        }
    }

    Timer {
        id: myPhotoTimer
        interval: 1500
        triggeredOnStart: false
        onTriggered: {
            console.log("Timer triggered")
            camera.imageCapture.capture()
        }
        running:true
        repeat: true
    }
}
