const fs = require('fs');

let firstTask = fs.readFileSync('./text1.txt');
let firstTaskEnglish = fs.readFileSync('./text2.txt');
let secondTask = fs.readFileSync('./text3.txt');

const alfabhetRussian = 'абвгдеёжзийклмнопрстуфхцчшщъыьэюя';
const alfabhetEnglish = 'abcdefghijklmnopqrstuvwxyz';
const alfabhetBinary = '01';

firstTask = firstTask.toString().toLowerCase().replace(/[^А-Яа-яЁё]/gi, '');
firstTaskEnglish = firstTaskEnglish.toString().toLowerCase().replace(/[^a-zA-Z]/gi, '');
secondTask = secondTask.toString().toLowerCase().replace(/[^01]/gi, '');

console.log(secondTask);

let hartley = n => Math.log2(n);

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

console.log(`-----------------Задание 1---------------`);
console.log(`Длина русского текста = ${firstTask.length}`);
const HShanonRu =  shanon(firstTask, alfabhetRussian);
console.log(`Энтропия по Шеннону -russian-: ${HShanonRu}`);
const HHartleyRu =  hartley(alfabhetRussian.length);
console.log(`Энтропия по Хартли -russian-: ${HHartleyRu}`);
console.log(`Длина английского текста = ${firstTaskEnglish.length}`);
console.log(`Энтропия по Шеннону -english-: ${shanon(firstTaskEnglish, alfabhetEnglish)}`);
console.log(`Энтропия по Хартли -english-: ${hartley(alfabhetEnglish.length)}`);

console.log(`-----------------Задание 2---------------`);
console.log(`Длина бинарного текста = ${secondTask.length}`);
const HBinary = shanon(secondTask.toString(), alfabhetBinary);
console.log('Энтропия бинарного алфавита:', HBinary);

let countOfInformation = (name, H) => name.length * H;

const str = 'Борисов Антон Андреевич';
const str1 = str.toLowerCase().replace(/[^А-Яа-яЁё]/gi, '');

console.log(`-----------------Задание 3---------------`);
console.log(`Количество информации(по Шеннону): ${countOfInformation(str1, HShanonRu)}`);
console.log(`Количество информации(по Хартли): ${countOfInformation(str1, HHartleyRu)}`);

const ruNameASCII = str1.split('').map((letter) =>
    (letter.charCodeAt() - 848).toString(2)).join('');
console.log(`Количество информации(в кодах ASCII): ${countOfInformation(ruNameASCII, HBinary)}`);

let lastTask = (p)  => {
    const q = 1 - p;
    const h = (- p * Math.log2(p) - q * Math.log2(q));
    return (h);
};

console.log(`-----------------Задание 4---------------`);
console.log("ФИО при 0,1", ( HShanonRu - lastTask(0.1 )) * str1.length);
console.log("ФИО при 0,5", ( HShanonRu - lastTask(0.5 )) * str1.length);
console.log("ФИО при 1",   ( HShanonRu - lastTask(1.0 )) * str1.length);
