const fs = require("fs");

const belAlphabet = "абвгдеёжзійклмнопрстуўфхцчшыьэяю’"
const N = belAlphabet.length;
const k = 5;
const string = fs.readFileSync("skazka.txt","utf8").toLowerCase();
console.time('encrypt')
let encryptString = string.split("")
    .map(symbol =>
    {
        const indexOfSymbol = belAlphabet.indexOf(symbol);
        if(indexOfSymbol !== -1) {
            return belAlphabet[(indexOfSymbol + k) % N]
        }
        return symbol;
    }).join("")
console.timeEnd('encrypt')
fs.writeFileSync("encryptText.txt", encryptString);
console.time('decrypt')
const decryptString = encryptString.split("")
    .map(symbol =>
    {
        const indexOfSymbol = belAlphabet.indexOf(symbol);
        if(indexOfSymbol !== -1) {
            return belAlphabet[(indexOfSymbol - k) >= 0 ? (indexOfSymbol - k) : N + (indexOfSymbol - k)];
        }
        return symbol;
    }).join("");
console.timeEnd('decrypt')
fs.writeFileSync("decryptText.txt", decryptString);

let result = [];
const key = "барысаў";
let keyIndex = 0;
const stringLength = string.length
console.time("VizineraEncrypt")
string.split("").forEach(symbol => {
    const indexOfSymbol = belAlphabet.indexOf(symbol);
    if(indexOfSymbol === -1){
        result.push(symbol);
        return;
    }
    const c = ( stringLength + belAlphabet.indexOf(symbol) + belAlphabet.indexOf(key[keyIndex])) % N;
    result.push(belAlphabet[c]);
    keyIndex++;
    if((keyIndex + 1) === key.length){
        keyIndex = 0;
    }
})
console.timeEnd("VizineraEncrypt")

fs.writeFileSync("encryptTextVizenera.txt", result.join(""));
const deResult = [];
keyIndex=0;
console.time("VizineraDecrypt")
result.forEach(symbol => {
    const indexOfSymbol = belAlphabet.indexOf(symbol);
    if(indexOfSymbol === -1){
        deResult.push(symbol);
        return;
    }
    const c = (stringLength + indexOfSymbol - belAlphabet.indexOf(key[keyIndex])) % N;
    deResult.push(belAlphabet[c]);
    keyIndex++;
    if((keyIndex + 1) === key.length){
        keyIndex = 0;
    }
})
console.timeEnd("VizineraDecrypt")

fs.writeFileSync("decryptTextVizenera.txt", deResult.join(""));


const newString = string.toString().toLowerCase().replace(/[^абвгдеёжзійклмнопрстуўфхцчшыьэяю’]/gi, '');
encryptString = encryptString.toString().toLowerCase().replace(/[^абвгдеёжзійклмнопрстуўфхцчшыьэяю’]/gi, '');
result = result.join("").toString().toLowerCase().replace(/[^абвгдеёжзійклмнопрстуўфхцчшыьэяю’]/gi, '');

let shanon = (str, alphabet) => {
    let H = 0;
    let checkMySelf = 0;
    for (let i = 0; i < alphabet.length; i++) {
        let symbol = alphabet.charAt(i),
            s = new RegExp(symbol, 'g'),
            p = (str.match(s) === null) ? 0 : str.match(s).length / str.length;
        console.log(`символ: '${symbol}', p(${symbol}) = ${p}`);
        if (p !== 0) {
            H += p * Math.log2(p);
        }
        checkMySelf += p;
    }
    console.log(`Сумма всех вероятностей: ${checkMySelf}`);
    return -H;
};

//console.log('Decode');
//const notEncrypted =  shanon(newString, belAlphabet);
//console.log('Mono');
//const monoCrypted =  shanon(encryptString, belAlphabet);
//console.log('Vizinera');
//const vizinira =  shanon(result, belAlphabet);
