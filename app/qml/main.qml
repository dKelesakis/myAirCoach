//import QtQuick 2.1

import QtQuick 2.4
import QtQuick.Window 2.2
import Qt.labs.settings 1.0
import QtQuick.Controls 1.2


Rectangle {
    width: 100
    height: 62
    color: "red"

    MouseArea {
        anchors.fill: parent
        onClicked: MainMenuPage.click()    //this
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
