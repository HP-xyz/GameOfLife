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
        changeViewModel()
        updateUI()
    }
    function updateUI()
    {
        if(gridItemModel.count === 0) return
        for(var k = 0; k < world.Cells.length; k++)
        {
            for(var i = 0; i < 100; i++)
            {
                var currentItem = gridItemModel.get(i)
                if(currentItem.X === world.Cells[k].X
                    && currentItem.Y === world.Cells[k].Y)
                {
                    gridItemModel.set(i,
                                {
                                    "colorCode": "white",
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
        for(var i = 0; i < 10; i++)
            for(var j = 0; j < 10; j++)
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
        cellHeight: 30
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
    }
}
