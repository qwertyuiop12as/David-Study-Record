const input = document.querySelector("#input");
const addButton = document.querySelector(".input_button");
const todoList = document.querySelector(".todos");
const filter = document.querySelector(".filter");

document.addEventListener("DOMContentLoaded", printTodo);
addButton.addEventListener("click", addTodo);
todoList.addEventListener("click", changeTodo);
filter.addEventListener("click", filterTodo);

function addElement(todo) {
  let text = todo[0];
  if (text === "") {
    return;
  }

  // let box = document.createElement("label");
  box.classList.add("todo");
  box.innerText = text;

  let checkbox = document.createElement("input");
  checkbox.type = "checkbox";

  if (todo[1] === true) {
    checkbox.checked = true;
  }

  let checkmark = document.createElement("span");
  checkmark.classList.add("checkmark");

  let deletebutton = document.createElement("button");
  deletebutton.classList.add("deletebutton");

  box.appendChild(checkbox);
  box.appendChild(checkmark);
  box.appendChild(deletebutton);

  todoList.appendChild(box);
}

function getLocal() {
  let todoItems = null;
  if (localStorage.getItem("todo_items") === null) {
    todoItems = [];
  } else {
    todoItems = JSON.parse(localStorage.getItem("todo_items"));
  }

  return todoItems;
}

function printTodo() {
  let todoItems = getLocal();
  let filterValue = filter.options[filter.selectedIndex].value;

  todoList.innerHTML = ``;
  todoItems.forEach((todo) => {
    addElement(todo);
  });
}

function addTodo(e) {
  e.preventDefault();

  if (input.value === "") {
    return;
  }

  addElement([input.value, false]);
  updateLocal(input.value);
  input.value = "";
}

function updateLocal(todo) {
  let todoItems = getLocal();

  // [vlaue, (checked or not)]
  todoItems.push([todo, false]);
  localStorage.setItem("todo_items", JSON.stringify(todoItems));
}

function checkItem(todo) {
  let todoItems = getLocal();

  for (let i = 0; i < todoItems.length; i++) {
    if (todoItems[i][0] === todo) {
      todoItems[i][1] = !todoItems[i][1];
      break;
    }
  }

  localStorage.setItem("todo_items", JSON.stringify(todoItems));
  printTodo();
}

function deleteItem(todo) {
  let todoItems = getLocal();
  console.log(todo.innerText, "delete");

  console.log(todoItems.findIndex((item) => item.includes(todo.innerText)));

  todoItems.splice(
    todoItems.findIndex((item) => item.includes(todo.innerText)),
    1
  );

  localStorage.setItem("todo_items", JSON.stringify(todoItems));

  printTodo();
}

function changeTodo(e) {
  e.preventDefault();

  let clickedItem = e.target;
  console.log("clicked Item : ", clickedItem);

  if (clickedItem.classList[0] === "todo") {
    checkItem(clickedItem.innerText);
  } else if (clickedItem.classList[0] === "checkmark") {
    checkItem(clickedItem.parentElement.innerText);
  }

  if (clickedItem.classList[0] === "deletebutton") {
    let todo = clickedItem.parentElement;

    todo.classList.add("delete");

    todo.addEventListener("transitionend", (e) => {
      if (e.propertyName === "transform") {
        deleteItem(todo);
      }
    });

    // todo.remove();
  }
}

function filterTodo(e) {
  e.preventDefault();
  let filterValue = filter.options[filter.selectedIndex].value;

  if (filterValue === "all") {
    filterAll();
  } else if (filterValue === "completed") {
    filterCompleted();
  } else if (filterValue === "uncompleted") {
    filterUncompleted();
  }
}

function filterAll() {
  let todos = todoList.childNodes;

  todos.forEach((todo) => {
    todo.style.display = "flex";
  });
}

function filterCompleted() {
  let todos = todoList.childNodes;

  todos.forEach((todo) => {
    console.log(todo);
  });
}
