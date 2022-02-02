const buttonContainer = document.querySelector(".button_container");
// let numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
const screen = document.querySelector(".screen");
let currentNumber = 0;

buttonContainer.addEventListener("click", buttonClicked);
// document.addEventListener("DOMContentLoaded", printNumber);

function printNumber() {
  screen.innerHTML = currentNumber;
}

function buttonClicked(e) {
  // e.preventDefault();
  let button = e.target;

  // console.log("button is : ", button.innerText);
//   console.log(parseInt(button.innerText));
//   console.log(button);

  if (button.classList.contains("number")) {
    console.log("it's a number!");
    numberClicked(parseInt(button.innerText));
  } else {
    console.log("it's not a number!");
  }
}

function numberClicked(number) {
  currentNumber = number;
  printNumber();
}
