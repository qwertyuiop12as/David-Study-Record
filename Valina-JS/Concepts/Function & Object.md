# Function & Object

```javascript
console.log("Hello My name is A");
console.log("Hello My name is B");
console.log("Hello My name is C");
console.log("Hello My name is D");
console.log("Hello My name is E");
```

The code above is repeating *same thing*. The only difference between each line is the ***Character*** at the end of the string(sentence).

```javascript
function sayHello() {
    console.log("Hello my name is A");
}

sayHello(); // output : Hello my name is A
```

Let's say there is a function like this.

The output of this code might be "Hello my name is A".

If we can replace that A with other characters, we can get the same output with the first code.



### Arguments

```javascript
function sayHello(nameOfPerson) {
	console.log("Hello my name is" + nameOfPerson);
}

sayHello("A");
sayHello("B");
sayHello("C");
sayHello("D");
sayHello("E");
```

We can send something called ***argument(s)*** to functions.

Arguments works similar with the variables in the regular code, but it is different for each function.

As a result, the argument `nameOfPerson` has changed every single time we call the function.

```javascript
function sayHello(nameOfPerson, age) {
	console.log("Hello my name is", nameOfPerson, "and I'm", age, "years old.");
}

sayHello("A", 10);
sayHello("B", 15);
sayHello("C", 19);
sayHello("D", 17);
sayHello("E", 23);
```

We can put more than one arguments for function.

This time, the function has two arguments : `nameOfPerson` and `age`.



```javascript
function plus(a, b) {
    console.log(a, b);
}

plus();
```

output : undefined undefined

In this code, we mentioned that we are going to get two arguments when we call the function. 

However, we left it empty(didn't give any value for `a` and `b`). 

As a result, `a` and `b` are set as ***undefined***.



Also, we can't use arguments outside of the function.

Let's see the code below.

```javascript
function func(num1, num2) {
    console.log("First num is" + num1, ". Second num is" + num2);
}

func(1, 2);
console.log(num1);
```

If we run the code, we will get error like this.

![Error](https://cdn-images-1.medium.com/max/1000/1*ahMwQLJRb-spidBQOgF_dA.png)

***num1 is not defined.***

Even though there is `num1` for `func`, we can't use it outside of the function.

As a result, the code made an error.



##### Functions in Object

```javascript
player = {
    name : "jaewook",
    printName : function (personName) {
        console.log(`Hi my name is ${personName}`);
    }
}

player.printName(player.name);
```

we can define a function in a object and use it.

we use the function with code like below.

<p style="color:red; font-weight:bold">(object name).(key for function(argument(s));</p>



##### Add new Key & Value for Object

```javascript
player = {
    name : "jaewook",
    printName : function (personName) {
        console.log(`Hi my name is ${personName}`);
    }
}

player.lastName = "Cho";
console.log(player["lastName"]);
```

we can add new key & value for object with the code below

<p style="color:red; font-weight:bold">(object name).(new key) = (new value);</p>



### Calculator

```javascript
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
```

- Make each function with corresponding key



### Return

However, the results of the code above disappear when the functions end(the value 12 is gone when calculator.add(5, 7) is over).

to save the value 12, we should use something called `return`.

```javascript
function add(num1, num2) {
    return num1 + num2;
}

const result = add(5, 7);
console.log(result); // 12
```

We can see that the result of 5 + 7 is saved in const `result`.

As a result, we can use value 12 outside of the function.

Let's say we want to save the result of each calculation of calculator function(**Calculator** section)

```javascript
calculator = {
    add : function (num1, num2) {
        return (num1 + num2);
    },
    subtract : function (num1, num2) {
        return (num1 - num2);
    },
    multiply : function (num1, num2) {
        return (num1 * num2);
    },
    divide : function (num1, num2) {
        return (num1 / num2);
    },
    powerof : function (num1, num2) {
        return (num1 ** num2);
    }
}

const addResult = calculator.add(5, 7);       // 12
const subtractResult = calculator.subtract(8, 3);  // 5
const multiplyResult = calculator.multiply(2, 4);  // 8
const divideResult = calculator.divide(9, 3);    // 3
const powerofResult = calculator.powerof(2, 4);    // 16

console.log(addResult);
console.log(subtractResult);
console.log(multiplyResult);
console.log(divideResult);
console.log(powerofResult);
```

we should have code like this.

each Result values will save the result of calculations.

```javascript
function sayHi() {
    console.log("Hi");
    return;
    console.log("Hello");
}

sayHi();
```

Once we return the function, it will quit the function.

As a result, the code above only prints "Hi".