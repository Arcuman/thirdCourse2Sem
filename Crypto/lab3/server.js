const readline = require('readline');

const CalculateNOD = (x, y) => {
    while (x !== 0 && y !== 0) {
        if (x > y)
            x -= +y;
        else
            y -= +x;
    }
    return Math.max(x, y);
}

const IsSimple = (x) => {
    if (x === 1)
        return true;
    for (let i = 2; i * i <= x; i++)
        if (x % i === 0)
            return false;
    return true;
}

const SimpleInInterval = (m, n) => {
    let counter = 0;
    if (n < m) {
        console.log('Incorrect value');
        return;
    }
    console.log(`Simple numbers on interval [${m},${n}]:`);
    for (let i = m; i <= n; i++) {
        if (IsSimple(i)) {
            console.log(i);
            counter++;
        }
    }
    console.log(`Count of simple numbers is ${counter}`);
    //console.log(`n/ln(n) ${n/Math.log(n)}`);
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
}

//console.log(CalculateNOD(CalculateNOD(6, 10), 16));
//SimpleInInterval(450,503);
//simpleNumbers(450);
//console.log(CalculateNOD(450, 503));
console.log('Enter number');
console.log('1-node 450 and 503, 2- simpleIn interval 450-503, 3-simple numbers of 450 4-custom NOD');
process.stdin.on('data', function (data) {
    const input = data.toString('utf8').slice(0, -2);
    switch (+input) {
        case 1:
            console.log(CalculateNOD(450, 503));
            break;
        case 2:
            SimpleInInterval(450, 503);
            break;
        case 3:
            simpleNumbers(450);
            break;
        default:
            console.log('default');
            break;
    }
    console.log('Enter number');
    console.log('1-node 450 and 503, 2- simpleIn interval 450-503, 3-simple numbers of 450 4-custom NOD');
});
//

