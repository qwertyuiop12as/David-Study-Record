// Private
class Rectangle {
    #height = 0;
    #width;
    constructor(height, width) {
      this.#height = height;
      this.#width = width;
    }
  }
  

let val = new Rectangle(1, 2);
console.log(val.height);
