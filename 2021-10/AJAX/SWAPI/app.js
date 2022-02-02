const menuBar = document.querySelector(".menu");
const baseUrl = "https://swapi.dev/api/";
const menuTitle = document.querySelector(".title");
const output = document.querySelector(".output");
let curTopic = "";

// output.addEventListener("click", ElemClicked);
//   output.addEventListener("click", ElemClicked(result));

// function ElemClicked(e) {
//   console.log(e.target);
// //   console.log(result);

//     if (e.target.classList.contains("elem__btn")) {

//         printInfo(e.target);
//     }
// }

function getMenu() {
  fetch(baseUrl)
    .then((data) => data.json())
    .then((menuList) => updateMenuBar(menuList))
    .catch((err) => printError(err));
}

function updateMenuBar(menuList) {
  // console.log(menuList);
  Object.keys(menuList).forEach((key) => {
    const btn = document.createElement("button");
    btn.innerText = key;
    btn.classList.add("menu__btn");
    // btn.addEventListener("click", MenuClicked(baseUrl));
    menuBar.appendChild(btn);
  });
}

function MenuClicked(event) {
  event.preventDefault();

  if (event.target.classList.contains("menu__btn")) {
    let topic = event.target.innerText.toLowerCase();
    curTopic = topic;
    fetchMenu(`${baseUrl}${topic}`);
  }
}

function fetchMenu(url) {
  output.innerHTML = "";
  // console.log(topic);
  title = document.createElement("h1");
  title.classList.add("title");
  title.innerText = curTopic;
  output.appendChild(title);

  let para = document.createElement("p");
  para.classList.add("url");
  para.innerText = url;
  output.appendChild(para);

  // print Page Elements
  fetch(url)
    .then((url) => url.json())
    .then((url) => {
      printTitle(url);
      printPage(url);
    })
    .catch((err) => printError(err));

  // print Page Numbers
  // fetch(url)
  //   .then((url) => url.json())
  //   .then((url) => printPage(url))
  //   .catch((err) => printError(err));
}

function printTitle(url) {
  // console.log(url);
  let results = url.results;
  let key = "name";

  if (Object.keys(results[0]).includes("name") == false) {
    key = "title";
  }
  // console.log(key);

  results.forEach((result) => printResult(result, key));
}

function printResult(result, key) {
  // console.log(result, key);
  const box = document.createElement("box");
  box.innerText = result[key];
  box.classList.add("elem__btn");
  box.addEventListener("click", () => printDetail(result));
  output.appendChild(box);
}

function printPage(url) {
  // console.log(url);
  // console.log("count", url["count"]);
  let pageContainer = document.createElement("div");
  let pageNumber = (url["count"] - 1) / 10 + 1;

  if (pageNumber > 1) {
    pageContainer.classList.add("page__container");

    if (url["previous"] != null) {
      let prevBtn = document.createElement("button");
      prevBtn.innerText = "Prev";
      prevBtn.classList.add("prev__btn");
      prevBtn.addEventListener("click", () => fetchMenu(url["previous"]));
      pageContainer.appendChild(prevBtn);
    }
    // let nextBtn = document.createElement

    for (let num = 1; num <= pageNumber; num++) {
      let numBtn = document.createElement("button");
      numBtn.innerText = num;
      numBtn.classList.add("num__btn");
      numBtn.addEventListener("click", () =>
        fetchMenu(`${baseUrl}${curTopic}/?page=${num}`)
      );
      pageContainer.appendChild(numBtn);
    }

    if (url["next"] != null) {
      let nextBtn = document.createElement("button");
      nextBtn.innerText = "Next";
      nextBtn.classList.add("next__btn");
      nextBtn.addEventListener("click", () => fetchMenu(url["next"]));
      pageContainer.appendChild(nextBtn);
    }

    output.appendChild(pageContainer);
  }
}

function printDetail(result) {
  // console.log("elemClicked");
  // console.log(result);

  output.innerHTML = ``;

  Object.keys(result).forEach((key) => {
    console.log(key);
    let content = document.createElement("p");
    content.classList.add("elem__info");
    content.innerHTML = `<span class="elem__info--key">${key}</span> : <span class="elem__info--value">${result[key]}</span>`;
    output.appendChild(content);
  });
}

function printError(message) {
  console.log(`Error exist! ${message}`);
  return 0;
}

document.addEventListener("DOMContentLoaded", getMenu);
menuBar.addEventListener("click", MenuClicked);
