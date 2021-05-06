const fs = require('fs');
const https = require('https');
const express = require('express');

const cert = {
    // Replace private key and cert with the appropriate names of the credentials you use
    key: fs.readFileSync('./docs/LAB.key', 'utf8'),
    cert: fs.readFileSync('./docs/RS-25-BAA.crt', 'utf8')
};
const app = express();

app.get('/', (request, response) => {
    response.end('<h1>Hello world</h1>')
});

const httpsServer = https.createServer(cert, app);
httpsServer.listen(8081, () => {
    console.log('Listening to https://localhost:8081/');
    console.log('Also available: https://BAA:8081/');
});
