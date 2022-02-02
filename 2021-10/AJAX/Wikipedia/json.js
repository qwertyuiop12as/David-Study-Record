const input = document.querySelector(".value");
const button = document.querySelector(".button");
const result = document.querySelector(".result");

button.addEventListener("click", GenerateUrl);

function GenerateUrl(e) {

    e.preventDefault();

    // console.log(input.value);

    const search = input.value || "javascript";
    const validUrl = "https://en.wikipedia.org/w/api.php?action=query&format=json&list=search&origin=*&srsearch=" + search;
    // fetch(validUrl)
    console.log(validUrl);

    GetResult(validUrl);
}

function RenderPage(search) {
    search.forEach(post => {
        const div = document.createElement("div");
        div.classList.add("box");

        // const title = document.createElement("a");
        // title.innerText = post.title;
        const title = document.createElement("h1");
        title.innerHTML = `<a href="https://en.wikipedia.org/wiki?curid=${post.pageid}">${post.title}</a>`;

        const postInfo = document.createElement("h3");
        postInfo.innerText = `Page ID ${post.pageid} | Size ${post.size} | WordCount ${post.wordcount}`;

        const content = document.createElement("div");
        console.log("snippet", post.snippet);
        content.innerHTML = post.snippet;

        div.appendChild(title);
        div.appendChild(postInfo);
        div.appendChild(content);

        // console.log("div", div);
        result.appendChild(div);
    });
    input.value = "";
}

function TotalResult(query) {
    const totalNum = query.searchinfo.totalhits;
    const totalResult = document.createElement("p");
    totalResult.innerText = `Total Results : ${totalNum}`;

    console.log(totalResult);
    console.log(result);

    result.appendChild(totalResult);

    RenderPage(query.search);
}

function GetQuery(data) {
    // console.log(data);
    console.log(data.query);
    TotalResult(data.query);
}

function GetResult(url) {
    result.innerHTML = ``;
    fetch(url)
        .then((data) => data.json())
        .then((result) => GetQuery(result));
}