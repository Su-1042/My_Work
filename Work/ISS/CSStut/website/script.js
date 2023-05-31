//TASK 1

const alertopt = document.getElementById("hello-world-button");
alertopt.addEventListener("click", () => {
    alert("Sujal Deoda");
});

//TASK 2

var bold = document.getElementById("bold-button");
bold.addEventListener("click", () => {
    var paragraphs = document.getElementsByTagName("p");
    for (var i = 0; i < paragraphs.length; i++) {
        paragraphs[i].style.fontWeight = "bold";
    }
});


var bold = document.getElementById("bold-button");
bold.addEventListener("click", () => {
    var paragraphs = document.getElementsByTagName("li");
    for (var i = 0; i < paragraphs.length; i++) {
        paragraphs[i].style.fontWeight = "bold";
    }
});


var unbold = document.getElementById("unbold-button");
unbold.addEventListener("click", () => {
    var paragraphs = document.getElementsByTagName("p");
    for (var i = 0; i < paragraphs.length; i++) {
        paragraphs[i].style.fontWeight = "400";
    }
});


var unbold = document.getElementById("unbold-button");
unbold.addEventListener("click", () => {
    var paragraphs = document.getElementsByTagName("li");
    for (var i = 0; i < paragraphs.length; i++) {
        paragraphs[i].style.fontWeight = "400";
    }
});



//TASK 3

var next = document.getElementsByClassName("next-image-button")[0];
var image1 = document.getElementById("cookie-image");
var index = 1;

next.addEventListener("click", () => {
    index++;

    if (index == 2) {
        image1.src = "images/cookie2.jpg";
    }
    if (index == 3) {
        image1.src = "images/cookie3.jpg";
    }
    if (index >= 4) {
        index = 1;
        image1.src = "images/cookie1.jpg";
    }
});



//TASK 4

var darkmode = document.getElementById("dark-mode-switch");
darkmode.addEventListener("click", () => {

    if (darkmode.checked == true)
        document.body.style.backgroundColor = "grey";
    if (darkmode.checked == false)
        document.body.style.backgroundColor = "#f2f2f2";

});

//TASK 5
const button = document.querySelector('#new-joke');
const jokeDiv = document.querySelector('#joke');

function getNewJoke() {
  fetch('https://official-joke-api.appspot.com/random_joke')
    .then(response => response.json())
    .then(data => {
      const joke = data.setup + " " + data.punchline;
      jokeDiv.textContent = joke;
    })
    .catch(error => console.error(error));
}

button.addEventListener('click', () => {
  getNewJoke();
});