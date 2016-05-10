import QtQuick 2.4
import QtQuick.Controls 1.2


Item {
    id: menu

    signal menuItemClicked( string item, string page )
    property alias currentItem: listViewMenu.currentIndex

    ListModel {
        id: modelMenu
        ListElement {
            item: "personalProfile"
            icon: "qrc:/images/icon_game.png"
            page: "PersonalProfile.qml"
        }
        ListElement {
            item: "personaleDoctor"
            icon: "qrc:/images/icon_game.png"
            page: "PersonaleDoctor.qml"
        }
        ListElement {
            item: "microphoneBreathMonitoring"
            icon: "qrc:/images/icon_settings.png"
            page: "MicrophoneBreathMonitoring.qml"
        }
        ListElement {
            item: "sensorsBreathMonitoring"
            icon: "qrc:/images/icon_settings.png"
            page: "SensorsBreathMonitoring.qml"
        }
        ListElement {
            item: "help"
            icon: "qrc:/images/icon_info.png"
            page: "Help.qml"
        }
    }

    function textItemMenu( item )
    {
        var textReturn = ""
        switch( item ) {
        case "personalProfile":
            textReturn = qsTr("Personal Profile")
            break;
        case "personaleDoctor":
            textReturn = qsTr("Personal eDoctor")
            break;
        case "microphoneBreathMonitoring":
            textReturn = qsTr("Microphone Breath Monitoring")
            break;
        case "sensorsBreathMonitoring":
            textReturn = qsTr("Sensors Breath Monitoring")
            break;
        case "help":
            textReturn = qsTr("Help")
            break;
        case "log":
            textReturn = "Log"
            break;
        }
        return textReturn
    }

    Rectangle {
        id: logoWtapper
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        width: parent.width
        height: width*0.5
        color: palette.primary //"#3078fe" //this color is equal to the background of imgLogo
        clip: true
        Image {
            id: imgLogo
            source: "qrc:/images/background.png"
            height: parent.height
            width: parent.width
            antialiasing: true
            smooth: true
            anchors.top: parent.top
            anchors.left: parent.left
            opacity: 0.5
        }
    }
    Image {
        id: imgShadow
        anchors.top: logoWtapper.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 10*app.dp
        z: 4
        source: "qrc:/images/shadow_title.png"
    }
    ListView {
        id: listViewMenu
        anchors.top: logoWtapper.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        clip: true
        model: modelMenu
        delegate: componentDelegate
    }

    Component {
        id: componentDelegate

        Rectangle {
            id: wrapperItem
            height: 60*app.dp
            width: parent.width
            color: wrapperItem.ListView.isCurrentItem || ma.pressed ? palette.currentHighlightItem : "transparent"
            Image {
                id: imgItem
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 0.5*imgItem.width
                height: parent.height*0.5
                width: height
                source: icon
                visible: icon != ""
                smooth: true
                antialiasing: true
            }

            Label {
                id: textItem
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: imgItem.right
                anchors.leftMargin: 0.7*imgItem.width
                text: textItemMenu( item )
                font.pixelSize: parent.height*0.3
                color: wrapperItem.ListView.isCurrentItem ? palette.darkPrimary : palette.primaryText
            }


            MouseArea {
                id: ma
                anchors.fill: parent
                enabled: app.menuIsShown
                onClicked: {
                    menu.menuItemClicked( item, page )
                    listViewMenu.currentIndex = index
                }
            }
        }

    }
}

