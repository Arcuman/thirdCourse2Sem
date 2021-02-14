const fs = require('fs');

let firstTask = fs.readFileSync('./text1.txt');
let firstTaskEnglish = fs.readFileSync('./text2.txt');
let secondTask = fs.readFileSync('./text3.txt');
const thirdTask = fs.readFileSync('./text5.txt');

const alfabhetRussian = 'абвгдеёжзийклмнопрстуфхцчшщъыьэюя';
const alfabhetEnglish = 'abcdefghijklmnopqrstuvwxyz';
const alfabhetName = 'борисвантден';
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
console.log(`Энтропия по Шеннону -russian-: ${shanon(firstTask, alfabhetRussian)}`);
console.log(`Энтропия по Хартли -russian-: ${hartley(alfabhetRussian.length)}`);
console.log(`Длина английского текста = ${firstTaskEnglish.length}`);
console.log(`Энтропия по Шеннону -english-: ${shanon(firstTaskEnglish, alfabhetEnglish)}`);
console.log(`Энтропия по Хартли -english-: ${hartley(alfabhetEnglish.length)}`);

console.log(`-----------------Задание 2---------------`);
console.log(`Длина бинарного текста = ${secondTask.length}`);
console.log('Энтропия бинарного алфавита:', shanon(secondTask.toString(), alfabhetBinary));

let shanonByName = (name, alfabhet) => name.length * shanon(name, alfabhet);
let hartleyByName = (name, alfabhet) => name.length * hartley(alfabhet.length);

const str = 'Борисов Антон Андреевич';
const str1 = str.toLowerCase().replace(regExpSimbols, '');


console.log(`-----------------Задание 3---------------`);
console.log(`Количество информации(по Шеннону): ${shanonByName(str1, alfabhetName)}`);
console.log(`Количество информации(по Хартли): ${hartleyByName(str1, alfabhetName)}`);
console.log(`Количество информации(в бинарном виде): ${shanonByName(thirdTask.toString(), alfabhetBinary)}`);
