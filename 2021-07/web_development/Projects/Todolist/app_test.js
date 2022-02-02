const addButton = document.querySelector(".todo-button");
const selectFilter = document.querySelector(".filter-todo");
// const deleteButton = document.querySelector(".delete-button");
const todoInput = document.querySelector(".todo-input");
const listContainer = document.querySelector(".todo-list");

// EventListener
addButton.addEventListener("click", addItem);
// selectFilter.addEventListener("change", changeFilter);
// console.log(checkButtons);

// functions
function updateLocal() {
  let todo_items = null;

  if (localStorage.getItem("todo_items") === null) {
    todo_items = [];
  } else {
    todo_items = JSON.parse(localStorage.getItem("todo_items"));
  }

  todo_items.push(todoInput.value);
  localStorage.setItem("todo_items", JSON.stringify(todo_items));
}

function changeFilter(event) {
  event.preventDefault();
}

function checkItem() {
  console.log("Hi I'm checkButton.");
}

function deleteItem() {
  // event.preventDefault();
  console.log("Hi I'm deleteButton.");
}

function addItem(event) {
  event.preventDefault();

  if (todoInput.value !== "") {
    let newDiv = document.createElement("div");
    let newContent = document.createElement("li");
    let newCheckButton = document.createElement("button");
    let newDeleteButton = document.createElement("button");

    newCheckButton.innerHTML = `<i class="fas fa-check"></i>`;
    newCheckButton.classList.add("todo-list__item--done-button");

    newDeleteButton.innerHTML = `<i class="fas fa-trash"></i>`;
    newDeleteButton.classList.add("todo-list__item--delete-button");

    newContent.innerHTML = todoInput.value;
    newContent.classList.add("todo-list__item--content");

    newDiv.appendChild(newContent);
    newDiv.appendChild(newCheckButton);
    newDiv.appendChild(newDeleteButton);
    newDiv.classList.add("todo-list__item");

    listContainer.appendChild(newDiv);

    
    newCheckButton.addEventListener("click", function() {
      // ****** localstorage ******
      newDiv.classList.toggle("compeleted");
    });

    newDeleteButton.addEventListener("click", function() {
      // ****** localstorage ******
      let deleteButtons = document.getElementsByClassName("todo-list__item--delete-button");
      // index = deleteButtons.indexOf(newDeleteButton);
      console.log(deleteButtons);
      // localStorage.removeItem();
      newDiv.remove();
    });

    // console.log(newDiv);

    updateLocal();

    todoInput.value = "";

    // let checkButtons = document.querySelectorAll(".todo-list__item--done-button");
    // console.log(checkButtons);
    // checkButtons.forEach(checkButton => checkItem());
    // const checkButtons = document.querySelectorAll(".todo-list__item--done-button");
    // console.log(checkButtons);
    // checkButtons.forEach(checkButton => {
    //   console.log(checkButton);
    // }
    // );
  }
}
