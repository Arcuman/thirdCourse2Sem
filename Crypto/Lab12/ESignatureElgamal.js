const crypto = require('crypto');

let prKey, pubKey, s;

class ServerSignElgam{
    constructor(){
        const {privateKey, publicKey} = crypto.generateKeyPairSync('dsa', {
            modulusLength: 2048,
            publicKeyEncoding: {type: 'spki', format: 'pem'},
            privateKeyEncoding: {type: 'pkcs8', format: 'pem'}
        });

        prKey = privateKey;
        pubKey = publicKey;

        s = crypto.createSign('SHA256');
    }

    getSignContext(rs,cb){
        rs.pipe(s);
        rs.on('end', () => {
            cb({
                signature: s.sign(prKey).toString('hex'),
                publicKey: pubKey.toString('hex')
            });
        });
    };
}

///////////////////////////////////////////////////////////////////
let v;

class ClientVerifyElgam{
    constructor(){
        v = crypto.createVerify('SHA256')
    }

    async verify(signContext, rs) {
        v.write(rs);
        v.end();
        // signContext.signature = "MEYCIQCPfWhpzxMqu3gZWflBm5V0aetgb2/S+SGyGcElaOjgdgIhALaD4lbxVwa8HUUBFOLz+CGvIioDkf9oihSnXHCqh8yV";
        return await v.verify(signContext.publicKey, signContext.signature, 'hex')
    };
}


module.exports.ServerSignElgam = ServerSignElgam;
module.exports.ClientVerifyElgam = ClientVerifyElgam;
