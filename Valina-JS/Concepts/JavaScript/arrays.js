const mon = "mon";
const tue = "tue";
const wed = "wed";
const thu = "thu";
const fri = "fri";
const sat = "sat";
const sun = "sun";

const daysOfWeek = mon + tue + wed + thu + fri + sat + sun;
console.log(daysOfWeek);


const daysOfWeek_array = ["mon", "tue", "wed", "thu", "fri", "sat"];
console.log(daysOfWeek_array);

console.log("The 1st day of the week is " + daysOfWeek_array[0]);
// number of the index of array starts with 0

// Add one more day to array
daysOfWeek_array.push("sun");
console.log(daysOfWeek_array);

console.log(daysOfWeek_array[100]);
// if the index is out of range, it prints "undefined"

const array = [1, "A", 0.5, true, false, undefined, null, "Hello", "David"];
// doesn't matter on their data type;
console.log(array);