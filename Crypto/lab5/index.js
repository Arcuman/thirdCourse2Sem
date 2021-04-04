const express = require('express')
const bodyParser = require('body-parser');
const app = express()
const port = 3000
const belAlphabet = "абвгдеёжзійклмнопрстуўфхцчшыьэяю’";

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));

app.get('/', (req, res) => {
    res.sendFile(__dirname + "/index.html")
})

const encryptRoute = (text, rows, cols, res) => {
    const n = text.length;
    if (n <= rows * cols) {
        const matrix = [];
        for (let i = 0, k = 0; i < rows; i++) {
            const row = []
            for (let j = 0; j < cols; j++, k++) {
                row.push(text[k] ?? ' ')
            }
            matrix.push(row);
        }
        let encryptString = "";
        for (let i = cols - 1; i >= 0; i--) {
            for (let j = 0; j < rows; j++) {
                encryptString += matrix[j][i];
            }
        }
        res.send(`Decode string : ${text} \n 
                Encrypt string : ${encryptString} \n`)
    } else {
        res.send("Input correct value of rows and columns")
    }
}

const decryptRoute = (text, rows, cols, res) => {
    const n = text.length;
    if (n === rows * cols) {
        const matrix = [];
        for (let i = 0; i < rows; i++) {
            const row = []
            for (let j = 0; j < cols; j++) {
                row.unshift(text[i + j * rows])
            }
            matrix.push(row);
        }
        const decryptString = matrix.flat().join("");
        res.send(`Encrypt string : ${text} \n 
                Decrypt string : ${decryptString} \n`)
    } else {
        res.send("Input correct value of rows and columns")
    }
}

const createMatrix = (n, m) => {
    let matrix = new Array(n);
    for (let i = 0; i < matrix.length; i++) {
        matrix[i] = new Array(m);
    }
    return matrix;
}

const enctyptRoute2 = (lastName, firstName, text, res) => {
    const n = text.length;
    if (n > lastName.length * firstName.length)
        res.send("Invalid input n>row*col");
    const key1 = lastName.toLowerCase().split("");
    const key2 = firstName.toLowerCase().split("");
    const rows = key1.length;
    const cols = key2.length;
    let matrix = [];
    let rowMatrix = createMatrix(key1.length, key2.length);
    let encMatrix = createMatrix(key1.length, key2.length);

    for (let i = 0, k = 0; i < rows; i++) {
        const row = []
        for (let j = 0; j < cols; j++, k++) {
            row.push(text[k] ?? ' ')
        }
        matrix.push(row);
    }
    console.log(matrix)
    const newKey1 = key1.slice().sort();
    const newKey2 = key2.slice().sort();
    console.log(key1);
    console.log(newKey1);
    let map = new Map();
    key1.forEach(symbol => {
        map.set(symbol, 1)
    })
    console.log(map);
    for (let i = 0; i < newKey1.length; i++) {
        for (let j = 0, k = 1; j < key1.length; j++) {
            if (newKey1[i] === key1[j]) {
                const time = map.get(key1[j])
                if (k === time) {
                    rowMatrix[i] = matrix[j];
                    map.set(key1[j], (map.get(key1[j]) + 1));
                    break;
                } else {
                    k++
                }
            }
        }
    }
    console.log(rowMatrix);
    map = new Map();
    key2.forEach(symbol => {
        map.set(symbol, 1)
    })
    console.log('KEY2')
    console.log(key2);
    console.log(newKey2);
    console.log(map);
    for (let i = 0; i < newKey2.length; i++) {
        for (let j = 0, k = 1; j < key2.length; j++) {
            if (newKey2[i] === key2[j]) {
                const time = map.get(key2[j])
                if (k === time) {
                    map.set(key2[j], (map.get(key2[j]) + 1));
                    for (let o = 0; o < rows; o++)
                        encMatrix[o][i] = rowMatrix[o][j];
                    console.log(encMatrix);
                } else {
                    k++;
                }
            }
        }
    }
    console.log(encMatrix);
    res.send(encMatrix);
}

const denctyptRoute2 = (lastName, firstName, text, res) => {
    const n = text.length;
    if (n > lastName.length * firstName.length)
        res.send("Invalid input n>row*col");
    let key1 = lastName.toLowerCase().split("");
    let key2 = firstName.toLowerCase().split("");
    const rows = key1.length;
    const cols = key2.length;
    let matrix = [];
    let rowMatrix = createMatrix(key1.length, key2.length);
    let encMatrix = createMatrix(key1.length, key2.length);

    for (let i = 0, k = 0; i < rows; i++) {
        const row = []
        for (let j = 0; j < cols; j++, k++) {
            row.push(text[k] ?? ' ')
        }
        matrix.push(row);
    }
    console.log(matrix)
    let newKey1 = key1.slice().sort();
    let newKey2 = key2.slice().sort();
    [newKey1, key1] = [key1, newKey1];
    [newKey2, key2] = [key2, newKey2];
    console.log(key1);
    console.log(newKey1);
    let map = new Map();
    key1.forEach(symbol => {
        map.set(symbol, 1)
    })
    console.log(map);
    for (let i = 0; i < newKey1.length; i++) {
        for (let j = 0, k = 1; j < key1.length; j++) {
            if (newKey1[i] === key1[j]) {
                const time = map.get(key1[j])
                if (k === time) {
                    rowMatrix[i] = matrix[j];
                    map.set(key1[j], (map.get(key1[j]) + 1));
                    break;
                } else {
                    k++
                }
            }
        }
    }
    console.log(rowMatrix);
    map = new Map();
    key2.forEach(symbol => {
        map.set(symbol, 1)
    })
    console.log('KEY2')
    console.log(key2);
    console.log(newKey2);
    console.log(map);
    for (let i = 0; i < newKey2.length; i++) {
        for (let j = 0, k = 1; j < key2.length; j++) {
            if (newKey2[i] === key2[j]) {
                const time = map.get(key2[j])
                if (k === time) {
                    map.set(key2[j], (map.get(key2[j]) + 1));
                    for (let o = 0; o < rows; o++)
                        encMatrix[o][i] = rowMatrix[o][j];
                    console.log(encMatrix);
                } else {
                    k++;
                }
            }
        }
    }
    console.log(encMatrix);
    res.send(encMatrix);
}

app.post('/encrypt', (req, res) => {
    encryptRoute(req.body.text, req.body.rows, req.body.cols, res);
})

app.post('/decrypt', (req, res) => {
    decryptRoute(req.body.text, req.body.rows, req.body.cols, res);
})

app.post('/encrypt2', (req, res) => {
    enctyptRoute2(req.body.lastName, req.body.firstName, req.body.text, res);
})
app.post('/dencrypt2', (req, res) => {
    denctyptRoute2(req.body.lastName, req.body.firstName, req.body.text, res);
})

app.listen(port, (err) => {
    console.log(err);
    console.log('start 3000')
})
