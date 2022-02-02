// const makeBurger = (nextStep) => {
//     getBeef(function (beef) {
//         cookBeef(beef, function (cookedBeef) {
//             getBuns(function (buns) {
//                 putBeefBetweenBuns(buns, cookedBeef, function (burger) {
//                     nextStep(burger);
//                 });
//             });
//         });
//     });
// };

// makeBurger(function (burger) {
//     serve(burger);
// });

// function serve(burger) {
//     console.log(`${burger} is delivering...`);
// }

// function requestBeef(name){
//     return "Beef";
// }

// const getBeef = (callback) => {
//     const beef = requestBeef();
//     try {
//         return callback(beef);
//     } catch (err) {
//         throw Error("고기가 도착하지 않았어요!!!");
//     }
// };

// const cookBeef = (beef, callback) => {
//     const cookedBeef = "cookedBeef";
//     return callback(cookedBeef);
// };

// Promise
// - pending
// - fulfilled (resolve)
// - rejcted

const leftFright = "Freeze Beef";

function getBeefFromFridge(fridge) {
    return `${fridge}`;
    // return false;
}

function putBeefinOven(beef) {
    return `cooked ${beef}`;
}

function friedBuns(beef) {
    return `${beef} + friedBuns`;
}

const getBeef = (_) => {
    const fridge = leftFright;
    const beef = getBeefFromFridge(fridge); // "Freeze Beef"

    console.log("A:", beef);

    return new Promise((resolve, reject) => {
        if (beef) {
            resolve(beef);
        } else {
            reject(new Error("No More Beef!"));
        }
    });
};

const cookBeef = (beef) => {
    const workInProgress = putBeefinOven(beef);
    
    console.log("B:", workInProgress);

    return new Promise((resolve, reject) => {
        if (workInProgress) {
            setTimeout(() => {
                resolve(workInProgress);
            }, 3000);
        } else {
            reject(new Error("Oven Error!"));
        }
    })
}

const getBuns = (beef) => {
    const friedBunsAndBeef = friedBuns(beef);
    
    console.log("C:", friedBunsAndBeef);

    return new Promise((resolve, reject) => {
        if (friedBunsAndBeef) {
            resolve(friedBunsAndBeef);
        } else {
            reject(new Error("No More Buns!"));
        }
    })
}

const putBeefBetweenBuns = (bunsAndBeef) => {
    return `Delicious Burger : ${bunsAndBeef}`;
}

const makeBurger = () => {
    return getBeef()
        .then((beef) => cookBeef(beef))
        .then((cookedBeef) => getBuns(cookedBeef))
        .then((bunsAndBeef) => putBeefBetweenBuns(bunsAndBeef))
        .catch((err) => console.log(`${err}`));
};

function resolvePromise(promise) {
    promise.then((result) => {
        console.log(result);
    });
}

resolvePromise(makeBurger());