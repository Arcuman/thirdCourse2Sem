const express = require('express')
const app = express()
const port = 3000

const CalculateNOD = (x, y) => {
    while (x !== 0 && y !== 0) {
        if (x > y)
            x = x % y;
        else
            y = y % x;
    }
    return Math.max(x, y);
}

const IsSimple = (x) => {
    if (x === 1)
        return true;
    for (let i = 2; i <= Math.floor(Math.sqrt(x)); i++)
        if (x % i === 0)
            return false;
    return true;
}

const SimpleInInterval = (m, n) => {
    let counter = 0;
    const simpleArrays = [];
    if (n < m) {
        console.log('Incorrect value');
        return;
    }
    console.log(`Simple numbers on interval [${m},${n}]:`);
    for (let i = m; i <= n; i++) {
        if (IsSimple(i)) {
            console.log(i);
            simpleArrays.push(i);
            counter++;
        }
    }
    console.log(`Count of simple numbers is ${counter}`);
    console.log(`n/ln(n) ${n/Math.log(n)}`);
    return ` ${counter} числа = ${simpleArrays.map(i=> ` ${i} `)} \n n\\ln(n) = ${n/Math.log(n)}`;
}

const simpleNumbers = a => {
    let b = 2;
    let rez = "";
    while (a > 1) {
        if (a % b === 0) {
            rez += b + "*";
            a /= b;
            b = 2;
        } else
            b++;
    }
    console.log(rez.slice(0, -1));
    return rez.slice(0,-1);
}

app.get('/', (req, res) => {
    res.sendFile(__dirname + '/index.html');
})

app.get('/primeCount', (req, res) => {
    console.log('primeCount')
    res.json(SimpleInInterval(+req.query.start, +req.query.finish))
})

app.get('/two', (req, res) => {
    console.log('two');
    console.log(req.query.first)
    res.send(CalculateNOD(+req.query.first, +req.query.second).toString())
})

app.get('/three', (req, res) => {
    console.log('three');
    res.send(CalculateNOD(CalculateNOD(+req.query.first, +req.query.second),+req.query.third).toString());
})
app.get('/simple', (req, res) => {
    res.json(simpleNumbers(+req.query.first));
})

app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`)
})
