# const & let

<b>`Const`</b> 로 선언한 변수는 값 수정이 불가

```javascript
const gender = "Male";
let age = 16;
let name = "David Cho";

console.log("My Info : " + gender, age, name);

age = 30;
name = "Jaewook Cho";

console.log("My Info : " + gender, age, name);
```

위의 코드의 경우 <b>`const`</b>로 선언한 gender는 바꿀 수 없지만 <b>`let`</b>으로 선언한 age, name은 바꿀 수 있다.

(만약 위의 코드에 gender = "Female"을 입력한다면 에러가 발생)

![error](https://cdn-images-1.medium.com/max/1000/1*w8WDH1oQ7rSaavknaqH4iw.png)



### **Conclusion**

- The variables declared with `const` can't be modified(**can not be changed**)

- The variables declared with `let` can't be modified(**can be changed**) 
- We use `const` when we have to declare a variable which we will use the same value forever