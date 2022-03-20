// unnamed
let Rectangle = class {
    constructor(height, width) {
        this.height = height;
        this.width = width;
    }
};

console.log(Rectangle.name);
// output : "Rectangle"

// ---------------
// named
let Rectangle2 = class Rectangle_2 {
    constructor(height, width) {
        this.height = height;
        this.width = width;
    }
};
console.log(Rectangle2.name)
// output : Rectangle_2


// ----------------
// static
class Point {
    constructor(x, y) {
        this.x = x;
        this.y = y;
    }
    
    static displayName = "Point";

    static distance(a, b) {
        const dx = a.x - b.x;
        const dy = a.y - b.y;

        return Math.hypot(dx, dy);
    }
}

const p1 = new Point(5, 5);
const p2 = new Point(10, 10);

// static으로 정의했기 때문에 변수로는 사용 불가
console.log("p1.displayName : ", p1.displayName); // output : undefined
console.log("p1.distance : ", p1.distance); // output : undefined
console.log("p2.displayName : ", p2.displayName); // output : undefined
console.log("p2.distance : ", p2.distance); // output : undefined
// 하지만 class 자체로는 사용 가능
console.log("Point.displayName : ", Point.displayName); // output : undefined
console.log("Point.distance(p1, p2) : ", Point.distance(p1, p2)); // output : 7.0710678118654755

//---------------------------------------
class Animal {
    speak() {
        return this;
    }
    static eat() {
        return this;
    }
}

let obj = new Animal();
console.log(obj.speak()); // output : Animal {}
let speak = obj.speak;
console.log(speak()); // output : undefined

console.log(Animal.eat()); // output : [class Animal]
let eat = Animal.eat;
console.log(eat()); // output : undefined