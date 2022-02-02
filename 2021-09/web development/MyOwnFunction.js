// Array.prototype.MyFilter = function (callback) {
//     const filteredArr = [];

//     for (let index = 0; index < this.length; index++) {
//         if (callback(this[index], index, this)) {
//             filteredArr.push(this[index]);
//         }
//     }

//     return filteredArr;
// }

// testArr = [1, 2, 3, 4, 5, 6, 7, 8];
// console.log(testArr.MyFilter(el => el % 2 == 0));

// Array.prototype.MyFindIndex = function (callback) {
//     for (let i = 0; i < this.length; i++) {
//         if(callback(this[index], i, this)) {
//             return
//         }
//     }
// }

test = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
];

console.log(test.findIndex((item) => item.includes(7)));