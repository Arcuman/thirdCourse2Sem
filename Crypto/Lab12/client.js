const app = require('express')();
const fs = require('fs');
const {ServerSignShnorr, ClientVerifyShnorr} = require('./ESignatureShnorr');
const {ServerSignElgam, ClientVerifyElgam} = require('./ESignatureElgamal');
const {ServerSignRSA, ClientVerifyRSA} = require('./ESignatureRSA');
const request = require('request-promise');

const PORT = 3001;


app.listen(PORT, async () => {
    await request({
        method: 'GET',
        uri: 'http://localhost:3000/signature/rsa',
        json: true
    })
        .then((response) => {
            let signature = response.sign;
            let txt = response.file;
            console.log(signature)
            let cv = new ClientVerifyRSA();
            cv.verify(signature, txt).then((isVerify) => {
                    if (isVerify) {
                        console.log('Verified RSA')
                    } else {
                        console.log('Fake RSA')
                    }
                }
            )
        })
        .catch((err) => {
            console.log(`RSA ERROR: ${err}`);
        });

    await request({
        method: 'GET',
        uri: 'http://localhost:3000/signature/elgamal',
        json: true
    })
        .then((response) => {
            let signature = response.sign;
            let txt = response.file;
            let cv = new ClientVerifyElgam();
            cv.verify(signature, txt).then((isVerify) => {
                    if (isVerify) {
                        console.log('Verified ELGAM')
                    } else {
                        console.log('Fake ELGAM')
                    }
                }
            )
        })
        .catch((err) => {
            console.log(`Elgamal ERROR: ${err}`);
        });

    await request({
        method: 'GET',
        uri: 'http://localhost:3000/signature/shnorr',
        json: true
    })
        .then((response) => {
            let signature = response.sign;
            let txt = response.file;
            let cv = new ClientVerifyShnorr();
            cv.verify(signature, txt).then((isVerify) => {
                    if (isVerify) {
                        console.log('Verified Shnorr')
                    } else {
                        console.log('Fake Shnorr')
                    }
                }
            )
        })
        .catch((err) => {
            console.log(`Shnorr ERROR: ${err}`);
        });
})
    .on('error', (e) => {
        console.log(`Listener | error: ${e.code}`)
    });
