
const redis = require('redis');
function HSet(client, count) {
    let time = Date.now();
    for (var i = 0; i < count; i++) {
        let param = `s${i}`;
        client.hset('hash', `${param}`, `${param}`, (err) => {
            if (err) console.log('Error msg: ' + err);
        });
    }
    console.log(`Task 4: Time for SET: ${count} ---- ${Date.now() - time} ms`);
}

function HGet(client, count) {
    let time = Date.now();
    for (var i = 0; i < count; i++) {
        let param = `s${i}`;
        client.hget('hash', param, (err, result) => {
            if (err) console.log('Error msg: ' + err);
            //console.log( `Result ${param} =` + result);
        })
    }
    console.log(`Task 4: Time for GET: ${count} ---- ${Date.now() - time} ms`);
}

function HDel(client, count) {
    let time = Date.now();
    for (var i = 0; i < count; i++) {
        let param = `s${i}`;
        client.hdel('hash', param, (err) => {
            if (err) console.log('Error msg: ' + err);
        })
    }
    console.log(`Task 2: Time for DEL: ${count} ---- ${Date.now() - time} ms`);
}


const client = redis.createClient();

client
    .on('ready', () => {
        console.log('Client is ready');

    })
    .on('error', (err) => {
        console.log('Error: ' + err);
    })
    .on('end', () => {
        console.log('end');
    })
    .on('connect', () => {
        console.log('Connect ');
        Promise.resolve()
            .then(() => HSet(client, 10000))
            .then(() => HGet(client, 10000))
            .then(() => HDel(client, 10000));

    });


setTimeout(() => {
    client.quit();
}, 1000)
//client.quit();