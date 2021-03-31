const rotors = [
    ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
        's', 't', 'u', 'v', 'w', 'x', 'y', 'z'],
    ['e', 'k', 'm', 'f', 'l', 'g', 'd', 'q', 'v',
        'z', 'n', 't', 'o', 'w', 'y', 'h', 'x', 'u',
        's', 'p', 'a', 'i', 'b', 'r', 'c', 'j'],
    ['a', 'j', 'd', 'k', 's', 'i', 'r', 'u', 'x',
        'b', 'l', 'h', 'w', 't', 'm', 'c', 'q', 'g',
        'z', 'n', 'p', 'y', 'f', 'v', 'o', 'e'],
    ['b', 'd', 'f', 'h', 'j', 'l', 'c', 'p', 'r',
        't', 'x', 'v', 'z', 'n', 'y', 'e', 'i', 'w',
        'g', 'a', 'k', 'm', 'u', 's', 'q', 'o']
];

const reflector = {
    'a': 'y', 'b': 'r', 'c': 'u', 'd': 'h',
    'e': 'q', 'f': 's', 'g': 'l', 'i': 'p',
    'j': 'x', 'k': 'n', 'm': 'o', 't': 'z', 'v': 'w'
};
const rotorShifts = [0, 2, 2];
const firstLettersRotor = ['a', rotors[1][0] , rotors[2][0] , rotors[3][0]];
let rotor = []

function setDefaultRotors(){
    rotor = []
    const rotor1 = document.querySelector('#router1').value;
    const rotor2 = document.querySelector('#router2').value;
    const rotor3 = document.querySelector('#router3').value;
    rotor.push(rotors[0]);
    rotor.push(rotors[rotor1].slice());
    rotor.push(rotors[rotor2].slice());
    rotor.push(rotors[rotor3].slice());
}


setDefaultRotors();

function shiftRotor(n, shCount) {
    console.log('shift')
    temp = [];
    for(let i =0; i < shCount; i++){
        console.log('rotor number:'+ n +' letter ' + rotor[n][i+1] + " fletter " + firstLettersRotor[n]);
        if(rotor[n][i+1] === firstLettersRotor[n] && n > 1) {
            console.log('here');
            shiftRotor(n - 1, 1);
        }
    }
    for (let i = 0; i < rotor[n].length; i++) {
        temp[i] = (i + shCount >= rotor[n].length) ?
            rotor[n][(i + shCount) % rotor[n].length] : rotor[n][i + shCount];
    }
    for (let i = 0; i < rotor[n].length; i++) {
        rotor[n][i] = temp[i];
    }
}

function Enigma() {
    const key = document.getElementById("inputText").value.toLowerCase();
    console.log(key)
    const result = document.querySelector('#result');
    console.log('Enigma');
    let keySH = key.split("");
    for (let k = 0; k < key.length; k++) {
        for (let n = rotor.length - 1; n > 0; n--) {
            keySH[k] = rotor[n][rotor[0].indexOf(keySH[k])];
        }
        for (e in reflector) {
            if (keySH[k] === reflector[e]) {
                keySH[k] = e;
            } else if (keySH[k] === e) {
                keySH[k] = reflector[e];
            }
        }
        for (let n = 1; n < rotor.length; n++) {
            keySH[k] = rotor[0][rotor[n].indexOf(keySH[k])];
        }
        for (let i = rotor.length - 1; i > 1; i--) {
            shiftRotor(i, rotorShifts[i - 1]);
        }
    }
    console.log('keySH: ' + keySH.join(''));
    console.log('key: ' + key);
    result.innerHTML = keySH.join("");
}
