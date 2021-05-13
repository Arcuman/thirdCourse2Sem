const crypto = require('crypto');
const fs = require('fs')
const { pipeline } = require('stream');
const {cipherFile, decipherFile22} = require('./cryptoPipe');
module.exports.cipherFile = (key, res, cb) => {
    const cipher = crypto.createCipher('aes192', 'a password');

let clRS = fs.createReadStream('./file2.txt');
let clWS = fs.createWriteStream('./file3.enc');

clRS.pipe(cipher).pipe(clWS);
clWS.on('close', (err) => {
    decipherFile22('vadim');
})
}

module.exports.decipherFile =  (key, iv, cb) =>{
    const decipher = crypto.createDecipher('aes192', 'a password');

    let clRS = fs.createReadStream('./file3.enc');
    let clWS = fs.createWriteStream('./file1.txt');

    clRS.pipe(decipher).pipe(clWS);
}