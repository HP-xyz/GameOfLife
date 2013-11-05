import QtQuick 2.0



Rectangle {
    signal evolve()
    function startEvolving()
    {
        changeViewModel()
        //itemGridview.Timer.start()
    }
    function tick()
    {
        evolve()
        updateUI()
    }
    function updateUI()
    {
        console.log("updateUI")
        if(gridItemModel.count === 0) return
        for(var k = 0; k < world.Cells.length; k++)
        {
            for(var i = 0; i < 2500; i++)
            {
                var currentItem = gridItemModel.get(i)
                if(currentItem.X === world.Cells[k].X
                    && currentItem.Y === world.Cells[k].Y)
                {
                    console.log("changing cell at " + currentItem.X + " " + currentItem.Y)
                    gridItemModel.set(i,
                                {
                                    "colorCode": "white",
                                    "X": currentItem.X,
                                    "Y": currentItem.Y
                                })
                }
                else
                {
                    gridItemModel.set(i,
                                {
                                    "colorCode": "grey",
                                    "X": currentItem.X,
                                    "Y": currentItem.Y
                                })
                }
            }
        }
    }
    function changeViewModel()
    {
        gridItemModel.clear()
        for(var i = 0; i < 50; i++)
            for(var j = 0; j < 50; j++)
                gridItemModel.append(
                            {
                                "colorCode": "grey",
                                "X": i,
                                "Y": j
                            })
    }

    ListModel
    {
        id: gridItemModel
    }

    width: 360
    height: 360
    GridView {
        id: itemGridview
        x: 8
        y: 8
        width: 344
        height: 344
        cellHeight: 15
        model: gridItemModel
        Timer
        {
            interval: 1000
            running: true
            repeat: true
            onTriggered: tick()
        }
        delegate: Item {
            x: 5
            height: 15
            Column {
                spacing: 0
                Rectangle {
                    width: 15
                    height: 15
                    color: colorCode
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
        cellWidth: 15

        Rectangle {
            id: rectangle1
            x: 98
            y: 310
            width: 149
            height: 26
            color: "black"
            MouseArea
            {
                     anchors.fill: parent
                     onClicked: changeViewModel()
            }
        }

    }
}
