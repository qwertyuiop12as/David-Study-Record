calculator = {
    add : function (num1, num2) {
        console.log(num1 + num2);
    },
    subtract : function (num1, num2) {
        console.log(num1 - num2);
    },
    multiply : function (num1, num2) {
        console.log(num1 * num2);
    },
    divide : function (num1, num2) {
        console.log(num1 / num2);
    },
    powerof : function (num1, num2) {
        console.log(num1 ** num2);
    }
}

calculator.add(5, 7);       // 12
calculator.subtract(8, 3);  // 5
calculator.multiply(2, 4);  // 8
calculator.divide(9, 3);    // 3
calculator.powerof(2, 4);    // 16