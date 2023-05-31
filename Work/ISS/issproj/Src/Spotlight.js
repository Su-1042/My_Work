//Typing Effect
var element = document.getElementById("typing-effect");
var text = element.innerHTML;
element.innerHTML = "";
var i = 0;
var intervalId = setInterval(function() {
  element.innerHTML += text.charAt(i);
  i++;
  if (i == text.length) {
    clearInterval(intervalId);
  }
}, 50); 


//Zooming Image

const spotlightImg = document.querySelector('.SpotLight img');
let scale = 1;

spotlightImg.style.transition = 'transform 0.5s ease-in-out';
spotlightImg.style.transformOrigin = 'center center';
function zoomInOut() {
  if (scale === 1) {
    scale = 1.2;
  } else {
    scale = 1;
  }
  spotlightImg.style.transform = `scale(${scale})`;
}

setInterval(zoomInOut, 1000);



// Countdown to upcoming release
// Set the release date for the album/song
const releaseDate = new Date("2023-06-30T00:00:00Z");

// Get the countdown timer element
const countdownTimer = document.getElementById("countdown-timer");

// Update the countdown timer every second
setInterval(() => {
  // Calculate the time remaining until the release date
  const now = new Date();
  const timeRemaining = releaseDate - now;
  
  // If the release date has passed, display a message instead of the timer
  if (timeRemaining < 0) {
    countdownTimer.innerHTML = "The album/song has been released!";
    return;
  }
  
  // Convert the time remaining into days, hours, minutes, and seconds
  const days = Math.floor(timeRemaining / (1000 * 60 * 60 * 24));
  const hours = Math.floor((timeRemaining % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
  const minutes = Math.floor((timeRemaining % (1000 * 60 * 60)) / (1000 * 60));
  const seconds = Math.floor((timeRemaining % (1000 * 60)) / 1000);
  
  // Display the countdown timer
  countdownTimer.innerHTML = ` "Speak NOW" will be released in ${days}:${hours}:${minutes}:${seconds}`;
}, 1000);

        // Submit review form
        function submitReview() {
            var name = document.forms["reviewForm"]["name"].value;
            var rating = document.forms["reviewForm"]["rating"].value;
            var review = document.forms["reviewForm"]["review"].value;
    
            if (name == "" || rating == "" || review == "") {
                alert("Please fill in all fields.");
            } else {
                var reviewTable = document.getElementById("reviewTable");
                var newRow = reviewTable.insertRow(-1);
                var nameCell = newRow.insertCell(0);
                var ratingCell = newRow.insertCell(1);
                var reviewCell = newRow.insertCell(2);
                nameCell.innerHTML = name;
                ratingCell.innerHTML = rating;
                reviewCell.innerHTML = review;
    
                // Clear form inputs
                document.forms["reviewForm"]["name"].value = "";
                document.forms["reviewForm"]["rating"].value = "";
                document.forms["reviewForm"]["review"].value = "";
    
                // Show review table
                reviewTable.style.display = "table";
            }
        }