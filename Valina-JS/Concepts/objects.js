// const playerName = "David";
// const playerPoint = 100;
// const playerAge = 16;
// const playerFat = true;

const player = {
  name: "David",
  points: 10,
  fat: true,
  age: 16,
};

console.log(player);
// all the key and valeus in the object

console.log(player.name);
console.log(player["name"]);
// value for the player's name

console.log(
  "my name is " +
    player.name +
    " / points : " +
    player.points +
    " / is fat : " +
    player.fat +
    " / age : " +
    player.age
);

console.log("Before : " + player.fat);
player.fat = false;
console.log("After : " + player.fat);
// Eventhough the object itself was declared as const variable, but we can still change the value inside the object

player = false;
// The error occurs when we try to change the whole object

player.lastName = "Cho";
console.log(player["lastName"]);
// We can also add new key&value for const object