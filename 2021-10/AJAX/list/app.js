const output = document.querySelector(".output");
const buttonContainer = document.querySelector(".buttons");

const urls = [
  {
    "url": "./books.json",
    "keys": "books",
  },
  {
    "url": "./friends.json",
    "keys": "friends",
  },
  {
    "url": "./coins.json",
    "keys": "coins",
  }
];

function PrintData(data, key) {
  console.log(data, typeof(data));
  output.innerHTML = `<h3>Searching for ${key}</h3>`;
  data[key].forEach((dict) => {
    const div = document.createElement("div");
    div.classList.add("box");
    Object.keys(dict).forEach((key) => {
      // console.log(key, ":", dict[key]);
      const elem = document.createElement("p");
      elem.innerHTML = `${key} : ${dict[key]}`;
      div.appendChild(elem);
      console.log(`div : ${div}`);
      output.appendChild(div);
    });
  });
}


urls.forEach(elem => {
  const button = document.createElement("button");
  // button.classList.add(elem.keys);
  button.classList.add("button");
  button.innerText = `${elem.keys}`;

  button.addEventListener("click", () => {
    fetch(elem.url)
      .then((data) => data.json())
      .then((data) => PrintData(data, elem.keys));
  });

  buttonContainer.appendChild(button);
});