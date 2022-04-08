# Prompt

`prompt` in JavaScript used to get user input from browser.

```javascript
const age = prompt("How old are you?");
console.log(age);
```

![result](https://cdn-images-1.medium.com/max/1000/1*71knOasUxKedsaMCIUhzqw.png)

Eventhough we put *console.log* at line 2, there is no output on Console until we put value in prompt.

After we type something into the blank, we can get console.

![](https://cdn-images-1.medium.com/max/1000/1*_fTTjarWtUq9aUHyBrZIxg.png)



![console.log](https://cdn-images-1.medium.com/max/1000/1*nlCLbOX6FUpEFqgbu9dYqQ.png)





# `parseInt()`

`parseInt()` is a function which change string variable into int type variable.

```javascript
const age = prompt("How old are you?");
console.log(typeof age);
```

![](https://cdn-images-1.medium.com/max/1000/1*0fZuAeT6wgke4A1BCa2V6Q.png)

For this code, the output is "string". Which means we can't use the variable `age` as Integer.

In order to change the type of variable into Int, we have to use the function called `parseInt()`.

`parseInt()` retruns the argument with type of `number`. 

```javascript
const age = parseInt(prompt("How old are you?"));
console.log(typeof age);
```

![](https://cdn-images-1.medium.com/max/1000/1*IzPi11ZSHTFMms9mY3DePw.png)

(If we put some string that doesn't look like a number, `parseInt()` returns NaN)

```javascript
console.log(parseInt("AAA"));
```

![](https://cdn-images-1.medium.com/max/1000/1*rujrrs3udOa4mSLpCU_GZA.png)