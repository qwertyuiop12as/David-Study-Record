const buttonContainer = document.querySelector(".buttons");
const output = document.querySelector(".output");

urls = [
    {
        "url" : "./books.json",
        "key" : "books"
    },
    {
        "url" : "./coins.json",
        "key" : "coins"
    },
    {
        "url" : "./friends.json",
        "key" : "friends"
    }
];

function print(elements, key) {
    // console.log(`elements : ${elements[key][properties]}, ${typeof(elements)}`);
    output.innerHTML = `<h3>Searching for ${key}</h3>`
    elements[key].forEach((elem) => {
        const div = document.createElement("div");
        div.classList.add("box");
        console.log(elem);
        Object.keys(elem).forEach((property_key) => {
            const content = document.createElement("p");
            content.innerHTML = `${property_key} : ${elem[property_key]}`;
            div.appendChild(content);
        });
        output.appendChild(div);
    });
}

urls.forEach(file => {
    const button = document.createElement("button");
    button.classList.add("button");
    button.innerText = file.key;

    button.addEventListener("click", () => {
        fetch(file.url)
            .then((elem) => elem.json())
            .then((elem) => print(elem, file.key))
            .catch((err) => console.log(`error has been detected ${err}`));
    });

    buttonContainer.appendChild(button);
});