const header = document.querySelector("#header");
const generator = document.querySelector(".generator");
const categorySelector = document.querySelector("#generator__category");
const difficultySelector = document.querySelector("#generator__difficulty");

const startBtn = document.querySelector(".generator__button");
const game = document.querySelector(".game");
const gameQuestion = document.querySelector(".game__question__box");
const gameProgress = document.querySelector(".game__progress");
const choiceContainer = document.querySelector(".game__choice__container");
const nextBtn = document.querySelector(".game__next-btn");

const input_number = document.querySelector("#generator__number");
const option_category = document.querySelector("#generator__category");
const option_difficulty = document.querySelector("#generator__difficulty");

const baseUrl = "https://opentdb.com/api.php?";
const categoryUrl = "https://opentdb.com/api_category.php";

const difficulties = [
  {
    name: "Any Difficulty",
    value: "Default",
  },
  {
    name: "Easy",
    value: "easy",
  },
  {
    name: "Medium",
    value: "medium",
  },
  {
    name: "Hard",
    value: "hard",
  },
];

let questionList = {
  question: [],
  current: 0,
  total: 0,
  score: 0,
  token: true,
};

// let questionList["current"] = 0;

// function createGenerator(e) {
//   e.preventDefault();
//   generator.innerHTML = `<p>Number of Question</p>`;
//   generator.appendChild(`<p>Select Category</p>`);
//   fetchCategory(e);
// }

function resetQuestionList() {
  questionList = {
    question: [],
    current: 0,
    total: 0,
    score: 0,
    token: true,
  };

  categorySelector.innerHTML = ``;
  difficultySelector.innerHTML = ``;
  
  nextBtn.innerHTML = "Next";
  header.style.display = "block";
  generator.style.display = "block";
  game.style.display = "none";
}

function fetchGenerator(e) {
  generator.style.display = "block";
  game.style.display = "none";
  if (questionList["token"] == false) {
    resetQuestionList();
  }
  console.log("fetchGEnerator");
  nextBtn.removeEventListener("click", fetchGenerator);
  nextBtn.addEventListener("click", questionCenter);
  e.preventDefault();
  fetch(categoryUrl)
    .then((data) => data.json())
    .then((categories) => {
      genSelections(categories);
    })
    .catch((err) => console.log(`err : ${err}`));

  genDifficulties();
}

function genSelections(categories) {
  console.log("genSelection");
  genElement(categorySelector, "option", "Any Category");
  // categorySelector.
  categories["trivia_categories"].forEach((category) => {
    let option = genElement(categorySelector, "option", category["name"]);
    option.value = category["id"];
    // console.log(option);
    // categorySelector.appendChild(option);
  });
}

function genDifficulties() {
  console.log("genDifficulties");
  difficulties.forEach((difficulty) => {
    let option = genElement(difficultySelector, "option", difficulty["name"]);
    option.value = difficulty["value"];
  });
}

function generateURL() {
  let url_number = `amount=${input_number.value}`;
  let url_category = `&category=${option_category.value}`;
  let url_difficulty = `&difficulty=${option_difficulty.value}`;

  if (input_number.value < 1 || input_number.value > 50) {
    alert("Please Choose a number between 1 and 50!");
    return;
  }

  console.log(url_category);
  if (url_category == "&category=Any Category") url_category = "";
  if (option_difficulty.value == "Default") url_difficulty = "";

  let newUrl = baseUrl + url_number + url_category + url_difficulty;
  console.log(newUrl);

  header.style.display = "none";
  generator.style.display = "none";
  game.style.display = "block";

  questionList["total"] = Number(input_number.value);
  // console.log(questionList["total"]);

  fetchQuestion(newUrl);
}

function fetchQuestion(Url) {
  fetch(Url)
    .then((Url) => Url.json())
    .then((Url) => {
      Url["results"].forEach((question) => {
        questionList["question"].push(question);
      });

      questionCenter();
    })
    .catch((err) => console.log(`err : ${err}`));

  console.log(
    questionList,
    questionList["question"],
    questionList["question"].length
  );

  // questionList["total"] = questionList["question"].length;
  // console.log(questionList);
}

function questionCenter() {
  console.log(questionList["current"], questionList["total"]);
  if (questionList["current"] < questionList["total"]) {
    // console.log("II");
    printQuestion();
  } else {
    showResult();
  }
}

function printQuestion() {
  nextBtn.style["display"] = "none";
  gameProgress.innerHTML = `Question ${questionList["current"] + 1}<span>/${
    questionList["total"]
  }</span>`;
  gameQuestion.innerHTML = ``;

  var curQuestion = questionList["question"][questionList["current"]];

  var question = genElement(gameQuestion, "h1", curQuestion["question"]);
  question.classList.add("game__question");

  var choiceContainer = genElement(gameQuestion, "div", "");
  choiceContainer.classList.add("game__choice__container");

  var incorrectAnswers = curQuestion["incorrect_answers"];
  // console.log(incorrectAnswers, incorrectAnswers.length);

  var correctAnswer = document.createElement("box");
  correctAnswer.innerText = curQuestion["correct_answer"];
  correctAnswer.classList.add("game__choice");
  correctAnswer.classList.add("choice__correct");

  var randomNum = Math.floor(Math.random() * incorrectAnswers.length) - 1;


  if (randomNum == -1) {
    choiceContainer.append(correctAnswer);
  }

  for (let i = 0; i < incorrectAnswers.length; i++) {
    var incorrectAnswer = genElement(
      choiceContainer,
      "box",
      incorrectAnswers[i]
    );
    incorrectAnswer.classList.add("game__choice");
    incorrectAnswer.classList.add("choice__wrong");
    if (i == randomNum) {
      choiceContainer.append(correctAnswer);
    }
  }

  choiceContainer.addEventListener("click", choiceClicked);

  questionList["token"] = true;
  questionList["current"] += 1;
}

function choiceClicked(e) {
  // console.log("current : ", questionList["current"]);
  // console.log("Clicked Item : ", e.target);
  if (
    e.target.classList[0] == "game__choice" &&
    questionList["token"] == true
  ) {
    showAnswer(e.target);
    questionList["token"] = false;
  }
}

function showAnswer(clickedItem) {
  var correct_answer = document.querySelector(".choice__correct");
  console.log("Co : ", correct_answer);

  if (clickedItem.classList[1] == "choice__correct") {
    console.log("Correct!", clickedItem);
    questionList["score"] += 1;
  } else if (clickedItem.classList[1] == "choice__wrong") {
    console.log("Incorrect!", clickedItem);
    clickedItem.classList.add("wrong");
  }

  correct_answer.classList.add("correct");

  let answerChoices = document.querySelectorAll(".game__choice");

  answerChoices.forEach((choice) => {
    choice.classList.remove("game__choice");
  });

  if (questionList["current"] == questionList["total"])
    nextBtn.innerHTML = "Show Result";

  nextBtn.style["display"] = "block";
  // clickedItem.classList.add("move");
  // choiceContainer.removeEventListener("click", choiceClicked);
}

function showResult() {
  questionList["token"] = false;
  gameProgress.innerHTML = "Result";
  gameQuestion.innerHTML = ``;
  let score = genElement(gameQuestion, "h1", `${questionList["score"]}/${questionList["total"]}<span>(${Math.round(questionList["score"] / questionList["total"] * 1000) / 10}%)</span>`);
  score.classList.add("game__question");
  score.classList.add("game__result__score");
  nextBtn.innerHTML = "Play Again";
  // nextBtn.removeEventListener("click", questionCenter);
  nextBtn.addEventListener("click", fetchGenerator);
}

// 하나의 요소를 만들고 그 내용을 적은 다음 부모 요소에 append 해주는 function
function genElement(parent, eleType, html) {
  let temp = document.createElement(eleType);
  temp.innerHTML = html;
  parent.append(temp);
  return temp;
}

document.addEventListener("DOMContentLoaded", fetchGenerator);
startBtn.addEventListener("click", generateURL);
nextBtn.addEventListener("click", questionCenter);
