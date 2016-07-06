//import QtQuick 2.1

import QtQuick 2.4
import QtQuick.Window 2.2
import Qt.labs.settings 1.0
import QtQuick.Controls 1.2


Rectangle {
    id: root
    width: joystick.width
    height: joystick.height
    color: "transparent"

    signal joystick_moved(double x, double y);

    Image {
        id: joystick

        property real angle : 0
        property real distance : 0

        source: "background.png"
        anchors.centerIn: parent

        ParallelAnimation {
            id: returnAnimation
            NumberAnimation { target: thumb.anchors; property: "horizontalCenterOffset";
                to: 0; duration: 200; easing.type: Easing.OutSine }
            NumberAnimation { target: thumb.anchors; property: "verticalCenterOffset";
                to: 0; duration: 200; easing.type: Easing.OutSine }
        }

        MouseArea {
            id: mouse
            property real fingerAngle : Math.atan2(mouseX, mouseY)
            property int mcx : mouseX - width * 0.5
            property int mcy : mouseY - height * 0.5
            property bool fingerInBounds : fingerDistance2 < distanceBound2
            property real fingerDistance2 : mcx * mcx + mcy * mcy
            property real distanceBound : width * 0.5 - thumb.width * 0.5
            property real distanceBound2 : distanceBound * distanceBound

            property double signal_x : (mouseX - joystick.width/2) / distanceBound
            property double signal_y : -(mouseY - joystick.height/2) / distanceBound

            anchors.fill: parent

            onPressed: {
                returnAnimation.stop();
            }

            onReleased: {
                returnAnimation.restart()
                joystick_moved(0, 0);
            }

            onPositionChanged: {
                if (fingerInBounds) {
                    thumb.anchors.horizontalCenterOffset = mcx
                    thumb.anchors.verticalCenterOffset = mcy
                } else {
                    var angle = Math.atan2(mcy, mcx)
                    thumb.anchors.horizontalCenterOffset = Math.cos(angle) * distanceBound
                    thumb.anchors.verticalCenterOffset = Math.sin(angle) * distanceBound
                }

                // Fire the signal to indicate the joystick has moved
                angle = Math.atan2(signal_y, signal_x)

                if(fingerInBounds) {
                    joystick_moved(
                        Math.cos(angle) * Math.sqrt(fingerDistance2) / distanceBound,
                        Math.sin(angle) * Math.sqrt(fingerDistance2) / distanceBound
                    );
                } else {
                    joystick_moved(
                        Math.cos(angle) * 1,
                        Math.sin(angle) * 1
                    );
                }
            }
        }

        Image {
            id: thumb
            source: "finger.png"
            anchors.centerIn: parent
        }
    }
}



/*
Rectangle {
    id: test
    visible: true
    width: 200
    height: 50

    Connections {
        target: receiver
        onSendToQml: {
            console.log("Received in QML from C++: " + count)
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            receiver.receiveFromQml(42);
        }
    }

    Text {
        text: qsTr("Press me to send a signal to C++")
        anchors.centerIn: parent
    }
}
*/


/*
Rectangle {
    id: simplebutton
    color: "grey"
    width: 150; height: 75

    Text{
        id: buttonLabel
        anchors.centerIn: parent
        text: "button label"
    }

    property color buttonColor: "lightblue"
       property color onHoverColor: "gold"
       property color borderColor: "white"

       signal buttonClick()
       onButtonClick: {
           console.log(buttonLabel.text + " clicked" )
       }

       MouseArea{
           onClicked: buttonClick()
           hoverEnabled: true
           onEntered: parent.border.color = onHoverColor
           onExited:  parent.border.color = borderColor
       }


}*/





/*Rectangle {
id: menu
state: "MAIN_MENU_SHOWN"

Rectangle
{
    id: topLeftRect
    x: 0
    y: 0
    width: 100
    height: 100
    color: "red"
    radius: 6
    MouseArea { id: mousearea1; width: 100; height: 100; anchors.rightMargin: 0;anchors.fill: parent; onClicked: HelpPage.handleButton()}
}

Rectangle
{
    id: topRightRect
    width: 100
    height: 100
    color: "blue"
    x: 350; y: 100
    radius: 6
    MouseArea {anchors.fill: parent; onClicked: menu.state = "MAIN_MENU_HIDDEN"}
}

Rectangle
{
    id: bottomLeftRect
    width: 100
    height: 100
    color: "green"
    x: 100; y: 250
    radius: 6
    MouseArea {anchors.fill: parent; onClicked: menu.state = "MAIN_MENU_HIDDEN"}
}

Rectangle
{
    id: bottomRightRect
    width: 100
    height: 100
    color: "yellow"
    x: 350; y: 250
    radius: 6
            MouseArea {
                id: mousearea2;
                anchors.fill: parent;
                onClicked:
                {
                menu.state = "MAIN_MENU_HIDDEN"
                mainmenu.GoToPanel();
                }
                }

                }

                states: [
                    State
                    {
                        name: "MAIN_MENU_HIDDEN"
                        PropertyChanges {
                            target: bottomRightRect
                            x: 624
                            y: 467
                            opacity: 0
                        }

                        PropertyChanges {
                            target: topRightRect
                            x: 624
                            y: -86
                            opacity: 0
                        }

                        PropertyChanges {
                            target: bottomLeftRect
                            x: -85
                            y: 467
                            opacity: 0
                        }

                        PropertyChanges {
                            target: topLeftRect
                            x: -85
                            y: -86
                            opacity: 0
                        }

                        PropertyChanges
                        {
                            target: menu
                            opacity: 0
                        }

                    },
                    State {
                        name: "MAIN_MENU_SHOWN"
                    }
                ]

                transitions:
                [
                    Transition {
                    from: "MAIN_MENU_SHOWN"; to: "MAIN_MENU_HIDDEN"
                        ParallelAnimation
                        {
                        NumberAnimation { properties: "x,y"; easing.type: Easing.OutQuad; duration: 1000 }
                        NumberAnimation { property: "opacity"; duration: 1000 }
                        }
                    },

                    Transition {
                    from: "MAIN_MENU_HIDDEN"; to: "MAIN_MENU_SHOWN"
                        ParallelAnimation
                        {
                        NumberAnimation { properties: "x,y"; easing.type: Easing.OutQuad; duration: 1000 }
                        NumberAnimation { property: "opacity"; duration: 1000 }
                        }
                    }
                ]
                }
*/
