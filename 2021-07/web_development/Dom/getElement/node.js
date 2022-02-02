let color = "rgb(132, 173, 254)";

// 1. get Element by Id
let header = document.getElementById("header");
header.style.backgroundColor = color;

// 2. get Elements by className
let classElements = document.getElementsByClassName("header");

for(let i = 0; i < classElements.length; i++) {
    classElements[i].style.backgroundColor = color;
}

// 3. get Elements by TagName
let tagElements = document.getElementsByTagName("p");

for (let i = 0; i < tagElements.length; i++) {
    tagElements[i].style.backgroundColor = color;
}

// 4. querySelector
let queryElement = document.querySelector("#query");
queryElement.style.backgroundColor = color;

// 5. querySelectorAll
let queryAllElements = document.querySelectorAll(".query-all");

queryAllElements.forEach((element) => { // querySelectorAll로 받은 요소들은 arrary처럼 동작이 가능 ex) forEach
  element.style.backgroundColor = color;
});