const express = require('express');
const API = require('./Handler/API');
const bodyParser = require('body-parser')

const app = express();
app.use(bodyParser.json());

const PORT = 3000;
const HOST = 'localhost';


app.get('/', (req, res) => {
    console.log('Send html');
    res.sendFile(__dirname + '/index.html');
});

app.get('/api/:tab', (req, res) => {
    let tab = req.params.tab;
    API.get(tab, req, res);
});

//-----POST------
app.post('/api/:tab', (req, res) => {
    console.log(req.body);
    let tab = req.params.tab;
    API.post(tab, req, res);
});

//-----PUT------
app.put('/api/:tab', (req, res) => {
    let tab = req.params.tab;
    API.put(tab, req, res);
});

//-----DELETE------
app.delete('/api/:tab', (req, res) => {
    let tab = req.params.tab;
    API.delete(tab, req, res)
});

app.listen(PORT, () => {
    console.log(`Listening on http://localhost:${PORT}`);
})
    .on('error', (e) => {
        console.log(`${URL} | error: ${e.code}`)
    });