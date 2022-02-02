const container = document.querySelector(".container");
function GetItem(url) {
    fetch(url)
        .then((data) => data.json())
        .then((result) => RenderData(result));
}

function RenderData(data) {
    console.log(data);
    data.forEach((item) => {
        console.log(item);

        const div = document.createElement("div");
        div.classList.add("human");

        // const name = document.createElement("span");
        // name.classList.add("name");
        const name = `${item.name.first} ${item.name.last}`;

        // const age = document.createElement("span");
        // age.classList.add("age");
        const age = item.age;

        const city = document.createElement("p");
        city.classList.add("city");
        city.innerText = `- ${item.location.city}, ${item.location.country}`;

        const initial = document.createElement("span");
        initial.innerText = `${name} (${age})`;

        div.appendChild(initial);
        div.appendChild(city);

        container.appendChild(div);
    });
}


GetItem("https://www.discoveryvip.com/shared/test1.json");