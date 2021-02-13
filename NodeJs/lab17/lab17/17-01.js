const redis = require('redis');

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
})
.on('end', () => {
    console.log('end');
});


client.quit();