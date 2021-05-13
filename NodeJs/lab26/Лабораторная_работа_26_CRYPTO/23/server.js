const {ServerDH, ClientDH} = require('./23-01m');
const {cipherFile, decipherFile} = require('./cryptoPipe');
const fs= require('fs')
const  serverDH = new ServerDH(128, 2);

const  serverContext = serverDH.getContext();
console.log('serverContext =', serverContext);




//client
const  clientDH = new ClientDH(serverContext);
const  clientSecret = clientDH.getSecret(serverContext);
const clientContext = clientDH.getContext();
console.log('clientContext =', clientContext);

const  serverSecret = serverDH.getSecret(clientContext);

console.log(' sSecret =', serverSecret.toString('hex'));
console.log('clSecret =', clientSecret.toString('hex'));
function qq() {
    cipherFile('vadim');
    decipherFile('vadim');
}
qq()