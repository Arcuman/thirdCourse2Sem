const express = require('express');
const fs = require('fs');
const bodyParser = require('body-parser');
const stream = require("stream");
const {ServerSignShnorr, ClientVerifyShnorr} = require('./ESignatureShnorr');
const {ServerSignElgam, ClientVerifyElgam} = require('./ESignatureElgamal');
const {ServerSignRSA, ClientVerifyRSA} = require('./ESignatureRSA');

const app = express();
app.use(bodyParser.json());

const PORT = 3000;

app.get('/signature/rsa', (req, res) => {
    console.log('/rsa');
    try{
        const textStream = fs.createReadStream(`${__dirname}/file.txt`);
        const passThrough = new stream.PassThrough({allowHalfOpen: false});
        const passThrough2 = new stream.PassThrough({allowHalfOpen: false});
        let text = '';
        passThrough.on('data', (chunk) => {
            text += chunk.toString();
        });
        passThrough.on('end',() => {
            console.log(text);
            const ss = new ServerSignRSA();
            ss.getSignContext(passThrough2, (signContext) => {
                console.log('RES SEND')
                res.send({
                    file: text,
                    sign: signContext});
            });
        })
        textStream.pipe(passThrough);
        textStream.pipe(passThrough2);
    }
    catch(e){
        console.log('RSA error: ', e);
        res.status(409).json({ msg: 'RSA error' });
    }
});

app.get('/signature/shnorr', (req, res) => {
    console.log('/shnorr');
    try{
        const text = fs.readFileSync(`${__dirname}/file.txt`, 'utf8');
        let ss = new ServerSignShnorr();
        ss = ss.getSignContext(text);
        res.json({
            file: text,
            sign: ss
        });
    }
    catch(e){
        console.log('Shnorr error: ', e);
        res.status(409).json({ msg: 'Shnorr error' });
    }
});

app.get('/signature/elgamal', (req, res) => {
    console.log('/elgamal');
    try{
        const textStream = fs.createReadStream(`${__dirname}/file.txt`);
        const passThrough = new stream.PassThrough({allowHalfOpen: false});
        const passThrough2 = new stream.PassThrough({allowHalfOpen: false});
        let text = '';
        passThrough.on('data', (chunk) => {
            text += chunk.toString();
        });
        passThrough.on('end',() => {
            console.log(text);
            const ss = new ServerSignElgam();
            ss.getSignContext(passThrough2, (signContext) => {
                console.log('RES SEND')
                res.send({
                    file: text,
                    sign: signContext});
            });
        })
        textStream.pipe(passThrough);
        textStream.pipe(passThrough2);
    }
    catch(e){
        console.log('Elgamal error: ', e);
        res.status(409).json({ msg: 'Elgamal error' });
    }
});

app.listen(PORT, () =>{
  console.log(`Listening on https://localhost:${PORT}`);
})
.on('error', (e) => {console.log(`Listener | error: ${e.code}`)});
