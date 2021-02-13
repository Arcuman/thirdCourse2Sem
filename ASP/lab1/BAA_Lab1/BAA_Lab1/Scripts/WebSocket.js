var ta;
var ws = null;
var bstart;
var bstop;
window.onload = function () {
    if (Modernizr.websockets) {
        WriteMessage('support', 'yes');
        ta = document.getElementById('ta');
        bstart = document.getElementById('bstart');
        bstop = document.getElementById('bstop');
        bstart.disabled = false;
        bstop.disabled = true;
    }
}

function WriteMessage(idspan, txt) {
    document.getElementById(`${idspan}`).innerHTML= txt;
}

function exe_start() {
    if (ws == null) {
        ws = new WebSocket("wss://" + location.host + "/websockets.websocket");
        ws.onopen = function () { ws.send('connect'); }
        ws.onclose = function () { console.log('onclose', s); }
        ws.onmessage = function (evt) {ta.innerHTML += '\n' + evt.data; }
        ws.onerror = function (err) {console.log(err) }
        bstart.disabled = true;
        bstop.disabled = false;
    }
}


function exe_stop() {
    console.log(ws);
    console.log(1);
    ws.close();
    ws = null;
    bstart.disabled = false;
    bstop.disabled = true;
}