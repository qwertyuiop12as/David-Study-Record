function func(a, b) {
    return a + b + 100;
}

// console.log(func(1, 2));

// remove the word "function" and place arrow ( => ) between the argument and opening body bracket

let arrow_func = (a, b) => a + b + 100;
// console.log(arrow_func(1, 2));

// --------------------------------------------------

// arrow function with no argument
let a = 4;
let b = 2;
let arrow_func2 = () => a + b + 100;
//console.log(arrow_func2());