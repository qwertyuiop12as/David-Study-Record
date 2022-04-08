# Conditional

`if` is a function which determines weather the statement in parenthesis / ( ) is true or false.

```javascript
if (statement) {
	// code here will runs when the statement is true.
} else {
	// code here will runs when the statement is false.
}
```



`isNaN()` is a function which performs action below

- If argument is a number, return **false**.
- If argument is <span style="color: red">not</span> a number, return **true**.



```javascript
const age = parseInt(prompt("How old are you?"));

if(isNaN(age)) {
    console.log("Please write a number!");
}
```

If we input something that is not a number (which will make `isNaN` returns true and run the code inside `if` statement)...

![](https://cdn-images-1.medium.com/max/1000/1*TXIsrk_hVi5NsS4KGXpwZw.png)

Console will say *"Please write a number!"*

![](https://cdn-images-1.medium.com/max/1000/1*5zRkius4B8w5LQzvRkqn1w.png)



```javascript
const age = parseInt(prompt("How old are you?"));

if(isNaN(age)) {
    console.log("Please write a number!");
} else {
    console.log(`You are ${age} years old.`);
}
```

If we add the code for `else` part and input a number (where input is not NaN)...



![](https://cdn-images-1.medium.com/max/1000/1*X5fE-J6sUvB1bo2kSTj2Bw.png)

We can get proper output when we put a number.
