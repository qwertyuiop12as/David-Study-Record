class Animal {
    constructor(name) {
        this.name = name;
    }

    speak() {
        console.log(`${this.name} makes a noise.`);
    }
}

// "class Child-class extrnds Parent-class" 
class Dog extends Animal {
    constructor(name) {
        super(name); // call the super constructor and pass in the name parameter
        // Parent class(Animal)'s consturctor로 pass 됨
    }

    speak() {
        console.log(`${this.name} barks.`);
    }
}

let d = new Dog('Mitzie');
d.speak(); // Mitzie barks.
// if there wasn't speak function in Dog class, it will use Animal's function
// --> Mitizie makes a noise.