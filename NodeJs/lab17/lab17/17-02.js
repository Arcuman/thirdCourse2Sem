const redis = require('redis');

function Set(client, count) {
    let time = Date.now();
    for (let i = 0; i < count; i++) {
        let param = `s${i}`;
        client.set(`${param}`, `${param}`, (err) => {
            if (err) console.log('Error msg: ' + err);
        });
    }
    console.log(`Task 2: Time for SET: ${count} ---- ${Date.now() - time} ms`);
}

function Get(client, count) {
    let time = Date.now();
    for (let i = 0; i < count; i++) {
        let param = `s${i}`;
        client.get(param, (err, result) => {
            if (err)
                console.log('Error msg: ' + err);
            if (i % 100 === 0)
                console.log(`Result ${param} =` + result);
        })
    }
    console.log(`Task 2: Time for GET: ${count} ---- ${Date.now() - time} ms`);
}

function Del(client, count) {
    let time = Date.now();
    for (let i = 0; i < count; i++) {
        let param = `s${i}`;
        client.del(param, (err) => {
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
            .then(() => Set(client, 10000))
            .then(() => Get(client, 10000))
            .then(() => Del(client, 10000));

    });

setTimeout(() => {
    client.quit();
}, 1000)