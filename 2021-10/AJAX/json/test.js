function getTest() {
    fetch("./test.json")
        .then((data) => data.json())
        .then((test) => console.log(test.data));
}

getTest();