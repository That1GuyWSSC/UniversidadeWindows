'use strict'

let message = document.querySelector('.message');
const checkButton = document.querySelector('.check')
let displayScore = document.querySelector('.score')
let displayHighscore = document.querySelector('.highscore')
const number = document.querySelector('.number')
const again=document.querySelector('.again');
let guessNumber = document.querySelector('.guess')


let secretNumber = Math.trunc(Math.random()*20)+1
console.log(secretNumber)

let score=20
let highscore=0

checkButton.addEventListener('click', function(){
  
  Number(guessNumber.value)
  
  if(!guessNumber){
    message.textContent = "🛑 No Number! "
  }else if(guessNumber===secretNumber){ // = = = 
    if(score>highscore){
    displayHighscore.textContent = score;  
    message.textContent = "🎉 Correct Number!!"
    document.querySelector('body').style.backgroundColor = '#60b347'

    }
  }else if(guessNumber !== secretNumber){  // '! = = 
    if(score>=1){
    score--;
    message.textContent = guessNumber < secretNumber ? ' 📉 Too low!' : '📈 Too high'
    displayScore.textContent = score;
    }
    else{
      message.textContent = "☄️ You lost"
      document.querySelector('body').style.backgroundColor = 'red'
      displayScore.textContent = 0;
    }
  }
})


again.addEventListener('click', function(){
secretNumber = Math.trunc(Math.random()*20)+1
displayHighscore.textContent=0;
displayScore.textContent = 20;
message.textContent = "Start guessing"
number.textContent = '?'
guessNumber.value=''
})