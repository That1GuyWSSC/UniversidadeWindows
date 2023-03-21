/* let firstName = "Joao";


/*  */

/* let name = "John"; //string
const year = "2000";
let age = 25; // number
let isStudent = true; //boolean

console.log(name);
console.log(year);
console.log(age);
console.log(isStudent);

console.log(typeof name);
console.log(typeof year);
console.log(typeof age);
console.log(typeof isStudent);

name ="Eva";
console.log(name);




let hobbies = ["reading","playing video games", "watching movies"]; */ 


/* let year;
console.log(year);
console.log(typeof year);
console.log(typeof null); */

/* function test(){
    let x = 10;
    var y = 20;
    if(true){
        let x = 5;
        var y = 50;
        console.log(x); //5
        console.log(y); //50
    }
    console.log(x); //10
    console.log(y); //50
}
test(); */

/* console.log(10==10); //comparacao true
console.log("hello" == "world"); // false
console.log(10=="10"); // true (type coercion)
console.log(10==="10"); // False

let result = 10+20 / 5;
console.log(result);

 */

/* const firstName = "John";
const job = "teacher";
const birthYear = 2000;
const year = 2023;


const john =
    "I'm " + firstName + ", a " + (year - birthYear) + " year old " + job + "!";

console.log(john);

//com template strings
const newJohn = `I'm ${firstName}, a ${year - birthYear} year old ${job}!`;
console.log(newJohn); */


/* function add1(x,y){
    return x+y;
}


let add2 = function(x,y){
    return x+y;
}

console.log(add1(3,6));

let add3 = (x,y) => x+y;

console.log(add3(80,89));
 */


/* const calAge1= function(birthYear){
    console.log(birthYear); 
    return 2023-birthYear;
}

console.log((calAge1(2000)));

const yearUntilRetirement = (birthYear) => {
    const age = 2023 - birthYear;
    const retirement = 65 - age;
    return retirement;

}
console.log(yearUntilRetirement(2002)); */

/* 
function cutFruitPieces(fruit){
    return fruit*4;
}

function fruitProcessor(apples , oranges){
    const applePieces = cutFruitPieces(apples);
    const orangesPieces = cutFruitPieces(oranges);
    const juice = `Juice with ${applePieces} apple pieces and ${orangesPieces} oranges pieces. `
    return juice;
}

console.log(fruitProcessor(4,5));
console.log(fruitProcessor(40,50));
console.log(fruitProcessor(1,1)); */
/* 
const me = ['Joao' , 'Diogo' , '20' , 'student',['nia','nio']];

console.log(me[4][1]);
 */


let me = {
    firstName:'Joao',
    lastName: 'Machado',
    age:20,
    birthYear: 2002,
    job:'student',
    pets : ['nia','nio'],
    hasDriverLicense: true,
    calAge : function(){
        return 2023-this.birthYear;
    }
}
console.log(me.calAge());


/* 
//console.log(me);
console.log(me.firstName);
console.log(me['firstName']);

const nameKey = 'Name';

console.log(me['last' + nameKey])

me.location = 'Braga'

console.log(me.location)
 */
//console.log(me['calAge'](2002))