const redis = require('redis');
function Set(client, count) {
    let time = Date.now();
    for (var i = 0; i < count; i++) {
        client.set(`s${i}`, i, (err) => {
            if (err) console.log('Error msg: ' + err);
        });
    }
    console.log(`Task 3: Time for SET:  ${count} ---- ${Date.now() - time} ms`);
}

function Del(client, count) {
    let time = Date.now();
    for (let i = 0; i < count; i++) {
        client.del(`s${i}`, (err) => {
            if (err) console.log('Error msg: ' + err);
        })
    }
    console.log(`Task 3: Time for DEL:  ${count} ---- ${Date.now() - time} ms`);
}

function Incr(client, count) {
    let time = Date.now();
    for (let i = 0; i < count; i++) {
        client.incr(`s${i}`, (err) => {
            if (err) console.log('error msg: ' + err);
        });
    }
    console.log(`Task 3: Time for Incr: ${count} ---- ${Date.now() - time} ms`);
}

function Decr(client, count) {
    let time = Date.now();
    for (let i = 0; i < count; i++) {
        client.decr(`s${i}`, (err) => {
            if (err) console.log('error msg: ' + err);
        });
    }
    console.log(`Task 3: Time for Decr: ${count} ---- ${Date.now() - time} ms`);
}


const client = redis.createClient();

client
    .on('ready', () => {
        console.log('Client is ready');
    })
    .on('error', (err) => {
        console.log('Error: ' + err);
    })
    .on('connect', () => {
        console.log('Connect ');

        Promise.resolve()
            .then(() => Set(client, 10000))
            .then(() => Incr(client, 10000))
            .then(() => Decr(client, 10000))
            .then(() => Del(client, 10000));
    })
    .on('end', () => {
        console.log('end');
    });


setTimeout(() => {
    client.quit()
}, 1000);
//client.quit();