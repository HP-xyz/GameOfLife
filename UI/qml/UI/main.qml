import QtQuick 2.0



Rectangle {
    signal startGame()
    function updateFrontend(worldCells)
    {
        var model = new ListModel()
        for(var i = 0; i < worldCells.length; i++)
        {
            model.append();
        }
    }
    function changeViewModel()
    {

    }

    width: 360
    height: 360
    GridView {
        id: itemGridview
        x: 8
        y: 8
        width: 344
        height: 344
        cellHeight: 30
        delegate: Item {
            x: 5
            height: 32
            Column {
                spacing: 0
                Rectangle {
                    width: 32
                    height: 32
                    color: colorCode
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
        cellWidth: 32

        Rectangle {
            id: startGameRect
            x: 110
            y: 312
            width: 124
            height: 32
            color: "#ffffff"
            border.color: "grey"
            MouseArea
            {
                anchors.fill: parent
                onClicked: initializeGrid()
            }
        }
    }
}
