calculator = {
  add: function (num1, num2) {
    return num1 + num2;
  },
  subtract: function (num1, num2) {
    return num1 - num2;
  },
  multiply: function (num1, num2) {
    return num1 * num2;
  },
  divide: function (num1, num2) {
    return num1 / num2;
  },
  powerof: function (num1, num2) {
    return num1 ** num2;
  },
};

const addResult = calculator.add(5, 7); // 12
const subtractResult = calculator.subtract(8, 3); // 5
const multiplyResult = calculator.multiply(2, 4); // 8
const divideResult = calculator.divide(9, 3); // 3
const powerofResult = calculator.powerof(2, 4); // 16

console.log(addResult);
console.log(subtractResult);
console.log(multiplyResult);
console.log(divideResult);
console.log(powerofResult);
