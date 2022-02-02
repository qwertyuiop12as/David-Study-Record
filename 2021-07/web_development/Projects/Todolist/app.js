const addButton = document.querySelector(".todo-button");
const checkButton = document.querySelector(".check-button");
const deleteButton = document.querySelector(".delete-button");
const todoInput = document.querySelector(".todo-input");
const list_container = document.querySelector(".todo-list");

// Event Listener
addButton.addEventListener("click", addItem);

// functions

function showItem(event, todo_items) {
  const todo_list = JSON.parse(localStorage.getItem("todo_items"));
  console.log(todo_list[1]);

  // for(let work = 0; )

  // const element = document.createElement("li");
  // element.innerHTML = `<p><p>`
}

function addItem(event) {
  event.preventDefault();

  let todo_items = null;

  if (localStorage.getItem("todo_items") === null) {
    todo_items = [];
  } else {
    todo_items = JSON.parse(localStorage.getItem("todo_items"));
  }

  todo_items.push(todoInput.value);
  localStorage.setItem("todo_items", JSON.stringify(todo_items));

  function createItem(todo) {
    console.log(todo);
    const item = document.createElement("li");

    const doneButton = document.createElement("button");
    const deleteButton = document.createElement("button");

    const para = document.createElement("p");

    // check and delete marks
    const doneIcon = document.createElement("i");
    const deleteIcon = document.createElement("i");
    doneIcon.classList.add("fas");
    doneIcon.classList.add("fa-check");
    deleteIcon.classList.add("fas");
    deleteIcon.classList.add("fa-trash");

    // append icons in buttons
    doneButton.appendChild(doneIcon);
    deleteButton.appendChild(deleteIcon);

    // append className
    item.classList.add("todo-list__item");
    doneButton.classList.add("todo-list__item--done-button");
    deleteButton.classList.add("todo-list__item--delete-button");

    para.classList.add("todo-list__item--para");
    para.innerHTML = todo;

    item.appendChild(para);
    item.appendChild(doneButton);
    item.appendChild(deleteButton);

    console.log(item);
    list_container.appendChild(item);
  }

  // console.log(todo_items);

  const last_item_index = todo_items.length - 1;
  createItem(todo_items[last_item_index]);

  // todo_items = [];

  // todo_items.array.forEach(createItem());

  // showItem();
}

// function addBox(event) {
//     event.preventDefault();

//     const box = document.createElement("div");
//     box.innerHTML = `<a href="https://www.google.com/">Google</a>`;
//     box.classList.add("box");

//     conatiner.appendChild(box);
// }
