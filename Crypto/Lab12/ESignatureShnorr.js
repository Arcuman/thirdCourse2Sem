let crypto = require('crypto');

let prKey, pubKey, s;

class ServerSignShnorr{
    constructor(){
        //It's would be ok on nodejs v12.0.0
        const {privateKey, publicKey} = crypto.generateKeyPairSync('ed25519', {
            modulusLength: 2048,
            publicKeyEncoding: {type: 'spki', format: 'pem'},
            privateKeyEncoding: {type: 'pkcs8', format: 'pem'}
        });
        prKey = privateKey;
        pubKey = publicKey;
    }

    getSignContext(rs){
        return {
            signature: crypto.sign(null, Buffer.from(rs), prKey),
            publicKey: pubKey.toString('hex')
        };
    };
}

///////////////////////////////////////////////////////////////////
let v;

class ClientVerifyShnorr{
    constructor() {
    }

    async verify(signContext, rs) {
        return crypto.verify(null, Buffer.from(rs), signContext.publicKey, Buffer.from(signContext.signature));
    };
}


module.exports.ServerSignShnorr = ServerSignShnorr;
module.exports.ClientVerifyShnorr = ClientVerifyShnorr;
