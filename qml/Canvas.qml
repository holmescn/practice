import QtQuick 2.3

Rectangle {
    id: page
    width: 640
    height: 480

    Canvas {
        id: canvas
        anchors.fill: parent
        onPaint: {
            var ctx = canvas.getContext('2d');
            ctx.clearRect(0, 0, canvas.width, canvas.height);

            ctx.lineWidth = 4;
            ctx.fillStyle = "#FF0000";
            ctx.strokeStyle = "#FFFFFF";
            ctx.rect(4, 4, 100, 50);
            ctx.fill();
            ctx.stroke();

            ctx.rect(108, 4, 100, 50);
            ctx.stroke();
            ctx.fill();
        }
    }
}
