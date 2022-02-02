const categoryBox = document.querySelector(".category__container");
const userInput = document.querySelector(".user__input");
const userButton = document.querySelector(".user__button");
const output = document.querySelector(".output");
const baseUrl = "https://api.chucknorris.io/jokes/";

document.addEventListener("DOMContentLoaded", getCategory);
categoryBox.addEventListener("click", categoryClicked);
userButton.addEventListener("click", searchQuery);

function printQuery(query) {
  const total = query["total"];
  const result = query["result"];
  const content = document.createElement("p");

  content.innerHTML = `Total Result(s) : ${total}<br/><br/>`;
  
  result.forEach(elem => {
      content.innerHTML += `" ${elem["value"]} "<br/><br/>`;
  });
  // console.log(`result : ${result}`);

  output.appendChild(content);
  // console.log(total);
}

function searchQuery(event) {
  event.preventDefault();
  const query = userInput.value;
  if (query.length < 3) {
    alert("반드시 최소값 3과(와) 최대값 120 사이의 크기이어야 합니다.");
  } else {
    output.innerHTML = `<hr/>`;

    fetch(`${baseUrl}search?query=${query}`)
      .then((data) => data.json())
      .then((data) => printQuery(data))
      .catch((data) => console.log(`${data["violations"]["search.query"]}`));
  }
  userInput.value = "";
}

function categoryClicked(event) {
  event.preventDefault();
  // fetch(`${baseUrl}random?category=${keyword}`)
  //     .
  //   console.log(e.target);
  //   if (e.target)
  //   console.log(`${baseUrl}random?category=${keyword}`);
  //   console.log(
  //     "\n이벤트가 발생한 오브젝트 정보\n" +
  //       "event.target : " +
  //       event.target +
  //       "\n" +
  //       "event.target.id : " +
  //       event.target.id +
  //       "\n" +
  //       "event.target.name : " +
  //       event.target.name +
  //       "\n" +
  //       "event.target.value : " +
  //       event.target.value +
  //       "\n" +
  //       "event.target.nodeType : " +
  //       event.target.nodeType +
  //       "\n" +
  //       "event.target.nodeName : " +
  //       event.target.nodeName +
  //       "\n" +
  //       "event.target.parentNode.nodeName : " +
  //       event.target.parentNode.nodeName +
  //       "\n" +
  //       "event.target.parentNode.id : " +
  //       event.target.parentNode.id +
  //       "\n" +
  //       "event.target.nextSibling.nextSibling.id : " +
  //       event.target.nextSibling.nextSibling.id +
  //       "\n" +
  //       "event.target.parentNode : " +
  //       event.target.parentNode +
  //       "\n" +
  //       "event.target.parentElement : " +
  //       event.target.parentElement +
  //       "\n"
  //   );

  if (event.target.nodeName === "BUTTON") {
    const keyword = event.target.innerText;
    console.log(keyword);
    fetch(`${baseUrl}random?category=${keyword}`)
      .then((url) => url.json())
      .then((data) => {
        output.innerHTML = `<hr/>`;
        console.log(data);
        const content = document.createElement("p");
        content.innerHTML = `"${data["value"]}"`;
        output.appendChild(content);
        // console.log(data);
      })
      .catch((err) => console.log(`err : ${err}`));
  }
}

function getCategory(e) {
  e.preventDefault();
  fetch(`${baseUrl}categories`)
    .then((data) => data.json())
    .then((data) => {
      //   console.log(data);
      data.forEach((elem) => {
        const box = document.createElement("button");
        box.classList.add("category__button");
        // box.addEventListener("click", categoryClicked(elem));
        box.innerText = elem;

        categoryBox.appendChild(box);
        // console.log(elem);
      });
    })
    .catch((err) => console.log(`err : ${err}`));
}
