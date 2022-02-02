function GetRandomInt() {
    var randomNum = Math.random();
    var randomInt = Math.floor(randomNum * 6) + 1;

    return randomInt;
}

function NumberDifference(num1, num2) {
    if (num1 > num2)
        return num1 - num2;
    else
        return num2 - num1;
}

function InputPlayAgain() {
    var inputChar = window.prompt("Would You like to Play again? (Y or N)")[0].toUpperCase();
    return inputChar;
}

var point = 0;
var isGame = true;

while (isGame == true) {
    alert("Current Score : " + point);

    var inputNum = window.prompt("Enter a number (1 ~ 6): ");

    randomInt = GetRandomInt();
    alert("Random Number : " + randomInt + "\nYour Number : " + inputNum);

    if (randomInt == inputNum) {
        alert("Two Numbers are same at " + inputNum + ". (2 points)");
        point += 2;
    } else if (NumberDifference(inputNum, randomInt) == 1) {
        alert("Your Number is different than the Random Number by 1. (1 point)");
        point += 1;
    } else {
        alert("Numbers are too different! (0 point)");
    }

    isGame = InputPlayAgain() === "Y";
    // alert("isGame : " + isGame);
}

alert("Done!");
alert("Final Score : " + point);