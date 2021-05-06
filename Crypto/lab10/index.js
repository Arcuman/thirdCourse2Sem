const ElGamal = require("elgamal");
const NodeRSA = require('node-rsa');
const express = require('express')
const bodyParser = require('body-parser');
const Crypto = require('./elgamal')
const EncryptedValue = require("elgamal/lib/models/encrypted-value");
const app = express()
const port = 3000

var Alphabet = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~ π®ƒ©∆";
Alphabet = Alphabet.split("");

let Alice ;
let Bob ;

const keyRSA = new NodeRSA({b: 2048});
let keyEl = null;

const encryptEL = (text) => {
    return keyRSA.encrypt(text, 'base64');
}

const decryptEL = (text) => {
    return keyRSA.decrypt(text, 'utf8');
}

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));

app.get('/', (req, res) => {
    res.sendFile(__dirname + "/index.html")
})

app.post('/encryptRSA', (req, res) => {
    res.send(encryptEL(req.body.text));
})
app.post('/decryptRSA', (req, res) => {
    res.send(decryptEL(req.body.text));
})

app.post('/encryptEL', async (req, res) => {
    if(!Alice){
    Alice = Crypto(Alphabet, 69);
    Bob = Crypto(Alphabet, 69);
    }
    var message1 = req.body.text;
    message1 = Alice.encrypt(message1, Bob.pubKey);
    return res.send(message1);
})

app.post('/decryptEL', async(req, res) => {
    if(!Alice){
        Alice = Crypto(Alphabet, 69);
        Bob = Crypto(Alphabet, 69);
    }
    res.send(Bob.decrypt(req.body.text));
})

app.listen(port, (err) => {
    console.log(err);
    console.log('start 3000')
})


function runRSA() {
    console.time('KEY GENERATION')
    const key = new NodeRSA({b: 2048});
    console.timeEnd('KEY GENERATION')
    const text = 'Borisov Anton!';
    console.time('START ENCRYPTION');
    const encrypted = key.encrypt(text, 'base64');
    console.timeEnd('START ENCRYPTION')
    console.log('encrypted: ', encrypted);
    console.time('START DECRYPTION');
    const decrypted = key.decrypt(encrypted, 'utf8');
    console.timeEnd('START DECRYPTION');
    console.log('decrypted: ', decrypted);
}

async function runElGamal() {
    console.time('KEY GENERATE ElGAMAL');
    const eg = await ElGamal.default.generateAsync(2048);
    console.timeEnd('KEY GENERATE ElGAMAL');
    const secret = 'Borisov Anton';
    console.time('ENCRYPT ElGAMAL');
    const encrypted = await eg.encryptAsync(secret);
    console.timeEnd('ENCRYPT ElGAMAL');
    console.time('DECRYPT ElGAMAL');
    const decrypted = await eg.decryptAsync(encrypted);
    console.timeEnd('DECRYPT ElGAMAL');
    console.log(decrypted.toString() === secret);
}

runRSA();
runElGamal();
